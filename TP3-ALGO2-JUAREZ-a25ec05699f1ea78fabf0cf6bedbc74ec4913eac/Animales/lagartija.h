#ifndef LAGARTIJA_H
#define LAGARTIJA_H
#include "animales.h"

class Lagartija : public Animal
{
    private:
        string especie_t = "Lagartija";
    
    public:
        //Pre: Recibe el nombre, edad, especie, tamanio y el modificador personalidad
        //Post: Crea un objeto Lagartija perteneciente a la clase "Madre" Animal.
        Lagartija(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad);

        //Pre: -
        //Post: Muestra la especie
        string devolver_especie();   

        //Pre:-
        //Post: Las lagartijas no necesitan bañarse, informa al usuario de esto.
        void lavarse();

        //Pre:-
        //Post: La lagartija se alimenta como es debido, disminuye su hammbre hasta 0
        void alimentarse();

        //Pre:-
        //Post: Al pasar el tiempo, el hambre y la higiene de la Lagartija cambiaran.
        void pasar_tiempo();

        //Pre:-
        //Post: Destruye al objeto Lagartija.    
        ~Lagartija();
};

#endif