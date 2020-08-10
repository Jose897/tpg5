#ifndef TPG5_MENU_H
#define TPG5_MENU_H

#include "ABB.h"
#include "Dijkstra.h"
#include "Grafo.h"
#include<iostream>

using namespace std;

class Menu{
    private:
        bool salir;
        BST<string>* diccionario;
        Grafo*h;
    public:
        // Constructor
        // PRE: -
        // POST: Crea el objeto Menu
        Menu(BST<string>* diccionario,Grafo*h);
        // Muestra el menu con las opciones disponibles para elegir
        // PRE: -
        // POST: -
        void mostrar_menu();
        // PRE: La opcion debe ser un entero
        // POST: Devuelve true si la opcion es mayor o igual a 0 y menor o igual a 7
        bool opcion_valida(int entrada);
        // PRE: La opcion debe ser un entero
        // POST: -
        void procesar_opcion(int opcion);
        // Se encarga de la opcion 1 del menu
        // PRE: -
        // POST: -
        void procesar_opcion_uno();
        // Se encarga de limpiar la pantalla luego de elegir la opcion
        // PRE: -
        // POST: -
        void limpiar_pantalla();
        // Se encarga de la opcion 2 del menu
        // PRE: -
        // POST: -
        void procesar_opcion_dos();
        // Se encarga de la opcion 3 del menu
        // PRE: -
        // POST: -
        void procesar_opcion_tres();
        // Se encarga de la opcion 4 del menu
        // PRE: -
        // POST: -
        void procesar_opcion_cuatro();
        // Se encarga de la opcion 5 del menu
        // PRE: -
        // POST: -
        void procesar_opcion_cinco();
        //
        //PRE: pasar dos string por parametro
        //POST: valida datos ingresados
        bool pedir_datos_validos( string*, string* );
        // Se encarga de la opcion 6 del menu
        // PRE: -
        // POST: -
        void procesar_opcion_seis();
        // Se encarga de la opcion 7 del menu
        // PRE: -
        // POST: -
        void procesar_opcion_siete();
	//
	//
	//
	void pausa_pantalla();
};

#endif //TPG5_MENU_H
