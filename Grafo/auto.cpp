#include "auto.hpp"

Auto::Auto(){
    posicion = 0;
    combustible = 100;
    identificador = 'X';
}

void Auto::recargar_combustible(){
    if ( (combustible + 5) <= 100)
    {
        combustible += 5;
    }
}

void Auto::restar_combustible(int costo){
    if(costo <= obtener_combustible())
    {
        combustible = combustible - costo;
    }
}

int Auto::obtener_posicion(){
    return posicion;
}

void Auto::cambiar_posicion(int posicion)
{
    this->posicion = posicion; 
}

int Auto::obtener_combustible(){
    return combustible;
}

bool Auto::queda_combustible(){
    return combustible != 0;
}