#include "auto.hpp"
#include "../validaciones.h"

Auto::Auto(){
    posicion = 0;
    combustible = 100;
    identificador = 'X';
}

void Auto::cargar_combustible(){
    std::cout << "El combustible actual es: " << combustible << std::endl;
    
    int valor;
    std::cout << "Ingrese el valor de combustible que desea cargar(entre 0 y 100): " << std::endl;
    valor = validar_opcion(0, 100);

    if ((combustible + valor) <= 100)
    {
        combustible += valor;
    }else{
        combustible = 100;
    }
}

void Auto::recarga_automatica(){
    if ((combustible + 5) <= 100)
    {
        combustible += 5;
    }else{
        combustible = 100;
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

int Auto::validar_opcion(int min, int max){
    std::string opcion;
    getline(cin>>ws, opcion);
    while(!es_opcion_valida(opcion, min, max)){
        cout<<"El dato ingresado no es válido. Por favor, ingrese una opción correcta: ";
        getline(cin>>ws, opcion);
    }
    return stoi(opcion);
}


int Auto::obtener_combustible(){
    return combustible;
}

bool Auto::queda_combustible(){
    return combustible != 0;
}