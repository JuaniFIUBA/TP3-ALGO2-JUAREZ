#ifndef AUTO_HPP
#define AUTO_HPP

class Auto{
private:
    int posicion;
    int combustible;
    char identificador;

    friend class Terreno;

public:
    Auto();
    
    //Pre:-
    //Post: Aumenta +5 de combustible
    void recargar_combustible();

    //Pre:-
    //Post: Reduce el combustible debido al costo del desplazamiento
    void restar_combustible(int costo);

    //Pre:-
    //Post: Devuelve la posicion del auto
    int obtener_posicion();

    //Pre:-
    //Post: Actualiza la ubicacion del auto
    void cambiar_posicion(int posicion);

    //Pre:-
    //Post: Devuelve el combustible actual.
    int obtener_combustible();

    //Pre:-
    //Post: Revisa el combustible.
    bool queda_combustible();

};

#endif