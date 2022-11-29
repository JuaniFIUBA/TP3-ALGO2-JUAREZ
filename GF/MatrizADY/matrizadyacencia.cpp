#include <iostream>

using namespace std;

#define INF 99;

int const filas = 8;
int const columnas = 8;

int main() 
{
    int matriz_ady[filas][columnas];

    /* 64 224*/

    /*1 -> 2 ; Coste X*/
    /*2 -> 3 ; Coste X*/

    int V = 64; //Vertices
    int E = 244; //Conexiones

    cin >> V >> E;

    int u, v , w;

    for (int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            matriz_ady[i][j] = INF;
        }
        matriz_ady[i][i] = 0;
    }

    for (int i = 0; i < E; i++){
        cin >> u >> v >> w;

        u--;
        v--;

        matriz_ady[u][v] = w;
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout<<matriz_ady[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}