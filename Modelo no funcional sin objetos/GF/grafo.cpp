#include "grafo.hpp"

Grafo::Grafo()
{
    raiz = nullptr;
    capacidad = 0;

}

bool Grafo::ChequearVacio()
{
    return capacidad == 0;
}

int Grafo::obtener_cantidad()
{
    return capacidad;
}

Vertice* Grafo::obtener_vertice(int posicion)
{
    Vertice* puntero_soporte = raiz; //Puntero Auxiliar a la raiz.
    while (puntero_soporte != nullptr)
    {
        if (puntero_soporte->posicion == posicion){
            return puntero_soporte;
        }
    }

    return nullptr;
}

void Grafo::insertar_vertice(int posicion)
{
    if (obtener_vertice(posicion) == nullptr) //Verifica si existe el vertice
    {
        Vertice* nuevo = new Vertice(posicion);

        if (ChequearVacio())
        {
            raiz = nuevo;
        }
        else{
            Vertice* i = raiz;

            while (i->sig != nullptr)
            {
                i->sig = nuevo;
            }

        }
        capacidad++;
    }
    else{
        std::cout << "Ese vertice ya existe en el grafo" <<std::endl;
    }
}

void Grafo::insertar_arista(int posicion_uno, int posicion_dos, int costo)
{
    Vertice* vertice_uno = obtener_vertice(posicion_uno);
    Vertice* vertice_dos = obtener_vertice(posicion_dos);

    if (vertice_uno == nullptr)
    {
        std::cout<<"El vertice uno, no existe"<<std::endl;
    }
    
    if (vertice_dos == nullptr)
    {
        std::cout<<"El vertice dos, no existe"<<std::endl;
    }

    if(vertice_uno != nullptr && vertice_dos != nullptr)
    {
        Arista* nueva = new Arista(vertice_dos, costo);

        if (vertice_uno == nullptr)
        {
            vertice_uno->ady = nueva;
        }
        else{
            Arista* puntero_soporte = vertice_uno->ady;

            while (puntero_soporte->sig != nullptr)
            {
                puntero_soporte = puntero_soporte->sig;
            }
            
            puntero_soporte->sig = nueva;

        }
    }

}

