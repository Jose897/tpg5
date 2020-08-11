/*
 * Grafo.h
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include "Vertice.h"
#include <iostream>

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
		//Metodo obtener_arista
		//PRE: parametros validos
		//POST: devuelve la direccion de la arista que une a los parametros
		Arista* obtener_arista( Vertice*, Vertice* );
		////Metodo obtener_costo
		//PRE: parametros validos
		//POST: devuelve el costo de la arista que une a los parametros
		long int obtener_costo( Vertice*, Vertice* );
		////Metodo obtener_duracion
		//PRE: parametros validos
		//POST:  devuelve la duracion de la arista que une a los parametros
		float obtener_duracion( Vertice*, Vertice* );
		////Metodo obtener_primer_vertice
		//PRE: Grafo no vacio
		//POST: devuelve el primer vertice 
		Vertice* obtener_primer_vertice();
		//Destructor
		//PRE: objeto creado
		//POST: borra el vertice apuntado por h
		~Grafo();
};

#endif /* GRAFO_H_ */
