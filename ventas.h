//
// Created by jalb2 on 07/06/2022.
//

#ifndef TRABAJOFINAL2_VENTAS_H
#define TRABAJOFINAL2_VENTAS_H

#include <iostream>
#include <utility>
#include <vector>
#include "varios.h"
#include "ropa.h"
#include "electronico.h"

using namespace std;

class Ventas{
protected:
    string nombre;
    int cantidad;
    float precio;
public:
    Ventas() = default;
    ~Ventas() = default;

    //set
    inline void setNombre(string value){ this->nombre = std::move(value); };
    inline void setCantidad(int value){ this->cantidad = value; };
    inline void setPrecio(float value){ this->precio = value; };
    //get
    inline string getNombre() { return this->nombre; };
    inline int getCantindad() { return this->cantidad; };
    inline float getPrecio() { return this->precio; };

};

class CorrelativoVentas{
private:
    int correlativo;
public:
    //set
    inline void setCorrelativo(int value){ this->correlativo = value; };
    //get
    inline int getCorrelativo(){ return this->correlativo;};
    void sumar1(){ this-> correlativo ++; };
    void read_csv(){
        try {
            int i;
            size_t pos;
            string line;
            string temp[1];
            fstream variosCsv;
            variosCsv.open("correlativos.csv", ios::in);

            if (variosCsv.is_open()) {
                while (!variosCsv.eof()) {
                    while(getline(variosCsv,line)) {
                        i = 0;
                        while((pos = line.find(';'))  != string::npos) {
                            temp[i] = line.substr(0,pos);
                            line.erase(0, pos + 1);
                            i++;
                        }
                        setCorrelativo(stoi(temp[0]));
                    }
                }
            }
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

    void write_csv(CorrelativoVentas correlativo) {
        try {
            fstream electroCSV;
            electroCSV.open("correlativo.csv", ios::app);
            if (electroCSV.is_open()) {
                electroCSV << correlativo.getCorrelativo() << ";" << endl;
                electroCSV.close();
            }
        }
        catch (const std::exception &e) {
            cout << e.what() << " Result: Failed to write to CSV.\n";
        }
    }
};

class VectorVenta{
private:
    vector<Ventas> vectorVentas;
    string csv;
public:
    // Constructor
    VectorVenta() = default;
    // Destructor
    ~VectorVenta() = default;
    // Metodos
    // Agregar Valores al Vector
    void addVentas(const Ventas& ventas){
        vectorVentas.push_back(ventas);
    }
    // Retornar al Cliente Actual, Segun la Posicion Pasada como Parametro
    Ventas get(int pos){
        return vectorVentas[pos];
    }
    // Tamano del Vector
    size_t rows(){
        return vectorVentas.size();
    }

    // Eliminiar Objeto del Vector
    void remove(int pos){
        vectorVentas.erase(vectorVentas.begin() + pos);
    }

    void limpiarVector(){
        vectorVentas.clear();
    }

    void listar(){
        cout<<"Producto\t\tCantidad\t\t\tPrecio\n" <<endl;
        for(Ventas x: vectorVentas){
            cout<<x.getNombre()<< "\t\t" << x.getCantindad() <<"\t\t\t\t"<<x.getCantindad()* x.getPrecio()<<endl;
        }
    }

    float precioTotal(){
        float suma = 0;
        for(Ventas x: vectorVentas){
            suma += (x.getPrecio()*float(x.getCantindad()));
        }
        return suma;
    }

    void write_csv(Ventas ventas, int correlativo){
        try {
            fstream variosCSV;
            string csv = "Boleta" + to_string(correlativo) + ".csv";
            variosCSV.open(csv, ios::app);
            if (variosCSV.is_open()) {
                variosCSV << ventas.getNombre() << ";" << ventas.getCantindad() << "; "<< ventas.getPrecio()<<endl;
                variosCSV.close();
            }
        }
        catch (const std::exception &e) {
            cout << e.what() << " Result: Failed to write to CSV.\n";
        }
    }

    void read_csv(int correlativo){
        try {
            int i;
            size_t pos;
            string line;
            string temp[3];
            fstream variosCsv;
            string csv = "Boleta" + to_string(correlativo) + ".csv";
            variosCsv.open(csv, ios::in);

            if (variosCsv.is_open()) {
                while (!variosCsv.eof()) {
                    while(getline(variosCsv,line)) {
                        i = 0;
                        while((pos = line.find(';'))  != string::npos) {
                            temp[i] = line.substr(0,pos);
                            line.erase(0, pos + 1);
                            i++;
                        }
                        Ventas vent;
                        vent.setNombre(temp[0]);
                        vent.setCantidad(std::stoi(temp[1]));
                        vent.setPrecio(std::stof(temp[2]));

                        vectorVentas.push_back(vent);

                    }
                }
            }
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

};

#endif //TRABAJOFINAL2_VENTAS_H
