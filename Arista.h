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
		Arista();
		Arista * obtener_siguiente();
		~Arista();
};

#endif /* ARISTA_H_ */
