/*
 * Dijkstra.cpp
 *
 *  Created on: 28 jul. 2020
 *      Author: Jose
 */

#include "Dijkstra.h"

Dijkstra::Dijkstra(){
	g = 0;
	lista_prioridad=0;
	lista_resultado=0;
}

void Dijkstra::inicializar(Grafo*h,string origen, string destino){
	Vertice* aux;
	Lista<Vertice*>* lista_prioridad = new Lista<Vertice*>;
	Lista<Vertice*>* lista_resultado = new Lista<Vertice*>;
	int i;
	this->g=h;
	this->origen=origen;
	this->destino=destino;
	this->lista_prioridad = lista_prioridad;
	this->lista_resultado = lista_resultado;
	aux = g->obtener_primer_vertice();
	for( i=1; i<= g->tamanio() ;i++){
		aux->cambiar_vicitado(false);
		aux->cambiar_predecesor("-");
		aux->cambiar_acumulador_costo(0);
		aux->cambiar_acumulador_duracion(0);
		aux=aux->obtener_siguiente();
	}
	aux=g->obtener_vertice(origen); 
	lista_prioridad->insertar(aux);
}

Vertice* Dijkstra::obtener_minimo_costo_en_lista(){
	Vertice*aux;
	unsigned i;
	long int menor;
	unsigned posicion;
	
	menor=lista_prioridad->obtener_dato(1)->obtener_acumuladorCosto();
	posicion = 1;
	for(i=1; i <= lista_prioridad->obtener_tamanio() ;i++){
		aux = lista_prioridad->obtener_dato(i);
		if(aux->obtener_acumuladorCosto() < menor ){
			menor=aux->obtener_acumuladorCosto();
			posicion = i;
		}
	}
	aux = lista_prioridad->obtener_dato(posicion);
	lista_prioridad->borrar_dato(posicion);
	return aux;
}

void Dijkstra::borrar_lista_resultado(){
	unsigned i;
	unsigned tamanioLista;

	tamanioLista= lista_resultado->obtener_tamanio();

	for(i=1; i <= tamanioLista ; i++){
		lista_resultado->borrar_dato(1);
	}
}

void Dijkstra::guardar_secuencia_lista_resultado(Vertice* verticeB){
	Vertice*verticeAux;
	string predecesorAux;
	
	verticeAux=verticeB;

	while(verticeAux->obtener_cod_vertice() != origen ){
		lista_resultado->insertar(verticeAux);
		predecesorAux = verticeAux->obtener_predecesor();
		verticeAux=g->obtener_vertice(predecesorAux);
	}
	
	lista_resultado->insertar(verticeAux);
}

void Dijkstra::procesar_camino_minimo_por_costo(){
	int i;
	long int costoAB, costoB;
	Vertice*verticeA;
	Vertice*verticeB;

	while(!lista_prioridad->lista_vacia()){
		verticeA=obtener_minimo_costo_en_lista();
		verticeA->cambiar_vicitado(true);

		for(i=1; i<=verticeA->obtener_cant_ady() ;i++){
			verticeB = verticeA->obtener_vertice_ady(i);
			if(!verticeB->obtener_vicitado()){
				costoAB = verticeA->obtener_acumuladorCosto() + g->obtener_costo(verticeA, verticeB);
				costoB = verticeB->obtener_acumuladorCosto();
				if( (verticeB->obtener_cod_vertice() == destino) && ( costoB  > costoAB ) ){
					borrar_lista_resultado();
				}
				if( costoB  == 0 && verticeB->obtener_cod_vertice() != destino ){
					lista_prioridad->insertar(verticeB);
				}	
				if( ( costoB >= costoAB ) || ( costoB == 0 ) ){
					verticeB->cambiar_acumulador_costo( costoAB );
					verticeB->cambiar_predecesor(verticeA->obtener_cod_vertice());
					if(verticeB->obtener_cod_vertice() == destino){
						guardar_secuencia_lista_resultado(verticeB);
					}
				}
			}	
		}
	}
}

Vertice* Dijkstra::obtener_minimo_duracion_en_lista(){
	Vertice*aux;
	unsigned i;
	float menor;
	unsigned posicion;
	
	menor=lista_prioridad->obtener_dato(1)->obtener_acumuladorDuracion();
	posicion = 1;
	for(i=1; i <= lista_prioridad->obtener_tamanio() ;i++){
		aux = lista_prioridad->obtener_dato(i);
		if(aux->obtener_acumuladorDuracion() < menor ){
			menor=aux->obtener_acumuladorDuracion();
			posicion = i;
		}
	}

	aux = lista_prioridad->obtener_dato(posicion);
	lista_prioridad->borrar_dato(posicion);
	return aux;
}

void Dijkstra::procesar_camino_minimo_por_duracion(){
	int i;
	float duracionAB, duracionB;
	Vertice*verticeA;
	Vertice*verticeB;

	while(!lista_prioridad->lista_vacia()){
		verticeA=obtener_minimo_duracion_en_lista();
		verticeA->cambiar_vicitado(true);

		for(i=1; i<=verticeA->obtener_cant_ady() ;i++){
			verticeB = verticeA->obtener_vertice_ady(i);
			if(!verticeB->obtener_vicitado()){
				duracionAB = verticeA->obtener_acumuladorDuracion() + g->obtener_duracion(verticeA,verticeB) ;
				duracionB = verticeB->obtener_acumuladorDuracion();
				if( (verticeB->obtener_cod_vertice() == destino) && (duracionB > duracionAB ) ){
					borrar_lista_resultado();
				}
				if( ( duracionB == 0 ) && ( verticeB->obtener_cod_vertice() != destino ) ){
					lista_prioridad->insertar(verticeB);
				}
				if( ( duracionB >= duracionAB ) || ( duracionB == 0 ) ){
					verticeB->cambiar_acumulador_duracion(duracionAB);
					verticeB->cambiar_predecesor(verticeA->obtener_cod_vertice());
					if(verticeB->obtener_cod_vertice() == destino){
						guardar_secuencia_lista_resultado(verticeB);
					}
				}
			}	
		}	
	}
}

Lista<Vertice*>* Dijkstra::obtener_lista_resultado(){
	return lista_resultado;
}
Dijkstra::~Dijkstra(){
	delete lista_prioridad;
	delete lista_resultado;
}
