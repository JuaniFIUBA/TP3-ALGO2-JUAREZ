#include <iostream>
#include "vector.hpp"

using namespace std;

//prototipo
void merge(Vector<int>&arreglo, int inicio, int mitad, int final);

void merge_sort(Vector<int>&arreglo, int inicio, int final)
{
    if(inicio < final){
        int mitad = inicio + (final - inicio)/2;
        merge_sort(arreglo, inicio, mitad);
        merge_sort(arreglo, mitad+1,final);
        merge(arreglo, inicio, mitad, final);
    }
}

void merge(Vector<int>&arreglo, int inicio, int mitad, int final){
    int i,j,k;
    int elementos_izquierda = mitad - inicio + 1;
    int elementos_derecha = final - mitad;

    Vector<int>izquierda(elementos_izquierda);
    Vector<int>derecha(elementos_derecha);

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
        if(izquierda.en(i) <= derecha.en(j))
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

void imprimir_arreglo(Vector<int>&arreglo)
{
    cout << arreglo.tamanio();
    for(int i = 0; i < int(arreglo.tamanio() -1); i++)
    {
        cout << arreglo.en(i) << " ";
    }
    cout << endl;
}

int main(){
    Vector<int> prueba1(7);
    
    prueba1.en(0) = 16;
    prueba1.en(1) = 6;
    prueba1.en(2) = 5;
    prueba1.en(3) = 44;
    prueba1.en(4) = 2;
    prueba1.en(5) = 14;
    prueba1.en(6) = 555;

    imprimir_arreglo(prueba1);
    merge_sort(prueba1,0,int(prueba1.tamanio()) - 1);
    imprimir_arreglo(prueba1);
}

//g++ *.cpp -Wall -Werror -Wconversion -o mergesort