//
// Created by mykh on 08.10.23.
//

#ifndef LAB1_4_2_LIBRARY_H
#define LAB1_4_2_LIBRARY_H

#include "book.h"


class Library {
    std::vector<std::pair<std::set<book>, std::string>> vectorBooksSeries;
    std::map<character, std::set<book>> mapCharacterInfo;

    static std::pair<bool, std::string> isBookSerial(const book &lhs, const book &rhs);

public:
    void addBook(const book &bookToAdd);

    void printCharacterInfo(character &character);

    void insertBookToAppropriatePosition(const book &bookToAddInLibrary);

    void print(std::ostream &out = std::cout);

    void printUnseried(std::ostream &out = std::cout) const;

    void printSeried(std::ostream &out = std::cout) const;

    void addSeries(std::set<book>& setOfBook, std::string& seriesName);

    void removeBook(book &bookToDelete);
};

#endif //LAB1_4_2_LIBRARY_H
