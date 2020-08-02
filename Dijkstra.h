/*
 * Dijkstra.h
 *
 *  Created on: 28 jul. 2020
 *      Author: Jose
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "Grafo.h"
#include "Lista.h"
#include "Nodo.h"
#include "Vertice.h"
#include <iostream>

using namespace std;

class Dijkstra {
	private:
		Grafo* g;
		string origen;
		string destino;
		Lista<Vertice*>*lista_prioridad;
		Lista<Vertice*>*lista_resultado;

	public:
		Dijkstra();
		void inicializar(Grafo*,string,string);
		Vertice*obtener_minimo_costo_en_lista();
		void borrar_lista_resultado();
		void guardar_secuencia_lista_resultado();
		int procesar();
		//int procesar(duracion);
		//Lista<...>* mostrar();

#endif /* DIJKSTRA_H_ */
