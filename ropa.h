//
// Created by jalb2 on 03/06/2022.
//
#ifndef TRABAJOFINAL2_ROPA_H
#define TRABAJOFINAL2_ROPA_H

#include <iostream>
#include <vector>
#include "product.h"

using namespace std;


class Ropa : public Product {
private:
    string tipoRopa;
    string talla;


public:
    //constructor
    Ropa() = default;

    //Destructor
    ~Ropa() = default;

    // Set
    inline void setTipoRopa(string value) { this->tipoRopa = value; };

    inline void setTallaRopa(string value) { this->talla = value; };

    //get
    string getTipoRopa() {
        string value;
        int option;

        do {
            cout<<"Selecciona un tipo: \n";
            cout<<"1. Prendas Superior \n";
            cout<<"2. Prendas Inferiores\n";
            cout<<"3. Ropa Interior\n";
            cout<<"4. Calzado\n";
            cout<<"5. Accesorios\n";
            cin>>option;
        } while (option<1 || option>5);

        switch (option) {
            case 1:
                value = "Prenda Superior";
                break;
            case 2:
                value = "Prenda Inferior";
                break;
            case 3:
                value = "Ropa Interior";
                break;
            case 4:
                value = "Calzado";
                break;
            default:
                value = "Accesorios";
                break;
        }

        this->tipoRopa = std::move(value);
    };

    inline string getTallaRopa() { return this->talla; };
};

#endif //TRABAJOFINAL2_ROPA_H
