#include "Archivo.h"
const string EXCEPCION = "Error al encontrar el archivo solicitado";

Archivo::Archivo() {}

Archivo:: ~Archivo() {
}

void Archivo::lectura_aeropuertos(const string nombre_archivo, BST<string>* &diccionario){
    string linea;
    try{
        ifstream archivo(nombre_archivo);
        if(archivo.is_open()){
            while(getline(archivo, linea)){
                string iata, nombre, ciudad, pais;
                float superficie;
                int terminales, nacionales, internacionales;
                stringstream ss(linea);
                ss >> iata >> nombre >> ciudad >> pais >> superficie >> terminales >> nacionales >> internacionales;
                Aeropuertos *aero = new Aeropuertos(nombre, ciudad, pais, superficie, terminales, nacionales, internacionales);
                diccionario->insert(iata, aero);
                //aero->mostrar(); Solo si queres ver si funciona bien
            }
            archivo.close();
        }
        else{
            throw EXCEPCION;
        }
    }
    catch(const string e){
        cout << "Ha ocurrido una excepcion del tipo '" << e << "'." << endl;
    }
}

void Archivo::lectura_vuelos(const string nombre_archivo){
    string linea;
    try{
        ifstream archivo(nombre_archivo);
        if(archivo.is_open()){
            while(getline(archivo, linea)){
                string iata_partida, iata_destino;
                float precio, tiempo;
                stringstream ss(linea);
                ss >> iata_partida >> iata_destino >> precio >> tiempo;
                precio = precio/1000;
                cout << iata_partida << " " <<iata_destino << " " << precio << " " << tiempo << endl; // cout de prueba
            }
            archivo.close();
        }
        else{
            throw EXCEPCION;
        }
    }
    catch(const string e){
        cout << "Ha ocurrido una excepcion del tipo '" << e << "'." << endl;
    }
}