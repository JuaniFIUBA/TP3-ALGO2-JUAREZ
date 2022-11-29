#include "nodo_cola.h"

Nodo::Nodo(Dato d) {
    dato = d;
    siguiente = 0;
}

void Nodo::cambiar_siguiente(Nodo* pn) {
    siguiente = pn;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}

Dato Nodo::obtener_dato() {
    return dato;
}
