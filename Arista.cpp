/*
 * Arista.cpp
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#include "Arista.h"

Arista::Arista(Vertice * ver, Arista * ari, long int _costo, float _horas)
{
	ady = ver;
	sig = ari;
	costo = _costo;
	horas = _horas;
}

Arista * Arista::obtener_siguiente()
{
	return sig;
}

Vertice * Arista::obtener_adyacente()
{
	return ady;
}

void Arista::setear_vertice(Vertice * ver)
{
	ady = ver;
}

void Arista::setear_arista(Arista * ari)
{
	sig = ari;
}

long int Arista::obtener_costo(){
	return costo;
}
