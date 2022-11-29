#ifndef SOCIABLE_H
#define SOCIABLE_H
#include "personalidad.h"

class Sociable : public Personalidad
{
    private:
        string personalidad = "Sociable";
        float estadistica_hambre = 1; //Velocidad con la que crece el hambre
        float estadistica_higiene = 0.5; //Velocidad con la que decrece la higiene

    public:
        //Pre:-
        //Post: Construye al objeto Sociable.
        Sociable();

        //Pre:-
        //Post: Muestra la personalidad.
        string mostrar_personalidad();

        //Pre:-
        //Post: Modifica la higiene del animal
        void modificar_bases(float &crecimiento_hambre, float &decrecimiento_higiene);
        
        //Pre:-
        //Post: Destruye al objeto Jugueton.
        virtual ~Sociable(){};
};

#endif