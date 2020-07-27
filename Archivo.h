#ifndef TPG5_ARCHIVO_H
#define TPG5_ARCHIVO_H
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "ABBNodo.h"
#include "ABB.h"
#include "Aeropuertos.h"
using namespace std;
class Archivo{
private:

public:
// Constructor
    // PRE: Ninguna
    // POST: construye objeto vacio
    Archivo();

void lectura_aeropuertos(const string nombre_archivo, BST<string>* &diccionario);
void lectura_vuelos(const string);
// Destructor
    // PRE: Ninguna
    // POST: destruye el objeto
    ~Archivo();
};

#endif //TPG5_ARCHIVO_H
