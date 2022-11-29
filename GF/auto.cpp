#include "auto.hpp"

Auto::Auto(){
    posicion.fil = 0;
    posicion.col = 0;
    combustible = 100;
    identificador = 'X';
}

void Auto::recargar_combustible(){
    combustible += 5;
}

void Auto::restar_combustible(int costo){
    combustible =- costo;
}

void Auto::mover_izquierda(){
    posicion.col --;
}

void Auto::mover_derecha(){
    posicion.col ++;
}

void Auto::mover_arriba(){
    posicion.fil ++;
}

void Auto::mover_abajo(){
    posicion.fil --;
}

coor Auto::obtener_posicion(){
    return posicion;
}

int Auto::obtener_combustible(){
    return combustible;
}