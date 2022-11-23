#ifndef VECTOR
#define VECTOR

template <class T>
class Vector
{
    private:
        T *datos;    
        int pedidos;
        // int usados; 
    
    public:
        //constructor
        Vector(int largo);
        
        void insertar(int pos, T dato);

        void insertar(T* iterador, T dato);

        void borrar(T *iterador);
    
        void borrar(int pos);

        int tamanio();

        T& en(int pos);

        void borrar_atras();

        void redimensionar(int nuevo_tamanio);
        //destructor
        ~Vector();
};

template <class T>
Vector<T>::Vector(int largo){
    this -> datos = new T[largo];
    this -> pedidos = largo;
    // this -> usados = 0;
}

// template <class T>   
// void Vector<T>::insertar(T* iterador, T dato){

//     T* nuevo_array = new T(cantidad + 1);
//     for(int i = 0; i < cantidad; i++){
//         if(i ==)
//     }
// }

template <class T>
void Vector<T>::insertar(int pos, T dato){
    this -> pedidos++;
    T* nuevo_array = new T[pedidos];
    nuevo_array[pos] = dato;
    int i = 0;
    int j =  0;
    while(i < pedidos){
        if(i == pos)
            i++;
        nuevo_array[i] = datos[j];
        i++;
        j++;
    }
    // usados++;
    delete [] datos;
    datos = nuevo_array; 
}

template <class T>
void Vector<T>::borrar(int pos){
    this -> pedidos--;
    T* nuevo_array = new T[pedidos];
    int i = 0; 
    int j = 0;
    while(i < pedidos){
        if(i == pos)
            i++;
        nuevo_array[j] = datos[i];
        j++;
        i++;
    }
    delete [] datos;
    datos = nuevo_array;
}


template <class T>
int Vector<T>::tamanio(){
    return this -> pedidos;
}


template <class T>
T& Vector<T>::en(int pos){
    return *(datos + pos);
}

template <class T>
void Vector<T>::borrar_atras(){
    pedidos--;
    T* nuevo_array = new T[pedidos];
    for(int i = 0; i < pedidos; i++)
        nuevo_array[i] = datos[i];
    delete [] datos;
    datos = nuevo_array;
}

template <class T>
void Vector<T>::redimensionar(int nuevo_tamanio){
    T* nuevo_array = new T[nuevo_tamanio];
    for(int i = 0; i < pedidos; i++)
        nuevo_array[i] = datos[i];
    pedidos = nuevo_tamanio;
    delete [] datos;
    datos = nuevo_array;
}

template <class T>
Vector<T>::~Vector()
{
    delete [] datos;
}
#endif
