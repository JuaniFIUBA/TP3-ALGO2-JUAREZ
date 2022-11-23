#ifndef NODO_B_H
#define NODO_B_H
#include <iostream>
#include <vector>
using namespace std;

template <class T, class E>
class Nodo_AB
{
    private:
        int vias;       
        vector<T> *claves;
        int claves_usadas;
        vector<E> *datos;
        Nodo_AB<T, E> *padre;
        vector<Nodo_AB<T, E>*> *hijos;
        bool es_hoja;

    public:
        //constructor
        Nodo_AB(int vias, T clave, E dato);

        void insertar(T clave, E dato);

        void asignar_hijo(Nodo_AB<T, E>* hijo, int pos);
        
        void insertar_hijo_izquierda(Nodo_AB<T, E>* nodo);

        void insertar_hijo_derecha(Nodo_AB<T, E>* nodo);

        void mostrar_claves();

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
    this -> claves = new vector<T>(vias);
    this -> claves -> at(0) = clave;
    this -> claves_usadas = 1;
    this -> datos = new vector<E>(vias);
    this -> datos -> at(0) = dato;
    //relaciones
    this -> padre = nullptr;
    this -> hijos = new vector<Nodo_AB<T, E>*>(vias + 1);
    this -> es_hoja = true;
}

template <class T, class E>
void Nodo_AB<T, E>::insertar(T clave, E dato)
{
    insertar_en_orden(clave, dato);

    if(claves_usadas == vias)
        dividir_nodo();
}

template <class T, class E>
void Nodo_AB<T, E>::asignar_hijo(Nodo_AB<T, E>* hijo, int pos)
{
    this -> hijos -> insert(hijos -> begin() + pos, hijo); 
    es_hoja = false;
}

template <class T, class E>
void Nodo_AB<T, E>::insertar_hijo_izquierda(Nodo_AB<T, E>* nodo){
    hijos -> insert(hijos -> begin(), nodo);
    es_hoja = false;
}

template <class T, class E>
void Nodo_AB<T, E>::insertar_hijo_derecha(Nodo_AB<T, E>* nodo){
    int i = vias;
    while(hijos -> at(i) == nullptr)
        i--;
    this -> hijos -> at(i) = nodo;
    es_hoja = false;
}

template <class T, class E>
void Nodo_AB<T, E>::mostrar_claves()
{
    for(int i = 0; i < claves_usadas; i++)
        cout << claves -> at(i) << endl;
}


template <class T, class E>
Nodo_AB<T, E>* Nodo_AB<T, E>::obtener_hijo(int pos)
{
    return this -> hijos -> at(pos);
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
    return this -> claves -> at(pos);
}


//-------------PRIVATE----------------


template <class T, class E>
void Nodo_AB<T, E>::dividir_nodo()
{
    if(padre == nullptr)
    {
        Nodo_AB<T, E>* aux_derecho = new Nodo_AB<T, E>(this -> vias, this -> claves -> at(2), this -> datos -> at(2));
        aux_derecho -> asignar_hijo(this -> hijos -> at(2), 0);
        aux_derecho -> asignar_hijo(this -> hijos -> at(3), 1);
        
        Nodo_AB<T, E>* aux_izquierdo = new Nodo_AB<T, E>(this -> vias, this -> claves -> at(0), this -> datos -> at(0));
        aux_izquierdo -> asignar_hijo(this -> hijos -> at(0), 0);
        aux_izquierdo -> asignar_hijo(this -> hijos -> at(1), 1);
        if(hijos -> at(0) != nullptr)
        {
            for(int i = 0; i < vias - 1; i++)
            {
                aux_derecho -> obtener_hijo(i) -> asignar_padre(aux_derecho);
                aux_izquierdo -> obtener_hijo(i) -> asignar_padre(aux_izquierdo);

            }
        }
        hijos->at(2) = nullptr;
        hijos->at(3) = nullptr;
            
        reordenar(claves -> at(1));
        this -> hijos -> at(0) = aux_izquierdo;
        this -> hijos -> at(1) = aux_derecho;
    }

    else
    {
        Nodo_AB<T, E>* aux_derecho = new Nodo_AB<T, E>(this -> vias, this -> claves -> at(2), this -> datos -> at(2));
        T clave_aux = this -> claves -> at(1); 
        E dato_aux = this -> datos -> at(1);
        if(aux_derecho -> obtener_mayor() > padre -> obtener_mayor())
        {
            if(padre -> obtener_hijo(2) == nullptr)
                padre -> asignar_hijo(aux_derecho, 2);
            else
                padre -> asignar_hijo(aux_derecho, 3);
        }
        else
            padre -> asignar_hijo(aux_derecho, 1);

        reordenar(this -> claves -> at(0));


        this -> padre -> insertar(clave_aux, dato_aux); 

    }
}


template <class T, class E>
void Nodo_AB<T, E>::insertar_en_orden(T clave, E dato)
{
    for(int i = 0; i < claves_usadas; i++)
    {
        if(clave < claves->at(i))
        {
            claves -> insert(claves->begin() + i, clave);
            datos -> insert(datos -> begin() + i, dato);
            this -> claves_usadas++;
            return;
        }
    }
    claves -> at(claves_usadas) = clave;
    datos -> at(claves_usadas) = dato;
    this -> claves_usadas++;
}


template <class T, class E>
T Nodo_AB<T, E>::obtener_mayor()
{
    T mayor = claves -> at(0); 
    for(int i = 1; i < claves_usadas; i++)
    {
        if(claves -> at(i) > mayor)
            mayor = claves -> at(i);
    }
    return mayor;
}

template <class T, class E>
void Nodo_AB<T, E>::reordenar(T clave)
{
    while(claves -> at(0) != clave)
    {
        claves -> erase(claves -> begin());
        datos -> erase(datos -> begin());   
    }

    while(claves -> at(claves -> size() - 1) != clave)
    {
        claves -> pop_back();
        datos -> pop_back();
    }
    this -> claves_usadas = 1;
    claves->resize(vias);
    datos -> resize(vias);
}



#endif