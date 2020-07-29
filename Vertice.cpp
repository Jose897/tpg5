/*
 * Vertice.cpp
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#include "Vertice.h"

Vertice::Vertice(Vertice * ver, Arista * ari, std::string cod)
{
	sig = ver;
	ady = ari;
	cod_vertice = cod;
}

Vertice* Vertice::obtener_siguiente()
{
	return sig;
}

Arista * Vertice::obtener_adyacente()
{
	return ady;
}

std::string Vertice::obtener_cod_vertice()
{
	return cod_vertice;
}

void Vertice::setear_arista(Arista * ari)
{
	ady = ari;
}

void Vertice::setear_vertice(Vertice * ver)
{
	sig = ver;
}
