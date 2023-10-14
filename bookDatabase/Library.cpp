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

void Library::printCharacterInfo(character &character) {
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
}

std::pair<bool, std::string> Library::isBookSerial(const book &lhs, const book &rhs) {
    if (lhs == rhs) {
        throw std::runtime_error("This book is already in Library.");
    }
    for (auto &k: lhs.getVectorCharacter()) {
        for (auto &z: rhs.getVectorCharacter()) {
            if (k == z && (k.getRole() == role::primary || k.getRole() == role::secondary) &&
                (z.getRole() == role::primary || z.getRole() == role::secondary)) {
                std::cout << k.getStringFormFullName() << std::endl;
                return std::make_pair(true, k.getStringFormFullName());
            }
        }
    }
    return std::make_pair(false, std::string{});
}

void Library::print(std::ostream &out) {
    std::cout << std::endl;
    std::cout << "<-----Library----->" << std::endl;
    printUnseried();
    printSeried();
    std::cout << "<----------------->" << std::endl;
}

void Library::printUnseried(std::ostream &out) const {
    std::cout << "Unseried books: ";
    bool wasPrinted = false;
    for (auto &i: vectorBooksSeries) {
        if (i.first.size() == 1) {
            wasPrinted = true;
            std::cout << i.first.cbegin()->getName() << "; ";
        }
    }
    if (!wasPrinted) {
        std::cout << "none" << std::endl;
    } else {
        std::cout << std::endl;
    }
}

void Library::printSeried(std::ostream &out) const {
    bool wasPrinted = false;
    for (auto &i: vectorBooksSeries) {
        if (i.first.size() > 1) {
            wasPrinted = true;
            std::cout << i.second << ": ";
            for (auto &j: i.first) {
                std::cout << j.getName() << "; ";
            }
        }
    }
    if (wasPrinted) {
        std::cout << std::endl;
    }
}


//can book appear in several series?
void Library::addSeries(std::set<book> &setOfBook, std::string &seriesName) {
    vectorBooksSeries.emplace_back(setOfBook, seriesName);
}

void Library::removeBook(book &bookToDelete) {
    for (auto &i: vectorBooksSeries) {
        for (auto &j: i.first) {
            if (bookToDelete == j) {
                i.first.erase(j);
                if (i.first.size() <= 1) {
                    i.second = "";
                }
            }
        }
    }
    for (auto &i: mapCharacterInfo) {
        for (auto &j: i.second) {
            if (j == bookToDelete) {
                i.second.erase(j);
            }
        }
    }
}

const std::set<book> &Library::getCharacterBookSet(const character &characterToGetInfo) const {
    for (auto &i: mapCharacterInfo) {
        if (i.first == characterToGetInfo) {
            return i.second;
        }
    }
}

