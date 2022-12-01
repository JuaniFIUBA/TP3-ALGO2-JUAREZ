#include <iostream>
#include "mapa.hpp"
#include "grafo.hpp"
#include <time.h>

using namespace std;

int main()
{
    srand((unsigned) time(NULL));

    Mapa mapa;
    
    mapa.crear_casilleros();

    mapa.unir_casilleros();

    mapa.mostrar_mapa();

    mapa.trasladar();

    mapa.trasladar();




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