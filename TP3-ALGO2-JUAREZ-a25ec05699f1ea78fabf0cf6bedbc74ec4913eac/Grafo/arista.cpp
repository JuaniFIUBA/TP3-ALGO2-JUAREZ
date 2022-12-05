#include "arista.hpp"
#include <iostream>

Arista::Arista(Vertice* dest, int costo)
{
    this->dest = dest;
    this->costo = costo;
    sig = NULL;
    dest = NULL;

}