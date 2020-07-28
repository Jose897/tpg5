/*
 * Dijkstra.h
 *
 *  Created on: 28 jul. 2020
 *      Author: Jose
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "Vertice.h"
#include "iostream"

//

class Dijkstra {
	private:
		Grafo* h;

	public:
		Dijkstra();
		bool vacio();
		int tamanio();
		Vertice *obtener_vertice(std::string cod_partida, std::string cod_destino);
		//Peso por costo
		void insertar_arista(Vertice *partida, Vertice *destino, int costo);
		//Peso por tiempo
		void insertar_arista(Vertice *partida, Vertice *destino, float horas);
		void insertar_vertice(std::string cod_partida, std::string cod_destin);
		void lista_adyacentes();
		void eliminar_arista(Vertice *partida, Vertice *destino);
		~Dijkstra();
};

#endif /* DIJKSTRA_H_ */
