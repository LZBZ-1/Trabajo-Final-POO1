#pragma once
#ifndef PERSON_H
#define PERSON_H

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

#endif //PERSON_H
