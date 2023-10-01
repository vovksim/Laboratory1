//
// Created by mykh on 01.10.23.
//
#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "../sparseMatrix.h"
#include <random>

TEST_CASE("Add() test", "[sparseMatrix]") {
    std::random_device rgen;
    std::mt19937 mt(rgen());
    std::uniform_int_distribution<int> dist(1, 1000);
    auto *addCheckMatrix = new sparseMatrix<int>();
    std::vector<int> vectorRandomData;
    std::vector<std::pair<std::size_t, std::size_t>> vectorRandRowCol;
    SECTION("All adding data is not equal to defaultValue, indexes are always different.") {
        for (std::size_t i = 0; i < 10; i++) {
            vectorRandomData.push_back(dist(mt) + addCheckMatrix->getDefaultValue() + 1); //no default values
            vectorRandRowCol.emplace_back(dist(mt), dist(mt));
            while (find(vectorRandRowCol.begin(), vectorRandRowCol.end(), vectorRandRowCol[i]) ==
                   vectorRandRowCol.end()) {
                vectorRandRowCol[i] = std::make_pair(dist(mt), dist(mt));
            }
            addCheckMatrix->add(vectorRandRowCol[i].first, vectorRandRowCol[i].second, vectorRandomData[i]);
            REQUIRE(static_cast<int>(addCheckMatrix->at(vectorRandRowCol[i].first, vectorRandRowCol[i].second)) ==
                    vectorRandomData[i]);
        }
    }
    SECTION("All data is equal defaultValue, indexes are different.") {
        int defaultValueData = addCheckMatrix->getDefaultValue();
        for (std::size_t i = 0; i < 10; i++) {
            vectorRandRowCol.emplace_back(dist(mt), dist(mt));
            while (find(vectorRandRowCol.begin(), vectorRandRowCol.end(), vectorRandRowCol[i]) ==
                   vectorRandRowCol.end()) {
                vectorRandRowCol[i] = std::make_pair(dist(mt), dist(mt));
            }
            REQUIRE_THROWS_AS(
                    addCheckMatrix->add(vectorRandRowCol[i].first, vectorRandRowCol[i].second, defaultValueData),
                    std::logic_error);
        }
    }
}

