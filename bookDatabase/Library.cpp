//
// Created by mykh on 09.10.23.
//
#include "Library.h"

void Library::addBook(const Book &bookToAdd) {
    vectorBook.push_back(bookToAdd);
    for (auto &iter: bookToAdd.vectorCharacter) {
        mapCharacterInfo[iter].insert(bookToAdd);
    }
}

void Library::getCharacterInfo(lib::character &character) {
    for(auto& iter : mapCharacterInfo[character])
    std::cout << iter.bookName << std::endl;
}
