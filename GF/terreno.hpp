#ifndef TERRENO_HPP
#define TERRENO_HPP

#include<iostream>
#include<cstdlib>
#include<string>
#include <fstream>
#include "colors.h"
#include "auto.hpp"
const int ANIMALES_A_SER_RESCATADOS = 5;
const int SUPERPUESTOS = 0;

using namespace std;


struct animal_rescate{
    int fil;
    int col;
    char especie;
};

class Terreno{
private:
    //Atributos
    Auto auto_jugador;
    static const int dimension = 8;
    string colores[dimension][dimension];
    char terreno[dimension][dimension];
    int mapa_de_consumo[dimension][dimension];
    animal_rescate animales[5];
    int tope_animales;
    int pos_jugador;
    friend class Mapa;
    //Metodos
    string asignar_color(int consumo);
    void cargar_mapa_consumo();
    void cargar_colores();
    void cargar_animales();
    void colocar_animales();
    void colocar_jugador();
    void colocar_jugador(int fil_orig, int col_orig, int fil_dest, int col_dest);
    int distancia_manhattan(int fil_1, int col_1, int fil_2, int col_2);
    int jugador_en_animal(int fil_auto, int col_auto);
    void eliminar_animal(int fil_auto, int col_auto);

public:
    Terreno();
    void inicializar_terreno();
    void actualizar_terreno();
    void mostrar_terreno();
};

#endif