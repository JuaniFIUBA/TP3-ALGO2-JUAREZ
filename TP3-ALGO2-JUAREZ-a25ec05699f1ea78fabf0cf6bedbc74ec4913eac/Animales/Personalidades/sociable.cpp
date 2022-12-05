#include "sociable.h"

Sociable::Sociable(){
}

string Sociable::mostrar_personalidad(){
    return personalidad;
}

void Sociable::modificar_bases(float &crecimiento_hambre, float &decrecimiento_higiene){
    decrecimiento_higiene = (decrecimiento_higiene) * this->estadistica_higiene;
}