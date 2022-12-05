#ifndef CONEJO_H
#define CONEJO_H
#include "animales.h"

class Conejo : public Animal
{
    private:
        string especie_t = "Conejo";
    
    public:
        //Pre: Recibe el nombre, edad, especie, tamanio y el modificador personalidad
        //Post: Crea un objeto Conejo perteneciente a la clase "Madre" Animal.
        Conejo(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad);

        //Pre: -
        //Post: Muestra la especie
        string devolver_especie();   

        //Pre:-
        //Post: El Conejo se bañara, aumentando su higiene a 100.
        void lavarse();
        
        //Pre:-
        //Post: El Conejo se alimentara como uno, disminuyendo su hambre a 0.
        void alimentarse();

        //Pre:-
        //Post: Al pasar el tiempo, el hambre y la higiene del Conejo cambiaran.
        void pasar_tiempo();

        //Pre:-
        //Post: Destruye al objeto Conejo.
        ~Conejo();
};

#endif