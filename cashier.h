//
// Created by jalb2 on 02/06/2022.
//

#ifndef TRABAJOFINAL2_CASHIER_H
#define TRABAJOFINAL2_CASHIER_H

#include "person.h"
#include <utility>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

class Cashier : public Person {
private:
    string cashierCode;
    string password;
public:
    // Constructor
    Cashier() = default;

    // Destructor
    ~Cashier() = default;

    // Set
    inline void setCashierCode(string value) { this->cashierCode = std::move(value); };

    inline void setPassword(string value) { this->password = std::move(value); };

    //get
    inline string getCashierCode() { return this->cashierCode; };

    inline string getPassword() { return this->password; };
};

class VectorCashier {
private:
    vector<Cashier> cashierVector;
public:
    // Constructor
    VectorCashier() = default;

    // Destructor
    ~VectorCashier() = default;

    // Metodos
    // Agregar Valores al Vector
    void addCashier(const Cashier &cashier) {
        cashierVector.push_back(cashier);
    }

    // Retornar el Cajero Actual, Segun la Posicion Pasada como Parametro
    Cashier get(int pos) {
        return cashierVector[pos];
    }

    // Tamano del Vector
    size_t rows() {
        return cashierVector.size();
    }

    // Buscar al Cajero por su Codigo
    Cashier searchByCode(const string &cod) {
        for (Cashier x: cashierVector) {
            if (cod == x.getCashierCode()) {
                return x;
            }
        }
        return {};
    }

    // Buscar al Cajero por su Nombre
    Cashier searchByName(const string &name) {
        for (Cashier x: cashierVector) {
            if (name == x.getName()) {
                return x;
            }
        }
        return {};
    }
    // Buscar al Cajero por su Codigo
    /*Cashier searchByCode(int cod){
        for (Cashier x: cashierVector){
            if (cod == x.getCashierCode()){
                return x;
            }
        }
        return {};
    }*/
    // Busqueda de la Posicion del Objeto en el Vector
    int getPostArray(Cashier cashier) {
        for (int i = 0; i < rows(); i++) {
            if (cashier.getDni() == get(i).getDni()) {
                return i;
            }
        }
        return {};
    }

    // Eliminiar Objeto del Vector
    void remove(const Cashier &cashier) {
        cashierVector.erase(cashierVector.begin() + getPostArray(cashier));
    }

    // Escribir en el CSV
    static void write_csv(Cashier cashier) {
        try {
            fstream cashierCsv;
            cashierCsv.open("cashier.csv", ios::app);
            if (cashierCsv.is_open()) {
                cashierCsv << cashier.getDni() << ";" << cashier.getName() << ";" << cashier.getCashierCode()
                           << ";" << cashier.getPassword() << ";" << endl;
                cashierCsv.close();
            }
        }
        catch (const std::exception &e) {
            cout << e.what() << " Result: Failed to write to CSV.\n";
        }
    }

    // Entrada de Datos del CSV al Vector
    void read_csv() {
        try {
            int i;
            size_t pos;
            string line;
            string temp[4];
            fstream cashierCsv;
            cashierCsv.open("cashier.csv", ios::in);

            if (cashierCsv.is_open()) {
                while (!cashierCsv.eof()) {
                    while (getline(cashierCsv, line)) {
                        i = 0;
                        while ((pos = line.find(';')) != string::npos) {
                            temp[i] = line.substr(0, pos);
                            line.erase(0, pos + 1);
                            i++;
                        }

                        Cashier cashier;
                        cashier.setDNI(temp[0]);
                        cashier.setName(temp[1]);
                        cashier.setCashierCode(temp[2]);
                        cashier.setPassword(temp[3]);

                        cashierVector.push_back(cashier);
                    }
                }
            }
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }
};

#endif //TRABAJOFINAL2_CASHIER_H
