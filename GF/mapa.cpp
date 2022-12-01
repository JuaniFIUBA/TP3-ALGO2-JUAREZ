#include "mapa.hpp"
#include <fstream>

using namespace std;

void Mapa::crear_casilleros()
{
    int posicion = 0;
    //Esto se puede fusionar
    for(int i = 0; i < FILAS; i++)
    {
        for(int j = 0; j < COLUMNAS; j++)
        {
             grafo.insertar_vertice(posicion);
             posicion++;
        }
    }  
}


void Mapa::unir_casilleros()
{
    //std::cout<<"Entraste al unir casilleros"<<std::endl;
    ifstream conexiones ("conexiones.txt");

    if(!conexiones.is_open()){
        std::cout<<"Error al abrir el archivo"<<std::endl;
    
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

void Mapa::editar_mapa(){
    //terreno_t.cargar_terreno();
}

void Mapa::mostrar_mapa(){
   
    //terreno_t.mostrar_terreno();
   /*
    for(int i = 0; i < DIMENSION_ADY; i++){
        std::cout<<std::endl;
        for(int j = 0; j < DIMENSION_ADY; j++){
            std::cout<<matriz_de_adyacencia[i][j]<<" ";
        }
    }
    std::cout<<std::endl;
   */
}

void Mapa::trazladar()
{
    int origen, destino;
    int fila_destino, columna_destino;

    std::cout<<"Ingrese por favor la fila destino (Coordenada X): ";
    cin>>fila_destino;
    
    std::cout<<"Ingrese por favor la columna destino (Coordenada Y):";
    cin>>columna_destino;

    origen = vehiculo.obtener_posicion();
    destino = traducir_coordenadas(fila_destino, columna_destino);

    camino_minimo(origen, destino);
    std::cout<<"Combustible actual: "<<vehiculo.obtener_combustible()<<std::endl;  
    editar_mapa();
}


void Mapa::camino_minimo(int origen,int destino)
{   
    int costo;
    costo = grafo.Dijkstra(origen,destino);

    int combustible_previo = vehiculo.obtener_combustible();
    vehiculo.restar_combustible(costo); 

    if(combustible_previo == vehiculo.obtener_combustible())
    {
        std::cout<<"El vehiculo no tiene el suficiente combustible"<<std::endl;
    }else{
        vehiculo.cambiar_posicion(destino);
        std::cout<<"La posicion del origen es:"<<origen<<std::endl;
        std::cout<<"La posicion del destino es:"<<destino<<std::endl;
    }
    
}

/*
void Mapa::mostrar_recorrido()
{
    int posicion;

    //Se itera la variable del grafo recorrido, pasanda los vertices al traducir posicion, obteniendo las coordenadas para la matriz.
    traducir_posicion(posicion);
}
*/


int Mapa::traducir_coordenadas(int x, int y)
{
    int posicion = (x * 8) + y; //Cada x fila hay una diferencia de 8 con el anterior F0 C1 = 0; F1 C1 = 8

    return posicion;
}

coor Mapa::traducir_posicion(int posicion)
{
    int fil = 1; 
    int col = INF; 
    coor coordenadas;

    while(posicion < COLUMNAS*fil && col == INF) //Analiza cual es la fila y columna correspondiente a la posicion
    {
        if(posicion < COLUMNAS*fil)
        {
            col = posicion - COLUMNAS*FILAS; 
        }
    }

    coordenadas.col = col;
    coordenadas.fil = fil;

    return coordenadas;
    
}