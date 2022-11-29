#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef char Dato;

class Nodo {
    // Atributos
private:
    Dato dato;
    Nodo* siguiente;

public:
    // Constructor
    // crea un nodo con dato = d y siguiente = 0
    Nodo(Dato d);

    void cambiar_siguiente(Nodo* pn);

    Dato obtener_dato();

    Nodo* obtener_siguiente();
};

#endif
