#ifndef MAPA_HPP
#define MAPA_HPP
#include "grafo.hpp"


class Mapa
{
    private:
        Grafo grafo;
        
    public:
        //Pre: Recibe la cantidad de filas y columnas
        //Pro: Une los vertices para crear casilleros para un mapa de fila x columna.Tiene que ser matriz cuadrada.
        void crear_casilleros(int fila, int columna);

        //Pre: Recibe la cantidad de filas y columnas
        //Pro: Une los vertices para crear casilleros para un mapa de fila x columna.Tiene que ser matriz cuadrada.
        void unir_casilleros();  

        //Pre:-
        //Post: Modifica el mapa en pantalla
        void editar_mapa();

        //Pre:-
        //Post: Muestra el mapa en pantalla
        void mostrar_mapa();

        //Pre:-
        //Post: Calcula el camino minimo a recorrer de origen a destino.
        void camino_minimo();

        //Pre: Usar camino_minimo
        //Post: Muestra en pantalla el recorrido hecho
        void mostrar_recorrido();

        //Pre:-
        //Post: Transforma las coordenadas recibidas en posición del vertice.
        int traducir_coordenadas(int x, int y);

        //Pre:-
        //Post: Descompone la posicion del vertice en coordenadasa X e Y.
        int traducir_posicion(int posicion);
};

#endif