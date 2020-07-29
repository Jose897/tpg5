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
		//Constructor con parametros
		//PRE:
		//POST: crear clase arista con punteros a NULL,
		//el costo y las horas respectivos
		Arista(Vertice *, Arista *, int, float);
		//Metodo obtener_siguiente
		//PRE:
		//POST: retornar el puntero siguiente a la Arista
		Arista * obtener_siguiente();
		//Metodo obtener_adyacente
		//PRE:
		//POST: retornar el puntero adyacente a la Arista
		Vertice * obtener_adyacente();
		//Metodo setear_vertice
		//PRE:
		//POST: setea el puntero al Vertice adyacente
		void setear_vertice(Vertice *);
		//Metodo setear_arista
		//PRE:
		//POST: setea el puntero a la Arista siguiente
		void setear_arista(Arista *);
};

#endif /* ARISTA_H_ */
