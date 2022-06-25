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

public:
    //constructor
    AlimentoPorPeso() = default;

    //Destructor
    ~AlimentoPorPeso() = default;

    //set
    inline void setTipo(string value) { this->tipo = std::move(value); };

    //get
    inline string getTipo() { return this->tipo; };

};

class VectorAlimentoPorPeso{
private:
    vector<AlimentoPorPeso> alimentoPorPesoVector;
public:
    // Constructor
    VectorAlimentoPorPeso() = default;
    // Destructor
    ~VectorAlimentoPorPeso() = default;
    // Metodos
    // Agregar Valores al Vector
    void addClient(const AlimentoPorPeso& alimento){
        alimentoPorPesoVector.push_back(alimento);
    }
    // Retornar al Cliente Actual, Segun la Posicion Pasada como Parametro
    AlimentoPorPeso get(int pos){
        return alimentoPorPesoVector[pos];
    }
    // Tamano del Vector
    size_t rows(){
        return alimentoPorPesoVector.size();
    }
    // Buscar al Objeto por su Codigo
    AlimentoPorPeso searchByCode(const string& cod){
        for (AlimentoPorPeso x : alimentoPorPesoVector){
            if (cod == x.getCode()){
                return x;
            }
        }
        return {};
    }
    // Buscar al Cliente por su Nombre
    AlimentoPorPeso searchByName(const string& name){
        for (AlimentoPorPeso x: alimentoPorPesoVector){
            if (name == x.getCode()){
                return x;
            }
        }
        return {};
    }
    // Busqueda de la Posicion del Objeto en el Vector
    int getPostCod(AlimentoPorPeso alimento)
    {
        for (int i = 0; i < rows(); i++)
        {
            if (alimento.getCode() == get(i).getCode())
            {
                return i;
            }
        }
        return -1;
    }
    // Eliminiar Objeto del Vector
    void remove(const AlimentoPorPeso& alimento){
        alimentoPorPesoVector.erase(alimentoPorPesoVector.begin() + getPostCod(alimento));
    }
    // Escribir en el CSV
    void write_csv(AlimentoPorPeso alimento) {
        try {
            fstream alimentoCSV;
            alimentoCSV.open("alimentoPorPeso.csv", ios::app);
            if (alimentoCSV.is_open()) {
                alimentoCSV << alimento.getCode() << ";" << alimento.getMarca() << ";" << alimento.getNombre() << ";"
                           << alimento.getPrecioCompra() << ";" << alimento.getPrecioVenta() << ";" << alimento.getTipo()
                           << ";" << endl;
                alimentoCSV.close();
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
            fstream alimentoCsv;
            alimentoCsv.open("electronico.csv", ios::in);

            if (alimentoCsv.is_open()) {
                while (!alimentoCsv.eof()) {
                    while(getline(alimentoCsv,line)) {
                        i = 0;
                        while((pos = line.find(';'))  != string::npos) {
                            temp[i] = line.substr(0,pos);
                            line.erase(0, pos + 1);
                            i++;
                        }

                        AlimentoPorPeso alimento;
                        alimento.setCode(temp[0]);
                        alimento.setMarca(temp[1]);
                        alimento.setNombre(temp[2]);
                        alimento.setPrecioCompra(std::stod(temp[3]));
                        alimento.setPrecioVenta(std::stod(temp[4]));
                        alimento.setTipo(temp[5]);

                        alimentoPorPesoVector.push_back(alimento);
                    }
                }
            }
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
};

#endif //TRABAJOFINAL2_ALIMENTOPORPESO_H
