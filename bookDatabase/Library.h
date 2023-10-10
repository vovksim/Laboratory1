//
// Created by mykh on 08.10.23.
//

#ifndef LAB1_4_2_LIBRARY_H
#define LAB1_4_2_LIBRARY_H

#include "book.h"



class Library {
    std::vector<std::pair<std::vector<Book>,std::string>> mapBooksSeries;
    std::map<lib::character, std::set<Book>> mapCharacterInfo;
    friend class Book;
public:
    void addBook(const Book& bookToAdd);
    void getCharacterInfo(lib::character& character);
};

#endif //LAB1_4_2_LIBRARY_H
