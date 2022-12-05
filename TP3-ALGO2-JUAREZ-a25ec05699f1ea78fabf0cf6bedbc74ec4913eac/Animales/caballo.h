#ifndef CABALLO_H
#define CABALLO_H
#include "animales.h"

class Caballo : public Animal
{
    private:
        string especie_t = "Caballo";
    
    public:
        //Pre: Recibe el nombre, edad, especie, tamanio y el modificador personalidad
        //Post: Crea un objeto Caballo perteneciente a la clase "Madre" Animal.
        Caballo(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad);

        //Pre: -
        //Post: Muestra la especie
        string devolver_especie();   

        //Pre:-
        //Post: Se baña al Caballo, aumentando su higiene a 100.
        void lavarse();

        //Pre:-
        //Post: El Caballo come como corresponde, disminuyendo su hambre a 0
        void alimentarse();

        //Pre:-
        //Post: Al pasar el tiempo, el hambre y la higiene del Caballo cambiaran.
        void pasar_tiempo();

        //Pre:-
        //Post: Destruye al objeto Caballo.   
        ~Caballo();
};

#endif