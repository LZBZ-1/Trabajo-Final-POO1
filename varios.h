#ifndef VARIOS_H
#define VARIOS_H

#include <iostream>
#include <vector>
#include "product.h"
#include "valores.h"

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

    inline void setTipoVarios(string value){ this->tipo = std::move(value); }

    //get
    inline string getTipo() { return this->tipo; };
};

class VectorVarios{
private:
    vector<Varios> variosVector;
public:
    // Constructor
    VectorVarios() = default;
    // Destructor
    ~VectorVarios() = default;
    // Metodos
    // Agregar Valores al Vector
    void addVarios(const Varios& varios){
        variosVector.push_back(varios);
    }
    // Retornar al Cliente Actual, Segun la Posicion Pasada como Parametro
    Varios get(int pos){
        return variosVector[pos];
    }
    // Tamano del Vector
    size_t rows(){
        return variosVector.size();
    }
    // Buscar al Objeto por su Codigo
    Varios searchByCode(const string& cod){
        for (Varios x : variosVector){
            if (cod == x.getCode()){
                return x;
            }
        }
        return {};
    }
    // Buscar al Cliente por su Nombre
    Varios searchByNameVario(const string& nameVario){
        for (Varios x: variosVector){
            if (nameVario == x.getNombre()){
                return x;
            }
        }
        return {};
    }
    // Busqueda de la Posicion del Objeto en el Vector
    int getPostCod(Varios vario)
    {
        for (int i = 0; i < rows(); i++)
        {
            if (vario.getCode() == get(i).getCode())
            {
                return i;
            }
        }
        return -1;
    }
    // Eliminiar Objeto del Vector
    void remove(const Varios& varios){
        variosVector.erase(variosVector.begin() + getPostCod(varios));
    }
    // Escribir en el CSV
    void write_csv(Varios varios) {
        try {
            fstream variosCSV;
            variosCSV.open("varios.csv", ios::app);
            if (variosCSV.is_open()) {
                variosCSV << varios.getCode() << ";" << varios.getMarca() << ";" << varios.getNombre() << ";"
                          << varios.getPrecioCompra() << ";" << varios.getPrecioVenta() << ";" << varios.getTipo()
                          << ";" << endl;
                variosCSV.close();
            }
        }
        catch (const std::exception &e) {
            cout << e.what() << " Result: Failed to write to CSV.\n";
        }
    }
    // Entrada de Datos del CSV al Vector
    void read_csv(){
        try {
            int i;
            size_t pos;
            string line;
            string temp[6];
            fstream variosCsv;
            variosCsv.open("varios.csv", ios::in);

            if (variosCsv.is_open()) {
                while (!variosCsv.eof()) {
                    while(getline(variosCsv,line)) {
                        i = 0;
                        while((pos = line.find(';'))  != string::npos) {
                            temp[i] = line.substr(0,pos);
                            line.erase(0, pos + 1);
                            i++;
                        }

                        Varios varios;
                        varios.setCode(temp[0]);
                        varios.setMarca(temp[1]);
                        varios.setNombre(temp[2]);
                        varios.setPrecioCompra(stringToFloat(temp[3]));
                        varios.setPrecioVenta(stringToFloat(temp[4]));
                        varios.setTipoVarios(temp[5]);

                        variosVector.push_back(varios);
                    }
                }
            }
        }
        catch(const std::exception& e) {
            cout<<"Error al leer archivo varios\n";
            system("pause");
        }
    }

};

#endif //VARIOS_H
