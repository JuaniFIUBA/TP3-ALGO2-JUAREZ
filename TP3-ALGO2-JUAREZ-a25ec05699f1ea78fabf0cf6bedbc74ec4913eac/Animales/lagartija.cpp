#include "lagartija.h"

Lagartija::Lagartija(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad) : Animal(nombre, edad, tamanio, especie, personalidad){
    this->personalidad->modificar_bases(crecimiento_hambre, decrecimiento_higiene);
}

string Lagartija::devolver_especie(){
    return especie_t;
}

void Lagartija::lavarse(){
    cout<<"La "<<especie_t<<" no quiere bañarse, las "<<especie_t<<"s no necesitan bañarse"<<endl;
}

void Lagartija::alimentarse(){
    cout<<"Alimentaste al "<<especie_t<<", "<<Animal::obtener_nombre()<<" con insectos "<<endl;
    hambre = 0;
}

void Lagartija::pasar_tiempo(){
    if(hambre + crecimiento_hambre > 100){
        this->hambre = 100;
    }else{
        this->hambre = hambre + crecimiento_hambre;
    }
}

Lagartija::~Lagartija(){
    delete personalidad;
}