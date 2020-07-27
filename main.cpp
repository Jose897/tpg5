#include "ABB.h"
#include "Aeropuertos.h"
#include "Menu.h"
#include<iostream>
#include<string>
#include "Archivo.h"

const string NOMBRE_ARCHIVO_AEROPUERTO = "aeropuertos.txt";
const string NOMBRE_ARCHIVO_VUELOS = "vuelos.txt";

using namespace std;
int main(){
    /*El programa pierde memoria.*/
    BST<string>* bst = new BST<string>();
    Archivo archivo;
    archivo.lectura_aeropuertos(NOMBRE_ARCHIVO_AEROPUERTO, bst);
    archivo.lectura_vuelos(NOMBRE_ARCHIVO_VUELOS);
    Menu menu(bst);
    menu.mostrar_menu();
    delete bst;
    return 0;

}

