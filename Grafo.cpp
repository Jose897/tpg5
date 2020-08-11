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

void Grafo::insertar_vertice(std::string cod_ver)
{
	//Usar constructor con parametros
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

void Grafo::insertar_arista(Vertice *partida, Vertice *destino, long int costo, float horas)
{
	Arista *nueva = new Arista(NULL, NULL, costo, horas);
	Arista *aux;
	
	//para can_ady
	partida->aumentar_cant_ady();
	aux = partida -> obtener_adyacente();
	
	if(aux == NULL)
	{
		//Usar setters
		partida->setear_arista(nueva); //De vertice
		nueva->setear_vertice(destino); //De arista
	}
	else
	{ 	//Obtener siguiente para arista
		while(aux -> obtener_siguiente() != NULL)
		{
			aux = aux -> obtener_siguiente();
		}
		aux->setear_arista(nueva);
		nueva->setear_vertice(destino);
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

Arista* Grafo::obtener_arista( Vertice* verticeA, Vertice* verticeB ){
	std::string A, B;
	int j = 1;
	bool encontrado = false;
	B = verticeB->obtener_cod_vertice();
	
	Arista* aristaAux;
	aristaAux = verticeA->obtener_adyacente();

	while( ( !encontrado ) || ( j <= verticeA->obtener_cant_ady() ) )
	{
		A = aristaAux->obtener_adyacente()->obtener_cod_vertice();
		if( A == B )
		{
			encontrado = true;
		}
		else
		{
			aristaAux = aristaAux->obtener_siguiente();
		}
		j++;
	}
	if( encontrado )
	{
		return aristaAux;
	}
	else
	{
		return 0;
	}

}
long int Grafo::obtener_costo( Vertice* verticeA, Vertice* verticeB )
{
	Arista* aristaAux = obtener_arista( verticeA, verticeB );

	if( aristaAux != 0 )
	{
		return aristaAux->obtener_costo();
	}
	else
	{
		return 0;
	}
}

float Grafo::obtener_duracion( Vertice* verticeA, Vertice* verticeB )
{
	Arista* aristaAux = obtener_arista( verticeA, verticeB );

	if( aristaAux != 0 )
	{
		return aristaAux->obtener_duracion();
	}
	else
	{
		return 0;
	}
}

Vertice* Grafo::obtener_primer_vertice()
{
	return h;
}

Grafo::~Grafo()
{
	delete h;
}
