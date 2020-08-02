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
	lista_Resultado=0;
}

void Dijkstra::inicializar(Grafo*g,string origen, string destino){
	Vertice* aux;
	Lista<Vertice*> lista_prioridad();
	Lista<Vertice*> lista_resultado();
	int i;
	this->g=g;
	this->origen=origen;
	this->destino=destino;
	this->lista_prioridad = lista_prioridad;
	this->lista_Resultado = lista_resultado;
	aux = g;
	for( i=1; i<= g->tamanio() ;i++){
		aux->cambiar_vicitado(false);
		aux->cambiar_predecesor('-');
		aux->cambiar_acumulador_costo(-1);
		aux->cambiar_acumulador_duracion(-1);
		aux=aux->obtener_siguiente();
	}
	aux=g->obtener_vertice(origen); 
	//gregar metodo a Grafo, obtener un puntero a Vertice origen
	lista_prioridad.insertar(aux);
}

Vertice* Dijkstra::obtener_minimo_costo_en_lista(){
	Vertice*aux;
	int i;
	int menor;
	unsigned posicion;
	
	menor=lista_prioridad.obtener_dato(1)->obtener_acumuladorCosto();
	posicion = 1;
	for(i=1; i <= lista_prioridad.obtener_tamanio() ;i++){
		aux = lista_prioridad.obtener_dato(i);
		if(aux->obtener_acumuladorCosto() < menor ){
			menor=aux->obtener_acumuladorCosto();
			posicion = i;
		}
	}
	return lista_prioridad.obtener_dato(posicion);
}

void Dijkstra::borrar_lista_resultado(){
	unsigned i;

	for(i=1; i <= lista_resultado.obtener_tamanio() ; i++){
		lista_resultado.borrar_dato(i);
	}
}

void Dijkstra::guardar_secuencia_lista_resultado(verticeB){
	Vertice*verticeAux;
	string predecesorAux;
	
	verticeAux=verticeB;

	while(verticeAux->obtener_cod_vertice() != origen ){
		lista_resultado.insertar(verticeAux);
		predecesorAux = verticeAux->obtener_predecesor();
		verticeAux=g->obtener_vertice(predecesorAux);
	}
	
	lista_resultado.insertar(verticeAux);
}

//procesar int costo
int Dijkstra::procesar(){
	int i;
	Vertice*verticeA;
	Vertice*verticeB;

	while(!lista_prioridad.lista_vacia()){
		//metodo Dijkstra obtener minimo de la lista_pri  --OK
		verticeA=obtener_minimo_costo_en_lista();
		verticeA->cambiar_vicitado(true);
		//metodo grafo pide vertice responde, 
		//int cant_ady en vertice , atributo del mismo
		//obtener la cantidad de adyacentes que tiene el vertice
		for(i=1; i<=verticeA->obtener_cant_ady() ;i++){
			//obtener adyacente numero 1 - 2- 3 ...
			verticeB=verticeA->obtener_vertice_ady(i);
			//vicitado metodo-grafo, vertice-return-atributo
			if(!verticeB->vicitado()){
				//obtener_costo;metodo grafo(A,B) costo?
				if( (verticeB->obtener_cod_vertice==destino) && (verticeB->obtener_acumuladorCosto() > verticeA->obtener_acumuladorCosto()+ g->obtener_costo(verticeA, verticeB) ){
					//metodo Dijkstra para borrar toda la lista_pri con un for   --OK
					borrar_lista_resultado();
				}

				if( (verticeB->obtener_acumuladorCosto() >= verticeA->obtener_acumuladorCosto() + g->obtener_costo(verticeA, VerticeB)) || (verticeB->obtener_acumuladorCosto()== -1 ) ){
					verticeB->cambiar_acumulador_costo(verticeA->obtener_acumuladorCosto + g->obtener_costo(verticeA, verticeB));
					//atributo vertice predecesor
					verticeB->cambiar_predecesor(verticeA->obtener_cod_vertice());
					if(verticeB->obtener_cod_vertice() == destino){
						//metodo Dijkstra barrer secuencia   --OK
						guardar_secuencia_lista_resultado(verticeB);
					}else{
						//adicionar a la lista_pri
						lista_prioridad.insertar(verticeB);
					}
				}
			}
		
		}	
	}

}
/*
void obtener_camino_minimo(float){
}
*/
Dijkstra::~Dijkstra(){
{

