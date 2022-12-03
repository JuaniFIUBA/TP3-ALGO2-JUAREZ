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
    //Pre: 
    //Post: Se va a tener la string correspondiente al consumo de cada casillero.
    string asignar_color(int consumo);
    //Pre: Debe recibir un archivo valido de 64 valores.
    //Post: Se va a cargar una matriz con todos los consumos de cada casillero.
    void cargar_mapa_consumo();
    //Pre:
    //Post: Matriz cargada con todas las strings de los colores correspondientes a cada casillero.
    void cargar_colores();
    //Pre:
    //Post: Se va a tener un vector con todas las inciales y posiciones de los animales sin superponerse
    void cargar_animales();
    //Pre:
    //Post: Se colocan los animales en la matriz terreno en su posicion
    void colocar_animales();
    //Pre:
    //Post: Se coloca al jugador en la matriz terreno en su posicion.
    void colocar_jugador();
    //Pre:
    //Post: Se modifica la posicion del jugador.
    void modificar_jugador(int fil_orig, int col_orig, int fil_dest, int col_dest);
    //Pre:
    //Post: Se obtiene la distancia manhattan entre dos coordenadas.
    int distancia_manhattan(int fil_1, int col_1, int fil_2, int col_2);
    //Pre:
    //Post: En caso de coincidir la posicion del jugador con la un animal, se obtiene la posicion de ese animal en el vector.
    int jugador_en_animal(int fil_auto, int col_auto);
    //Pre:
    //Post: Se elimina el animal del vector en caso de que el jugador se encuentre en esa posicion.
    void eliminar_animal(int fil_auto, int col_auto);
    void colocar_indices();

public:
    Terreno();
    //Pre:
    //Post: Inicializa el terreno para comenzar el juego.
    void inicializar_terreno();
    //Pre:
    //Post: Actualiza los valores de la matriz conforme transcurre el juego.
    void actualizar_terreno(int fil_orig, int col_orig, int fil_dest, int col_dest);
    //Pre:
    //Post: Se podra ver los casilleros, animales y el jugador todo con su debido color.
    void mostrar_terreno();
};

#endif