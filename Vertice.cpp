/*
 * Vertice.cpp
 *
 *  Created on: 24 jul. 2020
 *      Author: Santi
 */

#include "Vertice.h"

Vertice::Vertice(Vertice * ver, Arista * ari, std::string cod)
{
	sig = ver;
	ady = ari;
	cod_vertice = cod;
	//atributos para Dijkstra
	vicitado=false;
	predecesor="-";
	acumuladorCosto = -1;
	acumuladorDuracion = -1;
	cant_ady = 0;

}

Vertice* Vertice::obtener_siguiente()
{
	return sig;
}

Arista * Vertice::obtener_adyacente()
{
	return ady;
}

std::string Vertice::obtener_cod_vertice()
{
	return cod_vertice;
}

void Vertice::setear_arista(Arista * ari)
{
	ady = ari;
}

void Vertice::setear_vertice(Vertice * ver)
{
	sig = ver;
}

//para Dijkstra
void Vertice::cambiar_visitado(bool siono){
	vicitado = siono;
}

void Vertice::cambiar_predecesor(std::string codPredecesor){
	predecesor = codPredecesor;
}

void Vertice::cambiar_acumulador_costo(long int precio){
	acumuladorCosto = precio;
}

void Vertice::cambiar_acumulador_duracion(float hora){
	acumuladorDuracion = hora;
}

//
long int Vertice::obtener_acumulador_costo(){
	return acumuladorCosto;
}

float Vertice::obtener_acumulador_duracion(){
	return acumuladorDuracion;
}
void Vertice::aumentar_cant_ady(){
	cant_ady++;
}

int Vertice::obtener_cant_ady(){
	return cant_ady;
}

Vertice* Vertice::obtener_vertice_ady(int pos){
	int i;
	Arista* aux;
	
	aux = ady;
	for(i = 1; i < pos ; i++){
		aux = aux->obtener_siguiente();
	}

	return aux->obtener_adyacente();
}

bool Vertice::obtener_visitado(){
	return vicitado;
}

std::string Vertice::obtener_predecesor(){
	return predecesor;
}

Vertice::~Vertice(){
	delete sig;
	delete ady;
}
