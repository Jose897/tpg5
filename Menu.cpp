#include "Menu.h"
//borrar - prueba


Menu::Menu(BST<string>* &diccionario,Grafo*h){
    this->diccionario = diccionario;
    this->h = h;
    this->salir = false;
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
        cout << "Ingrese su opcion: " << endl << flush;
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
    if (diccionario->buscar(iata) == 1){
        diccionario->mostrar_elemento(iata);
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
    diccionario->insertar(iata, aero);
}

void Menu::procesar_opcion_tres(){
    string iata;
    cout << "Ingrese el codigo IATA del aeropuerto que desea eliminar:";
    cin >> iata;
    if(diccionario->buscar(iata) == 1){
        diccionario->eliminar(iata);
        cout << iata << " fue eliminado con exito." << endl;
    }
    else{
        cout << iata << " no se pudo eliminar ya que no se encuentra en la base de datos." << endl;
    }
}

void Menu::procesar_opcion_cuatro(){
    diccionario->imprimir_en_orden();
}
void Menu::procesar_opcion_cinco(){
    diccionario->imprimir_ancho();
}

void Menu::procesar_opcion_seis(){
	long int total=0;
	string origen, destino;

	if(h->vacio()){
		cout<<"El grafo esta vacio"<<endl;
	}else{
		cout<<"Ingrese origen"<<endl;
		cin>>origen;
		cout<<endl;
		cout<<"Ingrese destino"<<endl;
		cin>>destino;
		cout<<endl;

		if( h->obtener_vertice(origen) == NULL || h->obtener_vertice(destino) == NULL ){
			cout<<"Uno de los vertices no es valido"<<endl;
		
		}else{   //camino minimo costo
			Dijkstra dijkstra;
			dijkstra.inicializar(h, origen, destino);
			dijkstra.procesar_camino_minimo_por_costo();
			Lista<Vertice*>* lista = dijkstra.obtener_lista_resultado();
			Vertice* verticeA;
			Vertice* verticeB;
			
			if(!lista->lista_vacia()){	
				unsigned i=1; 
				while( i < lista->obtener_tamanio() ){
					verticeA = lista->obtener_dato(i);
					verticeB = lista->obtener_dato(i+1);
					cout<<" "<<verticeA->obtener_cod_vertice();
					total = total + h->obtener_costo(verticeA,verticeB);
					cout<<" -->($ "<<h->obtener_costo(verticeA,verticeB);
					
					if(verticeB->obtener_cod_vertice() == destino ){
						cout<<")--> "<<verticeB->obtener_cod_vertice()<<"      total :$ "<<total<<endl;
						i++;
						total=0;
					}else{
						cout<<")->";
					}
					i++;
				}
			}else{
				cout<<"No hay ruta"<<endl;
			}
		}
	}
}

void Menu::procesar_opcion_siete(){
	float total=0;
	string origen, destino;

	if(h->vacio()){
		cout<<"El grafo esta vacio"<<endl;
	}else{
		cout<<"Ingrese origen"<<endl;
		cin>>origen;
		cout<<endl;
		cout<<"Ingrese destino"<<endl;
		cin>>destino;
		cout<<endl;

		if( h->obtener_vertice(origen) == NULL || h->obtener_vertice(destino) == NULL ){
			cout<<"Uno de los vertices no es valido"<<endl;
		
		}else{   //camino minimo duracion
			Dijkstra dijkstra;
			dijkstra.inicializar(h, origen, destino);
			dijkstra.procesar_camino_minimo_por_duracion();
			Lista<Vertice*>* lista = dijkstra.obtener_lista_resultado();
			Vertice* verticeA;
			Vertice* verticeB;
			
			if(!lista->lista_vacia()){	
				unsigned i=1;
				while( i < lista->obtener_tamanio() ){
					verticeA = lista->obtener_dato(i);
					verticeB = lista->obtener_dato(i+1);
					cout<<" "<<verticeA->obtener_cod_vertice();
					total = total + h->obtener_duracion(verticeA,verticeB);
					cout<<" -->("<<h->obtener_duracion(verticeA,verticeB);
					if(verticeB->obtener_cod_vertice() == destino ){
						cout<<"hs)--> "<<verticeB->obtener_cod_vertice()<<"      total : "<<total<<" hs"<<endl;
						i++;
						total = 0;
					}else{
						cout<<"hs)->";
					}
					i++;
				}
			}else{
				cout<<"No hay ruta"<<endl;
			}
		}
	}

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
