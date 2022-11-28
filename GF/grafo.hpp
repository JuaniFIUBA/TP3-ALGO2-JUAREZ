#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include "vertice.hpp"
#include "arista.hpp"
#include "vector.hpp"

class Grafo
{
    private:
        Vertice *raiz; //Arranque del mapa
        int capacidad; //Capacidad del mapa

    public:
        //Pre:-
        //Post: Construye un grafo
        Grafo();

        //Pre:-
        //Post: Retorna True si el grafo esta vacio
        bool ChequearVacio();

        //Pre:-
        //Post: Retorna el numero de vertices en el grafo
        int obtener_cantidad();

        //Pre:-
        //Post: Retorna el vertice
        Vertice* obtener_vertice(int posicion);

        //Pre:-
        //Post: Inserta un vertice al grafo 
        //Esto se puede mejorar - Lean
        void insertar_vertice(int posicion);

        //Pre:-
        //Post: Inserta la arista entre los dos vertices especificados
        void insertar_arista(int posicion_uno, int posicion_dos, int costo); 

        //Pre:-
        //Post: Muestra todos los vertices con sus costos.
        void mostrar_lista_adyacencia();

        //Pre:-
        //Post: Elimina el vertice:
        void eliminar_vertice(int posicion);

        //Pre:-
        //Post Elimina las aristas del vertice.
        void eliminar_aristas(Vertice* vertice);

        //Pre:-
        //Post Elimina las aristas que tienen como destino el vertice especificado.
        void eliminar_aristas_vertice(int posicion);

        //Pre:-
        //Post: Elimina la arista
        void eliminar_arista(int posicion_uno, int posicion_dos);

        //Pre:-
        //Post: Elimina todos los vertices y aristas del Grafo
        void eliminar_todo();

        //Pre:-
        //Post: Despliega las rutas más cortas entre los vertices
        void Dijkstra(int posicion_uno, int posicion_dos);
};

#endif

//Cuidado con la linea 85 de cpp