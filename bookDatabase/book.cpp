//
// Created by mykh on 08.10.23.
//

#include "book.h"

book::book(std::string &&bookName, std::string &&annotation, std::size_t releaseYear,
           std::vector<fullName> &&vectorAuthor,
           std::vector<character> &&vectorCharacter) {
    this->bookName = bookName;
    this->annotation = annotation;
    this->releaseYear = releaseYear;
    this->vectorAuthor = vectorAuthor;
    this->vectorCharacter = vectorCharacter;
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


book::book() = default;