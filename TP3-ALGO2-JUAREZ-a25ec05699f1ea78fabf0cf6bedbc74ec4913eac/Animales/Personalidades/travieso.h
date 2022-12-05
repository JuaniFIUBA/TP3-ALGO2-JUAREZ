#ifndef TRAVIESO_H
#define TRAVIESO_H
#include "personalidad.h"

class Travieso : public Personalidad
{
    private:
        string personalidad = "Travieso";
        float estadistica_hambre = 1; //Velocidad con la que crece el hambre
        float estadistica_higiene = 2; //Velocidad con la que decrece la higiene

    public:
        //Pre:-
        //Post: Construye al objeto Travieso.
        Travieso();

        //Pre:-
        //Post: Muestra la personalidad.
        string mostrar_personalidad();

        //Pre:-
        //Post: Modifica la higiene del animal
        void modificar_bases(float &crecimiento_hambre, float &decrecimiento_higiene);
        
        //Pre:-
        //Post: Destruye al objeto Jugueton.
        virtual ~Travieso(){};
};

#endif