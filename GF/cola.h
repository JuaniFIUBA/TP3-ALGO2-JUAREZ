#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "nodo_cola.h"



class Cola {

private:
    Nodo* primero;
    Nodo* ultimo;

public:

    Cola();

    void alta(Dato d);

    void alta(int vertice, int costo);

    Dato consulta();

    Dato baja();

    void imprimir_cola();

    bool vacia();

    ~Cola();

};


#endif
