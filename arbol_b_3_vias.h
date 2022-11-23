#ifndef ARBOL_B_3_VIAS
#define ARBOL_B_3_VIAS  
#include "AB_Nodo.h"
#include <vector>       //cambiar luego-----------------------------------------------
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


template <class T>
class AB3 
{
    private:    
        int vias;
        Nodo_AB<T>* raiz;
    public:
        AB3(int vias);

        void agregar(T clave);

        void print_in_order();
    private:
        Nodo_AB<T>* agregar(Nodo_AB<T>* nodo, T clave);

        void print_in_order(Nodo_AB<T>* nodo);
};  

template <class T>
AB3<T>::AB3(int vias)
{
    this -> vias = vias;
    this -> raiz =  nullptr;
}



template <class T>
void AB3<T>::agregar(T clave)
{
    this -> raiz = agregar(this -> raiz, clave);
}

template <class T>
Nodo_AB<T>* AB3<T>::agregar(Nodo_AB<T>* nodo, T clave)
{
    if(nodo == nullptr)
    {
        nodo = new Nodo_AB<T>(this -> vias, clave);
        return nodo;
    }

    else if(nodo -> es_hoja())
        nodo -> insertar_clave(clave);
    

    // else if(nodo -> obtener_cantidad_hijos() == vias)
    // {
    //     cout << "cantidad hijos" <<endl;
    //     nodo -> insertar_clave(clave);
    // }

    if(nodo -> obtener_usados() == vias)
    {
        T aux_derecha = nodo -> obtener_dato(2);
        T aux_izquierda = nodo -> obtener_dato(0);

        if(nodo -> obtener_padre() == nullptr)
        {
            nodo -> dividir(1);
            nodo -> asignar_hijo(agregar(nodo -> obtener_hijo(0), aux_izquierda), 0, nodo);
            nodo -> asignar_hijo(agregar(nodo -> obtener_hijo(1), aux_derecha), 1, nodo);
        }
        else
        { 
            Nodo_AB<T>* padre = nodo -> obtener_padre();
            if(nodo -> obtener_dato(1) > padre -> obtener_mayor())
                padre -> asignar_hijo(agregar(padre-> obtener_hijo(2), nodo -> obtener_dato(2)), 2, padre);
            else
            {
                padre -> asignar_hijo(agregar(padre -> obtener_hijo(2), padre -> obtener_hijo(1) -> obtener_dato(0)), 2, padre); // swapeo 
                cout << "claves 2" <<endl;
                padre -> obtener_hijo(2) -> mostrar_claves();
                delete padre ->obtener_hijo(1);
                padre -> asignar_hijo(agregar(padre -> obtener_hijo(1), aux_derecha), 1, padre);
                padre -> obtener_hijo(0) -> dividir(1);
            }
            cout << "padres clave: "<< endl;
            padre -> mostrar_claves();
            // delete nodo;
            return padre;
        } 
    }
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