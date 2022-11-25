#include <iostream>

using namespace std;

int const INF = -1;

int const filas = 7;
int const columnas = 7;

int main() 
{

    int matriz_ady[filas][columnas];

    /* 64 224*/

    /*1 -> 2 ; Coste X*/
    /*2 -> 3 ; Coste X*/

    int V; //Vertices
    int E; //Conexiones

    int u, v , w;

    for (int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            matriz_ady[i][j] = INF;
        }
        matriz_ady[i][j] = 0;

    }
    
}