#include "dormilon.h"

Dormilon::Dormilon(){
}

string Dormilon::mostrar_personalidad(){
    return personalidad;
}

void Dormilon::modificar_bases(float &crecimiento_hambre, float &decrecimiento_higiene){
    crecimiento_hambre = crecimiento_hambre * this->estadistica_hambre;
}