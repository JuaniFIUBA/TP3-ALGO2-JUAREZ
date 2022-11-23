#include <iostream>
using namespace std;
#include "Nodo_AB.h"
// #include "arbol_b_3_vias.h"
#include "vector.h"
int main(void)
{

    // Vector<int*> g1(3);
    // if(g1.en(0) == nullptr)
        // cout << "asdsa" << endl;
    // for(int i = 0; i < 3;i++){
    //     g1.en(i) = i+1;
    // }


    Nodo_AB<int, bool> nodo1(3, 1, true);
    nodo1.insertar_clave(2, true);
    nodo1.insertar_clave(3, true);
    nodo1.obtener_hijo(0)->asignar_padre(&nodo1);
    nodo1.obtener_hijo(1)->asignar_padre(&nodo1);
    nodo1.obtener_hijo(1)->insertar_clave(4, true);// HACER UN OBTENER HIJO DERECHA, IZQUIERDA.
    nodo1.obtener_hijo(1)->insertar_clave(5, true);// HACER UN OBTENER HIJO DERECHA, IZQUIERDA.
    nodo1.obtener_hijo(2)->asignar_padre(&nodo1);
    nodo1.obtener_hijo(2)->insertar_clave(6, true);
    nodo1.obtener_hijo(2)->insertar_clave(7, true);
    nodo1.obtener_hijo(0)->asignar_padre(&nodo1);
    nodo1.obtener_hijo(1)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(1)->obtener_hijo(1)->insertar_clave(8, true);
    // nodo1.obtener_hijo(1)->obtener_hijo(1)->insertar_clave(9, true);
    // nodo1.obtener_hijo(1)->obtener_hijo(2)->mostrar_claves();
    // cout << nodo1.obtener_hijo(1)->obtener_claves_usadas();

    // Nodo_AB<int, bool> nodo1(3, 5, true);
    // nodo1.insertar_clave(6, true);
    // nodo1.insertar_clave(7, true);
    // nodo1.obtener_hijo(0)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(1)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(0)->insertar_clave(3, true); // HACER UN OBTENER HIJO DERECHA, IZQUIERDA.
    // nodo1.obtener_hijo(0)->insertar_clave(4, true); // HACER UN OBTENER HIJO DERECHA, IZQUIERDA.
    // nodo1.obtener_hijo(0)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(0)->insertar_clave(1, true);
    // nodo1.obtener_hijo(0)->insertar_clave(2, true);

    return 0;
}




