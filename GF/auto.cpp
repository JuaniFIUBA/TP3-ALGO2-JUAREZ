#include "auto.hpp"

Auto::Auto(){
    posicion = 0;
    combustible = 100;
    identificador = 'X';
}

void Auto::recargar_combustible(){
    combustible += 5;
}

void Auto::restar_combustible(int costo){
    combustible =- costo;
}

int Auto::obtener_posicion(){
    return posicion;
}

int Auto::obtener_combustible(){
    return combustible;
}