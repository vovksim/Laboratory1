//
// Created by mykh on 26.09.23.
//

#ifndef LAB1_4_2_HELPER_H
#define LAB1_4_2_HELPER_H
#include <iostream>

template<typename T>
std::ostream &operator<<(std::ostream &out, std::vector<T> vector) {
    out << "[";
    for (auto i = 0; i < vector.size(); i++) {
        out << vector[i];
        if (i < vector.size() - 1) {
            out << ",";
        }
    }
    out << "]";
    return out;
}
#endif //LAB1_4_2_HELPER_H
