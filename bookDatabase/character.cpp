//
// Created by mykh on 08.10.23.
//
#include "character.h"

lib::character::character(fullName &&pseudonim, role &&participation) {
    pairNameParticipation.first = pseudonim;
    pairNameParticipation.second = participation;
}

bool lib::character::operator==(character &rhs) {
    return this->pairNameParticipation.first == rhs.pairNameParticipation.first;
}

bool operator<(const lib::character &lhs, const lib::character &rhs) {
    return lhs.getName() < rhs.getName();
}

lib::character::character() = default;

fullName lib::character::getName() const{
    return pairNameParticipation.first;
}