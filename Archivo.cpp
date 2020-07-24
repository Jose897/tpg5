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
                cout<<iata<<endl;
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
