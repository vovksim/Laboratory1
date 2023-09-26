//
// Created by mykh on 26.09.23.
//

#ifndef LAB1_4_2_SPARSEMATRIX_H
#define LAB1_4_2_SPARSEMATRIX_H

#include <vector>

template<typename A>
class sparseMatrix {
    std::size_t capacity{};
    std::vector<std::tuple<std::size_t, std::size_t, A>> matrix{};
    A defaultValue{};
public:
    sparseMatrix(A defaultValue) {
        this->defaultValue = defaultValue;
    }
    sparseMatrix(A defaultValue, std::size_t capacity) {
        this->defaultValue = defaultValue;
        this->capacity = capacity;
    }
    sparseMatrix() = default;
};

#endif //LAB1_4_2_SPARSEMATRIX_H
