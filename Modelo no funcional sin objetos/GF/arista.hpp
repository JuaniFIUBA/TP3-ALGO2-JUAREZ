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

    public:
        Arista(int costo);
};

#endif