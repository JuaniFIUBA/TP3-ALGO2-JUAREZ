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

void Cola::ordenar_prioridad(){
    Nodo *aux1, *aux2;
    int vAux;
    int cAux;

    aux1 = primero;

    while(aux1->obtener_siguiente() != nullptr){
        aux2 = aux1->obtener_siguiente();

        while(aux2 != nullptr){
            if(aux1->obtener_dato().costo_camino > aux2->obtener_dato().costo_camino){
                vAux = aux1->obtener_dato().vertice_actual;
                cAux = aux1->obtener_dato().costo_camino;

                aux1->modificar_dato(aux2->obtener_dato().vertice_actual, aux2->obtener_dato().costo_camino);

                aux2->modificar_dato(vAux, cAux);
            }
            aux2 = aux2->obtener_siguiente();
        }
        aux1 = aux1->obtener_siguiente();
    }
}

void Cola::insertar(int vertice, int costo){
    alta(vertice, costo);
    ordenar_prioridad();
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


