#include "Menu.h"
class Dijkstra;

Menu::Menu(BST<string>* diccionario,Grafo*h)
{
    this->diccionario = diccionario;
    this->h = h;
    this->salir = false;
}

void Menu::mostrar_menu()
{
    int opcion;
    while (!salir)
    {
        cout << endl;
        cout << "================================== MENU ==================================" << endl;
        cout << "1. Consultar un aeropuerto" << endl;
        cout << "2. Agregar aueropuerto" << endl;
        cout << "3. Eliminar un aeropuerto" << endl;
        cout << "4. Mostrar todos los aeropuertos" << endl;
        cout << "5. Mostrar arbol a lo ancho" << endl << endl;
        cout << "->Vuelos:" << endl;
        cout << "6. Vuelo minimo por costo" << endl;
        cout << "7. Vuelo minimo por duracion" << endl << endl;
        cout << "0. Salir" << endl << endl;
        cout << "Ingrese su opcion: " << endl << flush;
        do
        {
            cin >> opcion;
            if (cin.good() && opcion_valida(opcion))
            {
                limpiar_pantalla();
                procesar_opcion(opcion);
            }
            else
            {
                cin.clear();
                cin.ignore();
                cout << "Por favor ingrese una opcion valida: " << endl;
            }
        }while (!opcion_valida(opcion));
    }

}

void Menu::limpiar_pantalla(){
#ifdef WINDOWS
    system("cls");
#else // Assume POSIX
    system ("clear");
#endif
}

bool Menu::opcion_valida(int entrada)
{
    return !(entrada < 0 || entrada > 7);
}

void Menu::procesar_opcion_uno()
{
    string iata;
    cout << "Ingrese el codigo IATA del Aeropuerto:";
    cin >> iata;

    if (diccionario->buscar(iata) == 1)
    {
        diccionario->mostrar_elemento(iata);
    }
    else
    {
        cout << iata << " no se encuentra en la base de datos" << endl;
    }
}

void Menu::procesar_opcion_dos()
{
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

void Menu::procesar_opcion_tres()
{
    if (diccionario->vacio()){
        cout<<"El diccionario esta vacio"<<endl;
    }
    else{
        string iata;
        cout << "Ingrese el codigo IATA del aeropuerto que desea eliminar:";
        cin >> iata;
        if(diccionario->buscar(iata) == 1)
        {
            diccionario->eliminar(iata);
            cout << iata << " fue eliminado con exito." << endl;
        }
        else
        {
            cout << iata << " no se pudo eliminar ya que no se encuentra en la base de datos." << endl;
        }
    }
}

void Menu::procesar_opcion_cuatro()
{
    if (diccionario->vacio()){
        cout<<"El diccionario esta vacio"<<endl;
    }
    else{
        diccionario->imprimir_en_orden();
    }
}

void Menu::procesar_opcion_cinco()
{
    if (diccionario->vacio()){
        cout<<"El diccionario esta vacio"<<endl;
    }
    else{
        diccionario->imprimir_ancho();
    }
}

bool Menu::pedir_datos_validos( string* origen, string* destino )
{
	bool valido = false;

	if(h->vacio())
	{
		cout<<"El grafo esta vacio"<<endl;
		valido = false;
	}
	else
	{
		cout<<"Ingrese origen: ";
		cin>>*origen;
		cout<<endl;
		cout<<"Ingrese destino: ";
		cin>>*destino;
		cout<<endl;

		if( h->obtener_vertice(*origen) == NULL || h->obtener_vertice(*destino) == NULL )
		{
			cout<<"Uno de los vertices no es valido"<<endl;
			valido = false;

		}
		else
		{
			valido = true;
		}
	}
	return valido;
}

void Menu::procesar_opcion_seis()
{
	string origen, destino;
	string cadena;
	Dijkstra dijkstra;

	if( pedir_datos_validos( &origen, &destino ) )
	{
		dijkstra.inicializar( h, origen, destino );
		dijkstra.procesar_camino_minimo( 1 );
		cadena = dijkstra.impresion_camino_minimo( 1 );
		cout<<cadena;
	}
}

void Menu::procesar_opcion_siete()
{
	string origen, destino;
	string cadena;
	Dijkstra dijkstra;

	if( pedir_datos_validos( &origen, &destino ) )
	{
		dijkstra.inicializar( h, origen, destino );
		dijkstra.procesar_camino_minimo( 2 );
		cadena = dijkstra.impresion_camino_minimo( 2 );
		cout<<cadena;
	}
}

void Menu::procesar_opcion(int opcion)
{
    switch(opcion)
    {
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
