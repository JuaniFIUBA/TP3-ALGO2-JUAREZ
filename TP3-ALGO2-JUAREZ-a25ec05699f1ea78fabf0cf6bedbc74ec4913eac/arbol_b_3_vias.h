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
        //CONSTRUCTOR 
        AB3(int vias);
        
        //PRE:
        //POST: Agrega la clave junto con el dato en el nodo que corresponda
        void agregar(T clave, E dato);

        //PRE:
        //POST: Wrapper
        void print_in_order();
        
        //PRE: Clave debe existir
        //POST: Devuelve el dato asociado a la clave 
        E buscar(T clave);

        //PRE:
        //POST: Wrapper
        void aplicar_funcion(void (*foo)(E dato));

        //PRE:
        //POST: Wrapper
        void aplicar_funcion2(void (*foo)(E dato, int parametro, Vector<E>* vector), int parametro, Vector<E>* vector);
        
        //PRE:
        //POST: Wrapper
        void aplicar_funcion3(void (*foo)(E dato, Vector<E>* vector), Vector<E>* vector);
        
        //PRE:
        //POST: Wrapper
        bool clave_existe(T clave);

        //DESTRUCTOR.        
        ~AB3();
    private:

        //PRE:
        //POST: Aplica la función pasada por interfaz a cada uno de los datos del árbol
        void aplicar_funcion(Nodo_AB<T,E>* nodo, void (*foo)(E dato));
        //PRE:
        //POST: Aplica la función pasada por interfaz a cada uno de los datos del árbol
        void aplicar_funcion2(Nodo_AB<T,E>* nodo, void (*foo)(E dato, int parametro, Vector<E>* vector), int parametro, Vector<E>* vector);
        //PRE:
        //POST: Aplica la función pasada por interfaz a cada uno de los datos del árbol
        void aplicar_funcion3(Nodo_AB<T,E> *nodo, void (*foo)(E dato, Vector<E>* vector), Vector<E>* vector);
        
        //PRE:
        //POST: Función recursiva. Devuelve el nodo asociado a la clave en caso de que exista, nullptr en caso de que no.
        Nodo_AB<T, E>* buscar(Nodo_AB<T,E>*nodo, T clave);
        
        //PRE:
        //POST: Muestra en orden las claves en el árbol.
        void print_in_order(Nodo_AB<T, E>* nodo);

        //PRE:
        //POST: Busca un nodo válido para insertar la clave dada.
        Nodo_AB<T, E>* buscar_para_insertar(Nodo_AB<T,E>*nodo, T clave);
       
        //PRE:
        //POST: Función recursiva. Borra los nodos del árbol.
        void borrar_nodo(Nodo_AB<T,E> *nodo);
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
    else{
        Nodo_AB<T, E>* nodo = buscar_para_insertar(this -> raiz, clave);
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
    if(nodo != nullptr)
    {
        print_in_order(nodo -> obtener_hijo(0));
        cout << nodo -> obtener_clave(0) << ", " << endl;
        print_in_order(nodo -> obtener_hijo(1));
        if(nodo -> obtener_claves_usadas() != 1)
            cout << nodo -> obtener_clave(1) << ", " <<endl;
        print_in_order(nodo -> obtener_hijo(2));
    }
}


template <class T, class E>
E AB3<T,E>::buscar(T clave){
    return (buscar(this -> raiz, clave)) -> obtener_dato(clave);
}


template <class T, class E>
Nodo_AB<T, E>* AB3<T, E>::buscar(Nodo_AB<T,E>*nodo, T clave)
{
    if(nodo != nullptr)
    {
        if(nodo -> contiene_clave(clave))
            return nodo;
        else if(nodo -> es_hoja())
            return nullptr;
        else
            return buscar(nodo->obtener_hijo(nodo -> menor_a(clave)), clave);
    }
    else   
        return nullptr;
}


template <class T, class E>
void AB3<T,E>::aplicar_funcion(void (*foo)(E dato))
{
    aplicar_funcion(this -> raiz, foo);
}

template <class T, class E>
void AB3<T,E>::aplicar_funcion(Nodo_AB<T,E>* nodo, void (*foo)(E dato))
{
    if(nodo != nullptr)
    {
        aplicar_funcion(nodo -> obtener_hijo(0), foo);
        for(int i = 0; i < nodo -> obtener_claves_usadas(); i++)
            foo(nodo -> obtener_dato(nodo -> obtener_clave(i)));
        aplicar_funcion(nodo -> obtener_hijo(1), foo);
        aplicar_funcion(nodo -> obtener_hijo(2), foo);
    }
}

template <class T, class E>
void AB3<T,E>::aplicar_funcion2(void (*foo)(E dato, int parametro, Vector<E>* vector), int parametro, Vector<E>* vector)
{
    aplicar_funcion2(this -> raiz, foo, parametro, vector);
}


template <class T, class E>
void AB3<T,E>::aplicar_funcion2(Nodo_AB<T,E>* nodo, void (*foo)(E dato, int parametro, Vector<E>* vector), int parametro, Vector<E>* vector)
{
    if(nodo != nullptr)
    {
        aplicar_funcion2(nodo -> obtener_hijo(0), foo, parametro, vector);
        for(int i =0; i < nodo -> obtener_claves_usadas(); i++)
            foo(nodo -> obtener_dato(nodo -> obtener_clave(i)), parametro, vector);
        aplicar_funcion2(nodo -> obtener_hijo(1), foo, parametro, vector);
        aplicar_funcion2(nodo -> obtener_hijo(2), foo, parametro, vector);
    }
}


template <class T, class E>
void AB3<T,E>::aplicar_funcion3(void (*foo)(E dato, Vector<E>* vector), Vector<E>* vector){
    aplicar_funcion3(this -> raiz, foo, vector);
}


template <class T, class E>
void AB3<T,E>::aplicar_funcion3(Nodo_AB<T,E> *nodo, void (*foo)(E dato, Vector<E>* vector), Vector<E>* vector)
{
    if(nodo != nullptr)
    {
        aplicar_funcion3(nodo -> obtener_hijo(0), foo, vector);
        for(int i =0; i < nodo -> obtener_claves_usadas(); i++)
            foo(nodo -> obtener_dato(nodo -> obtener_clave(i)), vector);
        aplicar_funcion3(nodo -> obtener_hijo(1), foo, vector);
        aplicar_funcion3(nodo -> obtener_hijo(2), foo, vector);
    }
}


template <class T, class E>
bool AB3<T,E>::clave_existe(T clave)
{
    Nodo_AB<T,E> *nodo = buscar(this -> raiz, clave);
    if(nodo != nullptr)
        return true;
    return false;
}

template <class T, class E>
AB3<T, E>::~AB3(){
    borrar_nodo(this -> raiz);
}

template <class T, class E>
void AB3<T,E>::borrar_nodo(Nodo_AB<T,E> *nodo){
    if(nodo == nullptr)
        return;
    borrar_nodo(nodo -> obtener_hijo(0));
    borrar_nodo(nodo -> obtener_hijo(1));
    borrar_nodo(nodo -> obtener_hijo(2));
    delete nodo;
}


#endif