#include "perro.h"

Perro::Perro(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad) : Animal(nombre, edad, tamanio, especie, personalidad){
    this->personalidad->modificar_bases(crecimiento_hambre, decrecimiento_higiene);
}

string Perro::devolver_especie(){
    return especie_t;
}

void Perro::lavarse(){
    cout<<""<<Animal::obtener_nombre()<<", se ha bañado"<<endl;
    higiene = 100;
}

void Perro::alimentarse(){
    cout<<"Alimentaste al "<<especie_t<<", "<<Animal::obtener_nombre()<<" con huesos "<<endl;
    hambre = 0;

}

void Perro::pasar_tiempo(){
    if(hambre + crecimiento_hambre > 100){
        this->hambre = 100;
    }else{
        this->hambre = hambre + crecimiento_hambre;
    }
    
    if(higiene - decrecimiento_higiene < 0){
        this->higiene = 0;
    }else{
        this->higiene = higiene - decrecimiento_higiene;
    }
}

Perro::~Perro(){
    delete personalidad;
}