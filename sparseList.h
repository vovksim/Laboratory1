//
// Created by mykh on 25.09.23.
//

#ifndef LAB1_4_2_SPARSELIST_H
#define LAB1_4_2_SPARSELIST_H

#include <iostream>
#include <list>
#include <algorithm>

template<typename T>
class sparseList {
private:
    std::list<std::pair<T, size_t>> list{};
    size_t capacity{}; //actual list size with default values
    T defaultValue{};
public:
    explicit sparseList(T defaultValue) {
        this->defaultValue = defaultValue;
    }

    sparseList() = default;

    size_t getCapacity() {
        return capacity;
    };

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

    void sortListIndex() {
        list.sort(comp);
    }

    void showList(std::ostream &out = std::cout) const {
        for (size_t i = 0; i < capacity; i++) {
            bool fromList = false;
            for (auto j = list.cbegin(); j != list.cend(); j++) {
                if (j->second == i) {
                    out << "[" << "data: " << j->first << " " << "index: " << j->second << "]\n";
                    fromList = true;
                }
            }
            if (!fromList) {
                out << "[" << "data: " << defaultValue << " " << "index: " << i << "]\n";
            }
        }
    }

    void showSparseList(std::ostream &out = std::cout) {
        for (auto i = list.cbegin(); i != list.cend(); i++) {
            out << "[" << "data: " << i->first << " " << "index: " << i->second << "]\n";
        }
    }

    static bool comp(const std::pair<T, size_t> &a, const std::pair<T, size_t> &b) {
        return a.second < b.second;
    }
};


#endif //LAB1_4_2_SPARSELIST_H
