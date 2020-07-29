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
		int costo;
		float horas;

	public:
		Arista(Vertice *, Arista *, int, float);
		Arista * obtener_siguiente();
		Vertice * obtener_adyacente();
		void setear_vertice(Vertice *);
		void setear_arista(Arista *);
};

#endif /* ARISTA_H_ */
