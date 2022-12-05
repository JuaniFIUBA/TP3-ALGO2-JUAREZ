#include "mergesort.h"

void merge(Vector<Animal*>&arreglo, int inicio, int mitad, int final){
    int i,j,k;
    int elementos_izquierda = mitad - inicio + 1;
    int elementos_derecha = final - mitad;

    Vector<Animal*>izquierda(elementos_izquierda);
    Vector<Animal*>derecha(elementos_derecha);

    for(int i = 0; i < elementos_izquierda; i++){
        izquierda.en(i) = arreglo.en(inicio+i);
    }

    for(int j = 0; j < elementos_derecha; j++){
        derecha.en(j) = arreglo.en(mitad + 1 + j);
    }

    i = 0;
    j = 0;
    k = inicio;

    while(i < elementos_izquierda && j < elementos_derecha){
        if(izquierda.en(i)->obtener_edad() <= derecha.en(j)->obtener_edad())
        {
            arreglo.en(k) = izquierda.en(i);
            i++;
        }else{
            arreglo.en(k) = derecha.en(j);
            j++;
        }
        k++;
    }

    while(j < elementos_derecha)
    {
        arreglo.en(k) = derecha.en(j);
        j++;
        k++;
    }

    while(i < elementos_izquierda)
    {
        arreglo.en(k) = izquierda.en(i);
        i++;
        k++;
    }

}

void merge_sort(Vector<Animal*>&arreglo, int inicio, int final)
{
    if(inicio < final){
        int mitad = inicio + (final - inicio)/2;
        merge_sort(arreglo, inicio, mitad);
        merge_sort(arreglo, mitad + 1,final);
        merge(arreglo, inicio, mitad, final);
    }
}

