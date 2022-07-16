#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include <utility>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

class Admin : public Person {
private:
    string adminCode;
    string password;
public:
    // Constructor
    Admin() = default;

    // Destructor
    ~Admin() = default;

    // Set
    inline void setAdminCode(string value) { this->adminCode = std::move(value); };

    inline void setPassword(string value) { this->password = std::move(value); };

    //get
    inline string getAdminCode() { return this->adminCode; };

    inline string getPassword() { return this->password; };
};

class VectorAdmin {
private:
    vector<Admin> adminVector;
public:
    // Constructor
    VectorAdmin() = default;

    // Destructor
    ~VectorAdmin() = default;

    // Metodos
    // Agregar Valores al Vector
    void addCashier(const Admin &admin) {
        adminVector.push_back(admin);
    }

    // Retornar el Cajero Actual, Segun la Posicion Pasada como Parametro
    Admin get(int pos) {
        return adminVector[pos];
    }

    // Tamano del Vector
    size_t rows() {
        return adminVector.size();
    }

    // Buscar al Cajero por su Codigo
    Admin searchByCode(const string &cod) {
        for (Admin x: adminVector) {
            if (cod == x.getAdminCode()) {
                return x;
            }
        }
        return {};
    }

    // Buscar al Cajero por su Nombre
    Admin searchByName(const string &name) {
        for (Admin x: adminVector) {
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
    int getPostArray(Admin admin) {
        for (int i = 0; i < rows(); i++) {
            if (admin.getDni() == get(i).getDni()) {
                return i;
            }
        }
        return {};
    }

    // Eliminiar Objeto del Vector
    void remove(const Admin &admin) {
        adminVector.erase(adminVector.begin() + getPostArray(admin));
    }

    // Escribir en el CSV
    static void write_csv(Admin admin) {
        try {
            fstream adminCsv;
            adminCsv.open("admin.csv", ios::app);
            if (adminCsv.is_open()) {
                adminCsv << admin.getDni() << ";" << admin.getName() << ";" << admin.getAdminCode()
                         << ";" << admin.getPassword() << ";" << endl;
                adminCsv.close();
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
            fstream adminCsv;
            adminCsv.open("admin.csv", ios::in);

            if (adminCsv.is_open()) {
                while (!adminCsv.eof()) {
                    while (getline(adminCsv, line)) {
                        i = 0;
                        while ((pos = line.find(';')) != string::npos) {
                            temp[i] = line.substr(0, pos);
                            line.erase(0, pos + 1);
                            i++;
                        }

                        Admin admin;
                        admin.setDNI(temp[0]);
                        admin.setName(temp[1]);
                        admin.setAdminCode(temp[2]);
                        admin.setPassword(temp[3]);

                        adminVector.push_back(admin);
                    }
                }
            }
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }
};

#endif //ADMIN_H
