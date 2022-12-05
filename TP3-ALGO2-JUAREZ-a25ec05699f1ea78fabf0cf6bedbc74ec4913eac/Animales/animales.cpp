#include "animales.h"

Animal::Animal(string nombre , int edad, string tamanio, char especie, Personalidad *personalidad)
{
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    this->personalidad_t = personalidad->mostrar_personalidad();
    this->hambre = 0;
    this->higiene = 100;
    this -> eliminado = false;
    this -> adoptado = false;
}

string Animal::obtener_nombre(){
    return nombre;
}

int Animal::obtener_edad(){
    return edad;
}

char Animal::crear_animal_base(){
    return especie;
}

string Animal::mostrar_personalidad(){
    return personalidad_t;
}

float Animal::obtener_hambre(){
    return hambre;
}
float Animal::obtener_higiene(){
    return higiene;
}

string Animal::obtener_tamanio(){
    return tamanio;
}

bool Animal::esta_eliminado(){
    return this -> eliminado;
}

void Animal::eliminar_animal(){
    this -> eliminado = true;
}

bool Animal::esta_adoptado(){
    return this -> adoptado;
}

void Animal::adoptar_animal(){
    this -> adoptado = true;
}

void Animal::cambiar_nombre(string nuevo_nombre)
{
    this -> nombre = nuevo_nombre;
}

Animal::~Animal(){}