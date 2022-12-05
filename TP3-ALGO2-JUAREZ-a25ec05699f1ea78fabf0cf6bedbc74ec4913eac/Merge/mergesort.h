#include <iostream>
#include "../vector.h"
#include "../Animales/animales.h"
#include "../Animales/perro.h"
#include "../Animales/gato.h"
#include "../Animales/caballo.h"
#include "../Animales/roedor.h"
#include "../Animales/conejo.h"
#include "../Animales/erizo.h"
#include "../Animales/lagartija.h"
#include "../Animales/Personalidades/dormilon.h"
#include "../Animales/Personalidades/jugueton.h"
#include "../Animales/Personalidades/sociable.h"
#include "../Animales/Personalidades/travieso.h"

void merge(Vector<Animal*>&arreglo, int inicio, int mitad, int final);
void merge_sort(Vector<Animal*>&arreglo, int inicio, int final);
