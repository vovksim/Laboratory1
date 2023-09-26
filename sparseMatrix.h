//
// Created by mykh on 26.09.23.
//

#ifndef LAB1_4_2_SPARSEMATRIX_H
#define LAB1_4_2_SPARSEMATRIX_H

#include<tuple>
#include <vector>

template<typename A>
class sparseMatrix {
    std::size_t capacity{};
    std::vector<std::tuple<std::size_t, std::size_t, A>> matrix{};
    A defaultValue{};
    std::size_t rowQuantity{};
public:
    sparseMatrix(A defaultValue) {
        this->defaultValue = defaultValue;
    }

    sparseMatrix() = default;

    void add(size_t row, size_t column, A data) {
        if (data == defaultValue) {
            throw std::invalid_argument("Error! Adding default value type to sparseList!");
        }
        for (auto iter: matrix) {
            if (iter->get<0>(matrix) == row && iter->get<1>(matrix) == column) {
                throw std::invalid_argument("Error! Element with this index already found!");
            }
        }
        matrix.push_back(std::make_tuple(row, column, data));
        if ((row + 1) * (column + 1) >= capacity) {
            capacity = (row + 1) * (column + 1);
            rowQuantity= row + 1;
        }
    }


};

#endif //LAB1_4_2_SPARSEMATRIX_H
