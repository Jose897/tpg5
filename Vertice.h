/*
 * Vertice.h
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#ifndef VERTICE_H_
#define VERTICE_H_

#include "Arista.h"
#include<iostream>
#include <string>

class Arista;

class Vertice {
	private:

		Vertice *sig;
		Arista *ady;
		std::string cod_vertice;
		int costo;
		float horas_vuelo;

	public:
		Vertice * obtener_siguiente();
		Arista * obtener_adyacente();
		std::string obtener_cod_vertice();
};

#endif /* VERTICE_H_ */
