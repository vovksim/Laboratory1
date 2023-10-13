//
// Created by mykh on 08.10.23.
//

#ifndef LAB1_4_2_CHARACTER_H
#define LAB1_4_2_CHARACTER_H

#include "role.h"
#include "fullName.h"

class character {
    std::pair<fullName, role> pairNameParticipation;
public:
    character();

    character(fullName &&pseudonim, role &&participation);

    bool operator==(const character &rhs) const;

    bool operator<(const character &rhs) const {
        return this->getPseudonim() < rhs.getPseudonim();
    }

    std::string getStringFormFullName() const;

    fullName getPseudonim() const;

    role getRole() const;
};


#endif //LAB1_4_2_CHARACTER_H
