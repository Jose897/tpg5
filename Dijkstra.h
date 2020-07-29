/*
 * Dijkstra.h
 *
 *  Created on: 28 jul. 2020
 *      Author: Jose
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "Grafo.h"
#include <iostream>

// 

class Dijkstra {
	private:
		Grafo* h;

	public:
		Dijkstra();
		~Dijkstra();
		bool vacio();
		int tamanio();
		void obtener_camino_minimo(int);
		void obtener_camino_minimo(float);

};

#endif /* DIJKSTRA_H_ */
