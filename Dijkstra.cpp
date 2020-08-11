/*
 * Dijkstra.cpp
 *
 *  Created on: 28 jul. 2020
 *      Author: Jose
 */

#include "Dijkstra.h"

Dijkstra::Dijkstra()
{
	g = 0;
	lista_prioridad = 0;
	lista_resultado = 0;
}

void Dijkstra::inicializar(Grafo*h, string origen, string destino)
{
	Vertice* aux;
	Lista<Vertice*>* lista_prioridad = new Lista<Vertice*>;
	Lista<Vertice*>* lista_resultado = new Lista<Vertice*>;
	int i;
	this->g = h;
	this->origen = origen;
	this->destino = destino;
	this->lista_prioridad = lista_prioridad;
	this->lista_resultado = lista_resultado;
	aux = g->obtener_primer_vertice();

	for( i = 1; i <= g->tamanio(); i++ )
	{
		aux->cambiar_visitado( false );
		aux->cambiar_predecesor( "-" );
		aux->cambiar_acumulador_costo( 0 );
		aux->cambiar_acumulador_duracion( 0 );
		aux = aux->obtener_siguiente();
	}
	aux = g->obtener_vertice( origen ); 
	lista_prioridad->insertar( aux );
}

Vertice* Dijkstra::obtener_minimo_costo_en_lista()
{
	Vertice* aux;
	unsigned i;
	long int menor;
	unsigned posicion;
	
	menor = lista_prioridad->obtener_dato(1)->obtener_acumulador_costo();
	posicion = 1;

	for( i = 1; i <= lista_prioridad->obtener_tamanio(); i++ )
	{
		aux = lista_prioridad->obtener_dato( i );
		if( aux->obtener_acumulador_costo() < menor )
		{
			menor = aux->obtener_acumulador_costo();
			posicion = i;
		}
	}

	aux = lista_prioridad->obtener_dato( posicion );
	lista_prioridad->borrar_dato( posicion );
	return aux;
}

Vertice* Dijkstra::obtener_minimo_duracion_en_lista()
{
	Vertice* aux;
	unsigned i;
	float menor;
	unsigned posicion;
	
	menor = lista_prioridad->obtener_dato( 1 )->obtener_acumulador_duracion();
	posicion = 1;
	for( i = 1; i <= lista_prioridad->obtener_tamanio(); i++ )
	{
		aux = lista_prioridad->obtener_dato( i );
		if( aux->obtener_acumulador_duracion() < menor )
		{
			menor = aux->obtener_acumulador_duracion();
			posicion = i;
		}
	}

	aux = lista_prioridad->obtener_dato( posicion );
	lista_prioridad->borrar_dato( posicion );
	return aux;
}

void Dijkstra::borrar_lista_resultado()
{
	unsigned i;
	unsigned tamanioLista;

	tamanioLista = lista_resultado->obtener_tamanio();

	for( i = 1; i <= tamanioLista; i++ )
	{
		lista_resultado->borrar_dato( 1 );
	}
}

void Dijkstra::guardar_secuencia_lista_resultado( Vertice* verticeB )
{
	Vertice* verticeAux;
	string predecesorAux;
	
	verticeAux = verticeB;
	if(verticeB->obtener_cod_vertice() == origen && verticeB->obtener_predecesor() == origen )
	{
		lista_resultado->insertar( verticeAux );
	}
	else
	{
		while( verticeAux->obtener_predecesor() != origen )
		{
			lista_resultado->insertar( verticeAux );
			predecesorAux = verticeAux->obtener_predecesor();
			verticeAux = g->obtener_vertice( predecesorAux );
		}	
		lista_resultado->insertar( verticeAux );
	}
	lista_resultado->insertar( g->obtener_vertice( origen ) );

}

void Dijkstra::evaluar_camino_costo( Vertice* verticeA, Vertice* verticeB )
{
	long int costoAB, costoB;

	costoAB = verticeA->obtener_acumulador_costo() + g->obtener_costo( verticeA, verticeB );
	costoB = verticeB->obtener_acumulador_costo();
	if( ( verticeB->obtener_cod_vertice() == destino ) && ( costoB  > costoAB ) )
	{
		borrar_lista_resultado();
	}
	if( ( costoB  == 0 ) && ( verticeB->obtener_cod_vertice() != destino ) )
	{
		lista_prioridad->insertar(verticeB);
	}	
	if( ( costoB >= costoAB ) || ( costoB == 0 ) )
	{
		verticeB->cambiar_acumulador_costo( costoAB );
		verticeB->cambiar_predecesor( verticeA->obtener_cod_vertice() );
		if( verticeB->obtener_cod_vertice() == destino )
		{
			guardar_secuencia_lista_resultado( verticeB );
		}
	}
}

void Dijkstra::evaluar_camino_duracion( Vertice* verticeA, Vertice* verticeB )
{
	float duracionAB, duracionB;

	duracionAB = verticeA->obtener_acumulador_duracion() + g->obtener_duracion( verticeA, verticeB );
	duracionB = verticeB->obtener_acumulador_duracion();
	if( ( verticeB->obtener_cod_vertice() == destino ) && ( duracionB > duracionAB ) )
	{
		borrar_lista_resultado();
	}
	if( ( duracionB == 0 ) && ( verticeB->obtener_cod_vertice() != destino ) )
	{
		lista_prioridad->insertar( verticeB );
	}
	if( ( duracionB >= duracionAB ) || ( duracionB == 0 ) )
	{
		verticeB->cambiar_acumulador_duracion( duracionAB );
		verticeB->cambiar_predecesor( verticeA->obtener_cod_vertice() );
		if( verticeB->obtener_cod_vertice() == destino )
		{
			guardar_secuencia_lista_resultado( verticeB );
		}
	}
}

void Dijkstra::procesar_camino_minimo( int parametro )
{
	int i;
	float duracionAB, duracionB;
	Vertice* verticeA;
	Vertice* verticeB;

	while( !lista_prioridad->lista_vacia() )
	{
		verticeA = obtener_minimo_costo_en_lista();
		verticeA->cambiar_visitado( true );
		for( i = 1; i <= verticeA->obtener_cant_ady(); i++ )
		{
			verticeB = verticeA->obtener_vertice_ady( i );
			if( !verticeB->obtener_visitado() || ( origen == destino) )
			{
				switch( parametro ){
					case 1 : evaluar_camino_costo( verticeA, verticeB ); break;
					case 2 : evaluar_camino_duracion( verticeA, verticeB ); break;
				}
			}	
		}
	}
}

Lista<Vertice*>* Dijkstra::obtener_lista_resultado()
{
	return lista_resultado;
}

void Dijkstra::concatenar_costo( string &cadena, Vertice* verticeA, Vertice* verticeB, long int* totalCosto, unsigned* i )
{
	long int costo; 
	ostringstream oc, ot;
	
	costo = g->obtener_costo( verticeA, verticeB );
	oc << costo;

	*totalCosto = *totalCosto + costo;
	cadena = cadena + " " + verticeA->obtener_cod_vertice() + " -->($ " + oc.str();
	if( verticeB->obtener_cod_vertice() == destino )
	{
		ot << *totalCosto;
		cadena = cadena + ")--> " + verticeB->obtener_cod_vertice() + "         total: $ " + ot.str() + "\n";
		(*i)++;
		*totalCosto = 0;
	}
	else
	{
		cadena = cadena + ")-->";
	}
}

void Dijkstra::concatenar_duracion( string &cadena, Vertice* verticeA, Vertice* verticeB, float* totalDuracion, unsigned* i )
{	
	float duracion;
	ostringstream od, ot;

	duracion = g->obtener_duracion( verticeA, verticeB );
	od << duracion;
	
	*totalDuracion = *totalDuracion + duracion;
	cadena = cadena + " " + verticeA->obtener_cod_vertice() + " -->(" + od.str();
	if( verticeB->obtener_cod_vertice() == destino )
	{
		ot << *totalDuracion;
		cadena = cadena + " hs)--> " + verticeB->obtener_cod_vertice() + "         total: " + ot.str() + " hs\n";
		(*i)++;
		*totalDuracion = 0;
	}
	else
	{
		cadena = cadena + " hs)-->";
	}

}


string Dijkstra::impresion_camino_minimo( int parametro )
{
	unsigned i = 1;
	Vertice* verticeA;
       	Vertice* verticeB;
	string cadena = "";
	long int totalCosto = 0;
	float totalDuracion = 0;

	if( !lista_resultado->lista_vacia() )
	{
		while( i < lista_resultado->obtener_tamanio() )
		{
			verticeA = lista_resultado->obtener_dato( i );
			verticeB = lista_resultado->obtener_dato( i + 1 );
			switch( parametro )
			{
				case 1 : concatenar_costo( cadena, verticeA, verticeB, &totalCosto, &i ); break;
				case 2 : concatenar_duracion( cadena, verticeA, verticeB, &totalDuracion, &i ); break;
			}	
			i++;
		}
	}
	else
	{
		cadena = "No hay ruta \n";
	}
	return cadena;
}


Dijkstra::~Dijkstra()
{
	delete lista_prioridad;
	delete lista_resultado;
}
