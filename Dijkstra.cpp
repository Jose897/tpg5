/*
 * Dijkstra.cpp
 *
 *  Created on: 28 jul. 2020
 *      Author: Jose
 */

#include "Dijkstra.h"

Dijkstra::Dijkstra(){
	h = NULL;
}

bool Dijkstra::vacio(){
}

int Dijkstra::tamanio(){
}

void obtener_camino_minimo_costo(Grafo*g,string origen,string destino){

	string A,B,Z;
	int interacion=0;
	int acumulador;
	int l=0;
	
	A=origen;
	Z=destino;

	//Vertice* verticeZ=g->obtener_vertice(Z);
	Lista<Etiqueta*> lista = new Lista<Etiqueta*>;
	
	Vertice* verticeA = g->obtener_vertice(A);
	Vertice* verticeB;
	Etiqueta<int>* etiquetaA = new Etiqueta<int>(0,'-',A,iteracion);

	lista->insertar(etiquetaA);

	Etiqueta<int>* etiquetaLista;

	while(!lista->lista_vacia()){
		
		etiquetaA = lista->buscar_dato(1);
		for(int k=2; k <= lista->obtener_tamanio() ;k++){
			etiquetaLista = lista->buscar_dato(k);
			if(etiquetaA->obtener_acumulador < etiquetaLista->obtener_acumulador()){
				etiquetaA=etiquetaLista;
				l++;
			}	
		}
		lista_resultado->insertar(etiquetaA);
		lista->desapilar(l);
		verticeA=g->obtener_vertice(etiquetaA->obtener_cod());

		for(int i=0; i<=verticeA->obtener_cant_ady(); i++){
			verticeB = verticeA->obtener_ady(i);
			B=verticeB->obtener_cod();
			if(!verticeB->obtener_vicitado()){
				acumulador = etiquetaA->obtener_acumulador() + g->btener_costo(A,B);
				Etiqueta<int>* etiquetaB = new Etiqueta<int>(acumulador,A,B,verticeB->obtener_cant_ady(),iteracion);
				
				if(Z==B){
					for(int m=0;m<=lista_resultado->obtener_tamanio();m++){
						etiquetaResultado=lista_resultado->obtener_dato(m);
						if(etiquetaResultado->cod==Z){
							if(etiquetaResultado->obtener_acumulador > etiquetaB->obtener_acumulador()){
								listaResultado->borrar_dato(m);
							}
						}

					}
					listaResultado->insertar(etiquetaB);
				}

				for(int j=0; j<=lista->obtener_tamanio() ;j++){
					etiquetaLista = lista->buscar_dato(j);
					if(etiquetaLista->obtener_acumulador() < etiquetaB->obtener_acumulador()){
						delete etiquetaB;
					}else{
						if(etiquetaLista-obtener_acumulador() > etiquetaB->obtener_acumulador()){
							lista->borrar_dato(j);
						}
						lista->insertar(etiquetaB);
					}


				}//fin_for2
			}
		}//fin_for1
		VerticeA->marcar_visitado();
	}




}

void obtener_camino_minimo(float){
}

Dijkstra::~Dijkstra(){
{

