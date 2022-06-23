#ifndef TRABAJOFINAL2_CLIENT_H
#define TRABAJOFINAL2_CLIENT_H

#include "person.h"
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

class Client : public Person {
public:
    // Constructor
    Client() = default;
    // Destructor
    ~Client() = default;
};

class VectorClient {
private:
    vector<Client> clientVector;
public:
    // Constructor
    VectorClient() = default;
    // Destructor
    ~VectorClient() = default;
    // Metodos
    // Agregar Valores al Vector
    void addClient(const Client& client){
        clientVector.push_back(client);
    }
    // Retornar al Cliente Actual, Segun la Posicion Pasada como Parametro
    Client get(int pos){
        return clientVector[pos];
    }
    // Tamano del Vector
    size_t rows(){
        return clientVector.size();
    }
    // Buscar al Cliente por su Codigo
    Client searchByCode(const string& dni){
        for (Client x : clientVector){
            if (dni == x.getDni()){
                return x;
            }
        }
        return {};
    }
    // Buscar al Cliente por su Nombre
    Client searchByName(const string& name){
        for (Client x: clientVector){
            if (name == x.getName()){
                return x;
            }
        }
        return {};
    }
    // Busqueda de la Posicion del Objeto en el Vector
    int getPostArray(Client client)
    {
        for (int i = 0; i < rows(); i++)
        {
            if (client.getDni() == get(i).getDni())
            {
                return i;
            }
        }
        return -1;
    }
    // Eliminiar Objeto del Vector
    void remove(const Client& client){
        clientVector.erase(clientVector.begin() + getPostArray(client));
    }
    // Escribir en el CSV
    void write_csv(Client client) {
        try {
            fstream clientCsv;
            clientCsv.open("client.csv", ios::app);
            if (clientCsv.is_open()) {
                clientCsv << client.getDni() << ";" << client.getName() << ";" << endl;
                clientCsv.close();
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
            string temp[2];
            fstream clientCsv;
            clientCsv.open("client.csv", ios::in);

            if (clientCsv.is_open()) {
                while (!clientCsv.eof()) {
                    while(getline(clientCsv,line)) {
                        i = 0;
                        while((pos = line.find(';'))  != string::npos) {
                            temp[i] = line.substr(0,pos);
                            line.erase(0, pos + 1);
                            i++;
                        }

                        Client client;
                        client.setDNI(temp[0]);
                        client.setName(temp[1]);

                        clientVector.push_back(client);
                    }
                }
            }
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
};

#endif //TRABAJOFINAL2_CLIENT_H
