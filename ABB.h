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
    BSTNode<T>* insertar(BSTNode<T>* node, T data, Aeropuertos* valor);
    void imprimir_en_orden(BSTNode<T> * node);
    void imprimir_ancho(BSTNode<T> * node);
    void mostrar_elemento(BSTNode<T> * node, T data);
    BSTNode<T>* buscar(BSTNode<T>* node, T data);
    T buscar_min(BSTNode<T>* node);
    T buscar_max(BSTNode<T>* node);
    T siguiente(BSTNode<T>* node);
    T anterior(BSTNode<T>* node);
    BSTNode<T>* eliminar(BSTNode<T>* node, T data);
    void eliminar_todos(BSTNode<T>* node);

public:
    //metodos

    //PRE:--
    //POST: Crea un arbol vacio
    BST();

    //PRE: Arbol creado
    //POST: Inserta un nodo en el arbol, si esta vacio el nodo sera la raiz
    void insertar(T data, Aeropuertos* valor);

    //PRE: Arbol creado
    //POST: Imprime todos los datos del BST de mas chico a mas grande
    void imprimir_en_orden();

    //PRE: Arbol creado
    //POST: Imprime el arbol a lo ancho por niveles
    void imprimir_ancho();
    //PRE: Arbol creado
    //POST: Muestra la clave y el valor asociado del codigo IATA que se pasa como parametro
    void mostrar_elemento(T data);
    //PRE: Arbol creado
    //POST: Si la clave existe, devuelve TRUE, de lo contrario, devuelve FALSE.
    bool buscar(T data);

    // Finds the successor of a given data value.
    T siguiente(T data);

    // Finds the predecessor of a given data value.
    T anterior(T data);
    //PRE: Dato este en el arbol
    //POST: Borra un dato del arbol
    void eliminar(T data);

    //PRE: Arbol creado
    //POST: borra todos los nodos
    void eliminar_todos();

    //Destructor
    ~BST<T>();

};

template <class T>
BST<T>::BST() {
    this->root = NULL;
}

template <class T>
BSTNode<T>* BST<T>::insertar(BSTNode<T>* node, T data, Aeropuertos* valor) {

    if (node == NULL) {
        node = new BSTNode<T>(data, valor);
    }

    else if (data > node->get_data()) {
        node->set_right(insertar(node->get_right(), data, valor), node);
    }

    else {
        node->set_left(insertar(node->get_left(), data, valor), node);
    }
    return node;
}

template <class T>
void BST<T>::insertar(T data, Aeropuertos* valor)
{
    this->root = insertar(this->root, data, valor);
}

template <class T>
void BST<T>::imprimir_en_orden(BSTNode<T>* node)
{
    if (node != NULL)
    {
        imprimir_en_orden(node->get_left());
        std::cout<<"\nClave = "<< node->get_data()<<endl;
        std::cout<<"\nValor = " << endl;
        node->get_valor()->mostrar();
        imprimir_en_orden(node->get_right());
    }
}

template <class T>
void BST<T>::imprimir_en_orden()
{
    this->imprimir_en_orden(this->root);
}

template <class T>
void BST<T>::imprimir_ancho(BSTNode<T>* node) {
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
void BST<T>::imprimir_ancho()
{
    this->imprimir_ancho(this->root);
}


template <class T>
void BST<T>::mostrar_elemento(BSTNode<T>* node, T data)
{
    if (node == NULL || node->get_data() == data) {
        std::cout << "\nClave = " << node->get_data() << endl;
        std::cout << "\nValor = " << endl;
        node->get_valor()->mostrar();
    }
    else if (data > node->get_data()){
        mostrar_elemento(node->get_right(), data);
    }

    else {
        mostrar_elemento(node->get_left(), data);
    }

}

template <class T>
void BST<T>::mostrar_elemento(T data)
{
    this->mostrar_elemento(this->root, data);
}

template <class T>
BSTNode<T>* BST<T>::buscar(BSTNode<T>* node, T data)
{
    if (node == NULL || node->get_data() == data)
        return node;

    if (data > node->get_data())
        return buscar(node->get_right(), data);

    return buscar(node->get_left(), data);
}

template <class T>
bool BST<T>::buscar(T data)
{
    BSTNode<T>* result = buscar(this->root, data);

    return result != NULL;
}

template <class T>
T BST<T>::buscar_min(BSTNode<T>* node)
{
    if(node == NULL)
        return NULL;
    else if(node->get_left() == NULL)
        return node->get_data();
    else
        return buscar_min(node->get_left());
}


template <class T>
T BST<T>::buscar_max(BSTNode<T>* node)
{
    if(node == NULL)
        return NULL;
    else if(node->get_right() == NULL)
        return node->get_data();
    else
        return buscar_max(node->get_right());
}


template <class T>
T BST<T>::siguiente(BSTNode<T>* node)
{
    if (node->get_right() != NULL)
    {
        return buscar_min(node->get_right());
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
T BST<T>::siguiente(T data)
{
    BSTNode<T>* data_node = this->buscar(this->root, data);
    // Return the key. If the key is not found or successor is not found, return -1
    if(data_node == NULL)
         return NULL;
    else return siguiente(data_node);
}

template <class T>
T BST<T>::anterior(BSTNode<T> * node)
{
    if (node->get_left() != NULL)
    {
        return buscar_max(node->get_left());
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
T BST<T>::anterior(T data)
{
    BSTNode<T> * data_node = this->buscar(this->root, data);

    if(data_node == NULL)
        return NULL;
    else return anterior(data_node);
}

template <class T>
BSTNode<T> * BST<T>::eliminar(BSTNode<T>* node, T data)
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
            T successor_data = this->siguiente(data);

            // Replace node's key with successor's key
            node->set_data(successor_data);

            // Delete the old successor's key
            node->set_right(eliminar(node->get_right(), successor_data));
        }
    }

    else if (node->get_data() < data)
        node->set_right(eliminar(node->get_right(), data));

    else
        node->set_left(eliminar(node->get_left(), data));

    return node;
}

template <class T>
void BST<T>::eliminar(T data)
{
    this->root = eliminar(this->root, data);
}


template <class T>
void BST<T>::eliminar_todos(BSTNode<T>* node)
{
    if(node == NULL)
        return;
    this->eliminar_todos(node->get_left());
    this->eliminar_todos(node->get_right());
    delete node->get_valor();
    delete node;
}

template <class T>
void BST<T>::eliminar_todos()
{
    this->eliminar_todos(this->root);
}

template <class T>
BST<T>::~BST<T>()
{
    this->eliminar_todos();
}


#endif // ABB_H_INCLUDED
