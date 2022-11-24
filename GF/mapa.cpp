#include "mapa.hpp"

void Mapa::crear_casilleros(int fila, int columna)
{
    int posicion = 0;

    for(int i = 0; i < fila; i++)
    {
        for(int j = 0; j < columna; j++)
        {
             grafo.insertar_vertice(posicion);
             posicion++;
        }
    }
}

void Mapa::unir_casilleros(int fila, int columna)
{
    for()
    grafo.insertar_arista(int posicion_uno, int posicion_dos, int costo);
}