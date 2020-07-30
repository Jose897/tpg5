/*
 * Dijkstra.h
 *
 *  Created on: 28 jul. 2020
 *      Author: Jose
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "Grafo.h"
#include "Etiqueta.h"
#include "ColaPriHeap"
#include "Pila"
#include <iostream>

using namespace std;

// en Grafo escribir Metodo obtener peso de arista A -> B 
// donde A y B son Aristas a eleccion
//
// Medoto obtener_peso(A,B);
// Metodo obtener_cantidad_adyacente(A)
// Metodo obtener_adyacente(1) 2, 3, 4 ...
//
template <typename Peso>
class Dijkstra {
	private:
		Grafo* g;
		ColaPriHeap* cola;
		Pila* pila;
		string origen;
		string destino;

	public:
		Dijkstra();
		
		void crear_etiqueta();
		

		//por costo $$
		void procesar();
		

		void comparar();

		Pila* resultado();
		
		~Dijkstra();

};
template <typename Peso>
Dijkstra<Peso>::Dijkstra(g,origen,destino){
	this->g = g;
	this->origen;
	this->destino;
	colaPriHeap=0;
	pila=0;
}

template <typename Peso>
Dijkstra<Peso>::procesar(){
	//g.obtener_peso(origenadyacente);
	int iteracion = 0;
	Peso acumulador = 0;
	string A,B,Z;
	Pila<Peso>* pila_vicitado = new Pila<Peso>;
	Pila<Peso>* pila_resultado = new Pila<Peso>;
	
	A = g.obtener_cod_vertice(origen);
	Z = g.obtener_cod_vertice(destino);

	Etiqueta<Peso>* etiquetaA = new Etiqueta<Peso>(acumulador,'-',origen,g.obtener_cantidad_ady(A),iteracion);
	
	cola>insertar(etiquetaA);

	while(!cola->vacia()){
		etiquetaA = cola->desencolar(); //devuelve un puntero a etiqueta
		iteracion = etiquetaA->obtener_interacion()+1;
		for(int i =0; i < etiquetaA->obtener_cant_adyacente() ;i++ ){
			B = g->obtener_cod_adyacente(etiquetaA->obtener_cod(),i);
			acumulador = etiquetaA->obtener_acumulador;
			if(!pila_vicitado->buscar(B)){ //busca en pila bool
				acumulador = acumulador + g->obtener_peso(A,B);
				Etiqueta<peso>* etiquetaB = crear_etiqueta(acumulador,A,B,g->obtener_cant_adyacente(B),iteraccion);
				if(Z==B){
					if(!pila_resultado->vacio() && (pila_resultado->obtener_acumulador() >= etiquetaB-obtener_acumulador() ) ){
						if( pila_resultado->obtener_acumulador() > etiquetaB->obtener_acumulador() ){
							pila_resultado->desapilado_total();
						}
						Etiqueta <Peso>* etiquetaAux = new Etiqueta<Peso>;
						while( origen != etiquetaB->obtener_predecesor()){
							etiquetaAux = etiquetaB; // sobrecargar el adicionar '='
							pila_resultado->insertar_etiqueta(etiquetaAux);
							etiquetaB=cola->obtener_etiqueta(etiquetaB->obtener_predecesor());//obtiene el puntero etiqueta
						}
						pila_resultado->insertar_etiqueta(etiquetaB);
					}
				}else{
					if(cola->buscar_etiqueta(B)){
						if(cola->obtener_acumulador(B) < etiquetaB->acumulador()){
							delete etiquetaB;
						}else{	
							if(cola->obtener_acumulado(B) > etiquetaB->acumulador()){
								cola->eliminar_etiqueta(B);
							}
							cola->insertar(etiquetaB); //////// al insertar evaluar cantidad de adyacentes mayor arriba
						}
					}else{
						cola->insertar(etiquetaB);
					}
				}

			}
		}//fin for
		pila_vicitado->insertar_etiqueta(etiquetaA);
	}//fin while
}

template<typename Peso>
Etiqueta* Dijstra<Peso>::crear_etiqueta(peso,predecesor,cod,cantAdyacente,iteracion){
	Etiqueta<Peso>* etiqueta = new Etiqueta<Peso>;

	etiqueta.acumulado = peso;
	etiqueta.predecesor = predecesor;
	etiqueta.vertice = cod;
	etiqueta.cantAdyacente = cantAdyacente;
	etiqueta.iteracion = iteracion;
	
	return etiqueta;

}






#endif /* DIJKSTRA_H_ */
