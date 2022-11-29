#ifndef PERRO_H
#define PERRO_H
#include "animales.h"

class Perro : public Animal
{
    private:
        string especie_t = "Perro";
    
    public:
        //Pre: Recibe el nombre, edad, especie, tamanio y el modificador personalidad
        //Post: Crea un objeto Perro perteneciente a la clase "Madre" Animal.
        Perro(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad);

        //Pre: -
        //Post: Muestra la especie
        string devolver_especie();    

        //Pre:-
        //Post: El Perro se bañara, aumentando su higiene a 100.
        void lavarse();
        
        //Pre:-
        //Post: El perro se alimentara como uno. Disminuyendo su hambre a 0.
        void alimentarse();

        //Pre:-
        //Post: Al pasar el tiempo, el hambre y la higiene del Perro cambiaran.
        void pasar_tiempo();

        //Pre:-
        //Post: Destruye al objeto Perro.
        ~Perro();
};

#endif