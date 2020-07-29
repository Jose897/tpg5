#include <iostream>
#include <windows.h>
#include "Grafo.h"

using namespace std;

int main()
{
    Grafo G;
    int opc;

    G.insertar_vertice("TIJ");
    G.insertar_vertice("MTY");
    G.insertar_vertice("MZT");
    G.insertar_vertice("BJX");
    G.insertar_vertice("GDL");
    G.insertar_vertice("SAN");
    G.insertar_vertice("TAM");
    G.insertar_vertice("MEX");
    G.insertar_vertice("CUN");
    G.insertar_vertice("MID");

    G.insertar_arista(G.obtener_vertice("TIJ"), G.obtener_vertice("MTY"), 800, 4);
    G.insertar_arista(G.obtener_vertice("MZT"), G.obtener_vertice("TIJ"), 400, 1);
    G.insertar_arista(G.obtener_vertice("MZT"), G.obtener_vertice("BJX"), 300, 3);
    G.insertar_arista(G.obtener_vertice("MTY"), G.obtener_vertice("BJX"), 700, 5);
    G.insertar_arista(G.obtener_vertice("BJX"), G.obtener_vertice("SAN"), 900, 4);
    G.insertar_arista(G.obtener_vertice("BJX"), G.obtener_vertice("TAM"), 400, 1);
    G.insertar_arista(G.obtener_vertice("BJX"), G.obtener_vertice("MEX"), 350, 9);
    G.insertar_arista(G.obtener_vertice("GDL"), G.obtener_vertice("MZT"), 500, 1.5);
    G.insertar_arista(G.obtener_vertice("GDL"), G.obtener_vertice("MTY"), 450, 2.3);
    G.insertar_arista(G.obtener_vertice("GDL"), G.obtener_vertice("BJX"), 250, 12);
    G.insertar_arista(G.obtener_vertice("GDL"), G.obtener_vertice("MEX"), 500, 3);
    G.insertar_arista(G.obtener_vertice("SAN"), G.obtener_vertice("MID"), 1200, 9.3);
    G.insertar_arista(G.obtener_vertice("TAM"), G.obtener_vertice("MID"), 450, 12);
    G.insertar_arista(G.obtener_vertice("MEX"), G.obtener_vertice("MID"), 450, 3);
    G.insertar_arista(G.obtener_vertice("MEX"), G.obtener_vertice("CUN"), 650, 4);
    G.insertar_arista(G.obtener_vertice("CUN"), G.obtener_vertice("GDL"), 650, 7);

    do
    {
        system("cls");
        cout<<"1. Ingresar Vertice"<<endl;
        cout<<"2. Ingresar arista"<<endl;
        cout<<"3. Lista de adyacencia"<<endl;
        cout<<"4. Tamaño"<<endl;
        cout<<"5. Eliminar vertice"<<endl;
        cout<<"6. Eliminar arista"<<endl;
        cout<<"7. Anular"<<endl;
        cout<<"8. Recorrido por peso costo"<<endl;
        cout<<"9. Recorrido por peso horas"<<endl;
        cout<<"10. Salir"<<endl;
        cout<<endl<<"Elija una opcion: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
        {
            string nombre;
            system("cls");
            cout<<"Ingrese el nombre del vertice: ";
            cin.ignore();
            getline(cin, nombre, '\n');
            G.insertar_vertice(nombre);
            cin.get();
            cin.get();
            break;
        }
        case 2:
        {
            string origen, destino;
            int costo;
            float horas;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese del nombre del vertice origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino, '\n');
                cout<<"Ingrese el costo: ";
                cin>>costo;
                cout<<"Ingrese las horas: ";
                cin>>horas;

                if(G.obtener_vertice(origen) == NULL || G.obtener_vertice(destino) == NULL)
                {
                    cout<<"Uno de los vertices no es valido"<<endl;
                }
                else
                {
                    G.insertar_arista(G.obtener_vertice(origen), G.obtener_vertice(destino), costo, horas);
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 3:
        {
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                G.lista_adyacentes();
            }
            cin.get();
            cin.get();
            break;
        }
        case 4:
        {
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Tamano: "<<G.tamanio()<<endl;
            }
            cin.get();
            cin.get();
            break;
        }
        case 5:
        {
            string nombre;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice a eliminar: ";
                cin.ignore();
                getline(cin, nombre, '\n');
                if(G.obtener_vertice(nombre) == NULL)
                {
                    cout<<"Vertice invalido"<<endl;
                }
                else
                {
                   G.eliminar_vertice(G.obtener_vertice(nombre));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 6:
        {
            string origen, destino;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese del nombre del vertice origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino, '\n');
                if(G.obtener_vertice(origen) == NULL || G.obtener_vertice(destino) == NULL)
                {
                    cout<<"Vertices no validos"<<endl;
                }
                else
                {
                    G.eliminar_arista(G.obtener_vertice(origen), G.obtener_vertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 7:
        {
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
               G.anular();
            }
            cin.get();
            cin.get();
            break;
        }
        case 8:
        {
            string nombre;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice inicial: ";
                cin.ignore();
                getline(cin, nombre, '\n');
                if(G.obtener_vertice(nombre) == NULL)
                {
                    cout<<"Ese vertice es invalido"<<endl;
                }
                else
                {
                    G.recorrido_ancho(G.obtener_vertice(nombre));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 9:
        {
            string nombre;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice inicial: ";
                cin.ignore();
                getline(cin, nombre, '\n');
                if(G.obtener_vertice(nombre) == NULL)
                {
                    cout<<"Ese vertice es invalido"<<endl;
                }
                else
                {
                    G.recorrido_profundidad(G.obtener_vertice(nombre));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 10:
        {
            break;
        }
        default:
        {
            cout<<"Elija una opcion valida"<<endl;
        }
        }
    }
    while(opc != 10);
    return 0;
}
