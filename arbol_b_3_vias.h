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

        E obtener_dato(T clave);

        E buscar(T clave);

        void aplicar_funcion(void (*foo)(E dato));
        
        void aplicar_funcion2(void (*foo)(E dato, int parametro), int parametro);

        void aplicar_funcion3(void (*foo)(E dato, Vector<T>* vector), Vector<T>* vector);

        bool clave_existe(T clave);

        void borrar(T clave);

        ~AB3();
    private:
        void aplicar_funcion(Nodo_AB<T,E>* nodo, void (*foo)(E dato));

        void aplicar_funcion2(Nodo_AB<T,E>* nodo, void (*foo)(E dato, int parametro), int parametro);

        void aplicar_funcion3(Nodo_AB<T,E> *nodo, void (*foo)(E dato, Vector<T>* vector), Vector<T>* vector);

        Nodo_AB<T, E>* buscar(Nodo_AB<T,E>*nodo, T clave);

        void print_in_order(Nodo_AB<T, E>* nodo);

        Nodo_AB<T, E>* buscar_para_insertar(Nodo_AB<T,E>*nodo, T clave);

        void borrar_nodo(Nodo_AB<T,E> *nodo);
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
        nodo -> mostrar_claves();
        print_in_order(nodo -> obtener_hijo(1));
        print_in_order(nodo -> obtener_hijo(2));
    }
}

template <class T, class E>
E AB3<T, E>::obtener_dato(T clave)
{
    Nodo_AB<T,E>* nodo = buscar(this -> raiz, clave);
    if(nodo == nullptr)
        cout << "Error, clave inválida" << endl;
    return nodo -> obtener_dato(clave);
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
void AB3<T,E>::aplicar_funcion2(void (*foo)(E dato, int parametro), int parametro){
    aplicar_funcion2(this -> raiz, foo, parametro);
}


template <class T, class E>
void AB3<T,E>::aplicar_funcion2(Nodo_AB<T,E>*nodo, void (*foo)(E dato, int parametro), int parametro){
    if(nodo != nullptr)
    {
        aplicar_funcion2(nodo -> obtener_hijo(0), foo, parametro);
        for(int i =0; i < nodo -> obtener_claves_usadas(); i++)
            foo(nodo -> obtener_dato(nodo -> obtener_clave(i)), parametro);
        aplicar_funcion2(nodo -> obtener_hijo(1), foo, parametro);
        aplicar_funcion2(nodo -> obtener_hijo(2), foo, parametro);
    }
}


template <class T, class E>
void AB3<T,E>::aplicar_funcion3(void (*foo)(E dato, Vector<T>* vector), Vector<T>* vector){
    aplicar_funcion3(this -> raiz, foo, vector);
}


template <class T, class E>
void AB3<T,E>::aplicar_funcion3(Nodo_AB<T,E> *nodo, void (*foo)(E dato, Vector<T>* vector), Vector<T>* vector)
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


//clave debe existir
template <class T, class E>
void AB3<T, E>::borrar(T clave)
{
    Nodo_AB<T, E>* nodo = buscar(clave);
    nodo -> eliminar_nodo();
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