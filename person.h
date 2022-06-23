#pragma once
#ifndef TRABAJOFINAL2_PERSON_H
#define TRABAJOFINAL2_PERSON_H

#include <iostream>
#include <utility>

using namespace std;

class Person {
public:
    // Set
    inline void setDNI(string value) { this->dni = std::move(value); };

    inline void setName(string value) { this->name = std::move(value); };

    // Get
    inline string getDni() { return this->dni; };

    inline string getName() { return this->name; };
protected:
    string dni = "No Data";
    string name = "No Data";
};

#endif //TRABAJOFINAL2_PERSON_H