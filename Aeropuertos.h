#ifndef AEROPUERTOS_H_INCLUDED
#define AEROPUERTOS_H_INCLUDED

#include<string>
#include<iostream>

using namespace std;

class Aeropuertos{
    private:
        string nombre;
        string ciudad;
        string pais;
        float superficie;
        int terminales;
        int destinos_nacionales;
        int destinos_internacionales;
    public:
        // Constructor
        // PRE: -
        // POST: Crea el objeto Aeropuerto
        Aeropuertos(string, string, string, float, int, int, int);
        // PRE: -
        // POST: Devuelve el nombre
        string obtener_nombre();
        // PRE: -
        // POST: Devuelve la ciudad
        string obtener_ciudad();
        // PRE: -
        // POST: Devuelve el pais
        string obtener_pais();
        // PRE: -
        // POST: Devuelve el valor de la superifcie
        float obtener_superficie();
        // PRE: -
        // POST: Devuelve la cantidad terminales
        int obtener_terminales();
        // PRE: -
        // POST: Devuelve la cantidad de destinos nacionales
        int obtener_destinos_nacionales();
        // PRE: -
        // POST: Devuelve la cantidad de destinos internacionales
        int obtener_destinos_internacionales();
        // PRE: -
        // POST: Muestra los datos del objeto de forma ordenada
        void mostrar();
};


#endif // AEROPUERTOS_H_INCLUDED
