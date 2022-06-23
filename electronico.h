//
// Created by jalb2 on 03/06/2022.
//
#pragma once

#ifndef TRABAJOFINAL2_ELECTRONICO_H
#define TRABAJOFINAL2_ELECTRONICO_H

#include <iostream>
#include <vector>
#include "product.h"

using namespace std;

class Electronico : public Product {

private:
    string tipoElec;

public:
    //Constructor
    Electronico() = default;

    //Destructor
    ~Electronico() = default;

    // Set
    void setTipoElectronico(string value) {
        string value;
        int option;

        do {
            cout<<"Selecciona un tipo: \n";
            cout<<"1. Electrodomestico \n";
            cout<<"2. Televisores\n";
            cout<<"3. Laptops\n";
            cout<<"4. Celulares\n";
            cout<<"5. Tablets\n";
            cout<<"6. Computadora\n";
            cout<<"7. Accesorios\n";
            cin>>option;
        } while (option<1 || option>7);

        switch (option) {
            case 1:
                value = "Electrodomestico";
                break;
            case 2:
                value = "Televisores";
                break;
            case 3:
                value = "Laptops";
                break;
            case 4:
                value = "Celulares";
                break;
            case 5:
                value = "Tablets";
                break;
            case 6:
                value = "Computadoras";
                break;
            default:
                value = "Accesorios";
                break;
        }

        this->tipo = std::move(value);

        this->tipoElec = std::move(value);
    }

    //get
    inline string getTipoElectronico() { return this->tipoElec; };
};

class vectorElectronico {
};

#endif //TRABAJOFINAL2_ELECTRONICO_H
