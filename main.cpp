#include "Archivo.h"
#include "Menu.h"

const string NOMBRE_ARCHIVO_AEROPUERTO = "aeropuertos.txt";
const string NOMBRE_ARCHIVO_VUELOS = "vuelos.txt";



using namespace std;
int main()
{
    /*
    ==============EJEMPLO PARA VER COMO FUNCIONA EL DICCIONARIO EN EL ABB=================
    COMENTARIOS: Hay que revisar como eliminar elementos, con el remove solo me setea la clave en 0.
    Tambien ver como setear nuevas claves e interactuar para en una clave poner mas valores o eliminar algunos.
    El programa pierde memoria.*/
    /*El programa pierde memoria.*/
    BST<string>* bst = new BST<string>();
    Grafo*h = new Grafo;
    Archivo archivo;
    archivo.lectura_aeropuertos(NOMBRE_ARCHIVO_AEROPUERTO, bst);
    archivo.lectura_vuelos(NOMBRE_ARCHIVO_VUELOS,h);
    Menu menu(bst,h);
    menu.mostrar_menu();
    //bst -> remove(7); Esta linea no funciona correctamente por lo mencionado en los comentarios
    delete bst;
    return 0;
}

