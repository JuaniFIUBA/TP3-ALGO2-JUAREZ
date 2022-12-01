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

    public:
        //constructor
        Nodo_AB(int vias, T clave, E dato);
        
        //PRE: 
        //POS: inserta una clave en el nodo y evalua si es válido, en caso de no serlo llama a dividir();
        void insertar_clave(T clave, E dato);
        
        //PRE: la clave existe
        //POS: devuelve el dato asociado a la clave
        E obtener_dato(T clave);
        
        //PRE:
        //POS: true en caso de que el nodo contenga la clave, false en otro caso
        bool contiene_clave(T clave);
        
        //PRE: El nodo pasado por referencia no es nullptr
        //POS: Asigna el nodo pasado por referencia como hijo en la posicion indicada
        void asignar_hijo(Nodo_AB<T, E>* hijo, int pos);
        
        //PRE:
        //POS: Inserta el nodo en el primer lugar del vector <hijos>
        void insertar_hijo_izquierda(Nodo_AB<T, E>* nodo);
        
        //PRE:
        //POS: Inserta el nodo luego del primer lugar distinto de nullptr del vector hijos 
        void insertar_hijo_derecha(Nodo_AB<T, E>* nodo);
        
        //PRE:
        //POS: Inserta el nodo en la posición indicada
        void insertar_hijo(Nodo_AB<T,E>* nodo, int pos);
        
        //PRE:
        //POS: Muestra las claves contenidas en el nodo 
        void mostrar_claves();
        
        //PRE:
        //POS: Devuelve la cantidad de claves contenidas en el nodo
        int obtener_claves_usadas();
        
        //PRE:
        //POS: Devuelve el nodo hijo en la posición indicada
        Nodo_AB<T, E>* obtener_hijo(int pos);
        
        //PRE:
        //POS: Asigna al nodo como nodo padre del nodo original
        void asignar_padre(Nodo_AB<T, E>* nodo);
        
        //PRE:
        //POS: Asigna a todos los hijos distintos de nullptr un padre dado por referencia
        void asignar_padre_a_hijos(Nodo_AB<T,E>* padre);
        
        //PRE:
        //POS: Devuelve el padre del nodo
        Nodo_AB<T, E>* obtener_padre();
        
        //PRE: La clave existe.
        //POS: Devuelve la clave contenida en la posición dada
        T obtener_clave(int pos);
        
        //PRE:
        //POS: Devuelve la posicion de la cual la clave pasada es menor
        int menor_a(T clave);
        
        //PRE:
        //POS: Devuelve true si los hijos del nodo son todos nullptr
        bool es_hoja();
    
        // DESTRUCTOR
        ~Nodo_AB();

    private:

        //PRE: El nodo contiene una cantidad de claves inválida 
        //POS: Separa el nodo en 2 y asigna la clave del medio al nodo padre. Ambos nodos serán hijos del padre. 
        void dividir_nodo();

        //PRE:
        //POS: Separa el nodo raíz en 2 nodos (que serán hijos de la nueva raíz) y crea una nueva raíz con la clave del medio. 
        void dividir_nodo_raiz();
        
        //PRE:
        //POS: Inserta la clave y el dato asociado en una posición válida (respetando un orden de menor a mayor).
        void insertar_en_orden(T clave, E dato);
        
        //PRE:
        //POS: Devuelve la clave de mayor orden del nodo
        T obtener_mayor();

        //PRE:
        //POS: Borra todas las claves y datos asociados a las mismas que no sean la pasada por parámetro
        void reordenar(T clave);
 
        //PRE:
        //POS: Devuelve el índice de la clave pasada por parámetro y -1 en caso de que no exista.
        int index_clave(T clave);
        
        //PRE:
        //POS: "Intercambia" hijos en las posiciones indicadas con el nodo pasado por referencia.
        void intercambiar_hijos(Nodo_AB<T,E>*nodo, int pos1, int pos2);

};


template <class T, class E>
Nodo_AB<T, E>::Nodo_AB(int vias, T clave, E dato)
{
    this -> vias = vias;
    //datos
    this -> claves = new Vector<T>(vias);
    this -> datos = new Vector<E>(vias);
    this -> claves -> en(0) = clave;
    this -> datos -> en(0) = dato;
    this -> claves_usadas = 1;
    //relaciones
    this -> padre = nullptr;
    this -> hijos = new Vector<Nodo_AB<T, E>*>(vias + 1);
}



template <class T, class E>
void Nodo_AB<T, E>::insertar_clave(T clave, E dato){
    insertar_en_orden(clave, dato);

    if(claves_usadas == vias)
        dividir_nodo();
}

template <class T, class E>
bool Nodo_AB<T,E>::contiene_clave(T clave){

    if(index_clave(clave) != -1)
        return true;
    else
        return false;
}

// clave debe existir
template <class T, class E>
E Nodo_AB<T,E>::obtener_dato(T clave){
    return datos -> en(index_clave(clave));
}

template <class T, class E>
void Nodo_AB<T, E>::asignar_hijo(Nodo_AB<T, E>* hijo, int pos)
{
    this -> hijos -> en(pos) = hijo; 
}

template <class T, class E>
void Nodo_AB<T, E>::insertar_hijo_izquierda(Nodo_AB<T, E>* nodo){
    hijos -> insertar(0, nodo);
    hijos -> redimensionar(4);
}

template <class T, class E>
void Nodo_AB<T, E>::insertar_hijo_derecha(Nodo_AB<T, E>* nodo){
    int i = vias;

    while(hijos -> en(i - 1) == nullptr && i != 0)
        i--;

    this -> hijos -> en(i) = nodo;
}

template <class T, class E>
void Nodo_AB<T,E>::insertar_hijo(Nodo_AB<T,E>* nodo, int pos)
{
    hijos -> insertar(pos, nodo);
}


template <class T, class E>
void Nodo_AB<T, E>::mostrar_claves()
{
    for(int i = 0; i < claves_usadas; i++)
        cout <<  claves -> en(i) << ", ";
    cout << "\n";
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
void Nodo_AB<T,E>::asignar_padre_a_hijos(Nodo_AB<T, E>* padre)
{
    for(int i = 0; i < vias; i++)
    {
        if(hijos -> en(i) != nullptr)
            hijos -> en(i) -> asignar_padre(padre);
    }
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


template <class T, class E>
int Nodo_AB<T,E>::menor_a(T clave){
    for(int i = 0; i < claves_usadas; i++){
        if(claves -> en(i) > clave)
            return i;
    }
    return claves_usadas;
}

template <class T, class E>
bool Nodo_AB<T, E>::es_hoja()
{
    for(int i = 0; i < vias; i++){
        if(hijos -> en(i) != nullptr)   
            return false;
    }
    return true;
}


template <class T, class E>
Nodo_AB<T, E>::~Nodo_AB()
{
    delete claves;
    delete datos;
    delete hijos;
}

//-------------PRIVATE----------------


template <class T, class E>
void Nodo_AB<T, E>::dividir_nodo()
{
    if(padre == nullptr)
        dividir_nodo_raiz();

    else
    {
        Nodo_AB<T, E>* aux_derecho = new Nodo_AB<T, E>(this -> vias, this -> claves -> en(2), this -> datos -> en(2));

        T clave_aux = this -> claves -> en(1); 
        E dato_aux = this -> datos -> en(1);

        T mayor_padre = padre -> obtener_mayor();
        T mayor_aux = aux_derecho -> obtener_mayor();
        if(mayor_aux > mayor_padre)
            padre -> insertar_hijo_derecha(aux_derecho);

        else if(mayor_aux < mayor_padre && mayor_aux > padre -> obtener_clave(0))
            padre -> asignar_hijo(aux_derecho, 2);

        else
            padre -> insertar_hijo(aux_derecho, 1);
        
        reordenar(this -> claves -> en(0));
        intercambiar_hijos(aux_derecho, 2, 0);
        intercambiar_hijos(aux_derecho, 3, 1);
        aux_derecho -> asignar_padre(this -> padre);
        this -> padre -> insertar_clave(clave_aux, dato_aux); 
    }
}

template <class T, class E>
void Nodo_AB<T,E>::dividir_nodo_raiz()
{
    Nodo_AB<T, E>* aux_izquierdo = new Nodo_AB<T, E>(this -> vias, this -> claves -> en(0), this -> datos -> en(0));
    aux_izquierdo -> asignar_hijo(this -> hijos -> en(0), 0);
    aux_izquierdo -> asignar_hijo(this -> hijos -> en(1), 1);

    Nodo_AB<T, E>* aux_derecho = new Nodo_AB<T, E>(this -> vias, this -> claves -> en(2), this -> datos -> en(2));
    aux_derecho -> asignar_hijo(this -> hijos -> en(2), 0);
    aux_derecho -> asignar_hijo(this -> hijos -> en(3), 1);
    

    if(hijos -> en(0) != nullptr && hijos -> en(1) != nullptr)
    {
        for(int i = 0; i < this -> vias - 1; i++)
        {
            aux_izquierdo-> asignar_padre_a_hijos(aux_izquierdo);                
            aux_derecho -> asignar_padre_a_hijos(aux_derecho);                
        }
    }
    hijos -> en(2) = nullptr;
    hijos -> en(3) = nullptr;
        
    reordenar(claves -> en(1));
    asignar_hijo(aux_izquierdo, 0);
    asignar_hijo(aux_derecho, 1);  
}

template <class T, class E>
void Nodo_AB<T, E>::insertar_en_orden(T clave, E dato){
    int i = 0;
    while(i < claves_usadas && clave > claves -> en(i))
        i++;
    
    claves -> insertar(i, clave);
    datos -> insertar(i, dato);
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
    this -> claves -> redimensionar(vias);
    this -> datos -> redimensionar(vias);
}


template <class T, class E>
int Nodo_AB<T,E>::index_clave(T clave)
{
    for(int i = 0; i < claves_usadas; i++)
    {
        if(claves -> en(i) == clave)
            return i;
    }
    return -1;
}

template <class T, class E>
void Nodo_AB<T,E>::intercambiar_hijos(Nodo_AB<T,E>* intercambio, int pos1, int pos2)
{
    Nodo_AB<T,E>* aux = this -> hijos -> en(pos1);
    this -> hijos -> en(pos1) = intercambio -> obtener_hijo(pos2);
    intercambio -> asignar_hijo(aux, pos2);
}

#endif