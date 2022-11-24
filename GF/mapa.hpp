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
        void unir_casilleros(int fila, int columna);

        void editar_mapa();
        void mostrar_mapa();
        void generar_mapa();
};

#endif