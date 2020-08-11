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
    BSTNode<T>* insertar(BSTNode<T>* nodo, T data, Aeropuertos* valor);
    void imprimir_en_orden(BSTNode<T> * nodo);
    void imprimir_ancho(BSTNode<T> * nodo);
    void mostrar_elemento(BSTNode<T> * nodo, T data);
    BSTNode<T>* buscar(BSTNode<T>* nodo, T data);
    T buscar_min(BSTNode<T>* nodo);
    T buscar_max(BSTNode<T>* nodo);
    T siguiente(BSTNode<T>* nodo);
    T anterior(BSTNode<T>* nodo);
    BSTNode<T>* eliminar(BSTNode<T>* nodo, T data);
    void eliminar_todos(BSTNode<T>* nodo);

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
    //PRE: Arbol creado
    //POST: Devuelve el predecesor del dato pasado como parametro
    T siguiente(T data);
    //PRE: Arbol creado
    //POST: Devuelve el sucesor del dato pasado como parametro
    T anterior(T data);
    //PRE: Dato este en el arbol
    //POST: Borra un dato del arbol
    void eliminar(T data);

    //PRE: Arbol creado
    //POST: borra todos los nodos
    void eliminar_todos();
    //TRUE en caso de que el arbol este vacio
    bool vacio();
    //Destructor
    ~BST<T>();

};

template <class T>
BST<T>::BST() {
    this->root = NULL;
}

template <class T>
bool BST<T>::vacio()
{
    return this->root == NULL;
}

template <class T>
BSTNode<T>* BST<T>::insertar(BSTNode<T>* nodo, T data, Aeropuertos* valor) {

    if (nodo == NULL) {
        nodo = new BSTNode<T>(data, valor);
    }

    else if (data > nodo->obtener_clave()) {
        nodo->set_right(insertar(nodo->obtener_derecho(), data, valor), nodo);
    }

    else {
        nodo->set_left(insertar(nodo->obtener_izquierdo(), data, valor), nodo);
    }
    return nodo;
}

template <class T>
void BST<T>::insertar(T data, Aeropuertos* valor)
{
    this->root = insertar(this->root, data, valor);
}

template <class T>
void BST<T>::imprimir_en_orden(BSTNode<T>* nodo)
{
    if (nodo != NULL){
        imprimir_en_orden(nodo->obtener_izquierdo());
        cout << "\nClave = " << nodo->obtener_clave() << endl;
        cout<<"\nValor = " << endl;
        nodo->obtener_valor()->mostrar();
        imprimir_en_orden(nodo->obtener_derecho());
    }
}

template <class T>
void BST<T>::imprimir_en_orden()
{
    this->imprimir_en_orden(this->root);
}

template <class T>
void BST<T>::imprimir_ancho(BSTNode<T>* nodo) {
    queue < BSTNode<T> * > cola;
    cola.push(nodo);
    while (true) {
        int tamanio_cola = cola.size();
        if (tamanio_cola == 0) {
            break;
        }
        int i = 0;
        while (i < tamanio_cola) {
            BSTNode<T> * n = cola.front();
            cout << n->obtener_clave() << " ";
            if (n->obtener_izquierdo() != NULL) {
                cola.push(n->obtener_izquierdo());
            }
            if (n->obtener_derecho() != NULL) {
                cola.push(n->obtener_derecho());
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
void BST<T>::mostrar_elemento(BSTNode<T>* nodo, T data)
{
    if (nodo == NULL || nodo->obtener_clave() == data)
    {
        cout << "\nClave = " << nodo->obtener_clave() << endl;
        cout << "\nValor = " << endl;
        nodo->obtener_valor()->mostrar();
    }
    else if (data > nodo->obtener_clave()){

        mostrar_elemento(nodo->obtener_derecho(), data);
    }

    else {
        mostrar_elemento(nodo->obtener_izquierdo(), data);
    }

}

template <class T>
void BST<T>::mostrar_elemento(T data)
{
    this->mostrar_elemento(this->root, data);
}

template <class T>
BSTNode<T>* BST<T>::buscar(BSTNode<T>* nodo, T data)
{
    if (nodo == NULL || nodo->obtener_clave() == data)
        return nodo;

    if (data > nodo->obtener_clave())
        return buscar(nodo->obtener_derecho(), data);

    return buscar(nodo->obtener_izquierdo(), data);
}

template <class T>
bool BST<T>::buscar(T data)
{
    BSTNode<T>* result = buscar(this->root, data);

    return result != NULL;
}

template <class T>
T BST<T>::buscar_min(BSTNode<T>* nodo)
{
    if(nodo == NULL)
        return NULL;
    else if(nodo->obtener_izquierdo() == NULL)
        return nodo->obtener_clave();
    else
        return buscar_min(nodo->obtener_izquierdo());
}


template <class T>
T BST<T>::buscar_max(BSTNode<T>* nodo)
{
    if(nodo == NULL)
        return NULL;
    else if(nodo->obtener_derecho() == NULL)
        return nodo->obtener_clave();
    else
        return buscar_max(nodo->obtener_derecho());
}


template <class T>
T BST<T>::siguiente(BSTNode<T>* nodo)
{
    if (nodo->obtener_derecho() != NULL)
    {
        return buscar_min(nodo->obtener_derecho());
    }
    BSTNode<T>* successor = NULL;
    BSTNode<T>* ancestor = this->root;
    while(ancestor != nodo) {
        if(nodo->obtener_clave() < ancestor->obtener_clave()) {
            successor = ancestor;
            ancestor = ancestor->obtener_izquierdo();
        }
        else
            ancestor = ancestor->obtener_derecho();
    }
    return successor->obtener_clave();
}

template <class T>
T BST<T>::siguiente(T data)
{
    BSTNode<T>* data_node = this->buscar(this->root, data);
    if(data_node == NULL)
         return NULL;
    else return siguiente(data_node);
}

template <class T>
T BST<T>::anterior(BSTNode<T> * nodo)
{
    if (nodo->obtener_izquierdo() != NULL)
    {
        return buscar_max(nodo->obtener_izquierdo());
    }

    BSTNode<T>* successor = NULL;
    BSTNode<T>* ancestor = this->root;
    while(ancestor != nodo) {
        if(nodo->obtener_clave() > ancestor->obtener_clave()) {
            successor = ancestor; // so far this is the deepest node for which current node is in left
            ancestor = ancestor->obtener_derecho();
        }
        else
            ancestor = ancestor->obtener_izquierdo();
    }
    return successor->obtener_clave();
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
BSTNode<T> * BST<T>::eliminar(BSTNode<T>* nodo, T data)
{
    // The given node is not found in BST
    if (nodo == NULL)
        return nodo;

    if (nodo->obtener_clave() == data)
    {
        if (nodo->es_hoja())
        {
            delete nodo->obtener_valor();
            delete nodo;
            nodo = NULL;
        }
        else if (nodo->hijo_derecho())
        {
            // The only child will be connected to the parent's of node directly
            nodo->obtener_derecho()->set_parent(nodo->obtener_padre());
            // Bypass node
            BSTNode<T>* aux = nodo;
            nodo = nodo->obtener_derecho();
            delete aux->obtener_valor();
            delete aux;
        }
        else if (nodo->hijo_izquierdo())
        {
            // The only child will be connected to the parent's of node directly
            nodo->obtener_izquierdo()->set_parent(nodo->obtener_padre());
            // Bypass node
            BSTNode<T>* aux = nodo;
            nodo = nodo->obtener_izquierdo();
            delete aux->obtener_valor();
            delete aux;
        }

        // The node has two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            T successor_data = this->siguiente(data);

            // Replace node's key with successor's key
            nodo->set_data(successor_data);

            // Delete the old successor's key
            nodo->set_right(eliminar(nodo->obtener_derecho(), successor_data));
        }
    }

    else if (nodo->obtener_clave() < data)
        nodo->set_right(eliminar(nodo->obtener_derecho(), data));

    else
        nodo->set_left(eliminar(nodo->obtener_izquierdo(), data));

    return nodo;
}

template <class T>
void BST<T>::eliminar(T data)
{
    this->root = eliminar(this->root, data);
}


template <class T>
void BST<T>::eliminar_todos(BSTNode<T>* nodo)
{
    if(nodo == NULL)
        return;
    this->eliminar_todos(nodo->obtener_izquierdo());
    this->eliminar_todos(nodo->obtener_derecho());
    delete nodo->obtener_valor();
    delete nodo;
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
