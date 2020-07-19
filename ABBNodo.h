#ifndef ABBNODO_H_INCLUDED
#define ABBNODO_H_INCLUDED

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
    string valor;

public:
    BSTNode(T data, string valor);
    T get_data();
    void set_data(T data);
    void set_right(BSTNode<T>* right, BSTNode<T>* parent);
    void set_left(BSTNode<T>* left, BSTNode<T>* parent);
    void set_left(BSTNode<T>* left);
    void set_right(BSTNode<T>* right);
    void set_parent(BSTNode<T>* parent);
    string get_valor();
    BSTNode<T>* get_right();
    BSTNode<T>* get_left();
    BSTNode<T>* get_parent();
    bool isLeaf();
    bool rightChildOnly();
    bool leftChildOnly();
};

template <class T>
BSTNode<T>::BSTNode(T data, string valor)
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
string BSTNode<T>::get_valor()
{
    return this->valor;
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
