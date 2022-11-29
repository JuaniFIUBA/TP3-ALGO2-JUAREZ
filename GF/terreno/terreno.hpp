#ifndef TERRENO_HPP
#define TERRENO_HPP

#include<iostream>
#include<cstdlib>
#include<string>
#include "colors.h"

using namespace std;

class Terreno{
private:
    static const int dimension = 8;
    string terreno[dimension][dimension];
    int mapa_de_consumo[dimension][dimension];
    int asignar_consumo(string color);

public:
    Terreno();
    void cargar_terreno();
    void cargar_mapa_consumo();
    void mostrar_terreno();
};

#endif