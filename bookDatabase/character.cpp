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
    return lhs.getName() < rhs.getName();
}

character::character() = default;

fullName character::getName() const{
    return pairNameParticipation.first;
}

role character::getRole() const {
    return pairNameParticipation.second;
}
