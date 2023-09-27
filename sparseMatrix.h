//
// Created by mykh on 26.09.23.
//

#ifndef LAB1_4_2_SPARSEMATRIX_H
#define LAB1_4_2_SPARSEMATRIX_H

#include<tuple>
#include <vector>
#include <algorithm>

template<typename A>
class sparseMatrix {
    std::size_t capacity{};
    std::vector<std::tuple<std::size_t, std::size_t, A>> matrix{};
    A defaultValue{};
    std::size_t rowQuantity{};

    static bool indexSort(const std::tuple<std::size_t, std::size_t, A> &a, const std::tuple<std::size_t, std::size_t, A> &b) {
        return (std::get<0>(a) < std::get<0>(b) && std::get<1>(a) < std::get<1>(b));
    }

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
            if (std::get<0>(iter) == row && std::get<1>(iter) == column) {
                throw std::invalid_argument("Error! Element with this index already found!");
            }
        }
        matrix.push_back(std::make_tuple(row, column, data));
        if ((row + 1) * (column + 1) >= capacity) {
            capacity = (row + 1) * (column + 1);
            rowQuantity = row + 1;
        }
    }

    void showMatrix(std::ostream &out = std::cout) {
        for (std::size_t i = 0; i < rowQuantity; i++) {
            for (std::size_t j = 0; j < capacity / rowQuantity; j++) {
                bool isIndexed = false;
                for (auto iter: matrix) {
                    if (std::get<0>(iter) == i && std::get<1>(iter) == j) {
                        out << std::get<2>(iter) << " ";
                        isIndexed = true;
                    }
                }
                if (!isIndexed) {
                    out << defaultValue << " ";
                }
            }
            std::cout << "\n";
        }
    }

    void showSparseMatrix(std::ostream &out = std:: cout) {
        for(auto iter : matrix) {
            out << "index:" << "(" << std::get<0>(iter) << "," << std::get<1>(iter) << ")" << " data: " << std::get<2>(iter) << "\n";
        }
    }

    void sortIndex() {
        std::sort(matrix.begin(), matrix.end(), indexSort);
    }

};

#endif //LAB1_4_2_SPARSEMATRIX_H
