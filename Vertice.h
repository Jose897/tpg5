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

		Vertice* sig;
		Arista* ady;
		std::string cod_vertice;
		//atributos para dijkstra
		bool vicitado;
		string predecesor;
		long int acumuladorCosto;
		float acumuladorDuracion;
		int cant_ady;


	public:
		//Constructor con parametros
		//PRE:
		//POST: crear clase Vertice con punteros a NULL
		//y aisgnar el codigo del vertice
		Vertice(Vertice *, Arista *, std::string);
		//Metodo obtener_siguiente
		//PRE:
		//POST: retornar el puntero siguiente al Vetice
		Vertice * obtener_siguiente();
		//Metodo obtener_adyacente
		//PRE:
		//POST: retornar el puntero adyacente al Vertice
		Arista * obtener_adyacente();
		//Metodo obtener_cod_vertice
		//PRE:
		//POST: retornar el codigo del vertice
		std::string obtener_cod_vertice();
		//Metodo setear_vertice
		//PRE:
		//POST: setea el puntero al Vertice siguiente
		void setear_vertice(Vertice *);
		//Metodo setear_arista
		//PRE:
		//POST: setea el puntero a la Arista adyacente
		void setear_arista(Arista *);

		void cambiar_vicitado(bool);

		void cambiar_predecesor(string);

		void cambiar_acumulador_costo(long int);

		void cambiar_acumulador_duracion(float);

		long int obtener_acumuladorCosto();

		void aumentar_cant_ady();

		int obtener_cant_ady();

		Vertice* obtener_vertice_ady(int);

		bool obtener_vicitado();


};

#endif /* VERTICE_H_ */
