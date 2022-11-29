#include "erizo.h"

Erizo::Erizo(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad) : Animal(nombre, edad, tamanio, especie, personalidad){
    this->personalidad->modificar_bases(crecimiento_hambre, decrecimiento_higiene);
}

string Erizo::devolver_especie(){
    return especie_t;
}

void Erizo::lavarse(){
    cout<<""<<Animal::obtener_nombre()<<", se ha bañado"<<endl;
    higiene = 100;
}

void Erizo::alimentarse(){
    cout<<"Alimentaste al "<<especie_t<<", "<<Animal::obtener_nombre()<<" con insectos"<<endl;
    hambre = 0;

}

void Erizo::pasar_tiempo(){
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

Erizo::~Erizo(){
    delete personalidad;
}