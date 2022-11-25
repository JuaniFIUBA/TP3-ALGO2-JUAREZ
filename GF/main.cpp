#include <iostream>
#include "grafo.hpp"

using namespace std;

int main()
{
    Grafo *grafo = new Grafo();
    int opc = 0;

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
        cout <<"8.Salir del menu" <<endl;
    }
}