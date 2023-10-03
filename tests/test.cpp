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
    std::uniform_int_distribution<int> distValue(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    std::uniform_int_distribution<std::size_t> distIndex(std::numeric_limits<std::size_t>::min(),
                                                         std::numeric_limits<std::size_t>::max());
    auto *addCheckMatrix = new sparseMatrix<int>();
    std::vector<int> vectorRandomData;
    std::vector<std::pair<std::size_t, std::size_t>> vectorRandRowCol;
    SECTION("All adding data is not equal to defaultValue, indexes are always different.") {
        for (std::size_t i = 0; i < 10; i++) {
            vectorRandomData.push_back(distValue(mt) + addCheckMatrix->getDefaultValue() + 1); //no default values
            vectorRandRowCol.emplace_back(distIndex(mt), distIndex(mt));
            while (find(vectorRandRowCol.begin(), vectorRandRowCol.end(), vectorRandRowCol[i]) ==
                   vectorRandRowCol.end()) {
                vectorRandRowCol[i] = std::make_pair(distIndex(mt), distIndex(mt));
            }
            addCheckMatrix->add(vectorRandRowCol[i].first, vectorRandRowCol[i].second, vectorRandomData[i]);
            REQUIRE(static_cast<int>(addCheckMatrix->at(vectorRandRowCol[i].first, vectorRandRowCol[i].second)) ==
                    vectorRandomData[i]);
        }
    }SECTION("All data is equal defaultValue, indexes are different.") {
        int defaultValueData = addCheckMatrix->getDefaultValue();
        for (std::size_t i = 0; i < 10; i++) {
            vectorRandRowCol.emplace_back(distIndex(mt), distIndex(mt));
            while (find(vectorRandRowCol.begin(), vectorRandRowCol.end(), vectorRandRowCol[i]) ==
                   vectorRandRowCol.end()) {
                vectorRandRowCol[i] = std::make_pair(distIndex(mt), distIndex(mt));
            }
            REQUIRE_THROWS_AS(
                    addCheckMatrix->add(vectorRandRowCol[i].first, vectorRandRowCol[i].second, defaultValueData),
                    std::logic_error);
        }
    }SECTION("All data is not equal defaultValue, indexes are equal.") {
        std::size_t rowTemp = 0, columnTemp = 0;
        addCheckMatrix->add(rowTemp, columnTemp, 1);
        for (int i = 1; i <= 10; i++) {
            REQUIRE_THROWS_AS(addCheckMatrix->add(rowTemp, columnTemp, i + 1), std::invalid_argument);
        }
    }SECTION("Random data test.") {
        for (int i = 0; i < 1000; i++) {
            vectorRandomData.push_back(distValue(mt));
            vectorRandRowCol.emplace_back(distIndex(mt), distIndex(mt));
            if (vectorRandomData[i] == addCheckMatrix->getDefaultValue()) {
                REQUIRE_THROWS_AS(
                        addCheckMatrix->add(vectorRandRowCol[i].first, vectorRandRowCol[i].second, vectorRandomData[i]),
                        std::logic_error);
            } else if (addCheckMatrix->isAlreadyIndexed(vectorRandRowCol[i].first, vectorRandRowCol[i].second)) {
                REQUIRE_THROWS_AS(
                        addCheckMatrix->add(vectorRandRowCol[i].first, vectorRandRowCol[i].second, vectorRandomData[i]),
                        std::invalid_argument);
            } else {
                addCheckMatrix->add(vectorRandRowCol[i].first, vectorRandRowCol[i].second, vectorRandomData[i]);
                REQUIRE(static_cast<int>(addCheckMatrix->at(vectorRandRowCol[i].first, vectorRandRowCol[i].second)) ==
                        vectorRandomData[i]);
            }
        }
    }
}

