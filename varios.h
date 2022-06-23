//
// Created by jalb2 on 03/06/2022.
//
#ifndef TRABAJOFINAL2_VARIOS_H
#define TRABAJOFINAL2_VARIOS_H

#include <iostream>
#include <vector>
#include "product.h"

using namespace std;

class Varios : public Product {
private:

    string tipo;
public:

    //Constructor
    Varios() = default;

    // Destructor
    ~Varios() = default;

    //set
    void setTipo() {
        string value;
        int option;

        do {
            cout<<"Selecciona un tipo: \n";
            cout<<"1. Abarrotes \n";
            cout<<"2. Congelados\n";
            cout<<"3. Bebidas\n";
            cout<<"4. Bebidas Alcoholicas\n";
            cout<<"5. Animales\n";
            cout<<"6. Limpieza\n";
            cout<<"7. Farmacia\n";
            cin>>option;
        } while (option<1 || option>7);

        switch (option) {
            case 1:
                value = "Abarrotes";
                break;
            case 2:
                value = "Congelados";
                break;
            case 3:
                value = "Bebidas";
                break;
            case 4:
                value = "Bebidas Alcoholicas";
                break;
            case 5:
                value = "Animales";
                break;
            case 6:
                value = "Limpieza";
                break;
            default:
                value = "Farmacia";
                break;
        }

        this->tipo = std::move(value);
    }

    //get
    inline string getTipo() { return this->tipo; };
};

#endif //TRABAJOFINAL2_VARIOS_H