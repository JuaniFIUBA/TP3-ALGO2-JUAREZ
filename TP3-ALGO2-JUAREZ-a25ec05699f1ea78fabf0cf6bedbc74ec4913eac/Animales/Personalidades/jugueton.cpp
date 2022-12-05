#include "jugueton.h"

Jugueton::Jugueton(){
}

string Jugueton::mostrar_personalidad(){
    return personalidad;
}

void Jugueton::modificar_bases(float &crecimiento_hambre,float &decrecimiento_higiene){
    crecimiento_hambre = crecimiento_hambre * this->estadistica_hambre;
}