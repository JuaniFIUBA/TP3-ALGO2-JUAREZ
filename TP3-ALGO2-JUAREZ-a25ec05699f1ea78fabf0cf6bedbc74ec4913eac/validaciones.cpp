#include "validaciones.h"
#include "sistema.hpp"

bool solicitar_personalidad(string &personalidad)
{
    cout << "Ingrese una personalidad: (jugueton, travieso, sociable o dormilon)" << endl;
    getline(cin, personalidad);
    a_minuscula(personalidad);
    if(!verificar_dato<string>(personalidad, (string*)PERSONALIDADES, CANTIDAD_PERSONALIDADES))
    {
        cout << "La personalidad ingresada es inválida" << endl;
        return false;
    }
    personalidad[0] = (char)toupper(personalidad[0]); 
    return true;
}



bool solicitar_tamanio(string &tamanio)
{
    cout << "Ingrese un tamanio: (diminuto, pequeño, mediano, grande o gigante)" << endl;
    getline(cin, tamanio);
    a_minuscula(tamanio);
    if(!verificar_dato<string>(tamanio, (string*)TAMANIOS, CANTIDAD_TAMANIOS))
    {
        cout << "El tamanio <" << tamanio << "> ingresado es inválido." << endl;
        return false;
    }
    return true;
}

bool solicitar_especie(char &especie)
{
    cout << "Ingrese una de las letras que se mostrarán a continuación para indicar la especie: " << endl;
    cout << "P: Perro, G: Gato, C: Caballo, R: Roedor, O: Conejo, E: Erizo, L: Lagartija " << endl;
    cin >> especie;
    especie = (char)toupper(especie);
    if(!verificar_dato<char>(especie, (char*)ESPECIES, CANTIDAD_ESPECIES))
    {
        cout << "La especie ingresada es inválida" << endl;
        return false;
    }
    return true;
}

template <typename T>
bool verificar_dato(T dato, T* array_datos, int largo_array)
{
    for(int i = 0; i < largo_array; i++)
    {
        if(dato == array_datos[i])
            return true;
    }
    return false;
}

void a_minuscula(string &cadena)
{
    int largo_cadena = (int)cadena.length();
    for(int i = 0; i < largo_cadena; i++)
        cadena[i] = (char)tolower(cadena[i]);
    cadena[largo_cadena] = '\0'; 
    
}

bool es_opcion_valida(string opcion, int rango_min, int rango_max){
    bool son_caracteres_numericos = true;
    int i = 0;
    int cantidad_numeros = (int)opcion.length();

    while(son_caracteres_numericos && i < cantidad_numeros){
        son_caracteres_numericos = isdigit(opcion[i]);
        i++;
    }
    if(!son_caracteres_numericos || stoi(opcion) < rango_min || stoi(opcion) > rango_max){
        return false;
    }
    return son_caracteres_numericos;
}