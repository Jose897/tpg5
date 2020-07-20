#include "Menu.h"

void Menu::mostrar_menu() {
    int opcion;
    while (!salir) {
        cout << "1.Consultar un aeropuerto" << endl;
        cout << "2. Agregar aueropuerto " << endl;
        cout << "3. Eliminar un aeropuerto" << endl;
        cout << "4. Mostrar todos los aeropuertos" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese su opcion " << endl << flush;
        do {
            cin >> opcion;
            if (cin.good() && opcion_valida(opcion)) {
                procesar_opcion(opcion);
            } else {
                cin.clear();
                cin.ignore();
                cout << "Por favor ingrese una opcion valida: " << endl;
            }
        }while (!opcion_valida(opcion));
    }
}

bool Menu::opcion_valida(int entrada){
    return !(entrada < 1 || entrada > 5);
}

void Menu::procesar_opcion(int opcion){

    switch(opcion){
        case 1:  break;
        case 2:  break;
        case 3:  break;
        case 4: break;
        case 5:
            cout << endl << "Gracias por utilizar el programa. Hasta luego." << endl;
            salir = true;
            break;
    }
}