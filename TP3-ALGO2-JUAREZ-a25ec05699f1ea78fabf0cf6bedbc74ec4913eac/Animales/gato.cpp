#include "gato.h"

Gato::Gato(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad) : Animal(nombre, edad, tamanio, especie, personalidad){
    this->personalidad->modificar_bases(crecimiento_hambre, decrecimiento_higiene);
}

string Gato::devolver_especie(){
    return especie_t;
}

void Gato::lavarse(){
    cout << Animal::obtener_nombre() << " se rehuso a bañarse, los "<< especie_t <<"s no necesitan bañarse"<<endl;
}

void Gato::alimentarse(){
    cout<<"Alimentaste al "<<especie_t<<", "<<Animal::obtener_nombre()<<" con atun "<<endl;
    hambre = 0;
}

void Gato::pasar_tiempo(){
    if(hambre + crecimiento_hambre > 100){
        this->hambre = 100;
    }else{
        this->hambre = hambre + crecimiento_hambre;
    }
}

Gato::~Gato(){
    delete personalidad;
}