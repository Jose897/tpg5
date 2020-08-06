#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#include "ABBNodo.h"
#include "Aeropuertos.h"
#include<iostream>
#include <queue>
template <class T>
class BST
{
private:
    // atributos
    BSTNode<T>* root;

    // metodos
    BSTNode<T>* insert(BSTNode<T>* node, T data, Aeropuertos* valor);
    void print_in_order(BSTNode<T> * node);
    void print_ancho(BSTNode<T> * node);
    void obtener_valor(BSTNode<T> * node, T data);
    BSTNode<T>* search(BSTNode<T>* node, T data);
    T find_min(BSTNode<T>* node);
    T find_max(BSTNode<T>* node);
    T successor(BSTNode<T>* node);
    T predecessor(BSTNode<T>* node);
    BSTNode<T>* remove(BSTNode<T>* node, T data);
    void delete_all(BSTNode<T>* node);

public:
    //metodos

    //PRE:--
    //POST: Crea un arbol vacio
    BST();

    //PRE: Arbol creado
    //POST: Inserta un nodo en el arbol, si esta vacio el nodo sera la raiz
    void insert(T data, Aeropuertos* valor);

    //PRE: Arbol creado
    //POST: Imprime todos los datos del BST de mas chico a mas grande
    void print_in_order();

    //PRE: Arbol creado
    //POST: Imprime el arbol a lo ancho por niveles
    void print_ancho();
    //PRE: Arbol creado
    //POST: Muestra la clave y el valor asociado del codigo IATA que se pasa como parametro
    void obtener_valor(T data);
    //PRE: Arbol creado
    //POST: Si la clave existe, devuelve TRUE, de lo contrario, devuelve FALSE.
    bool search(T data);

    // Finds the minimum value that exist in the BST.
    T find_min();

    // Finds the maximum value that exist in the BST.
    T find_max();

    // Finds the successor of a given data value.
    T successor(T data);

    // Finds the predecessor of a given data value.
    T predecessor(T data);
    //PRE: Dato este en el arbol
    //POST: Borra un dato del arbol
    void remove(T data);

    BSTNode<T>* get_root();
    bool empty();

    //PRE: Arbol creado
    //POST: borra todos los nodos
    void delete_all();

    //Destructor
    ~BST<T>();

};

template <class T>
BST<T>::BST() {
    this->root = NULL;
}

template <class T>
BSTNode<T>* BST<T>::insert(BSTNode<T>* node, T data, Aeropuertos* valor) {

    if (node == NULL) {
        node = new BSTNode<T>(data, valor);
    }

    else if (data > node->get_data()) {
        node->set_right(insert(node->get_right(), data, valor), node);
    }

    else {
        node->set_left(insert(node->get_left(), data, valor), node);
    }
    return node;
}

template <class T>
void BST<T>::insert(T data, Aeropuertos* valor)
{
    this->root = insert(this->root, data, valor);
}

template <class T>
void BST<T>::print_in_order(BSTNode<T>* node)
{
    if (node != NULL)
    {
        print_in_order(node->get_left());
        std::cout<<"\nClave = "<< node->get_data()<<endl;
        std::cout<<"\nValor = " << endl;
        node->get_valor()->mostrar();
        print_in_order(node->get_right());
    }
}

template <class T>
void BST<T>::print_in_order()
{
    this->print_in_order(this->root);
}

template <class T>
void BST<T>::print_ancho(BSTNode<T>* node) {
    queue < BSTNode<T> * > cola;
    cola.push(node);
    while (true) {
        int tamanio_cola = cola.size();
        if (tamanio_cola == 0) {
            break;
        }
        int i = 0;
        while (i < tamanio_cola) {
            BSTNode<T> * n = cola.front();
            cout << n->get_data() << " ";
            if (n->get_left() != NULL) {
                cola.push(n->get_left());
            }
            if (n->get_right() != NULL) {
                cola.push(n->get_right());
            }
            cola.pop();
            i++;
        }
        cout << endl;
    }
}

template <class T>
void BST<T>::print_ancho()
{
    this->print_ancho(this->root);
}


template <class T>
void BST<T>::obtener_valor(BSTNode<T>* node, T data)
{
    if (node == NULL || node->get_data() == data) {
        std::cout << "\nClave = " << node->get_data() << endl;
        std::cout << "\nValor = " << endl;
        node->get_valor()->mostrar();
    }
    else if (data > node->get_data()){
        obtener_valor(node->get_right(), data);
    }

    else {
        obtener_valor(node->get_left(), data);
    }

}

template <class T>
void BST<T>::obtener_valor(T data)
{
    this->obtener_valor(this->root, data);
}

template <class T>
BSTNode<T>* BST<T>::search(BSTNode<T>* node, T data)
{
    if (node == NULL || node->get_data() == data)
        return node;

    if (data > node->get_data())
        return search(node->get_right(), data);

    return search(node->get_left(), data);
}

template <class T>
bool BST<T>::search(T data)
{
    BSTNode<T>* result = search(this->root, data);

    return result != NULL;
}

template <class T>
T BST<T>::find_min(BSTNode<T>* node)
{
    if(node == NULL)
        return NULL;
    else if(node->get_left() == NULL)
        return node->get_data();
    else
        return find_min(node->get_left());
}

template <class T>
T BST<T>::find_min()
{
    return find_min(this->root);
}

template <class T>
T BST<T>::find_max(BSTNode<T>* node)
{
    if(node == NULL)
        return NULL;
    else if(node->get_right() == NULL)
        return node->get_data();
    else
        return find_max(node->get_right());
}

template <class T>
T BST<T>::find_max()
{
    return find_max(this->root);
}

template <class T>
T BST<T>::successor(BSTNode<T>* node)
{
    if (node->get_right() != NULL)
    {
        return find_min(node->get_right());
    }
    BSTNode<T>* successor = NULL;
    BSTNode<T>* ancestor = this->root;
    while(ancestor != node) {
        if(node->get_data() < ancestor->get_data()) {
            successor = ancestor;
            ancestor = ancestor->get_left();
        }
        else
            ancestor = ancestor->get_right();
    }
    return successor->get_data();
}

template <class T>
T BST<T>::successor(T data)
{
    BSTNode<T>* data_node = this->search(this->root, data);
    // Return the key. If the key is not found or successor is not found, return -1
    if(data_node == NULL)
         return NULL;
    else return successor(data_node);
}

template <class T>
T BST<T>::predecessor(BSTNode<T> * node)
{
    if (node->get_left() != NULL)
    {
        return find_max(node->get_left());
    }

    BSTNode<T>* successor = NULL;
    BSTNode<T>* ancestor = this->root;
    while(ancestor != node) {
        if(node->get_data() > ancestor->get_data()) {
            successor = ancestor; // so far this is the deepest node for which current node is in left
            ancestor = ancestor->get_right();
        }
        else
            ancestor = ancestor->get_left();
    }
    return successor->get_data();
}

template <class T>
T BST<T>::predecessor(T data)
{
    BSTNode<T> * data_node = this->search(this->root, data);

    if(data_node == NULL)
        return NULL;
    else return predecessor(data_node);
}

template <class T>
BSTNode<T> * BST<T>::remove(BSTNode<T>* node, T data)
{
    // The given node is not found in BST
    if (node == NULL)
        return node;

    if (node->get_data() == data)
    {
        if (node->isLeaf())
        {
            delete node->get_valor();
            delete node;
            node = NULL;
        }
        else if (node->rightChildOnly())
        {
            // The only child will be connected to the parent's of node directly
            node->get_right()->set_parent(node->get_parent());
            // Bypass node
            BSTNode<T>* aux = node;
            node = node->get_right();
            delete aux->get_valor();
            delete aux;
        }
        else if (node->leftChildOnly())
        {
            // The only child will be connected to the parent's of node directly
            node->get_left()->set_parent(node->get_parent());
            // Bypass node
            BSTNode<T>* aux = node;
            node = node->get_left();
            delete aux->get_valor();
            delete aux;
        }

        // The node has two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            T successor_data = this->successor(data);

            // Replace node's key with successor's key
            node->set_data(successor_data);

            // Delete the old successor's key
            node->set_right(remove(node->get_right(), successor_data));
        }
    }

    else if (node->get_data() < data)
        node->set_right(remove(node->get_right(), data));

    else
        node->set_left(remove(node->get_left(), data));

    return node;
}

template <class T>
void BST<T>::remove(T data)
{
    this->root = remove(this->root, data);
}

template <class T>
BSTNode<T>* BST<T>::get_root(){
    return this->root;
}

template <class T>
bool BST<T>::empty()
{
    return this->root == NULL;
}


template <class T>
void BST<T>::delete_all(BSTNode<T>* node)
{
    if(node == NULL)
        return;
    this->delete_all(node->get_left());
    this->delete_all(node->get_right());
    delete node->get_valor();
    delete node;
}

template <class T>
void BST<T>::delete_all()
{
    this->delete_all(this->root);
}

template <class T>
BST<T>::~BST<T>()
{
    this->delete_all();
}


#endif // ABB_H_INCLUDED
