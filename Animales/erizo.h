#ifndef ERIZO_H
#define ERIZO_H
#include "animales.h"

class Erizo : public Animal
{
    private:
        string especie_t = "Erizo";      
    
    public:
        //Pre: Recibe el nombre, edad, especie, tamanio y el modificador personalidad
        //Post: Crea un objeto Erizo perteneciente a la clase "Madre" Animal.
        Erizo(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad);

        //Pre: -
        //Post: Muestra la especie
        string devolver_especie();   

        //Pre:-
        //Post: Se baña al Erizo, aumentando su higiene a 100.
        void lavarse();

        //Pre:-
        //Post: El Erizo come como corresponde, bajando su hambre a 0.
        void alimentarse();

        //Pre:-
        //Post: Al pasar el tiempo, el hambre y la higiene del Erizo cambiaran.
        void pasar_tiempo();

        //Pre:-
        //Post: Destruye al objeto Erizo.        
        ~Erizo();
};

#endif