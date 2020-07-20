#include "ABB.h"
#include "Aeropuertos.h"
#include "Menu.h"
#include<iostream>
#include<string>
#include "Archivo.h"
const string NOMBRE_ARCHIVO_AEROPUERTO = "aeropuertos.txt";

using namespace std;
int main(){
    //==============EJEMPLO PARA VER COMO FUNCIONA LA CLASE AEROPUERTO=================
/*    Menu menu;
    menu.mostrar_menu();
    Archivo archivo;
    archivo.lectura_aeropuertos(NOMBRE_ARCHIVO_AEROPUERTO);*/
    string nom = "Ministro_Pistarini";
    string ciudad = "Ezeiza";
    string pais = "Argentina";
    float superficie = 34.75;
    int terminales = 4;
    int nacionales = 12;
    int internacionales = 46;
    Aeropuertos aero(nom, ciudad, pais, superficie, terminales, nacionales, internacionales);
    aero.mostrar();
    /*==============EJEMPLO PARA VER COMO FUNCIONA EL DICCIONARIO EN EL ABB=================
    COMENTARIOS: Hay que revisar como eliminar elementos, con el remove solo me setea la clave en 0.
    Tambien ver como setear nuevas claves e interactuar para en una clave poner mas valores o eliminar algunos.
    string entrada;
    BST<int>* bst = new BST<int>();
    int datos[] = { 23, 12, 31, 3, 7, 15, 29, 88, 53};
    for(int i=0;i<9;i++){
        cout << "Para la clave '" << datos[i] << "' elegir el valor: ";
        cin >> entrada;
        bst->insert(datos[i], entrada);
    }
    bst->print_in_order();
    //bst -> remove(7); Esta linea no funciona correctamente por lo mencionado en los comentarios

    delete bst;*/

    return 0;

}
