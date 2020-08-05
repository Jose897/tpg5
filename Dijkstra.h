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
		//
		//PRE:--
		//POST:crea el objeto Dijkstra
		Dijkstra();
		//
		//PRE: objeto este creado parametros validos
		//POST: se inicializa los parametros de Dijkstra por default
		void inicializar(Grafo*,string,string);
		//
		//PRE: objeto creado e inicializado
		//POST: devuelve el puntero del vertice con menor costo que esta en la lista
		Vertice* obtener_minimo_costo_en_lista();
		//
		//PRE: objeto creado y lista no vacia
		//POST: devuelve el puntero del vertice con menor duracion que esta en la lista
		Vertice* obtener_minimo_duracion_en_lista();
		//
		//PRE: objeto creado y lista no vacia
		//POST: borra la lista_resultado
		void borrar_lista_resultado();
		//
		//PRE: objeto creado y se debe procesar un camino minimo (costo/duracion)
		//POST: guarda en una lista, la secuencia de un/unos posible camino minima
		void guardar_secuencia_lista_resultado(Vertice*);
		//
		//PRE: objeto creado e inicializado
		//POST: crea una lista con el/los camino minimo del Grafo por costo
		void procesar_camino_minimo_por_costo();
		//
		//PRE: objeto creado e inicializado
		//POST: crea una lista con el/los camino minimo del GRafo por tiempo
		void procesar_camino_minimo_por_duracion();
		//
		//PRE: que se procese un camino minimo (costo/duracion)
		//POST: devuelve un puntero con la lista de el/los camino minimo
		Lista<Vertice*>* obtener_lista_resultado();
		//
		//PRE: objeto creado
		//POST: borra el objeto
		~Dijkstra();
};
#endif /* DIJKSTRA_H_ */
