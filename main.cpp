#include "Archivo.h"
#include "Menu.h"

const string NOMBRE_ARCHIVO_AEROPUERTO = "aeropuertos.txt";
const string NOMBRE_ARCHIVO_VUELOS = "vuelos.txt";


using namespace std;
int main()
{
    Archivo archivo;
    archivo.lectura_aeropuertos(NOMBRE_ARCHIVO_AEROPUERTO);
    archivo.lectura_vuelos(NOMBRE_ARCHIVO_VUELOS);
    Menu menu(archivo.obtener_diccionario(), archivo.obtener_grafo());
    menu.mostrar_menu();

    return 0;
}

