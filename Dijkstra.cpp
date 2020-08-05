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
	//gregar metodo a Grafo, obtener un puntero a Vertice origen
	lista_prioridad->insertar(aux);
}

Vertice* Dijkstra::obtener_minimo_costo_en_lista(){
	Vertice*aux;
	int i;
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
cout<<"guardar secuencia en lista resultado"<<endl;
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


//procesar int costo
void Dijkstra::procesar_costo(){
	int i;
	Vertice*verticeA;
	Vertice*verticeB;
//	cout<<" procesar\n";
	while(!lista_prioridad->lista_vacia()){
		//metodo Dijkstra obtener minimo de la lista_pri  --OK
		verticeA=obtener_minimo_costo_en_lista();
		
		verticeA->cambiar_vicitado(true);
		//metodo grafo pide vertice responde, 
		//int cant_ady en vertice , atributo del mismo
		//obtener la cantidad de adyacentes que tiene el vertice
//		cout<<"entro al while\n";
		for(i=1; i<=verticeA->obtener_cant_ady() ;i++){
			//obtener adyacente numero 1 - 2- 3 ...
//			cout<<"entro en for "<<verticeA->obtener_cant_ady()<<endl;
			verticeB = verticeA->obtener_vertice_ady(i);
//			cout<<"verticeB "<<verticeB->obtener_cod_vertice()<<endl ;
			//vicitado metodo-grafo, vertice-return-atributo
			if(!verticeB->obtener_vicitado()){
//				cout<<" no vicitado \n";
				//obtener_costo;metodo grafo(A,B) costo?
				if( (verticeB->obtener_cod_vertice() == destino) && (verticeB->obtener_acumuladorCosto() > verticeA->obtener_acumuladorCosto() + g->obtener_costo(verticeA, verticeB) ) ){
//				cout<<" borrar lista_resultado \n";
					//metodo Dijkstra para borrar toda la lista_pri con un for   --OK
					borrar_lista_resultado();
				}

				if( verticeB->obtener_acumuladorCosto() == 0 ){
					lista_prioridad->insertar(verticeB);
				}

				if( (verticeB->obtener_acumuladorCosto() >= (verticeA->obtener_acumuladorCosto() + g->obtener_costo(verticeA, verticeB))) || (verticeB->obtener_acumuladorCosto()== 0 ) ){
//				cout<<" cambiar acumulador costo \n";
					verticeB->cambiar_acumulador_costo(verticeA->obtener_acumuladorCosto() + g->obtener_costo(verticeA, verticeB));
					//atributo vertice predecesor
					verticeB->cambiar_predecesor(verticeA->obtener_cod_vertice());
					if(verticeB->obtener_cod_vertice() == destino){
//				cout<<" llego a destino\n";
						//metodo Dijkstra barrer secuencia   --OK
						guardar_secuencia_lista_resultado(verticeB);
					}else{
//				cout<<" insertar en lista \n";
						//adicionar a la lista_pri
						//lista_prioridad->insertar(verticeB);
					}
				}
			}	
		}	
	}

}
//////////////////////
Vertice* Dijkstra::obtener_minimo_duracion_en_lista(){
	Vertice*aux;
	int i;
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

void Dijkstra::procesar_duracion(){
	int i;
	Vertice*verticeA;
	Vertice*verticeB;
	cout<<" procesar\n";
	while(!lista_prioridad->lista_vacia()){
		//metodo Dijkstra obtener minimo de la lista_pri  --OK
		verticeA=obtener_minimo_duracion_en_lista();
		
		verticeA->cambiar_vicitado(true);
		//metodo grafo pide vertice responde, 
		//int cant_ady en vertice , atributo del mismo
		//obtener la cantidad de adyacentes que tiene el vertice
		cout<<"entro al while\n";
		for(i=1; i<=verticeA->obtener_cant_ady() ;i++){
			//obtener adyacente numero 1 - 2- 3 ...
			cout<<"entro en for "<<verticeA->obtener_cant_ady()<<endl;
			verticeB = verticeA->obtener_vertice_ady(i);
			cout<<"verticeB "<<verticeB->obtener_cod_vertice()<<endl ;
			//vicitado metodo-grafo, vertice-return-atributo
			if(!verticeB->obtener_vicitado()){
				cout<<" no vicitado \n";
				//obtener_costo;metodo grafo(A,B) costo?
				if( (verticeB->obtener_cod_vertice() == destino) && (verticeB->obtener_acumuladorDuracion() > verticeA->obtener_acumuladorDuracion()+ g->obtener_duracion(verticeA, verticeB) ) ){
//				cout<<" borrar lista_resultado \n";
					//metodo Dijkstra para borrar toda la lista_pri con un for   --OK
					borrar_lista_resultado();
				}

				if( (verticeB->obtener_acumuladorDuracion() >= (verticeA->obtener_acumuladorDuracion() + g->obtener_duracion(verticeA, verticeB))) || (verticeB->obtener_acumuladorDuracion()== 0 ) ){
//				cout<<" cambiar acumulador costo \n";
					verticeB->cambiar_acumulador_duracion(verticeA->obtener_acumuladorDuracion() + g->obtener_duracion(verticeA, verticeB));
					//atributo vertice predecesor
					verticeB->cambiar_predecesor(verticeA->obtener_cod_vertice());
					if(verticeB->obtener_cod_vertice() == destino){
//				cout<<" llego a destino\n";
						//metodo Dijkstra barrer secuencia   --OK
						guardar_secuencia_lista_resultado(verticeB);
					}else{
//				cout<<" insertar en lista \n";
						//adicionar a la lista_pri
						lista_prioridad->insertar(verticeB);
					}
				}
			}	
		}	
	}
}

Lista<Vertice*>* Dijkstra::obtener_lista_resultado(){
	return lista_resultado;
}
/*
void obtener_camino_minimo(float){
}
*/
Dijkstra::~Dijkstra(){
	//eliminar
}

