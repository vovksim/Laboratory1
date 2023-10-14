//
// Created by mykh on 08.10.23.
//
#include "fullName.h"

fullName::fullName(const std::pair<std::string, std::string> &fullName) {
    name = fullName.first;
    surname = fullName.second;
}

fullName::fullName() = default;


fullName::fullName(std::string &&name, std::string &&surname) {
    this->name = name;
    this->surname = surname;
}

std::string fullName::getName() const {
    return name;
}

std::string fullName::getSurname() const {
    return surname;
}

void fullName::setName(std::string &nameIn) {
    this->name = nameIn;
}

void fullName::setSurname(std::string &surnameIn) {
    this->surname = surnameIn;
}

bool fullName::operator==(const fullName &rhs) const {
    return ((this->name == rhs.name) && (this->surname == rhs.surname));
}

bool fullName::operator<(const fullName &rhs) const {
    return this->name < rhs.name && this->surname < rhs.surname;
}

std::ostream &operator<<(std::ostream &out, fullName &pseudonim) {
    out << pseudonim.getName() << " " << pseudonim.getSurname();
    return out;
}
