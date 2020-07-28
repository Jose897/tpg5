/*
 * Grafo.h
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include "Vertice.h"
#include "iostream"

//Grafo Dinamico

class Grafo {
	private:
		Vertice *h;

	public:
		Grafo();
		bool vacio();
		int tamanio();
		Vertice * obtener_vertice(std::string cod);
		void insertar_arista(Vertice *partida, Vertice *destino, int costo, float horas);
		void insertar_vertice(std::string cod);
		void lista_adyacentes();
		void eliminar_arista(Vertice *partida, Vertice *destino);
		void eliminar_vertice(Vertice *vert);
		void anular();
		void recorrido_ancho(Vertice *);
		void recorrido_profundidad(Vertice *);
};

#endif /* GRAFO_H_ */
