#include "caballo.h"

Caballo::Caballo(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad) : Animal(nombre, edad, tamanio, especie, personalidad){
    this->personalidad->modificar_bases(crecimiento_hambre, decrecimiento_higiene);
}

string Caballo::devolver_especie(){
    return especie_t;
}

void Caballo::lavarse(){
    cout<<"El "<<especie_t<<" se ha bañado"<<endl;
    higiene = 100;
}

void Caballo::alimentarse(){
    cout<<"Alimentaste al "<<especie_t<<", "<<Animal::obtener_nombre()<<" con manzanas"<<endl;
    hambre = 0;
}

void Caballo::pasar_tiempo(){
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

Caballo::~Caballo(){
    delete personalidad;
}