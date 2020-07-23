#include "Archivo.h"
const string EXCEPCION = "Error al encontrar el archivo solicitado";

Archivo::Archivo() {}

Archivo:: ~Archivo() {}

void Archivo::lectura_aeropuertos(const string nombre_archivo){

    string linea;
    try{
        ifstream archivo(nombre_archivo);
        if(archivo.is_open()){
            while(getline(archivo, linea)){
                string iata;
                string nombre;
                string ciudad;
                string pais;
                float superficie;
                int terminales;
                int nacionales;
                int internacionales;
                stringstream ss(linea);
                ss >> iata >> nombre >> ciudad >> pais >> superficie >> terminales >> nacionales >> internacionales;
                Aeropuertos aero(nombre, ciudad, pais, superficie, terminales, nacionales, internacionales);

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
