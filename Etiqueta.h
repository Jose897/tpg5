/*
 * Etiqueta.h
 *
 *  Created on: 30 jul. 2020
 *      Author: Jose
 */

#ifndef ETIQUETA_H_
#define ETIQUETA_H_

#include "Grafo.h"
#include "ColaPriHeap"
#include "Pila"
#include <iostream>

using namespace std;

template <typename Peso>
class Etiqueta {
	private:
		Peso acumulador;
		string predecesor;
		string cod_vertice;
		int cant_adyacente;
		int iteracion;

	public:
		Etiqueta(Peso,stringstring,int,int);
		Peso obtener_acumulador();
		string obtener_predecesor();
		string obtener_cod();		
		int obtener_cant_adyacente();
		int obtener_iteracion();
		~Etiqueta();
};

template<typename Peso>
Etiqueta<Peso>::Etiqueta(Peso acumulador,string predecesor,string cod_vertice ,int cant_adyacente,int interacion){
	this->acumulador=acumulador;
	this->predecesor=predecesor;
	this->cod_vertice=cod_vertice;
	this->cant_adyacente=cant_adyacente;
	this->interacion=iteracion;
}
template<typename Peso>
Peso Etiqueta<Peso>::obtener_acumulador(){
	return acumulador;
}
template<typename Peso>
string Etiqueta<Peso>::obtener_predecesor(){
	return predecesor;
}
template<typename Peso>
string Etiqueta<Peso>::obtener_cod(){
	return cod_vertice;
}
template<typename Peso>
int Etiqueta<Peso>::obtener_cant_adyacente(){
	return cant_adyacente;
}
template<typename Peso>
int Etiqueta<Peso>::obtener_iteracion(){
	return iteracion;
}
template<typename Peso>
Etiqueta<Peso>::~Etiqueta(){
}

#endif /* ETIQUETA_H_ */
