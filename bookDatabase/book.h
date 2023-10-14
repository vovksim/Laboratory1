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
    std::size_t pageQuantity;
public:
    book(std::string &&bookName, std::string &&annotation, std::size_t releaseYear, std::size_t pageQuantity,
         std::vector<fullName> &&vectorAuthor,
         std::vector<character> &&vectorCharacter);

    book();

    std::string getName() const;

    std::string getAnnotation() const;

    std::size_t getReleaseYear() const;

    std::size_t getPageQuantity() const;

    std::vector<fullName> getVectorAuthor() const;

    std::vector<character> getVectorCharacter() const;

    bool operator<(const book &rhs) const;

    bool operator==(const book& rhs) const;

};


#endif //LAB1_4_2_BOOKLIBRARY_H
