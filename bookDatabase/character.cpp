//
// Created by mykh on 08.10.23.
//
#include "character.h"

character::character(fullName &&pseudonim, role &&participation) {
    pairNameParticipation.first = pseudonim;
    pairNameParticipation.second = participation;
}

bool character::operator==(const character &rhs) const {
    return this->pairNameParticipation.first == rhs.pairNameParticipation.first;
}

bool operator<(const character &lhs, const character &rhs) {
    return lhs.getPseudonim() < rhs.getPseudonim();
}

character::character() = default;

fullName character::getPseudonim() const {
    return pairNameParticipation.first;
}

role character::getRole() const {
    return pairNameParticipation.second;
}

std::string character::getStringFormFullName() const {
    return this->getPseudonim().getName() + " " + this->getPseudonim().getSurname();
}
