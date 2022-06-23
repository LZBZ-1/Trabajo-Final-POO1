//
// Created by jalb2 on 03/06/2022.
//
#pragma once
#ifndef TRABAJOFINAL2_PRODUCT_H
#define TRABAJOFINAL2_PRODUCT_H

#include "client.h"
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

class Product {
protected:

    string marca;
    string nombre;
    int cantidad;
    double precioVenta;
    double precioCompra;

public:
    // Set
    inline void setMarca(string value) { this->marca = std::move(value); };

    inline void setNombre(string value) { this->nombre = std::move(value); };

    inline void setCantidad(int value) { this->cantidad = value; };

    inline void setPrecioVenta(int value) { this->precioVenta = value; };

    inline void setPrecioCompra(int value) { this->precioCompra = value; };

    // Get
    inline string getMarca() { return this->marca; };

    inline string getNombre() { return this->nombre; };

    inline int getCantidad() { return this->cantidad; };

    inline double getPrecioVenta() { return this->precioVenta; };

    inline double getPrecioCompra() { return this->precioCompra; };

};

#endif //TRABAJOFINAL2_PRODUCT_H