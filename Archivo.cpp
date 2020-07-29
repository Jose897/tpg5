#include "Archivo.h"
const string EXCEPCION = "Error al encontrar el archivo solicitado";

Archivo::Archivo() {}

Archivo:: ~Archivo()
{

}

void Archivo::lectura_aeropuertos(const string nombre_archivo, BST<string>* &diccionario)
{
    string linea;
    try
    {
        ifstream archivo(nombre_archivo);
        if(archivo.is_open()){
            while(getline(archivo, linea))
            {
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
        else
        {
            throw EXCEPCION;
        }
    }
    catch(const string e)
    {
        cout << "Ha ocurrido una excepcion del tipo '" << e << "'." << endl;
    }
}

void Archivo::lectura_vuelos(const string nombre_archivo, Grafo * G)
{
    string linea;
    try
    {
        ifstream archivo(nombre_archivo);
        if(archivo.is_open())
        {
            while(getline(archivo, linea))
            {
                string iata_partida, iata_destino;
                int precio;
                float tiempo;
                stringstream ss(linea);
                ss >> iata_partida >> iata_destino >> precio >> tiempo;
                G->insertar_vertice(iata_partida);
                G->insertar_vertice(iata_destino);
                G->insertar_arista(G->obtener_vertice(iata_partida), G->obtener_vertice(iata_destino), precio, tiempo);
            }
            archivo.close();
        }
        else
        {
            throw EXCEPCION;
        }
    }
    catch(const string e)
    {
        cout << "Ha ocurrido una excepcion del tipo '" << e << "'." << endl;
    }
}
