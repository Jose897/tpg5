/*
 * Arista.cpp
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#include "Arista.h"


Arista * Arista::obtener_siguiente()
{
	return sig;
}

Vertice * Arista::obtener_adyacente()
{
	return ady;
}
