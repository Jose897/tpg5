#ifndef TPG5_ARCHIVO_H
#define TPG5_ARCHIVO_H
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
class Archivo{
private:
    bool excepcion;

public:
// Constructor
    // PRE: Ninguna
    // POST: construye objeto vacio
    Archivo();

void lectura_aeropuertos(const string nombre_archivo);

// Destructor
    // PRE: Ninguna
    // POST: destruye el objeto
    ~Archivo();
};

#endif //TPG5_ARCHIVO_H
