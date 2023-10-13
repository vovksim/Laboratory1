//
// Created by mykh on 06.10.23.
//
#ifndef LAB1_4_2_BOOKLIBRARY_H
#define LAB1_4_2_BOOKLIBRARY_H

#include <vector>
#include <map>
#include "character.h"
#include <set>

class book {
    std::string bookName{};
    std::string annotation{};
    std::size_t releaseYear{};
    std::vector<fullName> vectorAuthor{};
    std::vector<character> vectorCharacter{};
public:
    book(std::string &&bookName, std::string &&annotation, std::size_t releaseYear,
         std::vector<fullName> &&vectorAuthor,
         std::vector<character> &&vectorCharacter);

    bool operator<(const book &rhs) const;

    std::string getName() const;

    std::string getAnnotation() const;

    std::size_t getReleaseYear() const;

    std::vector<fullName> getVectorAuthor() const;

    std::vector<character> getVectorCharacter() const;

    book();
};


#endif //LAB1_4_2_BOOKLIBRARY_H
