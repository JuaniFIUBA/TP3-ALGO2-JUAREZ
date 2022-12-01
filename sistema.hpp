#ifndef SISTEMA_HPP
#define SISTEMA_HPP
#include "arbol_b_3_vias.h"
#include "Nodo_AB.h"
#include "vector.h"
#include "./Merge/mergesort.h"
#include "validaciones.h"
#include "./Animales/animales.h"
#include "./Animales/perro.h"
#include "./Animales/gato.h"
#include "./Animales/caballo.h"
#include "./Animales/roedor.h"
#include "./Animales/conejo.h"
#include "./Animales/erizo.h"
#include "./Animales/lagartija.h"
#include "./Animales/Personalidades/dormilon.h"
#include "./Animales/Personalidades/jugueton.h"
#include "./Animales/Personalidades/sociable.h"
#include "./Animales/Personalidades/travieso.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

const char PERRO = 'P';
const char GATO = 'G';
const char CABALLO = 'C';
const char ROEDOR = 'R';
const char CONEJO = 'O';
const char ERIZO = 'E';
const int DIMINUTO = 2;
const int PEQUENIO = 10;
const int MEDIANO = 10;
const int GRANDE = 20;
const int GIGANTE = 50;
const int EDAD_MIN = 0;
const int EDAD_MAX = 100;
const int ESPACIO_MIN = 1;
const int ESPACIO_MAX = 500;
const int CANTIDAD_PERSONALIDADES = 4;
const int CANTIDAD_TAMANIOS =  5;
const int CANTIDAD_ESPECIES = 7;
const string TAMANIOS[] = {"diminuto", "pequeño", "mediano", "grande", "gigante"};
const string PERSONALIDADES[] = {"jugueton", "travieso", "sociable", "dormilon"};
const char ESPECIES[] = {'P', 'G', 'C', 'R', 'O', 'E', 'L'};

enum opciones_menu{
    LISTAR_ANIMALES = 1,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMAL,
    ADOPTAR_ANIMAL,
    GUARDAR_Y_SALIR
};

enum opciones_menu2{
    ELEGIR_INDIVIDUALMENTE = 1,
    REGRESAR
};

enum opciones_menu3{
    ALIMENTAR = 1,
    BANIAR,
    SALTEAR,
    VOLVER
};

class Sistema{
private:
    AB3<string, Animal*> *arbol;
    Vector<string>* animales_perdidos;
public:

    //pre:
    //pos: lee el archivo
    Sistema();
    //pre: 
    //pos: muestra por pantalla los datos de los animales registrados
    void imprimir_lista(); 
    //pre:
    //pos: actualiza el hambre y el higiene de cada animal de la lista
    void actualizar_atributos();
    //pre:
    //pos: agrega un animal al registro 
    void rescatar_animal();
    //pre:
    //pos: busca e imprime las características del animal ingresado por el usuario (busca por nombre)
    void buscar_animal();
    //pre:
    //pos: muestra los animales uno por uno y consulta por su mantención. 
    void elegir_individualmente();
    //pre:
    //pos: pide una opción y verifica que el input sea correcto.
    int pedir_opcion(int rango_min, int rango_max);
    //pre:
    //pos: Vuelve el hambre de todos los animales a 0
    void alimentar_todos();
    //pre:
    //pos: Vuelve la higiene de todos los animales a 100
    void baniar_todos();
    //pre:
    //pos: Muestra según el tamanio disponible los animales y una vez elegido uno de ellos lo elimina de la lista.
    void adoptar_animal();
    //pre:
    //pos: devuelve la cantidad de animales que escaparon
    int cantidad_perdidos();
    //pre:
    //pos: Wrapper que llama a una función para borrar los punteros a Animal
    void borrar_animales();
    //pre: 
    //pos: Actualiza el archivo "animales.csv" con las modificaciones realizadas por el usuario.
    void cerrar_archivo();
    ~Sistema();


private:
   
    //pre: el archivo está en formato csv correcto (ordenado) 
    //pos: crea una lista de <Animal*>
    void leer_archivo();
    
    //pre: personalidad fue creada
    //pos: devuelve un puntero a animal con las características del animal de n_especie
    Animal* crear_animal_base(std::string n_nombre, int n_edad, std::string n_tamanio, char n_especie, Personalidad *personalidad);
    
    //pre: 
    //pos: crea el animal y lo agrega a la lista en la ultima posicion
    void crear_animal(std::string n_personalidad, std::string n_nombre, int n_edad, std::string n_tamanio, char n_especie);
    
    //pre: pos < cantidad_elementos (lista)
    //pos: muestra todas las características del animal en la posición <<pos>>
    // void mostrar_info_animal(Animal*);
    
    void imprimir_lista(Nodo_AB<string, Animal*> * nodo); 
    
    //pre: 
    //pos: devuelve true en caso de que todos los datos ingresados sean válidos
    bool solicitar_datos_y_agregar();

    // void actualizar(Animal* animal);
 
    void actualizar_atributos(Nodo_AB<string, Animal*> * nodo);

    //pre:
    //pos: muestra por consola los animales que se puedan tener en un espacio contenido en espacio_disponible
    void mostrar_animales_disponibles(int espacio_disponible);
   
    //pre:
    //pos: true en caso de que el animal sea seleccionado con exito, false en caso de que no se encuentre el animal
    bool seleccionar_animal();

};

#endif