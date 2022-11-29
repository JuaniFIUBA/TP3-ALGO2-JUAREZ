#include <iostream>
#include "terreno.hpp"

int main(){
    Terreno t = Terreno();
    t.cargar_terreno();
    t.mostrar_terreno();
    return 0;
}