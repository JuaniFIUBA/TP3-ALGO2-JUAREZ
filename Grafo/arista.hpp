#ifndef ARISTA_HPP
#define ARISTA_HPP

//Prototipo
class Vertice;

class Arista 
{
    private:
        int costo; //Costo de movimiento
        Arista *sig; //Siguiente arista
        Vertice *dest; //Vertice al que muevo

    friend class Grafo;

    public:
        Arista(Vertice* dest, int costo); //Esto se puede mejorar, sobrecargando la funcion, logrando instanciar sin paraemtros, y con parametros creando una arista 
};

#endif