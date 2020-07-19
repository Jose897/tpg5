#include "Aeropuertos.h"

Aeropuertos::Aeropuertos(string nom, string ciu, string p, float sup, int term, int nacionales, int internacionales){
    nombre = nom;
    ciudad = ciu;
    pais = p;
    superficie = sup;
    terminales = term;
    destinos_nacionales = nacionales;
    destinos_internacionales = internacionales;
}

string Aeropuertos::obtener_nombre(){
    return nombre;
}

string Aeropuertos::obtener_ciudad(){
    return ciudad;
}

string Aeropuertos::obtener_pais(){
    return pais;
}

float Aeropuertos::obtener_superficie(){
    return superficie;
}

int Aeropuertos::obtener_terminales(){
    return terminales;
}

int Aeropuertos::obtener_destinos_nacionales(){
    return destinos_nacionales;
}

int Aeropuertos::obtener_destinos_internacionales(){
    return destinos_internacionales;
}

void Aeropuertos::mostrar(){
    cout << "Nombre: " << obtener_nombre() << endl;
    cout << "Cuidad: " << obtener_ciudad() << endl;
    cout << "Pais: " << obtener_pais() << endl;
    cout << "Superficie: " << obtener_superficie() << endl;
    cout << "Terminales: " << obtener_terminales() << endl;
    cout << "Tiene " << obtener_destinos_internacionales() << " destinos internaciones." << endl;
    cout << "Tiene " << obtener_destinos_nacionales() << " destinos nacionales." << endl;
}
