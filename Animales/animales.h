#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include "./Personalidades/personalidad.h"

const int crecimiento_hambre = 10;
const int decrecimiento_higiene = 10;

class Animal
{
    private:
        string nombre;
        int edad;
        string personalidad_t;
        string tamanio;
        bool eliminado;
        bool adoptado;

    protected:
        char especie;
        float hambre;
        float higiene;
        float crecimiento_hambre = 10; //Cuanto aumenta el hambre al pasar el tiempo
        float decrecimiento_higiene = 10; //Cuanto decrece la higiene al pasar el tiempo
        Personalidad *personalidad; //Es un decorador/modificador, que cambia o modifica algunas acciones del animal.    

    public:
        //Pre: Recibe el nombre y edad del animal, además de una clase Personalidad que modifica el comportamiento.
        //Post: Crea un objeto Animal.
        Animal(string nombre, int edad, string tamanio, char especie, Personalidad *);

        //Pre: -
        //Post: Devuelve el nombre del animal.
        string obtener_nombre();

        //Pre:-
        //Post: Devuelve la especie del animal.
        int obtener_edad();

        //Pre:-
        //Post: Devuelve el tamanio del animal.
        char crear_animal_base();

        //Pre:-
        //Post: Devuelve el tipo de personalidad del animal
        string mostrar_personalidad();
        
        //Pre:-
        //Post:Devuelve el hambre actual del animal.
        float obtener_hambre();

        //Pre:-
        //Post: Devuelve la higiene actual del animal.
        float obtener_higiene();

        //Pre:-
        //Post: Devuelve el tamanio del animal.
        string obtener_tamanio();

        //Pre:
        //Post: devuelve si el animal está eliminado
        bool esta_eliminado();

        //Pre:
        //Post: "elimina" al animal
        void eliminar_animal();
        
        //Pre:
        //Post: "elimina" al animal
        bool esta_adoptado();
        
        //Pre:
        //Post: "elimina" al animal
        void adoptar_animal();

        //Pre:- 
        //Post: Devuelve la especie del animal completa
        virtual string devolver_especie(){return "especie";} 

        //Pre:-
        //Post: Cuando el usuario interactue con el menu, la higiene y hambre de los animales cambiara con el tiempo.
        virtual void pasar_tiempo(){}

        //Pre:-
        //Post: Se alimenta al animal.
        virtual void alimentarse(){}

        //Pre:-
        //Post: Se baña al animal.
        virtual void lavarse(){}

        //Pre:
        //Post: Destruye al objeto animal, liberando el espacio del puntero a personalidad.
        virtual ~Animal();
};

#endif