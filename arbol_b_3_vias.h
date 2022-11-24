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
        Nodo_AB<T, E>* agregar(Nodo_AB<T, E>* nodo, T clave, E dato);

        Nodo_AB<T, E>* buscar(Nodo_AB<T,E>*nodo, T clave);
        void print_in_order(Nodo_AB<T, E>* nodo);
};  

template <class T, class E>
AB3<T, E>::AB3(int vias)
{
    this -> vias = vias;
    this -> raiz =  nullptr;
}



template <class T, class E>
void AB3<T, E>::agregar(T clave, E dato)
{
    if(raiz == nullptr)
        raiz = new Nodo_AB<T, E>(this -> vias, clave, dato);
    else
        buscar(this -> raiz) -> insertar_clave(clave, dato);
}


template <class T, class E>
Nodo_AB<T, E>* Nodo_AB<T,E>::buscar(Nodo_AB<T,E>*nodo, T clave){
    if(nodo -> _es_hoja())
        return nodo;
    else    
        return buscar(nodo -> obtener_hijo(es_menor(clave)), clave);
}



// template <class T, class E>
// Nodo_AB<T, E>* AB3<T, E>::agregar(Nodo_AB<T, E>* nodo, T clave, E dato)
// {
//     if(nodo == nullptr)
//         nodo = new Nodo_AB<T, E>(this -> vias, clave, dato);

//     else if(nodo -> _es_hoja())
//     {
//         nodo -> insertar_clave(clave, dato);
//         nodo -> asignar_padre_a_hijos(nodo);
//     }

//     else if (!(nodo -> _es_hoja())){

//         nodo -> asignar_hijo(agregar(nodo -> obtener_hijo(nodo -> menor_a(clave)), clave, dato), nodo -> menor_a(clave));
//     }
//     // cout << "claves "<< endl;
//     // nodo -> mostrar_claves();
//     return nodo;
// }

template <class T, class E>
void AB3<T, E>::print_in_order(Nodo_AB<T, E>* nodo)
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

template <class T, class E>
void AB3<T, E>::print_in_order()
{
    this->print_in_order(this->raiz);
}



#endif