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
		//Constructor sin parametros
		//PRE:
		//POST: inicializar la clase Grafo con el puntero Vertice *h
		//hacia NULL
		Grafo();
		//Metodo vacio
		//PRE:
		//POST: retornar si el grafo esta vacio o no
		bool vacio();
		//Metodo tamanio
		//PRE:
		//POST: retornar el tamanio del grado
		int tamanio();
		//Metodo obtener_vertice
		//PRE: recibir un codigo valido
		//POST: retornar el puntero hacia el vertice pedido
		Vertice * obtener_vertice(std::string cod);
		//Metodo insertar_vertice
		//PRE: recibir un codigo para el vertice
		//POST: crear un Vertice
		void insertar_vertice(std::string cod);
		//Metodo insertar_arista
		//PRE: recibir punteros hacia los vertices validos
		//POST: crear una Arista con sus conecciones
		void insertar_arista(Vertice *partida, Vertice *destino, long int costo, float horas);
		//Metodo lista_adyacentes
		//PRE: Grafo no vacio
		//POST: imprimir las conecciones entre los vertices
		void lista_adyacentes();
		//Metodo eliminar_arista
		//PRE: recibir punteros a los vertices no nulos
		//POST: elminar la arista que conectas a los vertices
		void eliminar_arista(Vertice *partida, Vertice *destino);
		//Metodo eliminar_vertice
		//PRE: recibir un puntero al vertice que se quiere eliminar
		//POST: Eliminar dicho vertice y sus conecciones
		void eliminar_vertice(Vertice *vert);
		//Metodo anular
		//PRE:
		//POST: eliminar memoria dinamica
		void anular_vertice();
		//Metodo recorrido_ancho
		//PRE:
		//POST:
		void recorrido_peso_costo(Vertice *);
		//Metodo recorrido_profundidad
		//PRE:
		//POST:
		void recorrido_peso_horas(Vertice *);
};

#endif /* GRAFO_H_ */
