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

void Grafo::insertar_vertice(std::string cod_ver)
{
	Vertice *nuevo = new Vertice(NULL, NULL, cod_ver);

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
		aux->setear_vertice(nuevo);
	}
}

void Grafo::insertar_arista(Vertice *partida, Vertice *destino, int costo, float horas)
{
	Arista *nueva = new Arista(NULL, NULL, costo, horas);
	Arista *aux;

	aux = partida -> obtener_adyacente();

	if(aux == NULL)
	{
		partida->setear_arista(nueva);
		nueva->setear_vertice(destino);
	}
	else
	{
		while(aux -> obtener_siguiente() != NULL)
		{
			aux = aux -> obtener_siguiente();
		}
		aux->setear_arista(nueva);
		nueva->setear_vertice(destino);
	}
}

void Grafo::eliminar_arista(Vertice *origen, Vertice *destino)
{
	Arista *actual, *anterior;
	bool band = false;

	actual =  origen -> obtener_adyacente();

	if(actual == NULL)
	{
		std::cout << "El vertice origen no tine aristas" << std::endl;
	}
	else if(actual -> obtener_adyacente() == destino)
	{
		origen->setear_arista(actual -> obtener_siguiente());
		delete actual;
	}
	else
	{
		while(actual -> obtener_adyacente() != NULL)
		{
			if(actual -> obtener_adyacente() == destino)
			{
				band = true;
				anterior->setear_arista(actual -> obtener_siguiente());
				delete actual;
				break;
			}
			anterior = actual;
			actual = actual -> obtener_siguiente();
		}
		if(band == false)
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
		anterior->setear_vertice(actual->obtener_siguiente());
		delete actual;
	}
}

Grafo::~Grafo()
{
	Vertice *aux;

	while(h != NULL)
	{
		aux = h;
		h = h -> obtener_siguiente();
		eliminar_vertice(aux);
		delete aux;
	}
}
