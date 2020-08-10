#include "Archivo.h"
const string EXCEPCION = "Error al encontrar el archivo solicitado";

Archivo::Archivo()
{
    bst = new BST<string>();
    h = new Grafo;
}

Archivo:: ~Archivo()
{
    delete bst;
    delete h;
}

void Archivo::lectura_aeropuertos(const string nombre_archivo)
{
    string linea;
    try
    {
        ifstream archivo(nombre_archivo);
        if(archivo.is_open())
        {
            while(getline(archivo, linea))
            {
                string iata, nombre, ciudad, pais;
                float superficie;
                int terminales, nacionales, internacionales;
                stringstream ss(linea);
                ss >> iata >> nombre >> ciudad >> pais >> superficie >> terminales >> nacionales >> internacionales;
                Aeropuertos *aero = new Aeropuertos(nombre, ciudad, pais, superficie, terminales, nacionales, internacionales);
                bst->insertar(iata, aero);
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

void Archivo::lectura_vuelos(const string nombre_archivo)
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
                long int precio;
                float tiempo;
                stringstream ss(linea);
                ss >> iata_partida >> iata_destino >> precio >> tiempo;
                //precio = precio/1000;
		if( h->obtener_vertice(iata_partida) == 0 )
		{
			h->insertar_vertice(iata_partida);
		}
		if( h->obtener_vertice(iata_destino) == 0 )
		{
			h->insertar_vertice(iata_destino);
		}
		h->insertar_arista( h->obtener_vertice(iata_partida), h->obtener_vertice(iata_destino), precio, tiempo);
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

BST<string> * Archivo::obtener_diccionario()
{
    return bst;
}

Grafo * Archivo::obtener_grafo()
{
    return h;
}
