/*
 * Arista.cpp
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#include "Arista.h"

Arista::Arista()
{
	sig = NULL;
	ady = NULL;
	peso = 0;
}

Arista * Arista::obtener_siguiente()
{
	return sig;
}

Arista::~Arista()
{
	// TODO Auto-generated destructor stub
}

