#ifndef ABBNODO_H_INCLUDED
#define ABBNODO_H_INCLUDED

#include "Aeropuertos.h"
#include<string>

using namespace std;

template <class T>
class BSTNode
{
private:
    T data;
    BSTNode<T>* izquierdo; //hijo izquierdo
    BSTNode<T>* derecho; // hijo derecho
    BSTNode<T>* padre;
    Aeropuertos* valor;

public:
    //Constructor
    BSTNode(T data, Aeropuertos* valor);
    // PRE: -
    // POST: Asigna una clave
    void set_data(T data);
    // PRE: -
    // POST: Asigna hijo derecho
    void set_right(BSTNode<T>* right, BSTNode<T>* parent);
    // PRE: -
    // POST: Asigna hijo izquierdo
    void set_left(BSTNode<T>* left, BSTNode<T>* parent);
    // PRE: -
    // POST: Asigna hijo izquierdo
    void set_left(BSTNode<T>* left);
    // PRE: -
    // POST: Asigna hijo derecho
    void set_right(BSTNode<T>* right);
    // PRE: -
    // POST: Le asigna un padre a un nodo
    void set_parent(BSTNode<T>* parent);
    // PRE: -
    // POST: Devuelve una clave
    T obtener_clave();
    // PRE: -
    // POST: Devuelve el valor asociado a una clave del diccionario
    Aeropuertos* obtener_valor();
    // PRE: -
    // POST: Devuelve el hijo derecho
    BSTNode<T>* obtener_derecho();
    // PRE: -
    // POST: Devuelve el hijo izquierdo
    BSTNode<T>* obtener_izquierdo();
    // PRE: -
    // POST: Devuelve el padre
    BSTNode<T>* obtener_padre();
    // PRE: -
    // POST: Devuelve true si el nodo es hoja
    bool es_hoja();
    // PRE: -
    // POST: Devuelve true si el nodo solo tiene hijo derecho
    bool hijo_derecho();
    // PRE:
    // POST: Devuelve true si el nodo solo tiene hijo izquierdo
    bool hijo_izquierdo();
};

template <class T>
BSTNode<T>::BSTNode(T data, Aeropuertos* valor)
{
    this->data = data;
    this->izquierdo = NULL;
    this->derecho = NULL;
    this->padre = NULL;
    this->valor = valor;
}

template <class T>
T BSTNode<T>::obtener_clave()
{
    return this->data;
}

template <class T>
Aeropuertos* BSTNode<T>::obtener_valor()
{
    return valor;
}

template <class T>
void BSTNode<T>::set_right(BSTNode<T>* right, BSTNode<T>* parent){
    this->derecho = right;
    this->padre = parent;
}

template <class T>
void BSTNode<T>::set_right(BSTNode<T>* right){
    this->derecho = right;
}

template <class T>
void BSTNode<T>::set_left(BSTNode<T>* left, BSTNode<T>* parent){
    this->izquierdo = left;
    this->padre = parent;
}

template <class T>
void BSTNode<T>::set_parent(BSTNode<T> *parent) {
    this->padre = parent;
}

template <class T>
void BSTNode<T>::set_data(T data) {
    this->data = data;
}


template <class T>
void BSTNode<T>::set_left(BSTNode<T>* left){
    this->izquierdo = left;
}

template <class T>
BSTNode<T>* BSTNode<T>::obtener_derecho()
{
    return this->derecho;
}

template <class T>
BSTNode<T>* BSTNode<T>::obtener_izquierdo()
{
    return this->izquierdo;
}

template <class T>
BSTNode<T>* BSTNode<T>::obtener_padre()
{
    return this->padre;
}

template <class T>
bool BSTNode<T>::es_hoja() {
    return (this->obtener_izquierdo() == NULL && this->obtener_derecho() == NULL);
}

template <class T>
bool BSTNode<T>::hijo_derecho() {
    return (this->obtener_izquierdo() == NULL && this->obtener_derecho() != NULL);
}

template <class T>
bool BSTNode<T>::hijo_izquierdo() {
    return (this->obtener_izquierdo() != NULL && this->obtener_derecho() == NULL);
}

#endif // ABBNODO_H_INCLUDED
