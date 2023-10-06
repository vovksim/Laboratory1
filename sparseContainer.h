//
// Created by mykh on 06.10.23.
//
#include <iostream>

#ifndef LAB1_4_2_SPARSEDCONTAINER_H
#define LAB1_4_2_SPARSEDCONTAINER_H

template<typename A>
class sparseContainer {
    virtual A &at(std::size_t, std::size_t) = 0;

    virtual void print(std::ostream &out = std::cout) = 0;

    virtual void printSparsed(std::ostream &out = std::cout) = 0;

    virtual void add(std::size_t, std::size_t, A data) = 0;
};

#endif //LAB1_4_2_SPARSEDCONTAINER_H
