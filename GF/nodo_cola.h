#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED



struct Dato{
    int vertice_actual;
    int costo_camino;
};

class Nodo {
private:
    Dato dato;
    Nodo* siguiente;

public:
    Nodo(Dato d);

    void cambiar_siguiente(Nodo* pn);

    Dato obtener_dato();

    Nodo* obtener_siguiente();
};

#endif
