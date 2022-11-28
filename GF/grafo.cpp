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
    
    while (puntero_soporte != NULL)
    {
        if (puntero_soporte->posicion == posicion){
            return puntero_soporte;
        }
        puntero_soporte = puntero_soporte ->sig;
    }

    return NULL;
}

void Grafo::insertar_vertice(int posicion)
{
    if (obtener_vertice(posicion) == NULL) //Verifica si existe el vertice
    {
        Vertice* nuevo = new Vertice(posicion);
        if (ChequearVacio())
        {
            raiz = nuevo;
        }
        else{
            Vertice* i = raiz;
            while (i->sig != NULL)
            {
                i = i->sig;
            }
            i->sig = nuevo;

        }
        capacidad++;
    }
    else{
        std::cout << "Ese vertice ya existe en el grafo" <<std::endl;
    }
    std::cout<<"Creaste el vertice "<<obtener_vertice(posicion)<<std::endl;
}

void Grafo::insertar_arista(int posicion_uno, int posicion_dos, int costo)
{
    Vertice* vertice_uno = obtener_vertice(posicion_uno);
    Vertice* vertice_dos = obtener_vertice(posicion_dos);

    if (vertice_uno == NULL)
    {
        std::cout<<"El vertice uno, no existe"<<std::endl;
    }
    
    if (vertice_dos == NULL)
    {
        std::cout<<"El vertice dos, no existe"<<std::endl;
    }

    if(vertice_uno != NULL && vertice_dos != NULL)
    {
        Arista* nueva = new Arista(vertice_dos, costo);

        if (vertice_uno->ady == NULL)
        {
            vertice_uno->ady = nueva;
        }
        else{
            
            Arista* puntero_soporte = vertice_uno->ady;
            
            //Hay un error de acceso a la clase arista

            while (puntero_soporte->sig != NULL)
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

void Grafo::eliminar_aristas(Vertice* vertice)
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
        eliminar_aristas(auxiliar);
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
                eliminar_aristas(actual);
                eliminar_aristas_vertice(actual->posicion);
                anterior->sig = actual->sig;
                std::cout<<"El vertice ["<<actual->posicion<<"] ha sido borrada"<<std::endl;
                capacidad--;
                encontrado = true;
            }

            anterior = actual;
            actual = actual->sig; 
        }
        if (encontrado == false)
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

void Grafo::eliminar_arista(int posicion_uno, int posicion_dos)
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
        if(vertice_uno->ady->dest == vertice_dos)
        {
            Arista* puntero = vertice_uno->ady;
            vertice_uno->ady = vertice_uno->ady->sig;
            std::cout<<"Arista"<<posicion_uno<<" -> "<<posicion_dos<<" "<<std::endl; 
            delete(puntero);
        }else{

            Arista* puntero = vertice_uno->ady;
            Arista* siguiente = puntero->sig;
            bool encontrado = false;

            while (siguiente != nullptr && encontrado == false)
            {
                if (siguiente->dest == vertice_dos){
                    puntero->sig =siguiente->sig;
                    std::cout<<"Arista"<<posicion_uno<<" -> "<<posicion_dos<<" "<<std::endl;                     
                    delete(siguiente);
                    //encontrado == true;
                }

                puntero = siguiente;
                siguiente = siguiente->sig;

            }
        }
    }    
}

void Grafo::eliminar_todo()
{
    Vertice* puntero = raiz;

    while (puntero != nullptr)
    {

        puntero = raiz;
        raiz = raiz->sig;
        eliminar_aristas(puntero);
        std::cout<<"Vertice"<<puntero->posicion<<" eliminado"<<std::endl;
        delete(puntero);
        capacidad--;

    }

}

/*
void Grafo::Dijkstra(int posicion_uno, int posicion_dos)
{
    Vertice* vertice_origen = obtener_vertice(posicion_uno);
    if (vertice_uno == NULL)
    {
        std::cout<<"El vertice uno, no existe"<<std::endl;
    }else{

    }
       
}
*/