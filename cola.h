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

    Dato consulta();

    Dato baja();

    bool vacia();

    ~Cola();

};


#endif
