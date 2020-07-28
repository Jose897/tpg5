/*
 * Vertice.cpp
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#include "Vertice.h"

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
