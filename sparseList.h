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
        list.sort();
    }

    void showList(std::ostream &out = std::cout) const {
        auto iter = list.cbegin();
        for (size_t i = 0; i < capacity || iter != list.cend(); i++) {
            if (iter->second == i) {
                out << "[" << "data: " << iter->first << " " << "index: " << iter->second << "]\n";
                if (iter != list.cend()) {
                    iter++;
                }
            } else {
                out << "[" << "data: " << defaultValue << " " << "index: " << i << "]\n";
            }
        }
    }

};


#endif //LAB1_4_2_SPARSELIST_H
