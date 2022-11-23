#ifndef VERTICE_HPP
#define VERTICE_HPP

//Prototipo
class Arista;

class Vertice
{
    private:
        int posicion; //Posicion del vertice
        Vertice *sig; //Siguiente vertice
        Arista *ady; //Siguiente arista

    friend class Grafo;

    public:
        Vertice(int posicion);
};

#endif