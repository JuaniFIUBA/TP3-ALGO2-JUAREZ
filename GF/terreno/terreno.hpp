#ifndef TERRENO_HPP
#define TERRENO_HPP

#include<iostream>
#include<cstdlib>
#include<string>
#include <fstream>
#include "colors.h"
const int ANIMALES_A_SER_RESCATADOS = 5;
const int SUPERPUESTOS = 0;

using namespace std;

struct coor{
    int col;
    int fil;
};

struct animal_rescate{
    coor pos;
    char especie;
};

class Terreno{
private:
    //Atributos
    static const int dimension = 8;
    string colores[dimension][dimension];
    char terreno[dimension][dimension];
    int mapa_de_consumo[dimension][dimension];
    animal_rescate animales[5];
    //Metodos
    string asignar_color(int consumo);
    void cargar_mapa_consumo();
    void cargar_colores();
    void cargar_animales();
    void colocar_animales();
    int distancia_manhattan(coor pos1, coor pos2);

public:
    Terreno();
    void cargar_terreno();
    void mostrar_terreno();
};

#endif