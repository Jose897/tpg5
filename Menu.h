#ifndef TPG5_MENU_H
#define TPG5_MENU_H
#include "ABB.h"
//#include "Dijkstra"
#include "Grafo.h"
#include<iostream>

using namespace std;

class Grafo;

class Menu{

private:
    bool salir = false;
    BST<string>* diccionario;
    Grafo * G;

public:
    Menu(BST<string>* &diccionario, Grafo * _G);
    void mostrar_menu();
    bool opcion_valida(int entrada);
    void procesar_opcion(int opcion);   //Se le debe pasar un puntero al arbol
    void procesar_opcion_uno();         //Se le debe pasar un puntero al arbol
    void procesar_opcion_dos();         //Se le debe pasar un puntero al arbol
    void procesar_opcion_tres();        //Se le debe pasar un puntero al arbol
    void procesar_opcion_cuatro();      //Se le debe pasar un puntero al arbol
    void procesar_opcion_cinco();
    void procesar_opcion_seis();
    void procesar_opcion_siete();      //Se le debe pasar un puntero al arbol
};

#endif //TPG5_MENU_H
