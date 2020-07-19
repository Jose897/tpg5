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
        Aeropuertos(string, string, string, float, int, int, int);
        string obtener_nombre();
        string obtener_ciudad();
        string obtener_pais();
        float obtener_superficie();
        int obtener_terminales();
        int obtener_destinos_nacionales();
        int obtener_destinos_internacionales();
        void mostrar();
};


#endif // AEROPUERTOS_H_INCLUDED
