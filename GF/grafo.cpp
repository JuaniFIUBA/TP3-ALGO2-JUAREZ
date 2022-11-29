#include "grafo.hpp"
#include <fstream>
#include "cola.h"

using namespace std;

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

void Grafo::inicializar_matriz_ady(){
    for(int i = 0; i < DIMENSION_ADY; i++){
        for(int j = 0; j < DIMENSION_ADY; j++){
            matriz_de_adyacencia[i][j] = INF;
            if(i == j){
                matriz_de_adyacencia[i][j] = 0;
            }
        }
    }
}

void Grafo::llenar_matriz_ady()
{

    inicializar_matriz_ady();

    ifstream conexiones ("conexiones.txt");

    if(!conexiones.is_open()){
        std::cout<<"Error al abrir el archivo"<<std::endl;
    }

    string vertice_uno, vertice_dos, valor;
    
    while(getline(conexiones, vertice_uno, ',')){
        getline(conexiones, vertice_dos, ',');
        getline(conexiones, valor);
           
        int posicion_uno = stoi(vertice_uno);
        int posicion_dos = stoi(vertice_dos);
        int costo = stoi(valor);

        matriz_de_adyacencia[posicion_uno][posicion_dos] = costo;

    }
    conexiones.close();
}



int Grafo::Dijkstra(int inicio, int destino)
{
    Cola cola;
    int distancias[capacidad];
    bool visitados[capacidad];
    
    for(int i = 0; i < capacidad; i++){
        distancias[i] = INF;
        visitados[i] = false;
    }

    Dato dato;
    dato.vertice_actual = inicio;
    dato.costo_camino = 0;
    
    distancias[inicio] = 0; // Valor inicial del vertice de partida.
    cola.alta(dato);

    while(!cola.vacia()){
        Dato aux = cola.consulta();
        cola.baja();
        visitados[aux.vertice_actual] = true;
        std::cout<<"costo camino despues de chequear ady: "<<aux.costo_camino<<std::endl;
        
        if(aux.vertice_actual == destino){
            while (! cola.vacia()){
                Dato print = cola.consulta();
                std::cout<<print.vertice_actual<<"-"<<print.costo_camino<<std::endl;
                cola.baja();

            }
            return aux.costo_camino;
        }
        Vertice* vertice = obtener_vertice(aux.vertice_actual);
        Arista* puntero_arista = vertice->ady;

        while (puntero_arista != nullptr){   
            int vertice_adyacente = puntero_arista->dest->posicion;
            int costo_adyacente = puntero_arista->costo;

            if(!visitados[vertice_adyacente] && (distancias[aux.vertice_actual] + costo_adyacente) < distancias[vertice_adyacente]){    
                distancias[vertice_adyacente] = aux.costo_camino + costo_adyacente;
                cola.insertar(vertice_adyacente, (distancias[aux.vertice_actual] + costo_adyacente));
            }
            puntero_arista = puntero_arista->sig;
        }
    }
    return -1;      
}

