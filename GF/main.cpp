#include <iostream>
#include "mapa.hpp"
#include "grafo.hpp"

using namespace std;

const int Filas = 8;
const int Columnas = 8;

int main()
{
    Mapa mapa;
    
    
    //Hay que borrar el tema de casilleros o filas, dejarlas como cte por ejemplo
    mapa.crear_casilleros(Filas,Columnas);

    mapa.unir_casilleros();

    //grafo.llenar_matriz_ady();

    //mapa.mostrar_mapa();

    mapa.camino_minimo();


    /*
    while(opc != 8)
    {
        system("cls");
        cout <<"1. Insertar vertice" <<endl;
        cout <<"2. Insertar arista" <<endl;
        cout <<"3. Obtener capacidad"<<endl;
        cout <<"4. Mostrar lista de adyacencia"<<endl;
        cout <<"5. Eliminar vertice" <<endl;
        cout <<"6. Eliminar arista" <<endl;
        cout <<"7. Eliminar todo" <<endl;
        cout <<"8. Salir del menu" <<endl;
    }
    */

   return 0;

}

//Para probar de manera rapida g++ *.cpp -o Demo -Wall -Werror -Wconversion