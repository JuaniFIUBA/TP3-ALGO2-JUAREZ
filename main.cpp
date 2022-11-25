#include <iostream>
using namespace std;
#include "Nodo_AB.h"
#include "arbol_b_3_vias.h"
#include "vector.h"

int main(void)
{



    // Nodo_AB<int, bool> nodo1(3, 1, true);
    // nodo1.insertar_clave(2, true);
    // nodo1.insertar_clave(3, true);
    // nodo1.obtener_hijo(0)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(1)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(1)->insertar_clave(4, true);// HACER UN OBTENER HIJO DERECHA, IZQUIERDA.
    // nodo1.obtener_hijo(1)->insertar_clave(5, true);// HACER UN OBTENER HIJO DERECHA, IZQUIERDA.
    // nodo1.obtener_hijo(2)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(2)->insertar_clave(6, true);
    // nodo1.obtener_hijo(2)->insertar_clave(7, true);
    // nodo1.obtener_hijo(1)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(0)->asignar_padre(&nodo1);
    // nodo1.obtener_hijo(1)->obtener_hijo(1)->mostrar_claves();
    // nodo1.obtener_hijo(1)->mostrar_claves();
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

    AB3<int, bool>ab(3);
    ab.agregar(1, true);
    ab.agregar(2, true);
    ab.agregar(3, true);
    ab.agregar(4, true);
    // ab.agregar(5, true);
    // ab.agregar(6, true);
    // ab.agregar(7, true);    
    // ab.agregar(8, true);
    // ab.agregar(9, true);
    // ab.agregar(10, true);
    // ab.agregar(11, true);
    ab.print_in_order();
    // ab.agregar(0, true);
    // ab.agregar(-1, true);
    // ab.agregar(-2, true);

    // ab.agregar(-3, true);
    // ab.agregar(8, true);    
    // ab.agregar(9, true);    
    // for(int i = 0; i < 40; i++)
        // ab.agregar(i, true);

    // ab.obtener_raiz()->mostrar_claves();
    // ab.print_in_order();
    return 0;
}




