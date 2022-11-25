#include "mapa.hpp"
#include <fstream>

using namespace std;
    


void Mapa::crear_casilleros(int fila, int columna)
{
    int posicion = 0;

    for(int i = 0; i < fila; i++)
    {
        for(int j = 0; j < columna; j++)
        {
             grafo.insertar_vertice(posicion);
             posicion++;
        }
    }
}

void Mapa::unir_casilleros()
{

    ifstream conexiones ("conexiones.txt");

    if(!conexiones.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
    
    }

    string vertice_uno, vertice_dos, valor;

    


    while(getline(conexiones, vertice_uno, ',')){
        getline(conexiones, vertice_dos, ',');
        getline(conexiones, valor);

        int posicion_uno = stoi(vertice_uno);
        int posicion_dos = stoi(vertice_dos);
        int costo = stoi(valor);

        grafo.insertar_arista(posicion_uno, posicion_dos, costo);
    }

    conexiones.close();

}

void Mapa::mostrar_mapa(){
    grafo.mostrar_lista_adyacencia();
}