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
             cout <<" Se ha creado el vertice nº"<< posicion << endl;
             posicion++;
        }
    }
    
}

void Mapa::unir_casilleros()
{
    std::cout<<"Entraste al unir casilleros"<<std::endl;
    ifstream conexiones ("conexiones.txt");

    if(!conexiones.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
    
    }

    string vertice_uno, vertice_dos, valor;

    while(getline(conexiones, vertice_uno, ',')){
        getline(conexiones, vertice_dos, ',');
        getline(conexiones, valor);
        
        std::cout<<"Vertice uno es..."<<vertice_uno<<" Y vertice dos es..."<<vertice_dos<<std::endl;

        int posicion_uno = stoi(vertice_uno);
        int posicion_dos = stoi(vertice_dos);
        int costo = stoi(valor);

        std::cout<<"Posicion uno es..."<<posicion_uno<<" Y posicion dos es..."<<posicion_dos<<" con un costo de..."<<costo<<std::endl;

        grafo.insertar_arista(posicion_uno, posicion_dos, costo);
    }

    conexiones.close();
    cout <<"Conexiones hechas, recordar borrar linea 49 de Mapa.cpp"<< endl;

}

void Mapa::mostrar_mapa(){
    grafo.mostrar_lista_adyacencia();
}