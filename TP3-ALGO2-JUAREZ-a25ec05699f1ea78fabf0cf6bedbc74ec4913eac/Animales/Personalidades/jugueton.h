#ifndef JUGUETON_H
#define JUGUETON_H
#include "personalidad.h"

class Jugueton : public Personalidad
{
    private:
        string personalidad = "Jugueton";
        
        float estadistica_hambre = 2; //Velocidad con la que crece el hambre
        float estadistica_higiene = 1; //Velocidad con la que decrece la higiene

    public:
        //Pre:-
        //Post: Construye al objeto Jugueton.
        Jugueton();

        //Pre:-
        //Post: Muestra la personalidad.
        string mostrar_personalidad();

        //Pre:-
        //Post: Modifica el hambre del animal
        void modificar_bases(float &crecimiento_hambre,float &decrecimiento_higiene); //Modifica pasar tiempo, en este caso, aumenta el hambre x2
        
        //Pre:-
        //Post: Destruye al objeto Jugueton.
        virtual ~Jugueton(){};
};

#endif