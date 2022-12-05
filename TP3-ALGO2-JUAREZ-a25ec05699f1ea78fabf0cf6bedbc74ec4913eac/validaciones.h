#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <iostream>

using namespace std;

//pre: 
//pos: devuelve true en caso de que todos los datos ingresados sean válidos
bool solicitar_personalidad(string &personalidad);

//pre: 
//pos: devuelve true en caso de que todos los datos ingresados sean válidos
bool solicitar_tamanio(string &tamanio);

//pre: 
//pos: devuelve true en caso de que todos los datos ingresados sean válidos
bool solicitar_especie(char &especie);

//pre: 
//pos: devuelve true en caso de que el dato esté en el array de datos
template <typename T> 
bool verificar_dato(T dato, T* array_datos, int largo_array);

//pre: 
//pos: devuelve el string en minuscula (no devuelve Ñ en minúsculas)
void a_minuscula(string &cadena);

//pre:
//pos: devuelve true en caso de que la opcion esté contenida entre los rangos dados (incluídos)
bool es_opcion_valida(string opcion, int rango_min, int rango_max);

   
#endif