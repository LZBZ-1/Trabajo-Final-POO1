#include "cashier.h"
#include "client.h"
#include <iostream>
#include "admin.h"
#include "electronico.h"
#include "varios.h"
#include "ropa.h"
#include "ventas.h"

using namespace std;

VectorClient vectorClient;
VectorCashier vectorCashier;
VectorAdmin vectorAdmin;
VectorVarios vectorVarios;
VectorRopa vectorRopa;
VectorElectronico vectorElectronico;
VectorVenta vectorVenta;
CorrelativoVentas correlativoVentas;
bool adminEntry = false;

void agregarProducto() {
    int cod, cant;
    string nombre;
    float precio;

    do {
        system("cls");
        cout<<"Ingrese el codigo del producto: "; cin>>cod;
        cout<<"Ingrese la cantidad: "; cin>>cant;
    } while ((cod < 0 && cod >=250) && cant < 0);

    if(cod <= 100){
        Varios vario;
        vario = vectorVarios.searchByCode(to_string(cod));
        nombre = vario.getNombre();
        precio = vario.getPrecioVenta();

        Ventas venta;
        venta.setCantidad(cant);
        venta.setNombre(nombre);
        venta.setPrecio(precio);

        vectorVenta.addVentas(venta);

    } else if(cod <= 200){
        Ropa ropa;
        ropa = vectorRopa.searchByCode(to_string(cod));
        nombre = ropa.getNombre();
        precio = ropa.getPrecioVenta();

        Ventas venta;
        venta.setCantidad(cant);
        venta.setNombre(nombre);
        venta.setPrecio(precio);

        vectorVenta.addVentas(venta);
    } else{
        Electronico electro;
        electro = vectorElectronico.searchByCode(to_string(cod));
        nombre = electro.getNombre();
        precio = electro.getPrecioVenta();

        Ventas venta;
         venta.setCantidad(cant);
         venta.setNombre(nombre);
         venta.setPrecio(precio);

         vectorVenta.addVentas(venta);
     }
 }

 void quitarProducto(){
     if(adminEntry){
         int pos;
         vectorVenta.listar();
         cout<<"Ingrese [0] para cancelar. \nSeleccione la posiciom del producto a eliminar: ";
         cin>>pos;

         if(pos != 0){
             vectorVenta.remove(pos-1);
         }
     }
 }

 void terminarCompra(){
    system("cls");
    for(int i = 0; i < vectorVenta.rows(); i++){
        vectorVenta.write_csv(vectorVenta.get(i), correlativoVentas.getCorrelativo());
    }
    vectorVenta.listar();
    cout<<"El precio a pagar: "<< vectorVenta.precioTotal()<<endl;

    correlativoVentas.sumar1();
    correlativoVentas.write_csv(correlativoVentas);
    system("PAUSE");
 }

 void menuDeVentas() {
     vectorVenta.limpiarVector();
     int option;
     string dni;
     string name;

     cout << "Ingrese el DNI del Cliente: ";
     cin >> dni;

     Client cliente;
     cliente.setDNI(dni);
     Client cliente2 = vectorClient.searchByCode(dni);

     if (cliente2.getDni() != cliente.getDni()) {
         cout << "Cliente No Registrado\n";
         cout << "Ingrese su Nombre: ";
         cin.ignore(100, '\n');
         getline(cin, name);

         cliente.setName(name);}

         vectorClient.addClient(cliente);
         vectorClient.write_csv(cliente);


     do {
         do {
             system("cls");
             cout << "Ingresa una opcion: \n";
             cout << "\t1. Agregar Productos\n";
             cout << "\t2. Quitar Productos\n";
             cout << "\t3. Finalizar Venta\n";

             cin >> option;

             if (option < 1 || option > 3) {
                 cout << "Respuesta Incorrecta. Ingresela otra vez.\n";
                 system("PAUSE");
             }

         } while (option < 1 || option > 3);

         switch (option) {
             case 1:
                 agregarProducto();
                 break;

             case 2:
                 quitarProducto();
                 break;

             default:
                 terminarCompra();
                 cout << "################# Profe un 20 X2 XD <3 ####################\n";// x3
                 system("PAUSE");
                 break;
         }

         if (option == 3) {
             break;
         }
     } while (true);
 }

 void menuMostrarMasOpciones() {
     cout << "no alcanzo tiempo para poner otras opciones, porfavor vuelva cuando esten listas. Besitos";

 }

 void menuDeOpciones() {

     int option;
     do {
         system("cls");
         cout << "Ingresa una opcion: \n";
         cout << "\t1. Generar Venta\n";
         cout << "\t2. Mostrar mas opciones\n";
         cout << "\t3. SALIR\n";

         cin >> option;

         if (option < 1 || option > 3) {
             cout << "Respuesta Incorrecta. Ingresela otra vez.\n";
             system("PAUSE");
         }

     } while (option < 1 || option > 3);

     switch (option) {
         case 1:
             menuDeVentas();
             break;

         case 2:
             menuMostrarMasOpciones();
             break;

         default:
             cout
                     << "################# profe un 20 por favor no he dormido en 2 dias ####################\n";
             system("PAUSE");
             exit(0);
     }

 }

 int main() {
     string usuario;
     string pass;
     Cashier cajero;
     Admin admin;

     int contador = 0;
     bool correcto = false;

     vectorClient.read_csv();
     vectorCashier.read_csv();
     vectorAdmin.read_csv();
     vectorVarios.read_csv();
     vectorElectronico.read_csv();
     vectorRopa.read_csv();
     correlativoVentas.read_csv();


     do {
         system("cls");
         cout << "Ingrese Usuario: ";
         getline(cin, usuario);
         cout << "Ingrese su password: ";
         getline(cin, pass);

         cajero.setCashierCode(usuario);
         cajero.setPassword(pass);

         admin.setAdminCode(usuario);
         admin.setPassword(pass);

         Admin admin2 = vectorAdmin.searchByCode(usuario);
         Cashier cajero2 = vectorCashier.searchByCode(usuario);

         if (usuario.empty() && pass.empty()) {
             cout << "El usuario o el password son incorrectos" << endl;
             system("PAUSE");
             contador++;
         } else if (admin.getAdminCode() == admin2.getAdminCode() && admin.getPassword() == admin2.getPassword()) {
             correcto = true;
             adminEntry = true;
         } else if (cajero2.getCashierCode() == cajero.getCashierCode() &&
                    cajero2.getPassword() == cajero.getPassword()) {
             correcto = true;
         } else {
             cout << "El usuario o el password son incorrectos" << endl;
             system("PAUSE");
             contador++;
         }
     } while (contador <= 3 && !correcto);

     if (correcto) {
         cout << "BIENVENIDO" << endl;
     } else {
         system("cls");
         cout << "NO SE PUDO INGRESAR" << endl;
         system("pause");
         exit(0);
     }

     do {
         menuDeOpciones();
     } while (true);

 }
 //funcion sha10