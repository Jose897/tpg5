/*
 * Grafo.cpp
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#include "Grafo.h"

Grafo::Grafo()
{
	h = NULL;
}

bool Grafo::vacio()
{
	if(h == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Grafo::tamanio()
{
	int cont = 0;
	Vertice *aux;
	aux = h;
	while(aux != NULL)
	{
		cont++;
		aux = aux -> obtener_siguiente();
	}
	return cont;
}

Vertice * Grafo::obtener_vertice(std::string cod_ver)
{
	//Recorrer el grafo y preguntar si el vertice que estamos recoriendo tiene los codigos
	Vertice *aux;
	aux = h;
	while(aux != NULL)
	{
		if(aux -> obtener_cod_vertice() == cod_ver)
		{
			return aux;
		}
		aux = aux -> obtener_siguiente();
	}
	return NULL;
}

void Grafo::insertar_vertice(std::string cod)
{
	//Usar setter para los poner los datos
	Vertice *nuevo = new Vertice;
	nuevo -> cod_vertice = cod;
	nuevo -> sig = NULL;
	nuevo -> ady = NULL;

	if(vacio())
	{
		h = nuevo;
	}
	else
	{
		Vertice *aux;
		aux = h;
		while(aux -> obtener_siguiente() != NULL)
		{
			aux = aux -> obtener_siguiente();
		}
		aux -> sig = nuevo;
	}
}

void Grafo::insertar_arista(Vertice *partida, Vertice *destino, int costo, float horas)
{
	//Usar setters
	Arista *nueva = new Arista;
	nueva -> costo = costo;
	nueva -> sig = NULL;
	nueva -> ady = NULL;
	nueva -> horas = horas;

	Arista *aux;

	aux = partida -> obtener_adyacente();

	if(aux == NULL)
	{
		//Usar setters
		partida -> obtener_adyacente() = nueva;
		destino -> obtener_siguiente() = nueva;
	}
	else
	{ 	//Obtener siguiente para arista
		while(aux -> obtener_siguiente() != NULL)
		{
			aux = aux -> obtener_siguiente();
		}
		aux -> obtener_siguiente() = nueva;
		nueva -> obtener_adyacente() = destino;
	}
}

void Grafo::lista_adyacentes()
{
	Vertice *ver_aux;
	Arista *ari_aux;

	ver_aux = h;

	while(ver_aux != NULL)
	{
		std::cout << ver_aux -> obtener_cod_vertice() << "->";
		ari_aux = ver_aux -> obtener_adyacente();
		while(ari_aux != NULL)
		{
			std::cout << ari_aux -> obtener_adyacente() -> obtener_cod_vertice() << "->";
			ari_aux = ari_aux -> obtener_siguiente();
		}
		ver_aux = ver_aux -> obtener_siguiente();
		std::cout << std::endl;
	}
}

void Grafo::eliminar_arista(Vertice *origen, Vertice *destino)
{
	Arista *actual, *anterior;
	int band = 0;

	actual =  origen -> obtener_adyacente();

	if(actual == NULL)
	{
		std::cout << "El vertice origen no tine aristas" << std::endl;
	}
	else if(actual -> obtener_adyacente() == destino)
	{
		origen -> obtener_adyacente() = actual -> obtener_siguiente();
		delete actual;
	}
	else
	{
		while(actual -> obtener_adyacente() != NULL)
		{
			if(actual -> obtener_adyacente() == destino)
			{
				band = 1;
				anterior -> obtener_siguiente() = actual -> obtener_siguiente();
				delete actual;
				break;
			}
			anterior = actual;
			actual = actual -> obtener_siguiente();
		}
		if(band == 0)
		{
			std::cout << "Esos dos vertices no estan conectados" << std::endl;
		}
	}
}

void Grafo::eliminar_vertice(Vertice *vert)
{
	Vertice *actual, *anterior;
	Arista *aux;

	actual = h;
	while(actual != NULL)
	{
		aux = actual -> obtener_adyacente();
		while(aux != NULL)
		{
			if(aux -> obtener_adyacente() == vert)
			{
				eliminar_arista(actual, aux -> obtener_adyacente());
				break;
			}
			aux = aux -> obtener_siguiente();
		}
		actual = actual -> obtener_siguiente();
	}

	actual = h;
	if(h == vert)
	{
		h = h -> obtener_siguiente();
		delete actual;
	}
	else
	{
		while(actual != vert)
		{
			anterior = actual;
			actual = actual -> obtener_siguiente();
		}
		anterior -> obtener_siguiente() = actual -> obtener_siguiente();
		delete actual;
	}
}

void Grafo::anular()
{
	Vertice *aux;

	while(h != NULL)
	{
		aux = h;
		h = h -> obtener_siguiente();
		delete aux;
	}
}

void Grafo::recorrido_ancho(Vertice *)
{

}

void Grafo::recorrido_profundidad(Vertice *)
{

}

