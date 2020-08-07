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
    BSTNode<T>* left; //Left children
    BSTNode<T>* right; //Right children
    BSTNode<T>* parent;
    Aeropuertos* valor;

public:
    //Constructor
    BSTNode(T data, Aeropuertos* valor);
    // Asigna una clave
    void set_data(T data);
    void set_right(BSTNode<T>* right, BSTNode<T>* parent);
    void set_left(BSTNode<T>* left, BSTNode<T>* parent);
    void set_left(BSTNode<T>* left);
    void set_right(BSTNode<T>* right);
    void set_parent(BSTNode<T>* parent);
    //Devuelve la clave del diccionario
    T get_data();
    //Devuelve el valor asociado a una clave del diccionario
    Aeropuertos* get_valor();           //Nose si esta bien que devuelva un puntero a la clase
    //Devuelve el hijo derecho
    BSTNode<T>* get_right();
    //Devuelve el hijo izquierdo
    BSTNode<T>* get_left();
    //Devuelve el padre
    BSTNode<T>* get_parent();
    //Devuelve true si es hoja
    bool isLeaf();
    //Devuelve true si solo tiene hijo derecho
    bool rightChildOnly();
    //Devuelve true si solo tiene hijo izquierdo
    bool leftChildOnly();
};

template <class T>
BSTNode<T>::BSTNode(T data, Aeropuertos* valor)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
    this->valor = valor;
}

template <class T>
T BSTNode<T>::get_data()
{
    return this->data;
}

template <class T>
Aeropuertos* BSTNode<T>::get_valor()
{
    return valor;
}

template <class T>
void BSTNode<T>::set_right(BSTNode<T>* right, BSTNode<T>* parent){
    this->right = right;
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_right(BSTNode<T>* right){
    this->right = right;
}

template <class T>
void BSTNode<T>::set_left(BSTNode<T>* left, BSTNode<T>* parent){
    this->left = left;
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_parent(BSTNode<T> *parent) {
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_data(T data) {
    this->data = data;
}


template <class T>
void BSTNode<T>::set_left(BSTNode<T>* left){
    this->left = left;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_right()
{
    return this->right;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_left()
{
    return this->left;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_parent()
{
    return this->parent;
}

template <class T>
bool BSTNode<T>::isLeaf() {
    return (this->get_left() == NULL && this->get_right() == NULL);
}

template <class T>
bool BSTNode<T>::rightChildOnly() {
    return (this->get_left() == NULL && this->get_right() != NULL);
}

template <class T>
bool BSTNode<T>::leftChildOnly() {
    return (this->get_left() != NULL && this->get_right() == NULL);
}

#endif // ABBNODO_H_INCLUDED
