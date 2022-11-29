#ifndef PERSONALIDAD_H
#define PERSONALIDAD_H

#include<iostream>

using namespace std;

class Personalidad  //Es un decoradaor de la clase animal
{
    public:
        //Pre:-
        //Post: Muestra la personalidad
        virtual string mostrar_personalidad() = 0;

        //Pre:-
        //Post: Modifica las bases.
        virtual void modificar_bases(float &crecimiento_hambre, float&decrecimiento_higiene) = 0;

        //Pre:-
        //Post: Destruye al objeto Personalidad.
        virtual ~Personalidad(){}
};

#endif