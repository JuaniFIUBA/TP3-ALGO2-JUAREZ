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

void Grafo::mostrar_lista_adyacencia()
{
    Vertice* i = raiz;

    while (i != nullptr)
    {
        Arista* j =i->ady;

        while (j != nullptr)
        {
            std::cout<<"["<<i->posicion<<" -> "<<j->costo<<" -> "<<j->dest->posicion<<"]"<<std::endl;
            j = j->sig;
        }

        std::cout<<std::endl;
        i = i->sig;
    }
}

void Grafo::eliminar_arista(Vertice* vertice)
{
    if(vertice != nullptr)
    {
        Arista* i = vertice->ady;

        while (vertice->ady != NULL)
        {
            i = vertice->ady;
            vertice->ady = vertice->ady->sig;
            std::cout<<"La arista ["<<vertice->posicion<<"] ha sido borrada"<<std::endl;
            delete(i);
        }
    }
}

void Grafo::eliminar_vertice(int posicion)
{
    if(raiz->posicion == posicion)
    {
        Vertice *auxiliar = raiz;
        raiz = raiz->sig;
        eliminar_arista(auxiliar);
        eliminar_aristas_vertice(auxiliar->posicion);
        std::cout<<"El vertice ["<<auxiliar->posicion<<"] ha sido borrada"<<std::endl;
        delete(auxiliar);
        capacidad--;
    
    } else{
        
        Vertice* anterior = raiz;
        Vertice* actual = anterior->sig;
        bool encontrado = false;

        while (actual != NULL && encontrado == false)
        {
            if (actual->posicion == posicion)
            {
                eliminar_arista(actual);
                eliminar_aristas_vertice(actual->posicion);
                anterior->sig = actual->sig;
                std::cout<<"El vertice ["<<actual->posicion<<"] ha sido borrada"<<std::endl;
                capacidad--;
                encontrado = true;
            }

            if(encontrado == false){
                anterior = actual;
                actual = actual->sig; 
            }
        }
        if (encontrado == true)
        {
            std::cout<<"El vertice no fue encontrado"<<std::endl;
        }

    }

}

void Grafo::eliminar_aristas_vertice(int posicion)
{
    Vertice* puntero = raiz;

    while (puntero != nullptr)
    {
        if (puntero->posicion == posicion)
        {
            continue;
        }

        if (puntero->sig->posicion == posicion)
        {
            Arista* auxiliar = puntero->ady;
            puntero->ady = puntero->ady->sig;
            std::cout<<"La arista "<<puntero->posicion<<" "<<auxiliar->dest->posicion<<" fue eliminada "<<std::endl;
            delete(auxiliar);

        }
        else{

            Arista* puntero_siguiente = puntero->ady;
            Arista* siguiente_siguiente = puntero_siguiente->sig;

            while (siguiente_siguiente != nullptr)
            {
                if (siguiente_siguiente->dest->posicion == posicion)
                {
                    puntero_siguiente->sig = siguiente_siguiente->sig;
                    std::cout<<"La arista "<<puntero->posicion<<" "<<posicion<<" fue eliminada "<<std::endl;
                    delete(puntero_siguiente);
                }
            }

        }

    }
}

void Grafo::eliminar_arista(Vertice* vertice)
{
    
}