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
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Dijkstra {
	private:
		Grafo* g;
		string origen;
		string destino;
		Lista<Vertice*>* lista_prioridad;
		Lista<Vertice*>* lista_resultado;

	public:
		//
		//PRE:--
		//POST:crea el objeto Dijkstra
		Dijkstra();
		//
		//PRE: objeto este creado parametros validos
		//POST: se inicializa los parametros de Dijkstra por default
		void inicializar( Grafo*, string, string );
		//
		//PRE: objeto inicializado
		//POST: evalua el Vertice con menor costo en lista
		void condicion_costo(long int*, Vertice*, unsigned, unsigned*);
		//
		//PRE: objeto inicializado
		//POST: evalua el Vertice con menor duracion en lista
		void condicion_duracion(float*, Vertice*, unsigned, unsigned*);
		//
		//PRE: objeto creado e inicializado
		//POST: devuelve el Vertice minimo en lista
		Vertice* obtener_minimo_en_lista(int);
		//
		//PRE: objeto creado y lista no vacia
		//POST: borra la lista_resultado
		void borrar_lista_resultado();
		//
		//PRE: objeto creado y se debe procesar un camino minimo (costo/duracion)
		//POST: guarda en una lista, la secuencia de un/unos posible camino minima
		void guardar_secuencia_lista_resultado( Vertice* );
		//?
		//PRE: objeto creado e inicializado
		//POST: resuelve las comparaciones para el camino costo
		void evaluar_camino_costo( Vertice*, Vertice* );
		//
		//PRE: objeto inicializado
		//POST: resuelve las comparaciones para el camino duracion
		void evaluar_camino_duracion( Vertice*, Vertice* );
		//
		//PRE: objeto creado e inicializado
		//POST: crea una lista con el/los camino minimo del Grafo por tiempo
		void procesar_camino_minimo( int );
		//
		//PRE: que se procese un camino minimo (costo/duracion)
		//POST: devuelve un puntero con la lista de el/los camino minimo
		Lista<Vertice*>* obtener_lista_resultado();
		//
		//PRE: lista_resultado no vaica
		//POST: arma una cadena con el resultado del camino minimo costo
		void concatenar_costo( string&, Vertice*, Vertice*, long int*, unsigned* );
		//
		//PRE: lista_resultado no vacia
		//POST: arma una cedena con el resultado del camino minimo duracion
		void concatenar_duracion( string&, Vertice*, Vertice*, float*, unsigned* );
		//
		//PRE: lista_resultado no vacia
		//POST: devuelve una cadena para imprimir en pantalla
		string impresion_camino_minimo( int );
		//
		//PRE: objeto creado
		//POST: borra el objeto
		~Dijkstra();
};
#endif /* DIJKSTRA_H_ */
