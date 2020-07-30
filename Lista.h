/*
 * Lista.h
 *
 *  Created on: 2 jul. 2020
 *      Author: Santi
 */
#ifndef LISTA_H_
#define LISTA_H_

# include <iostream>
# include "Nodo.h"
template < typename Dato >
class Lista
{
private:
    // Primer elemento de la lista
    Nodo<Dato>* primero;
    // Tamanio de la lista
    unsigned tam;
public:
    // Constructor
    // PRE: Ninguna
    // POST: construye una lista vacia
    // - primero apunta a nulo
    // - tam = 0
    Lista();
    // Destructor
    // PRE: Lista creada
    // POST: Libera todos los recursos de la lista
    ~Lista();
    // Agregar un elemento a la lista
    // PRE: lista creada y d valido
    // POST: agrega un dato dentro de un nodo al principio
    // - modifica el primero
    // - tam se incrementa en 1
    void insertar(Dato d);
    // Obtener el tamanio de la lista
    // PRE: Lista creada
    // POST: devuelve el tamanio de la lista (cantidad de nodos)
    unsigned obtener_tamanio();
    // Obtener el dato que esta en la posicion pos
    // PRE: - lista creada y no vacia
    // - 0 < pos <= tam
    // POST: devuelve el dato que esta en la posicion pos
    // se toma 1 como el primero
    Dato obtener_dato(unsigned pos);
    // Lista vacia?
    // PRE: Lista creada
    // POST: T si es vacia, F sino
    bool lista_vacia();
    // Borrado del nodo que esta en la posicion pos
    // PRE: - lista creada y no vacia
    // - 0 < pos <= tam
    // POST: libera el nodo que esta en la posicion pos
    // se toma 1 como el primero
    void borrar_dato(unsigned pos);
    //
    //
    //
    void asignar_dato(unsigned pos, Dato d);
};

template < typename Dato >
Lista<Dato>::Lista()
{
    primero = 0;
    tam = 0;
}

template < typename Dato >
Lista<Dato>::~Lista()
{
    while (!this->lista_vacia())
    {
        this->borrar_dato(1);
    }
}

template < typename Dato >
bool Lista<Dato>::lista_vacia()
{
    return (tam == 0);
}

template < typename Dato >
void Lista<Dato>::insertar(Dato d)
{
    Nodo<Dato>* nuevo = new Nodo<Dato>(d);
    if (!(this->lista_vacia()))
    {
        nuevo->asignar_siguiente(primero);
    }
    primero = nuevo;
    tam++;
}

template < typename Dato >
Dato Lista<Dato>::obtener_dato(unsigned pos)
{
    Nodo<Dato>* aux = primero;
    if (!lista_vacia())
    {
        for (unsigned cont = 1; (cont < pos && aux); cont++)
            aux = aux->obtener_siguiente();
        return aux->obtener_dato();
    }
    return 0;
}

template < typename Dato >
unsigned Lista<Dato>::obtener_tamanio()
{
    return tam;
}

template < typename Dato >
void Lista<Dato>::borrar_dato(unsigned pos)
{
    Nodo<Dato>* aux = primero;
    if (!lista_vacia())
    {
        if (pos == 1)
        {
            primero = primero->obtener_siguiente();
        }
        else
        {
            for (unsigned cont = 0; (cont < pos-1 && aux->obtener_siguiente()); cont++)
                aux = aux->obtener_siguiente();
            aux->asignar_siguiente(aux->obtener_siguiente());
        }
        delete aux;
        tam--;
    }
}

template < typename Dato >
void Lista<Dato>::asignar_dato(unsigned pos, Dato d){
	Nodo<Dato>* aux;
	aux = primero;
	if( pos == 1){
		aux->asignar_dato(d);
	}else{
		for(int i=1; i < pos ; i++){
			aux=aux->obtener_siguiente();
		}
		aux->asignar_dato(d);
	}
}

#endif //LISTA_H_
