#ifndef TPG5_MENU_H
#define TPG5_MENU_H
#include<iostream>

using namespace std;

class Menu{

private:
    bool salir = false;

public:

    void mostrar_menu();
    bool opcion_valida(int entrada);
    void procesar_opcion(int opcion);
    void procesar_opcion_uno();         //Se le debe pasar un puntero al arbol
    void procesar_opcion_dos();         //Se le debe pasar un puntero al arbol
    void procesar_opcion_tres();        //Se le debe pasar un puntero al arbol
    void procesar_opcion_cuatro();      //Se le debe pasar un puntero al arbol
};

#endif //TPG5_MENU_H
