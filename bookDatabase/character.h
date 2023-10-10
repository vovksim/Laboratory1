//
// Created by mykh on 08.10.23.
//

#ifndef LAB1_4_2_CHARACTER_H
#define LAB1_4_2_CHARACTER_H

#include "role.h"
#include "fullName.h"

namespace lib {
    class character {
        std::pair<fullName, role> pairNameParticipation;
    public:
        character();

        character(fullName &&pseudonim, role &&participation);

        bool operator==(character &rhs);

        bool operator<(const lib::character &rhs) const{
            return this->getName() < rhs.getName();
        }

        fullName getName () const;
    };
}


#endif //LAB1_4_2_CHARACTER_H
