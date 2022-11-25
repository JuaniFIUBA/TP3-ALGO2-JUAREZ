#ifndef ARBOL_B_3_VIAS
#define ARBOL_B_3_VIAS  
#include "Nodo_AB.h"
#include "vector.h"  
#include <iostream>
using namespace std;

template <class T, class E>
class AB3 
{
    private:    
        int vias;
        Nodo_AB<T, E>* raiz;
    public:
        AB3(int vias);

        void agregar(T clave, E dato);

        Nodo_AB<T, E>* obtener_raiz();

        void print_in_order();

        T obtener_dato(T clave);
        // bool existe_clave(T clave);

        Nodo_AB<T, E>* buscar(Nodo_AB<T,E>*nodo, T clave);

        void borrar(T clave);
    private:

        void print_in_order(Nodo_AB<T, E>* nodo);

        Nodo_AB<T, E>* buscar_para_insertar(Nodo_AB<T,E>*nodo, T clave);
};  

template <class T, class E>
AB3<T, E>::AB3(int vias)
{
    this -> vias = vias;
    this -> raiz =  nullptr;
}

template <class T, class E>
Nodo_AB<T, E>* AB3<T, E>::obtener_raiz()
{
    return this -> raiz;    
}

template <class T, class E>
void AB3<T, E>::agregar(T clave, E dato)
{
    if(raiz == nullptr)
        raiz = new Nodo_AB<T, E>(this -> vias, clave, dato);
    else{
        Nodo_AB<T, E>* nodo = buscar_para_insertar(this -> raiz, clave);
        // cout << "nodo a insertar: " <<endl;
        // nodo->mostrar_claves();
        nodo ->insertar_clave(clave, dato);
        nodo -> asignar_padre_a_hijos(nodo);
        raiz -> asignar_padre_a_hijos(raiz);
    }
}

template <class T, class E>
Nodo_AB<T, E>* AB3<T,E>::buscar_para_insertar(Nodo_AB<T,E>*nodo, T clave){
    if(nodo -> es_hoja())
        return nodo;
    else
        return buscar_para_insertar(nodo -> obtener_hijo(nodo->menor_a(clave)), clave);
}


template <class T, class E>
void AB3<T, E>::print_in_order()
{
    this->print_in_order(this->raiz);
}

template <class T, class E>
void AB3<T, E>::print_in_order(Nodo_AB<T, E>* nodo)
{
    if (!(nodo -> es_hoja()))
    {
        print_in_order(nodo -> obtener_hijo(nodo -> menor_a(nodo -> obtener_clave(0))));
        nodo -> mostrar_claves();
    } 
    if(nodo -> es_hoja())
        nodo -> mostrar_claves();
}

template <class T, class E>
T AB3<T, E>::obtener_dato(T clave)
{
    Nodo_AB<T,E>* nodo = buscar(this -> raiz, clave);
    if(nodo == nullptr)
        cout << "Error, clave inválida" << endl;
    return nodo -> obtener_dato(clave);
}

template <class T, class E>
Nodo_AB<T, E>* AB3<T, E>::buscar(Nodo_AB<T,E>*nodo, T clave)
{
    if(nodo -> contiene_clave(clave))   
        return nodo;
    else if(nodo -> es_hoja())
        return nullptr;
    else 
        return buscar(nodo->obtener_hijo(nodo -> menor_a(clave)), clave);
}


//clave debe existir
template <class T, class E>
void AB3<T, E>::borrar(T clave)
{
    Nodo_AB<T, E>* nodo = buscar(clave);
    nodo -> eliminar_nodo();
}


// template <class T, class E>
// bool AB3<T,E>::existe_clave(T clave){

// }


#endif