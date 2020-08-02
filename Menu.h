#ifndef TPG5_MENU_H
#define TPG5_MENU_H
#include "ABB.h"
#include "Dijkstra.h"
#include "Grafo.h"
#include<iostream>

using namespace std;

class Menu{

private:
    bool salir = false;
    BST<string>* diccionario;
    Grafo*h;

public:
    Menu(BST<string>* &diccionario,Grafo*h);
    void mostrar_menu();
    bool opcion_valida(int entrada);
    void procesar_opcion(int opcion);   //Se le debe pasar un puntero al arbol
    void procesar_opcion_uno();         //Se le debe pasar un puntero al arbol
    void procesar_opcion_dos();         //Se le debe pasar un puntero al arbol
    void procesar_opcion_tres();        //Se le debe pasar un puntero al arbol
    void procesar_opcion_cuatro();      //Se le debe pasar un puntero al arbol
    void procesar_opcion_cinco();      //Se le debe pasar un puntero al arbol
    void procesar_opcion_seis();      //Se le debe pasar un puntero al arbol
    void procesar_opcion_siete();      //Se le debe pasar un puntero al arbol
};

#endif //TPG5_MENU_H
