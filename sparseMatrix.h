//
// Created by mykh on 26.09.23.
//

#ifndef LAB1_4_2_SPARSEMATRIX_H
#define LAB1_4_2_SPARSEMATRIX_H

#include <tuple>
#include <vector>
#include <algorithm>
#include <iostream>

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

    sparseMatrix<A> getRow(std::size_t rowNumber) {
        sparseMatrix<A> tempRowElementCollector;
        for (auto &iter: vectorIndexValue) {
            if (std::get<0>(iter) == rowNumber) {
                tempRowElementCollector.add(rowNumber, std::get<1>(iter), std::get<2>(iter));
            }
        }
        tempRowElementCollector.sortIndex();
        return tempRowElementCollector;
    }

    void multiplyRow(const sparseMatrix<A> &rowLhs, const sparseMatrix<A> &rowRhs, sparseMatrix<A> &result) {
        A data{};
        if (rowLhs.capacity <= 0 || rowRhs.capacity <= 0) {
            return;
        }
        //setting new pos in result
        std::size_t rowAddToResult = (rowLhs.rowQuantity) - 1;
        std::size_t colAddToResult = (rowRhs.rowQuantity) - 1;
        //going through one row of both matrices
        for (auto &i: rowLhs.vectorIndexValue) {
            for (auto &j: rowRhs.vectorIndexValue) {
                if (std::get<1>(i) == std::get<1>(j)) {
                    data += std::get<2>(i) * std::get<2>(j);
                }
            }
        }
        if (data != defaultValue) {
            result.add(rowAddToResult, colAddToResult, data);
        }
    }

public:
    explicit sparseMatrix(A defaultValue) {
        this->defaultValue = defaultValue;
    }

    explicit sparseMatrix(std::vector<std::pair<std::pair<std::size_t, std::size_t>, A>> input) {
        std::size_t columnTempQuantity = 0, rowTempQuantity = 0;
        for (auto &iter: input) {
            if (rowTempQuantity < std::get<0>(iter)) {
                rowTempQuantity = std::get<0>(iter);
            }
            if (columnTempQuantity < std::get<1>(iter)) {
                columnTempQuantity = std::get<1>(iter);
            }
            if (std::get<2>(input) != defaultValue) {
                vectorIndexValue.push_back(iter);
            } else {
                throw std::logic_error("Error! DefaultValue cannot be indexed!");
            }
        }
        columnQuantity = columnTempQuantity;
        rowQuantity = rowTempQuantity;
        capacity = rowQuantity * columnQuantity;
    }

    //let to give default values because matrix will be sparsed after input
    explicit sparseMatrix(std::vector<std::vector<A>> input) {
        std::size_t checkSize = input[0].size();
        for (auto &iter: input) {
            if (iter.size() != checkSize) {
                throw std::invalid_argument("Error! It's not matrix!");
            }
        }
        for (std::size_t i = 0; i < input.size(); i++) {
            for (std::size_t j = 0; j < input[i].size(); j++) {
                if (input[i][j] != defaultValue) {
                    vectorIndexValue.push_back(std::make_tuple(i, j, input[i][j]));
                }
            }
        }
        rowQuantity = input.size();
        columnQuantity = checkSize;
        capacity = rowQuantity * columnQuantity;
    }

    std::size_t getRowQuantity() {
        return rowQuantity;
    }

    std::size_t getColumnQuantity() {
        return columnQuantity;
    }

    void setColumnQuantity(std::size_t value) {
        columnQuantity = value;
    }

    void setRowQuantity(std::size_t value) {
        rowQuantity = value;
    }

    sparseMatrix() = default;

    A getDefaultValue() {
        return defaultValue;
    }

    const std::tuple<size_t, size_t, A> &endSparseMatrix() {
        return *(vectorIndexValue.cend());
    }

    void add(size_t row, size_t column, A data) {
        if (data == defaultValue) {
            throw std::logic_error("Error! Adding default value type to sparseList!");
        }
        if (isAlreadyIndexed(row, column)) {
            throw std::invalid_argument("Error! Element with this index already found!");
        }
        vectorIndexValue.push_back(std::make_tuple(row, column, data));
        if (columnQuantity <= column + 1) {
            columnQuantity = column + 1;
        }
        if (rowQuantity <= row + 1) {
            rowQuantity = row + 1;
        }
        if (rowQuantity * columnQuantity >= capacity) {
            capacity = rowQuantity * columnQuantity;
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
        if (row >= rowQuantity || column >= columnQuantity) {
            throw std::out_of_range("Error! Index went out of bounds!");
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
            throw std::logic_error("Error! Unable to find default value!");
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
            throw std::logic_error("Error! Unable to find default value!");
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


    sparseMatrix<A> operator+(sparseMatrix<A> &rhs) {
        if (this->columnQuantity != rhs.columnQuantity || this->rowQuantity != rhs.rowQuantity) {
            throw std::invalid_argument("Error! Can't sum matrices of different size!");
        }
        sparseMatrix<A> result;
        for (std::size_t i = 0; i < rhs.getRowQuantity(); i++) {
            for (std::size_t j = 0; j < rhs.getColumnQuantity(); j++) {
                for (auto &iter: this->vectorIndexValue) {
                    if (std::get<0>(iter) == i && std::get<1>(iter) == j) {
                        result.add(i, j, std::get<2>(iter) + rhs.at(i, j));
                        break;
                    }
                }
            }
        }
        return result;
    }

    void operator+=(sparseMatrix<A> &rhs) {
        *this = *this + rhs;
    }

    bool isEmpty() {
        return capacity == 0;
    }

    //not by reference because of sort and transpose
    sparseMatrix<A> operator*(sparseMatrix<A> rhs) {
        if (this->isEmpty() || rhs.isEmpty()) {
            throw std::length_error("Error! Matrix is empty!");
        }
        if (this->columnQuantity != rhs.rowQuantity) {
            throw std::invalid_argument("Error! Matrix1colQuantity!= Matrix2rowQuantity.");
        }
        sparseMatrix<A> result;
        rhs.transpose();
        rhs.sortIndex();
        this->sortIndex();
        for (std::size_t i = 0; i < this->rowQuantity; i++) {
            for (std::size_t j = 0; j < rhs.rowQuantity; j++) {
                multiplyRow(this->getRow(i), rhs.getRow(j), result);
            }
        }
        return result;
    }

    bool operator==(const sparseMatrix<A> &rhs) const {
        if (this->vectorIndexValue != rhs.vectorIndexValue) {
            return false;
        }
        return true;
    }

    bool isAlreadyIndexed(std::size_t row, std::size_t column) {
        for (auto &iter: vectorIndexValue) {
            if (std::get<0>(iter) == row && std::get<1>(iter) == column) {
                return true;
            }
        }
        return false;
    }


};

#endif //LAB1_4_2_SPARSEMATRIX_H
