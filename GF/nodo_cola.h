#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED



struct Dato{
    int vertice_actual;
    int costo_camino;
};

class Nodo {
private:
    Nodo* siguiente;
    Dato dato;

public:
    Nodo(Dato d);

    void cambiar_siguiente(Nodo* pn);

    Dato obtener_dato();

    void modificar_dato(int vertice, int costo);

    Nodo* obtener_siguiente();
};

#endif
