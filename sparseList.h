//
// Created by mykh on 25.09.23.
//

#ifndef LAB1_4_2_SPARSELIST_H
#define LAB1_4_2_SPARSELIST_H

#include <iostream>
#include <list>
#include <vector>
#include "helper.h"

template<typename T>
class sparseList {
private:
    std::list<std::pair<T, size_t>> list{};
    size_t capacity{}; //actual list size with default values
    T defaultValue{};

    //custom comparator for sort by index
    static bool comp(const std::pair<T, size_t> &a, const std::pair<T, size_t> &b) {
        return a.second < b.second;
    }

public:
    explicit sparseList(T defaultValue) {
        this->defaultValue = defaultValue;
    }

    sparseList() = default;

    size_t getCapacity() {
        return capacity;
    };

    void sortListIndex() {
        list.sort(comp);
    }

    void sortListValue() {
        list.sort();
    }

    //method to check find() result
    std::pair<T, size_t> &end() {
        return *list.end();
    }

    void showList(std::ostream &out = std::cout) const {
        for (size_t i = 0; i < capacity; i++) {
            bool fromList = false;
            for (auto j = list.cbegin(); j != list.cend(); j++) {
                if (j->second == i) {
                    out << "[" << "index: " << j->second << " " << "data: " << j->first << "]\n";
                    fromList = true;
                }
            }
            if (!fromList) {
                out << "[" << "index: " << i << " " << "data: " << defaultValue << "]\n";
            }
        }
    }

    void showSparseList(std::ostream &out = std::cout) const {
        for (auto i = list.cbegin(); i != list.cend(); i++) {
            out << "[" << "index: " << i->second << " " << "data: " << i->first << "]\n";
        }
    }

    void add(T data, size_t index) {
        if (data == defaultValue) {
            throw std::invalid_argument("Error! Adding default value type to sparseList!");
        }
        for (auto i = list.cbegin(); i != list.cend(); i++) {
            if (i->second == index) {
                throw std::invalid_argument("Error! Element with this index already in list!");
            }
        }
        list.push_back(std::make_pair(data, index));
        if (index >= capacity) {
            capacity = index + 1;
        }
    }

    T &operator[](const size_t& index) {
        if (index >= capacity) {
            throw std::invalid_argument("Error! Index went out of bounds!");
        }
        for (auto &i: list) {
            if (i.second == index) {
                return i.first;
            }
        }
        //if default value
        return defaultValue;
    }

    const std::pair<T, size_t> &find(const T& value) const{
        if (value == defaultValue) {
            throw std::invalid_argument("Error! Searching default value in sparseList.");
        }
        for (const auto &i: list) {
            if (i.first == value) {
                return i;
            }
        }
        // not found
        return *(list.cend());
    }

    template<typename Compare>
    const std::pair<T, size_t> &find_if(Compare comp, const T &value) const{
        if(value == defaultValue) {
            throw std :: invalid_argument("Error! Trying to find defaultValue!");
        }
        for (const auto &i: list) {
            if (comp(i.first, value)) {
                return i;
            }
        }
        // not found
        return *(list.end());
    }

    friend std::ostream &operator<<(std::ostream &out, std::vector<T> vector);
};


#endif //LAB1_4_2_SPARSELIST_H
