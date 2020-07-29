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

	public:
		Vertice(Vertice *, Arista *, std::string);
		Vertice * obtener_siguiente();
		Arista * obtener_adyacente();
		std::string obtener_cod_vertice();
		void setear_arista(Arista *);
		void setear_vertice(Vertice *);
};

#endif /* VERTICE_H_ */
