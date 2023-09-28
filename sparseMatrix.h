//
// Created by mykh on 26.09.23.
//

#ifndef LAB1_4_2_SPARSEMATRIX_H
#define LAB1_4_2_SPARSEMATRIX_H

#include <tuple>
#include <vector>
#include <algorithm>

template<typename A>
class sparseMatrix {
    std::size_t capacity{};
    std::vector<std::tuple<std::size_t, std::size_t, A>> vectorIndexValue{};
    A defaultValue{};
    std::size_t rowQuantity{};
    std::size_t columnQuantity{};

    static bool
    indexSort(const std::tuple<std::size_t, std::size_t, A> &a, const std::tuple<std::size_t, std::size_t, A> &b) {
        return (std::get<0>(a) < std::get<0>(b) && std::get<1>(a) < std::get<1>(b));
    }

public:
    explicit sparseMatrix(A defaultValue) {
        this->defaultValue = defaultValue;
    }

    std::size_t getRowQuantity() {
        return rowQuantity;
    }

    std::size_t getColumnQuantity() {
        return columnQuantity;
    }

    sparseMatrix() = default;

    A getDefault() {
        return defaultValue;
    }

    const std::tuple<size_t, size_t, A> &endSparseMatrix() {
        return *(vectorIndexValue.cend());
    }

    void add(size_t row, size_t column, A data) {
        if (data == defaultValue) {
            throw std::invalid_argument("Error! Adding default value type to sparseList!");
        }
        for (auto iter: vectorIndexValue) {
            if (std::get<0>(iter) == row && std::get<1>(iter) == column) {
                throw std::invalid_argument("Error! Element with this index already found!");
            }
        }
        vectorIndexValue.push_back(std::make_tuple(row, column, data));
        if ((row + 1) * (column + 1) >= capacity) {
            capacity = (row + 1) * (column + 1);
            if (row + 1 > rowQuantity && columnQuantity < column + 1) {
                rowQuantity = row + 1;
                columnQuantity = column + 1;
            } else if (columnQuantity < column + 1) {
                columnQuantity = column + 1;
            } else if (rowQuantity < row + 1) {
                rowQuantity = row + 1;
            }
        }
    }

    void showMatrix(std::ostream &out = std::cout) {
        for (std::size_t i = 0; i < rowQuantity; i++) {
            for (std::size_t j = 0; j < columnQuantity; j++) {
                bool isIndexed = false;
                for (auto iter: vectorIndexValue) {
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

    void showSparseMatrix(std::ostream &out = std::cout) {
        for (auto iter: vectorIndexValue) {
            out << "index:" << "(" << std::get<0>(iter) << "," << std::get<1>(iter) << ")" << " data: "
                << std::get<2>(iter) << "\n";
        }
    }

    void sortIndex() {
        std::sort(vectorIndexValue.begin(), vectorIndexValue.end(), indexSort);
    }

    A &at(size_t row, size_t column) {
        if ((row + 1) * (column + 1) >= capacity) {
            throw std::invalid_argument("Error! Index went out of bounds!");
        }
        for (auto iter: vectorIndexValue) {
            if (std::get<0>(iter) == row && std::get<1>(iter) == column) {
                return std::get<2>(iter);
            }
        }
        return defaultValue;
    }

    const std::tuple<std::size_t, std::size_t, A> &find(A &value) {
        if (value == defaultValue) {
            throw std::invalid_argument("Error! Unable to find default value!");
        }
        for (const auto &iter: vectorIndexValue) {
            if (std::get<2>(iter) == value) {
                return iter;
            }
        }
        return endSparseMatrix();
    }

    template<typename Comparator>
    const std::tuple<std::size_t, std::size_t, A> &find_if(A &value, Comparator) {
        if (value == defaultValue) {
            throw std::invalid_argument("Error! Unable to find default value!");
        }
        for (auto &iter: vectorIndexValue) {
            if (comparator(iter, value)) {
                return iter;
            }
        }
        return endSparseMatrix();
    }

    void transpose() {
        if (columnQuantity != rowQuantity) {
            std::swap(rowQuantity, columnQuantity);
        }
        for (auto &iter: vectorIndexValue) {
            std::swap(std::get<0>(iter), std::get<1>(iter));
        }
    }
};

#endif //LAB1_4_2_SPARSEMATRIX_H
