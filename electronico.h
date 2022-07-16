#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include <iostream>
#include <utility>
#include <vector>
#include "product.h"
#include "valores.h"

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
    inline void setTipo(string value){ this -> tipoElec = std::move(value);}

    void setTipoElectronico() {
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
        this->tipoElec = std::move(value);
    }

    //get
    inline string getTipoElectronico() { return this->tipoElec; };
};

class VectorElectronico {
private:
    vector<Electronico> electroVector;
public:
    // Constructor
    VectorElectronico() = default;
    // Destructor
    ~VectorElectronico() = default;
    // Metodos
    // Agregar Valores al Vector
    void addClient(const Electronico& electro){
        electroVector.push_back(electro);
    }
    // Retornar al Cliente Actual, Segun la Posicion Pasada como Parametro
    Electronico get(int pos){
        return electroVector[pos];
    }
    // Tamano del Vector
    size_t rows(){
        return electroVector.size();
    }
    // Buscar al Objeto por su Codigo
    Electronico searchByCode(const string& cod){
        for (Electronico x : electroVector){
            if (cod == x.getCode()){
                return x;
            }
        }
        return {};
    }
    // Buscar al Cliente por su Nombre
    Electronico searchByNameElectro(const string& nameElectro){
        for (Electronico x: electroVector){
            if (nameElectro == x.getCode()){
                return x;
            }
        }
        return {};
    }
    // Busqueda de la Posicion del Objeto en el Vector
    int getPostCod(Electronico electro)
    {
        for (int i = 0; i < rows(); i++)
        {
            if (electro.getCode() == get(i).getCode())
            {
                return i;
            }
        }
        return -1;
    }
    // Eliminiar Objeto del Vector
    void remove(const Electronico& electro){
        electroVector.erase(electroVector.begin() + getPostCod(electro));
    }
    // Escribir en el CSV
    void write_csv(Electronico electro) {
        try {
            fstream electroCSV;
            electroCSV.open("electronico.csv", ios::app);
            if (electroCSV.is_open()) {
                electroCSV << electro.getCode() << ";" << electro.getMarca() << ";" << electro.getNombre() << ";"
                           << electro.getPrecioCompra() << ";" << electro.getPrecioVenta() << ";" << electro.getTipoElectronico()
                           << ";" << endl;
                electroCSV.close();
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
            fstream clientCsv;
            clientCsv.open("electronico.csv", ios::in);

            if (clientCsv.is_open()) {
                while (!clientCsv.eof()) {
                    while(getline(clientCsv,line)) {
                        i = 0;
                        while((pos = line.find(';'))  != string::npos) {
                            temp[i] = line.substr(0,pos);
                            line.erase(0, pos + 1);
                            i++;
                        }

                        Electronico electro;
                        electro.setCode(temp[0]);
                        electro.setMarca(temp[1]);
                        electro.setNombre(temp[2]);
                        electro.setPrecioCompra(stringToFloat(temp[3]));
                        electro.setPrecioVenta(stringToFloat(temp[4]));
                        electro.setTipo(temp[5]);

                        electroVector.push_back(electro);
                    }
                }
            }
        }
        catch(const std::exception& e) {
            cout<<"\nError al leer archivo elec";
        }
    }

};

#endif //ELECTRONICO_H
