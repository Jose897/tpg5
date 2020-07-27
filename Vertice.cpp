/*
 * Vertice.cpp
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#include "Vertice.h"

Vertice::Vertice() {
	ady = NULL;
	sig = NULL;
	cod_partida = "\0";
	cod_destino = "\0";
	costo = 0;
	horas_vuelo = 0;

}

Vertice* Vertice::obtener_siguiente()
{
	return sig;
}

Arista * Vertice::obtener_adyacente()
{
	return ady;
}

Vertice::~Vertice() {

}
