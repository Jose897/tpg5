#include "Archivo.h"
#include "Menu.h"

const string NOMBRE_ARCHIVO_AEROPUERTO = "aeropuertos.txt";
const string NOMBRE_ARCHIVO_VUELOS = "vuelos.txt";



using namespace std;
int main()
{

    Grafo* h = new Grafo;
    Archivo archivo;
    archivo.lectura_aeropuertos(NOMBRE_ARCHIVO_AEROPUERTO);
    archivo.lectura_vuelos(NOMBRE_ARCHIVO_VUELOS,h);
    Menu menu(archivo.obtener_diccionario(),h);
    menu.mostrar_menu();


    delete h;
    return 0;
}

