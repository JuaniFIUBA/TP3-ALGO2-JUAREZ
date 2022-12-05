#ifndef GATO_H
#define GATO_H
#include "animales.h"

class Gato : public Animal
{
    private:
        string especie_t = "Gato";
    
    public:
        //Pre: Recibe el nombre, edad, especie, tamanio y el modificador personalidad
        //Post: Crea un objeto Gato perteneciente a la clase "Madre" Animal.
        Gato(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad);

        //Pre: -
        //Post: Muestra la especie
        string devolver_especie();   

        //Pre:-
        //Post: Los gatos no necesitan bañarse, informa al usuario de esto.
        void lavarse();

        //Pre:-
        //Post: El Gato se alimenta como es debido, disminuyendo su hambre a 0
        void alimentarse();

        //Pre:-
        //Post: Al pasar el tiempo, el hambre y la higiene del Gato cambiaran.
        void pasar_tiempo();

        //Pre:-
        //Post: Destruye al objeto Gato.   
        ~Gato();
};

#endif