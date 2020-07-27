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
		Vertice *obtener_vertice(std::string cod_partida, std::string cod_destino);
		//Peso por costo
		void insertar_arista(Vertice *partida, Vertice *destino, int costo);
		//Peso por tiempo
		void insertar_arista(Vertice *partida, Vertice *destino, float horas);
		void insertar_vertice(std::string cod_partida, std::string cod_destin);
		void lista_adyacentes();
		void eliminar_arista(Vertice *partida, Vertice *destino);
		~Grafo();
};

#endif /* GRAFO_H_ */
