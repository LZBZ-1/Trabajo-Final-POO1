//
// Created by jalb2 on 03/06/2022.
//
#pragma once
#ifndef TRABAJOFINAL2_ALIMENTOPORPESO_H
#define TRABAJOFINAL2_ALIMENTOPORPESO_H

#include <iostream>
#include <vector>
#include "product.h"

using namespace std;

class AlimentoPorPeso : public Product {
private:
    string tipo;
    double kg;

public:
    //constructor
    AlimentoPorPeso() = default;

    //Destructor
    ~AlimentoPorPeso() = default;

    //set
    inline void setTipo(string value) { this->tipo = std::move(value); };

    inline void setKg(double value) { this->kg = value; };

    //get
    inline string getTipo() { return this->tipo; };

    inline double getKG() { return this->kg; };
};

class vectorAlimentoPorPeso {

};

#endif //TRABAJOFINAL2_ALIMENTOPORPESO_H
