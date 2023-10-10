//
// Created by mykh on 08.10.23.
//

#include "book.h"

Book::Book(std::string &&bookName, std::string &&annotation, std::size_t releaseYear,
           std::vector<fullName> &&vectorAuthor,
           std::vector<lib::character> &&vectorCharacter) {
    this->bookName = bookName;
    this->annotation = annotation;
    this->releaseYear = releaseYear;
    this->vectorAuthor = vectorAuthor;
    this->vectorCharacter = vectorCharacter;
}

bool Book::operator<(const Book &rhs) const {
    return this->releaseYear < rhs.releaseYear;
}


Book::Book() = default;