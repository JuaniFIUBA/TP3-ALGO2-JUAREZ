#ifndef MAPA_HPP
#define MAPA_HPP
#include "grafo.hpp"
#include "terreno.hpp"

const int FILAS = 8;
const int COLUMNAS = 8;

struct coor{
    int col;
    int fil;
};

class Mapa
{
    private:
        Grafo grafo;
        Auto vehiculo;
        Terreno terreno_t;
        int coordenada_valida();
        
    public:
        //Pre: Recibe la cantidad de filas y columnas
        //Pro: Une los vertices para crear casilleros para un mapa de fila x columna.Tiene que ser matriz cuadrada.
        void crear_casilleros();

        //Pre: Recibe la cantidad de filas y columnas
        //Pro: Une los vertices para crear casilleros para un mapa de fila x columna.Tiene que ser matriz cuadrada.
        void unir_casilleros();  

        //Pre:-
        //Post: Muestra el mapa en pantalla
        void mostrar_mapa();

        //Pre:-
        //Post: Pregunta al usuario hacia donde se desea trasladar
        void trasladar();

        //Pre:-
        //Post: Calcula el camino minimo a recorrer de origen a destino.
        void camino_minimo(int posicion_uno, int posicion_dos);

        //Pre: Usar camino_minimo
        //Post: Muestra en pantalla el recorrido hecho
        void mostrar_recorrido();

        //Pre:-
        //Post: Transforma las coordenadas recibidas en posición del vertice.
        int traducir_coordenadas(int x, int y);

        //Pre:-
        //Post: Descompone la posicion del vertice en coordenadasa X e Y.
        coor traducir_posicion(int posicion);

        //Pre:-Post
        //Post: Elimina el grafo
        void destruir_mapa();

        ~Mapa();
};

#endif