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
		bool vicitado;
		std::string predecesor;
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
		//
		//PRE: objeto creado
		//POST: cambia el estado del atributo vicitado
		void cambiar_vicitado(bool);
		//
		//PRE: objeto creado e inicializado
		//POST: cambia a un  predecesor al objeto
		void cambiar_predecesor(std::string);
		//
		//PRE: objeto creado
		//POST: cambia siempre a un menor costo acumulado
		void cambiar_acumulador_costo(long int);
		//
		//PRE: objeto creado
		//POST: cambia siempre a una menor duracion
		void cambiar_acumulador_duracion(float);
		//
		//PRE: objeto inicializado
		//POST: devuelve el menor costo que se acumulo
		long int obtener_acumuladorCosto();
		//
		//PRE: objeto inicializado
		//POST: devuelve la menor duracion que se acumulo
		float obtener_acumuladorDuracion();
		//
		//PRE: objeto creado
		//POST: aumenta en 1 la cantidad de aristas a las que apunta el objeto
		void aumentar_cant_ady();
		//
		//PRE: que el objeto este creado
		//POST: devuelve la cantidad de aristas del objeto que apuntan a otro/s vertice/s
		int obtener_cant_ady();
		//
		//PRE: parametro valido
		//POST: devuelve el vertice al cual apunta, estan enumerados
		Vertice* obtener_vertice_ady(int);
		//
		//PRE: objeto inicializado
		//POST: devuelve el estado del atributo vicitado
		bool obtener_vicitado();
		//
		//PRE: que el objeto este apuntado por una arista
		//POST: devuelve el codigo del vertice que precede al objeto
		std::string obtener_predecesor();


};

#endif /* VERTICE_H_ */
