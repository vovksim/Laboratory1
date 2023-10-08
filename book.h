//
// Created by mykh on 06.10.23.
//
#ifndef LAB1_4_2_BOOKLIBRARY_H
#define LAB1_4_2_BOOKLIBRARY_H

#include "helper.h"
#include <vector>
#include <map>

class character;

class fullName;

enum class role {
    primary,
    secondary,
    tertiary
};

class Book {
    std::string bookName;
    std::string annotation;
    std::size_t releaseYear;
    std::vector<fullName> vectorAuthor;
    std::vector<character> vectorCharacter;
};

class fullName {
    std::string name;
    std::string surname;
public:
    explicit fullName(const std::pair<std::string, std::string> &fullName) {
        name = fullName.first;
        surname = fullName.second;
    }

    fullName(std::string &name, std::string &surname) {
        this->name = name;
        this->surname = surname;
    }

    std::string getName() const {
        return name;
    }

    std::string getSurname() const {
        return surname;
    }

    void setName(std::string &nameIn) {
        this->name = nameIn;
    }
    void setSurname(std::string &surnameIn) {
        this->surname = surnameIn;
    }
};

class character {
    fullName pseudonim;
    std::map<Book, role> mapParticipationIn;
};


#endif //LAB1_4_2_BOOKLIBRARY_H
