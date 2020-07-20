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
};

#endif //TPG5_MENU_H
