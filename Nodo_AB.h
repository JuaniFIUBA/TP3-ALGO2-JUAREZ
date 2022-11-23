#ifndef NODO_B_H
#define NODO_B_H
#include <iostream>
#include "vector.h"
using namespace std;

template <class T, class E>
class Nodo_AB
{
    private:
        int vias;       
        Vector<T> *claves;
        int claves_usadas;
        Vector<E> *datos;
        Nodo_AB<T, E> *padre;
        Vector<Nodo_AB<T, E>*> *hijos;
        bool es_hoja;

    public:
        //constructor
        Nodo_AB(int vias, T clave, E dato);

        void insertar_clave(T clave, E dato);

        void asignar_hijo(Nodo_AB<T, E>* hijo, int pos);
        
        void insertar_hijo_izquierda(Nodo_AB<T, E>* nodo);

        void insertar_hijo_derecha(Nodo_AB<T, E>* nodo);

        void mostrar_claves();

        int obtener_claves_usadas();

        Nodo_AB<T, E>* obtener_hijo(int pos);

        void asignar_padre(Nodo_AB<T, E>* padre);
        
        Nodo_AB<T, E>* obtener_padre();
        
        T obtener_clave(int pos);

    private:
        void dividir_nodo();

        void insertar_en_orden(T clave, E dato);

        T obtener_mayor();

        //borra todo lo que no sea clave
        void reordenar(T clave);

};

template <class T, class E>
Nodo_AB<T, E>::Nodo_AB(int vias, T clave, E dato)
{
    this -> vias = vias;
    //datos
    this -> claves = new Vector<T>(vias);
    this -> claves -> en(0) = clave;
    this -> claves_usadas = 1;
    this -> datos = new Vector<E>(vias);
    this -> datos -> en(0) = dato;
    //relaciones
    this -> padre = nullptr;
    this -> hijos = new Vector<Nodo_AB<T, E>*>(vias + 1);
    this -> es_hoja = true;
}

template <class T, class E>
void Nodo_AB<T, E>::insertar_clave(T clave, E dato)
{
    insertar_en_orden(clave, dato);

    if(claves_usadas == vias)
        dividir_nodo();
}

template <class T, class E>
void Nodo_AB<T, E>::asignar_hijo(Nodo_AB<T, E>* hijo, int pos)
{
    this -> hijos -> insertar(pos, hijo); 
    es_hoja = false;
}

template <class T, class E>
void Nodo_AB<T, E>::insertar_hijo_izquierda(Nodo_AB<T, E>* nodo){
    hijos -> insertar(0, nodo);
    es_hoja = false;
}

template <class T, class E>
void Nodo_AB<T, E>::insertar_hijo_derecha(Nodo_AB<T, E>* nodo){
    int i = vias;
    while(hijos -> en(i) == nullptr)
        i--;
    this -> hijos -> en(i) = nodo;
    es_hoja = false;
}

template <class T, class E>
void Nodo_AB<T, E>::mostrar_claves()
{
    for(int i = 0; i < claves_usadas; i++)
        cout << claves -> en(i) << endl;
}


template <class T, class E>
int Nodo_AB<T, E>::obtener_claves_usadas()
{
    return this -> claves_usadas;
}


template <class T, class E>
Nodo_AB<T, E>* Nodo_AB<T, E>::obtener_hijo(int pos)
{
    return this -> hijos -> en(pos);
}

template <class T, class E>
void Nodo_AB<T, E>::asignar_padre(Nodo_AB<T, E>* nodo)
{
    this -> padre = nodo;
}


template <class T, class E>
Nodo_AB<T, E>* Nodo_AB<T, E>::obtener_padre()
{
    return this -> padre;
}

template <class T, class E>
T Nodo_AB<T, E>::obtener_clave(int pos)
{
    return this -> claves -> en(pos);
}


//-------------PRIVATE----------------


template <class T, class E>
void Nodo_AB<T, E>::dividir_nodo()
{
    if(padre == nullptr)
    {
        Nodo_AB<T, E>* aux_derecho = new Nodo_AB<T, E>(this -> vias, this -> claves -> en(2), this -> datos -> en(2));
        aux_derecho -> asignar_hijo(this -> hijos -> en(2), 0);
        aux_derecho -> asignar_hijo(this -> hijos -> en(3), 1);
        
        Nodo_AB<T, E>* aux_izquierdo = new Nodo_AB<T, E>(this -> vias, this -> claves -> en(0), this -> datos -> en(0));
        aux_izquierdo -> asignar_hijo(this -> hijos -> en(0), 0);
        aux_izquierdo -> asignar_hijo(this -> hijos -> en(1), 1);
        if(hijos -> en(0) != nullptr)
        {
            for(int i = 0; i < vias - 1; i++)
            {
                aux_derecho -> obtener_hijo(i) -> asignar_padre(aux_derecho);
                aux_izquierdo -> obtener_hijo(i) -> asignar_padre(aux_izquierdo);

            }
        }
        hijos->en(2) = nullptr;
        hijos->en(3) = nullptr;
            
        reordenar(claves -> en(1));
        this -> hijos -> en(0) = aux_izquierdo;
        this -> hijos -> en(1) = aux_derecho;
    }

    else
    {
        Nodo_AB<T, E>* aux_derecho = new Nodo_AB<T, E>(this -> vias, this -> claves -> en(2), this -> datos -> en(2));
        T clave_aux = this -> claves -> en(1); 
        E dato_aux = this -> datos -> en(1);
        if(aux_derecho -> obtener_mayor() > padre -> obtener_mayor())
        {
            if(padre -> obtener_hijo(2) == nullptr)
                padre -> asignar_hijo(aux_derecho, 2);
            else
                padre -> asignar_hijo(aux_derecho, 3);
        }
        else
            padre -> asignar_hijo(aux_derecho, 1);

        reordenar(this -> claves -> en(0));


        this -> padre -> insertar_clave(clave_aux, dato_aux); 

    }
}


template <class T, class E>
void Nodo_AB<T, E>::insertar_en_orden(T clave, E dato)
{
    for(int i = 0; i < claves_usadas; i++)
    {
        if(clave < claves->en(i))
        {
            claves -> insertar(i, clave);
            datos -> insertar(i, dato);
            this -> claves_usadas++;
            return;
        }
    }
    claves -> en(claves_usadas) = clave;
    datos -> en(claves_usadas) = dato;
    this -> claves_usadas++;
}


template <class T, class E>
T Nodo_AB<T, E>::obtener_mayor()
{
    T mayor = claves -> en(0); 
    for(int i = 1; i < claves_usadas; i++)
    {
        if(claves -> en(i) > mayor)
            mayor = claves -> en(i);
    }
    return mayor;
}

template <class T, class E>
void Nodo_AB<T, E>::reordenar(T clave)
{
    while(claves -> en(0) != clave)
    {
        claves -> borrar(0);
        datos -> borrar(0);   
    }

    while(claves -> en(claves -> tamanio() - 1) != clave)
    {
        claves -> borrar_atras();
        datos -> borrar_atras();
    }
    this -> claves_usadas = 1;
    claves->redimensionar(vias);
    datos -> redimensionar(vias);
}



#endif