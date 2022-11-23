#include <iostream>
using namespace std;
#include "Nodo_AB.h"
// #include "arbol_b_3_vias.h"
#include <vector>
int main(void)
{

    Nodo_AB<int, bool> nodo1(3, 1, true);
    nodo1.insertar(2, true);
    nodo1.insertar(3, true);
    nodo1.obtener_hijo(0)->asignar_padre(&nodo1);
    nodo1.obtener_hijo(1)->asignar_padre(&nodo1);
    nodo1.obtener_hijo(1)->insertar(4, true);// HACER UN OBTENER HIJO DERECHA, IZQUIERDA.
    nodo1.obtener_hijo(1)->insertar(5, true);// HACER UN OBTENER HIJO DERECHA, IZQUIERDA.
    nodo1.obtener_hijo(2)->asignar_padre(&nodo1);
    nodo1.obtener_hijo(2)->insertar(6, true);
    nodo1.obtener_hijo(2)->insertar(7, true);
    nodo1.obtener_hijo(0)->asignar_padre(&nodo1);
    nodo1.obtener_hijo(1)->asignar_padre(&nodo1);
    nodo1.obtener_hijo(1)->obtener_hijo(1)->insertar(8, true);
    nodo1.obtener_hijo(1)->obtener_hijo(1)->insertar(9, true);
    nodo1.obtener_hijo(1)->obtener_hijo(2)->mostrar_claves();
    // cout << nodo1.obtener_hijo(1)->obtener_claves_usadas();

    // Nodo_AB<int, bool> nodo1(3, 5, true);
    // nodo1.insertar(6, true);
    // nodo1.insertar(7, true);
    // nodo1.obtener_hijo(0)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(1)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(0)->insertar(3, true); // HACER UN OBTENER HIJO DERECHA, IZQUIERDA.
    // nodo1.obtener_hijo(0)->insertar(4, true); // HACER UN OBTENER HIJO DERECHA, IZQUIERDA.
    // nodo1.obtener_hijo(0)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(0)->insertar(1, true);
    // nodo1.obtener_hijo(0)->insertar(2, true);

    return 0;
}   




