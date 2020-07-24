#include "ABB.h"
#include "Aeropuertos.h"
#include "Menu.h"
#include<iostream>
#include<string>
#include "Archivo.h"

const string NOMBRE_ARCHIVO_AEROPUERTO = "aeropuertos.txt";

using namespace std;
int main(){
    /* Menu menu;
    menu.mostrar_menu();
    ==============EJEMPLO PARA VER COMO FUNCIONA EL DICCIONARIO EN EL ABB=================
    COMENTARIOS: Hay que revisar como eliminar elementos, con el remove solo me setea la clave en 0.
    Tambien ver como setear nuevas claves e interactuar para en una clave poner mas valores o eliminar algunos.*/
    BST<string>* bst = new BST<string>();
    Archivo archivo;
    archivo.lectura_aeropuertos(NOMBRE_ARCHIVO_AEROPUERTO, bst);
    bst->print_in_order();
    //bst -> remove(7); Esta linea no funciona correctamente por lo mencionado en los comentarios
    delete bst;
    return 0;

}

