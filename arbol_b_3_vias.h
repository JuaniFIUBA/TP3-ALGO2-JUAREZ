#ifndef ARBOL_B_3_VIAS
#define ARBOL_B_3_VIAS  
#include "Nodo_AB.h"
#include "vector.h"  
#include <iostream>
using namespace std;

/* Definición:

 Un árbol B de orden 3 es un árbol de búsqueda de 3-vías en el que

 La raíz, o bien es hoja, o bien tiene al menos dos hijos.

 Todas las hojas están al mismo nivel.

 Cada nodo, a excepción quizá del nodo raíz, tiene k – 1 claves, donde 3/2  ≤  k ≤  3.

 Cada nodo interno, a excepción quizá del nodo raíz, tiene k hijos, donde 3/2  ≤  k ≤  3.  

 Las claves están ordenadas de menor a mayor. 
 
--tengo entre 1 y 2 claves
--tengo entre 2 y 3 hijos 

 */


/* HASHING: 
1. SABER APROX CUANTOS DATOS
2. FACTOR DE CARGA = cant_datos / tamaño_tabla 
3. ELIJO UN NUMERO PRIMO SUPERIOR AL VALOR QUE DEBERIA TENER LA TALBA PARA HACER LO DE LA FUNCION DEL RESTO

*/


/*
si es hoja, agrego el dato.
si no es hoja, busco el menor o mayor segun corresponda, e inserto
en el caso de llegar al limite del vector, lo divido y subo la mitad al padre, cuyos dos hijos seran los anteriores valores
*/


template <class T, class E>
class AB3 
{
    private:    
        int vias;
        Nodo_AB<T, E>* raiz;
    public:
        AB3(int vias);

        void agregar(T clave, E dato);

        void print_in_order();
    private:
        Nodo_AB<T, E>* agregar(Nodo_AB<T>* nodo, T clave, E dato);

        void print_in_order(Nodo_AB<T>* nodo);
};  

template <class T>
AB3<T>::AB3(int vias)
{
    this -> vias = vias;
    this -> raiz =  nullptr;
}



template <class T>
void AB3<T>::agregar(T clave, E dato)
{
    this -> raiz = agregar(this -> raiz, clave, dato);
}

template <class T>
Nodo_AB<T>* AB3<T>::agregar(Nodo_AB<T>* nodo, T clave, E dato)
{
    if(nodo == nullptr)
        nodo = new Nodo_AB<T>(this -> vias, clave, dato);

    else if(nodo -> es_hoja())
        nodo -> insertar_clave(clave);

    else if (!(nodo -> es_hoja())) 
        nodo -> asignar_hijo(agregar(nodo ->obtener_hijo(nodo -> es_menor(clave)), clave), nodo -> es_menor(clave), nodo);
    
    return nodo;
}

template <class T>
void AB3<T>::print_in_order(Nodo_AB<T>* nodo)
{
    if (nodo != nullptr)
    {
        print_in_order(nodo -> obtener_hijo(0));
        nodo -> mostrar_claves();
        print_in_order(nodo -> obtener_hijo(1));
        nodo -> mostrar_claves();
        print_in_order(nodo -> obtener_hijo(2));
    }
}

template <class T>
void AB3<T>::print_in_order()
{
    this->print_in_order(this->raiz);
}



#endif