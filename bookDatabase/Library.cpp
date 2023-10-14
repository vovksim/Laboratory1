//
// Created by mykh on 09.10.23.
//
#include "Library.h"

void Library::addBook(const book &bookToAdd) {
    insertBookToAppropriatePosition(bookToAdd);
    for (auto &iter: bookToAdd.getVectorCharacter()) {
        mapCharacterInfo[iter].insert(bookToAdd);
    }
}

void Library::getCharacterInfo(character &character) {
    for (auto &iter: mapCharacterInfo[character])
        std::cout << iter.getName() << std::endl;
}

void Library::insertBookToAppropriatePosition(const book &bookToAddInLibrary) {
    bool addedToSeries = false;
    for (auto &i: vectorBooksSeries) {
        for (auto &j: i.first) {
            auto positionInfo = isBookSerial(j, bookToAddInLibrary);
            if (positionInfo.first) {
                addedToSeries = true;
                i.first.insert(bookToAddInLibrary);
                if (i.first.size() >= 1) {
                    i.second = "Books about <" + positionInfo.second + ">";
                }
                return;
            }
        }
    }
    vectorBooksSeries.emplace_back(std::set{bookToAddInLibrary}, std::string{});
    std::cout << "Book added to LIB!" << std::endl;
}

std::pair<bool, std::string> Library::isBookSerial(const book &lhs, const book &rhs) {
    for (auto &k: lhs.getVectorCharacter()) {
        for (auto &z: rhs.getVectorCharacter()) {
            std::cout << "From bookToAdd: " << z.getPseudonim().getName() << " ; " << z.getPseudonim().getSurname()
                      << std::endl;
            std::cout << "From bookInLib: " << k.getPseudonim().getName() << " ; " << k.getPseudonim().getSurname()
                      << std::endl;
            if (k == z && (k.getRole() == role::primary || k.getRole() == role::secondary) &&
                (z.getRole() == role::primary || z.getRole() == role::secondary)) {
                std::cout << "Book should be added to series!" << std::endl;
                std::cout << k.getStringFormFullName() << std::endl;
                return std::make_pair(true, k.getStringFormFullName());
            }
        }
    }
    return std::make_pair(false, std::string{});
}

void Library::print(std::ostream &out) {
    std::cout << "<-----Library----->" << std::endl;
    printUnseried();
    printSeried();
    std::cout << "<----------------->" << std::endl;
}

void Library::printUnseried(std::ostream &out) const {
    for (auto &i: vectorBooksSeries) {
        if (i.first.size() == 1) {
            std::cout << "Unseried books: ";
            std::cout << i.first.cbegin()->getName() << "; ";
        }
    }
}

void Library::printSeried(std::ostream &out) const {
    for (auto &i: vectorBooksSeries) {
        if (i.first.size() > 1) {
            std::cout << i.second << ": ";
            for (auto &j: i.first) {
                std::cout << j.getName() << "; ";
            }
        }
        std::cout << std::endl;
    }
}

