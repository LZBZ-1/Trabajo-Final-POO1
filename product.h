//
// Created by jalb2 on 03/06/2022.
//
#pragma once
#ifndef TRABAJOFINAL2_PRODUCT_H
#define TRABAJOFINAL2_PRODUCT_H

#include "client.h"
#include <utility>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

class Product {
protected:
    string code;
    string marca;
    string nombre;
    float precioVenta;
    float precioCompra;

public:
    // Set
    inline void setCode(string value) { this->code = std::move(value);}

    inline void setMarca(string value) { this->marca = std::move(value); };

    inline void setNombre(string value) { this->nombre = std::move(value); };

    inline void setPrecioVenta(float value) { this->precioVenta = value; };

    inline void setPrecioCompra(float value) { this->precioCompra = value; };

    // Get
    inline string getCode() { return this->code; };

    inline string getMarca() { return this->marca; };

    inline string getNombre() { return this->nombre; };

    inline float getPrecioVenta() { return this->precioVenta; };

    inline float getPrecioCompra() { return this->precioCompra; };

};

#endif //TRABAJOFINAL2_PRODUCT_H