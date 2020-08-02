#include "Menu.h"
//borrar - prueba
#include "Vertice.h"i
#include "Dijkstra.h"

Menu::Menu(BST<string>* &diccionario,Grafo*h){
    this->diccionario = diccionario;
    this->h = h;
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
	cout << endl;
        cout << "->Vuelos:" << endl;
        cout << "6. Vuelo minimo por costo" << endl;
        cout << "7. Vuelo minimo por duracion" << endl;
	cout << endl;
        cout << "0. Salir" << endl;
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
    return !(entrada < 0 || entrada > 7);
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
    diccionario->print_ancho();
}

void Menu::procesar_opcion_seis(){
	string origen, destino;

	if(h->vacio()){
		cout<<"El grafo esta vacio"<<endl;
	}else{
		cout<<"Ingrese origen"<<endl;
		cin.ignore();
		getline(cin, origen, "\n");
		cout<<"Ingrese destino"<<endl;
		getline(cin, destino, "\n");

		if( h->obtener_vertice(origen)==NULL || h->obtener_vertice(destino) ){
			cout<<"Uno de los vertices no es valido"<<endl;
		
		}else{   //camino minimo costo
			Dijkstra dijkstra;
			dijkstra.inicializar(h, origen, destino);
			dijkstra.procesar();
		}
	}
}

void Menu::procesar_opcion_siete(){
	cout<<" proceso 7 \n";
	Vertice* vertice;
	
	vertice = h->obtener_vertice("EZE");
	cout<<" EZE : "<<vertice->obtener_cod_vertice()<<endl;
	
	vertice=h->obtener_vertice("MIA");
	cout<<" EZE : "<<vertice->obtener_cod_vertice()<<endl;
	
	vertice=h->obtener_vertice("FCO");
	cout<<" EZE : "<<vertice->obtener_cod_vertice()<<endl;

	vertice=h->obtener_vertice("TXL");
	cout<<" EZE : "<<vertice->obtener_cod_vertice()<<endl;

}


void Menu::procesar_opcion(int opcion){

    switch(opcion){
	case 0:
            cout << endl << "Gracias por utilizar el programa. Hasta luego." << endl;
            salir = true;
            break;
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
            procesar_opcion_seis();
            break;
        case 7:
            procesar_opcion_siete();
            break;
    }
}
