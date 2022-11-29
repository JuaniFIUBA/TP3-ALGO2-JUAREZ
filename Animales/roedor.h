#ifndef ROEDOR_H
#define ROEDOR_H
#include "animales.h"

class Roedor : public Animal
{
    private:
        string especie_t = "Roedor";

    public:
        //Pre: Recibe el nombre, edad, especie, tamanio y el modificador personalidad
        //Post: Crea un objeto Roedor perteneciente a la clase "Madre" Animal.
        Roedor(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad);

        //Pre: -
        //Post: Muestra la especie
        string devolver_especie();

        //Pre:-
        //Post: Los roedores no necesitan bañarse, informa al usuario de esto.
        void lavarse();

        //Pre:-
        //Post: El Roedor se alimenta como es debido. disminuyendo su hambre a 0.
        void alimentarse();

        //Pre:-
        //Post: Al pasar el tiempo, el hambre y la higiene del Roedor cambiaran.
        void pasar_tiempo();

        //Pre:-
        //Post: Destruye al objeto Roedor.    
        ~Roedor();
};

#endif