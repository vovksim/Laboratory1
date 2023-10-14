//
// Created by mykh on 08.10.23.
//

#include "book.h"

book::book(std::string &&bookName, std::string &&annotation, std::size_t releaseYear, std::size_t pageQuantity,
           std::vector<fullName> &&vectorAuthor,
           std::vector<character> &&vectorCharacter) {
    this->bookName = bookName;
    this->annotation = annotation;
    this->releaseYear = releaseYear;
    this->vectorAuthor = vectorAuthor;
    this->vectorCharacter = vectorCharacter;
    this->pageQuantity = pageQuantity;
}

bool book::operator<(const book &rhs) const {
    return this->releaseYear < rhs.releaseYear;
}

std::string book::getName() const {
    return bookName;
}

std::string book::getAnnotation() const {
    return annotation;
}

std::size_t book::getReleaseYear() const {
    return releaseYear;
}

std::vector<fullName> book::getVectorAuthor() const {
    return vectorAuthor;
}

std::vector<character> book::getVectorCharacter() const {
    return vectorCharacter;
}

bool book::operator==(const book &rhs) const {
    return this->getName() == rhs.getName() && this->releaseYear == rhs.releaseYear &&
           this->getVectorAuthor() == rhs.getVectorAuthor() && this->getPageQuantity() == rhs.getPageQuantity();
}

std::size_t book::getPageQuantity() const {
    return pageQuantity;
}

std::ostream &operator<<(std::ostream &out, const book &bookToPrint) {
    out << "Name: " << bookToPrint.bookName << "\n";
    out << "\tReleased: " << bookToPrint.releaseYear << "\n";
    out << "\tAuthor: " << bookToPrint.vectorAuthor << "\n";
    out << "\tAnnotation: " << bookToPrint.annotation << "\n";
    out << "\tCharacters: " << bookToPrint.vectorCharacter << "\n";
    out << "\tPage quantity: " << bookToPrint.pageQuantity;
}


book::book() = default;