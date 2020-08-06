#include "Archivo.h"
#include "Menu.h"

const string NOMBRE_ARCHIVO_AEROPUERTO = "aeropuertos.txt";
const string NOMBRE_ARCHIVO_VUELOS = "vuelos.txt";



using namespace std;
int main()
{
    BST<string>* bst = new BST<string>();
    Grafo* h = new Grafo;
    Archivo archivo;
    archivo.lectura_aeropuertos(NOMBRE_ARCHIVO_AEROPUERTO, bst);
    archivo.lectura_vuelos(NOMBRE_ARCHIVO_VUELOS,h);
    Menu menu(bst,h);
    menu.mostrar_menu();

    delete bst;
    delete h;
    return 0;
}

