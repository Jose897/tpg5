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
		std::string cod_partida;
		std::string cod_destino;
		int costo;
		float horas_vuelo;

	public:
		Vertice();
		~Vertice();
		Vertice * obtener_siguiente();
		Arista * obtener_adyacente();
};

#endif /* VERTICE_H_ */
