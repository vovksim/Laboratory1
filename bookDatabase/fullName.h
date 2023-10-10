//
// Created by mykh on 08.10.23.
//

#ifndef LAB1_4_2_FULLNAME_H
#define LAB1_4_2_FULLNAME_H

#include <iostream>

class fullName : public std::error_code {
    std::string name{};
    std::string surname{};
public:
    explicit fullName(const std::pair<std::string, std::string> &fullName);

    fullName();

    fullName(std::string &&name, std::string &&surname);

    std::string getName() const;

    std::string getSurname() const;

    void setName(std::string &nameIn);

    void setSurname(std::string &surnameIn);

    bool operator==(fullName& rhs);

    bool operator<(const fullName& rhs) const;
};

#endif //LAB1_4_2_FULLNAME_H
