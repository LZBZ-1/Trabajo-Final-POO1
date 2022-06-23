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

    string getTipoRopa(){ return this->tipoRopa;}

    void setTipo() {
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

class VectorRopa{
private:
    vector<Ropa> RopaVector;
public:
    // Constructor
    VectorRopa() = default;
    // Destructor
    ~VectorRopa() = default;
    // Metodos
    // Agregar Valores al Vector
    void addRopa(const Ropa& ropita){
        RopaVector.push_back(ropita);
    }
    // Retornar al Cliente Actual, Segun la Posicion Pasada como Parametro
    Ropa get(int pos){
        return RopaVector[pos];
    }
    // Tamano del Vector
    size_t rows(){
        return RopaVector.size();
    }
    // Buscar al Objeto por su Codigo
    Ropa searchByCode(const string& cod){
        for (Ropa x : RopaVector){
            if (cod == x.getCode()){
                return x;
            }
        }
        return {};
    }
    // Buscar al Cliente por su Nombre
    Ropa searchByName(const string& name){
        for (Ropa x: RopaVector){
            if (name == x.getCode()){
                return x;
            }
        }
        return {};
    }
    // Busqueda de la Posicion del Objeto en el Vector
    int getPostCod(Ropa ropita)
    {
        for (int i = 0; i < rows(); i++)
        {
            if (ropita.getCode() == get(i).getCode())
            {
                return i;
            }
        }
        return -1;
    }
    // Eliminiar Objeto del Vector
    void remove(const Ropa& ropita){
        RopaVector.erase(RopaVector.begin() + getPostCod(ropita));
    }
    // Escribir en el CSV
    void write_csv(Ropa ropita) {
        try {
            fstream ropitaCSV;
            ropitaCSV.open("Ropa.csv", ios::app);
            if (ropitaCSV.is_open()) {
                ropitaCSV << ropita.getCode() << ";" << ropita.getMarca() << ";" << ropita.getNombre() << ";"
                          << ropita.getPrecioCompra() << ";" << ropita.getPrecioVenta() << ";" << ropita.getTipoRopa()
                          << ";" << ropita.getTallaRopa()<< endl;
                ropitaCSV.close();
            }
        }
        catch (const std::exception &e) {
            cout << e.what() << " Result: Failed to write to CSV. \n";
        }
    }
    // Entrada de Datos del CSV al Vector
    void read_csv(){
        try {
            int i;
            size_t pos;
            string line;
            string temp[6];
            fstream ropitaCsv;
            ropitaCsv.open("Ropa.csv", ios::in);

            if (ropitaCsv.is_open()) {
                while (!ropitaCsv.eof()) {
                    while(getline(ropitaCsv,line)) {
                        i = 0;
                        while((pos = line.find(';'))  != string::npos) {
                            temp[i] = line.substr(0,pos);
                            line.erase(0, pos + 1);
                            i++;
                        }

                        Ropa ropita;
                        ropita.setCode(temp[0]);
                        ropita.setMarca(temp[1]);
                        ropita.setNombre(temp[2]);
                        ropita.setPrecioCompra(std::stof(temp[3]));
                        ropita.setPrecioVenta(std::stof(temp[4]));
                        ropita.setTipoRopa(temp[5]);

                        RopaVector.push_back(ropita);
                    }
                }
            }
        }
        catch(const std::exception& e) {
            cout<<"\nError al leer archivo ropa";
        }
    }
};

#endif //TRABAJOFINAL2_ROPA_H
