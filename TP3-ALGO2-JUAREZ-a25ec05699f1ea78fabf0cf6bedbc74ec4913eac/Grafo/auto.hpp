#ifndef AUTO_HPP
#define AUTO_HPP
#include <iostream>

class Auto
{
private:
    int posicion;
    int combustible;
    char identificador;

    friend class Terreno;

public:
    Auto();

    // Pre:-
    // Post: carga el combustible ingresado por el usuario
    void cargar_combustible();

    // Pre:-
    // Post: Aumenta el combustible ingresado.
    void recarga_automatica();

    // Pre:-
    // Post: Reduce el combustible debido al costo del desplazamiento
    void restar_combustible(int costo);

    // Pre:-
    // Post: Devuelve la posicion del auto
    int obtener_posicion();

    // Pre:-
    // Post: Actualiza la ubicacion del auto
    void cambiar_posicion(int posicion);

    // Pre:-
    // Post: Devuelve el combustible actual.
    int obtener_combustible();

    // Pre:-
    // Post: Revisa el combustible.
    bool queda_combustible();

private:
    // Pre:-
    // Post: valida que la opcion ingresada se encuentre dentro del rango indicado.
    int validar_opcion(int min, int max);

};

#endif