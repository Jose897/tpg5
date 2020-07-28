/*
 * Arista.h
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#ifndef ARISTA_H_
#define ARISTA_H_

//Necesario para vertice

#include "Vertice.h"

class Vertice;

class Arista {

	private:

		Arista *sig;
		Vertice *ady;
		unsigned peso;

	public:
		Arista * obtener_siguiente();
		Vertice * obtener_adyacente();
};

#endif /* ARISTA_H_ */
