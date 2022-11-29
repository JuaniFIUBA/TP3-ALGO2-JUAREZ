#include "roedor.h"

Roedor::Roedor(string nombre, int edad, string tamanio, char especie, Personalidad *personalidad) : Animal(nombre, edad, tamanio, especie, personalidad){
    this->personalidad->modificar_bases(crecimiento_hambre, decrecimiento_higiene);
}

string Roedor::devolver_especie(){
    return especie_t;
}

void Roedor::lavarse(){
    cout << Animal::obtener_nombre() << " se rehuso a bañarse, los "<< especie_t <<"es no necesitan bañarse"<<endl;
}

void Roedor::alimentarse(){
    cout<<"Alimentaste al "<<especie_t<<", "<<Animal::obtener_nombre()<<" con queso "<<endl;
    hambre = 0;
}

void Roedor::pasar_tiempo(){
    if(hambre + crecimiento_hambre > 100){
        this->hambre = 100;
    }else{
        this->hambre = hambre + crecimiento_hambre;
    }
}

Roedor::~Roedor(){
    delete personalidad;
}