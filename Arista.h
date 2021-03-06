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
		long int costo;
		float horas;

	public:
		//Constructor con parametros
		//PRE:
		//POST: crear clase arista con punteros a NULL,
		//el costo y las horas respectivos
		Arista(Vertice *, Arista *, long int, float);
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
		//Metodo obtener_costo
		//PRE: constructor ejecutado
		//POST: devuelve el costo del atributo
		long int obtener_costo();
		//Metodo obtener_duracion
		//PRE: constructor ejecutado
		//POST: devuelve la duracion del atributo
		float obtener_duracion();
		//
		//PRE: objeto creado
		//POST: borra el puntero sig
		~Arista();
};

#endif /* ARISTA_H_ */
