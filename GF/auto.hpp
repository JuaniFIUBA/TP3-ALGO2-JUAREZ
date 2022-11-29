#ifndef AUTO_HPP
#define AUTO_HPP

struct coor{
    int col;
    int fil;
};

class Auto{
private:
    coor posicion;
    int combustible;
    char identificador;
    void mover_izquierda();
    void mover_derecha();
    void mover_arriba();
    void mover_abajo();
    friend class Terreno;
public:
    Auto();
    void recargar_combustible(); //Aumenta +5 de combustible.
    void restar_combustible(int costo);
    coor obtener_posicion();
    int obtener_combustible();
};

#endif