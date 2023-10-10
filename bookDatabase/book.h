//
// Created by mykh on 06.10.23.
//
#ifndef LAB1_4_2_BOOKLIBRARY_H
#define LAB1_4_2_BOOKLIBRARY_H

#include <vector>
#include <map>
#include "character.h"
#include <set>

class Book {
    std::string bookName{};
    std::string annotation{};
    std::size_t releaseYear{};
    std::vector<fullName> vectorAuthor{};
    std::vector<lib::character> vectorCharacter{};
public:
    Book(std::string &&bookName, std::string &&annotation, std::size_t releaseYear,
         std::vector<fullName> &&vectorAuthor,
         std::vector<lib::character> &&vectorCharacter);

    bool operator<(const Book &rhs) const;

    friend class Library;

    Book();
};


#endif //LAB1_4_2_BOOKLIBRARY_H
