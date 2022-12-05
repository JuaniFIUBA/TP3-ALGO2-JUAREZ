#ifndef DORMILON_H
#define DORMILON_H
#include "personalidad.h"

class Dormilon : public Personalidad
{
    private:
        string personalidad = "Dormilon";

        float estadistica_hambre = 0.5; //Velocidad con la que crece el hambre
        float estadistica_higiene = 1; //Velocidad con la que decrece la higiene
    
    public:
        //Pre:-
        //Post: Crea el objeto Dormilon
        Dormilon();

        //Pre:-
        //Post: Muestra la personalidad.
        string mostrar_personalidad();

        //Pre:-
        //Post: Modifica el hambre del animal
        void modificar_bases(float &crecimiento_hambre, float &decrecimiento_higiene);

        //Pre:-
        //Post: Destruye al dormilon.
        virtual ~Dormilon(){}
};

#endif