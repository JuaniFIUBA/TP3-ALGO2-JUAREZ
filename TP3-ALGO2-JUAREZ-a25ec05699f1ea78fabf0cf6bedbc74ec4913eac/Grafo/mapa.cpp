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

void Mapa::iniciar_terreno()
{
    terreno_t.inicializar_terreno();
}

void Mapa::mostrar_mapa(){
    terreno_t.mostrar_terreno();
}

void Mapa::coordenada_valida(int &ingreso){
    while((ingreso < 0)||(ingreso > 7)){
        std::cout<<"Ingrese por favor un numero entre 0 y 7: ";
        cin>>ingreso;
    }
}

char Mapa::trasladar()
{
    int origen, destino;
    int fila_destino, columna_destino;


    std::cout<<"Ingrese por favor la fila destino: ";
    cin>>fila_destino;

    coordenada_valida(fila_destino);

    std::cout<<"Ingrese por favor la columna destino:";
    cin>>columna_destino;

    coordenada_valida(columna_destino);

    origen = vehiculo.obtener_posicion();
    destino = traducir_coordenadas(fila_destino, columna_destino);

    camino_minimo(origen, destino);
    std::cout<<"Combustible actual: "<<vehiculo.obtener_combustible()<<std::endl;  
    return terreno_t.eliminar_animal(fila_destino, columna_destino); 
}


void Mapa::camino_minimo(int origen,int destino)
{   
    int costo;
    costo = grafo.Dijkstra(origen,destino);

    int combustible_previo = vehiculo.obtener_combustible();
    vehiculo.restar_combustible(costo); 

    if(combustible_previo == vehiculo.obtener_combustible())
    {
        if(!vehiculo.queda_combustible())
            std::cout<<"El vehiculo no tiene el suficiente combustible"<<std::endl;
    }else{
        mostrar_recorrido();
        vehiculo.cambiar_posicion(destino);
        std::cout<<"La posicion del origen es:"<<origen<<std::endl;
        std::cout<<"La posicion del destino es:"<<destino<<std::endl;
    }
    
}

void Mapa::mostrar_recorrido()
{
    coor coordenadas;
    coor coordenadas_auto;
    int posicion_auto = vehiculo.obtener_posicion();
    coordenadas_auto = traducir_posicion(posicion_auto);
    
    //for(int i = (grafo.tope_recorrido - 1) ; i <= 0; i--){
    int i = grafo.tope_recorrido -1; //tope
    while(i >= 0){    
        coordenadas = traducir_posicion(grafo.recorrido[i]);
        
        terreno_t.actualizar_terreno(coordenadas_auto.fil, coordenadas_auto.col, coordenadas.fil, coordenadas.col);
        terreno_t.mostrar_terreno();
        
        
        coordenadas_auto = coordenadas;
        std::cout<<"Auto cambiado: "<<coordenadas_auto.fil<<"-"<<coordenadas_auto.col<<std::endl;

        i--;
    }
}

int Mapa::traducir_coordenadas(int x, int y)
{
    int posicion = (x * 8) + y; //Cada x fila hay una diferencia de 8 con el anterior F0 C1 = 0; F1 C1 = 8

    return posicion;
}

coor Mapa::traducir_posicion(int posicion)
{ 
    int fil = 0; 
    coor coordenadas;


    while(posicion >= COLUMNAS*fil) //Analiza cual es la fila y columna correspondiente a la posicion
    {
        fil++;
    }
        
    if(COLUMNAS*fil == 0)
    {
        coordenadas.col = posicion;
        coordenadas.fil = fil;
    } else{
        coordenadas.col = posicion - COLUMNAS * (fil - 1);
        coordenadas.fil = (fil-1);
    }

    return coordenadas;
    
}

void Mapa::recarga_automatica()
{
    vehiculo.recarga_automatica();
    std::cout<<"El combustible es... "<<vehiculo.obtener_combustible()<<std::endl;;
}

void Mapa::cargar_combustible(){
    vehiculo.cargar_combustible();
}

Mapa::~Mapa()
{
    grafo.eliminar_todo();
}