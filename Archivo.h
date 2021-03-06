#ifndef TPG5_ARCHIVO_H
#define TPG5_ARCHIVO_H
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "ABBNodo.h"
#include "ABB.h"
#include "Aeropuertos.h"
//#include "Vertice.h"
//#include "Arista.h"
#include "Grafo.h"

using namespace std;

class Archivo{
    private:

    BST<string>* bst;
    Grafo* h;

    public:

        // Constructor
        // PRE: Ninguna
        // POST: construye objeto vacio
        Archivo();
        // PRE: Ninguna
        // POST: Carga el diccionario con los datos de los aeropuertos y el codigo IATA como clave
        void lectura_aeropuertos(const string nombre_archivo);
        // PRE: Ninguna
        // POST: Carga el grafo con los datos de los vuelos
        void lectura_vuelos(const string);
        // PRE: Ninguna
        // POST: Devuelve el diccionario
        BST<string>* obtener_diccionario();
        // PRE: Ninguna
        // POST: Devuelve el grafo
        Grafo* obtener_grafo();
        // Destructor
        // PRE: Ninguna
        // POST: destruye el objeto
        ~Archivo();


};

#endif //TPG5_ARCHIVO_H
