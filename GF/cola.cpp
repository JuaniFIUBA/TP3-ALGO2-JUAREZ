#include "cola.h"



Cola::Cola() {
    primero = 0;
    ultimo = 0;
}

void Cola::alta(Dato d) {
    Nodo* nuevo = new Nodo(d);
    if (vacia()) {
        primero = nuevo;
    }
    else {
        ultimo->cambiar_siguiente(nuevo);
    }
    ultimo = nuevo;
}

void Cola::alta(int vertice, int costo) {
    Dato d;
    d.vertice_actual = vertice;
    d.costo_camino = costo;
    Nodo* nuevo = new Nodo(d);
    if (vacia()) {
        primero = nuevo;
    }
    else {
        ultimo->cambiar_siguiente(nuevo);
    }
    ultimo = nuevo;
}

Dato Cola::consulta() {
    return (primero->obtener_dato());
}

Dato Cola::baja() {
    Nodo* auxiliar = primero;
    Dato devolver = auxiliar->obtener_dato();
    primero = auxiliar->obtener_siguiente();
    if (! primero)
        ultimo = 0;
    delete auxiliar;
    return devolver;
}

bool Cola::vacia() {
    return (primero == 0);
}

Cola::~Cola() {
    while (! vacia())
        baja();
}


