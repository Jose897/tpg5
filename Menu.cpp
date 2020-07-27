#include "Menu.h"

Menu::Menu(BST<string>* &diccionario){
    this->diccionario = diccionario;
}

void Menu::mostrar_menu(){
    int opcion;
    while (!salir) {
        cout << endl;
        cout << "================================== MENU ==================================" << endl;
        cout << "1. Consultar un aeropuerto" << endl;
        cout << "2. Agregar aueropuerto" << endl;
        cout << "3. Eliminar un aeropuerto" << endl;
        cout << "4. Mostrar todos los aeropuertos" << endl;
        cout << "5. Mostrar arbol a lo ancho" << endl;
        cout << "6. Salir" << endl;
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
    return !(entrada < 1 || entrada > 6);
}

void Menu::procesar_opcion_uno(){
    string iata;
    cout << "Ingrese el codigo IATA del Aeropuerto:";
    cin >> iata;
    if (diccionario->search(iata) == 1){
        diccionario->obtener_valor(iata);
    }
    else{
        cout << iata << " no se encuentra en la base de datos" << endl;
    }
}

void Menu::procesar_opcion_dos(){
    string iata, nombre, ciudad, pais;
    float superficie;
    int terminales, nacionales, internacionales;
    cout << "Ingrese IATA: " << endl;
    cin >> iata;
    cout << "Ingrese nombre: " << endl;
    cin >> nombre;
    cout << "Ingrese ciudad: " << endl;
    cin >> ciudad;
    cout << "Ingrese pais: " << endl;
    cin >> pais;
    cout << "Ingrese superficie: " << endl;
    cin >> superficie;
    cout << "Ingrese terminales: " << endl;
    cin >> terminales;
    cout << "Ingrese destinos nacionales: " << endl;
    cin >> nacionales;
    cout << "Ingrese destinos internacionales: " << endl;
    cin >> internacionales;
    Aeropuertos *aero = new Aeropuertos(nombre, ciudad, pais, superficie, terminales, nacionales, internacionales);
    diccionario->insert(iata, aero);
}

void Menu::procesar_opcion_tres(){
    string iata;
    cout << "Ingrese el codigo IATA del aeropuerto que desea eliminar:";
    cin >> iata;
    if(diccionario->search(iata) == 1){
        diccionario->remove(iata);
        cout << iata << " fue eliminado con exito." << endl;
    }
    else{
        cout << iata << " no se pudo eliminar ya que no se encuentra en la base de datos." << endl;
    }
}

void Menu::procesar_opcion_cuatro(){
    diccionario->print_in_order();
}
void Menu::procesar_opcion_cinco(){
}
void Menu::procesar_opcion(int opcion){

    switch(opcion){
        case 1:
            procesar_opcion_uno();
            break;
        case 2:
            procesar_opcion_dos();
            break;
        case 3:
            procesar_opcion_tres();
            break;
        case 4:
            procesar_opcion_cuatro();
            break;
        case 5:
            procesar_opcion_cinco();
            break;
        case 6:
            cout << endl << "Gracias por utilizar el programa. Hasta luego." << endl;
            salir = true;
            break;
    }
}
