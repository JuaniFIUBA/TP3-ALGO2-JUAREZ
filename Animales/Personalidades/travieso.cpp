#include "travieso.h"

Travieso::Travieso(){
}

string Travieso::mostrar_personalidad(){
    return personalidad;
}

void Travieso::modificar_bases(float &crecimiento_hambre, float &decrecimiento_higiene){
    decrecimiento_higiene = (decrecimiento_higiene) * this->estadistica_higiene;
}