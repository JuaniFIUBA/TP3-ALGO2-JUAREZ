#include <iostream>

using namespace std;

char opc;
char volver;
char valor;

struct nodo{
    int numero; //Nombre del vertice o nodo
    struct nodo *sgte;
    struct arista *ady; //Puntero hacia la primera arista del nodo
};

typedef struct nodo *Tnodo;
Tnodo puntero; //Puntero cabeza

struct arista{
    struct nodo *destino;//Puntero al nodo de llegada
    struct arista *sgte;
};

typedef struct arista *Tarista;

//Este metodo inserta un nuevo nodo al grafo.

void insertar_nodo(){
    //iNSTANCIA EL NODO Y DECLARA UN NUEVO PUNTERO
    Tnodo t, nuevo = new struct nodo;
    cout<<"Ingrese un numero para el nodo: "<<endl;
    cin>>nuevo->numero;
    nuevo->sgte=NULL;
    nuevo->sgte=NULL;
    //Si el puntero esta vacio lo crea.
    if(puntero==NULL){
        puntero = nuevo;
        cout<<"Nodo ingresado"<<endl;
    }
    else{
        //Si no debe recorrer este puntero para preguntar
        //Por la variable siguiente que este vacia
        t = puntero;
        while(t->sgte!=NULL){
            t = t->sgte;
        }
        cout<<"Nodo ingresado"<<endl;

    }
}

//este metodo agrega la arista
void agregar_arista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo){
    //Con el puntero de la arista incializamos otro puntero
    Tarista q;
    //Preguntamos si esta vacio para ingresar la nueva arista
    if(aux->ady==NULL){
        aux->ady=nuevo;
        nuevo->destino=aux2;
    }else{
        q=aux->ady;
        while(q->sgte!=NULL){
            q=q->sgte;
        }
        //Cuando encontremos la libre ahí si ingresamos la arista.
        nuevo->destino=aux2;
        q->sgte=nuevo;
        cout<<"Arista ingresada"<<endl;
    }
}

void insertar_arista(){
    //Declaramos variables para capturar el nodo final y el inicial
    int ini, fin;
    //Instancia auna arista
    Tarista nuevo = new struct arista;
    //Instancia dos nodos
    Tnodo aux, aux2;
    //Si el puntero esta vacio es porque no se ha definido
    //Ningun nodo
    if(puntero==NULL){
        cout<<"No hay Grafo"<<endl;
        return;
    }

    //De lo contrario instancia el nodo siguiente en null
    nuevo->sgte=NULL;
    //Coon estas dos variables captura el nodo final y el inicial
    cout<<"Ingrese el nodo de inicio:"<<endl;
    cin>>ini;
    cout<<"Ingrese el nodo final:"<<endl;
    cin>>fin;
    //A las dos variables auxiliares la llevamos el puntero
    aux=puntero;
    aux2=puntero;
    //Verificamos si el auxiliar dos tien ealgo
    while(aux2!=NULL){
        cout<<"Estas en el while"<<endl;
        if(aux2->numero==fin){
            break;
        }
        aux=aux2->sgte;
    }
    while(aux!=NULL){
        if(aux->numero==ini){
            agregar_arista(aux,aux2,nuevo);
            return;
        }
        aux=aux->sgte;
    }
}

void mostrar_grafo(){
    //Se instancia el puntero del nodo y el puntero de la arista
    Tnodo ptr;
    Tarista ar;
    //El puntero del nodo le llevamos el que tenemos inicialmente
    ptr=puntero;
    cout<<"Nodo : Adyacencia"<<endl;
    //Si esta vacio
        while(ptr!=NULL){
            //Muestra el dato del puntero
            cout<<"     "<<ptr->numero<<"|";
            if(ptr->ady!=NULL){
                ar=ptr->ady;
                //Despues muestra todas las aristas que tiene ese putnero
                while(ar!=NULL){
                    cout<<" "<<ar->destino->numero;
                    ar=ar->sgte;
                }
            ptr=ptr->sgte;
            cout<<endl;    
            }
        }
}

void mostrar_aristas(){
    //Inicializamos nodo y arista
    Tnodo aux;
    Tarista ar;
    int var;
    cout<<"Mostrar arista del nodo"<<endl;
    cout<<"Ingresa el nodo:"<<endl;
    cin>>var;
    //Capturamos el puntero y comenzamos el ciclo
    aux = puntero;
    while(aux!=NULL){
        if(aux->numero==var){
            if(aux->numero==var){
                if(aux->ady==NULL){
                    cout<<"El nodo no tiene aristas"<<endl;
                    return;
                }
                else{
                    cout<<"Nodo: Adyacencia"<<endl;
                    cout<<"     "<<aux->numero<<"|"<<endl;
                    ar=aux->ady;
                //Luego lo lleva a la siguiente posición para mostrar todas las aristas que tiene este nodo
                //Cuando termine se sale del programa
                }
                while(ar!=NULL){
                    cout<<ar->destino->numero<<"    ";
                    ar=ar->sgte;
                }
                cout<<endl;
                return;
            }
        }
        else{
            aux = aux->sgte;
        }
    }
}

void crear_menu(){
    cout<<"** Administracion de Grafos **"<<endl;
    cout<<"** Dijiste el numero de la accion que se desea realizar**"<<endl;
    cout<<"..."<<endl;
}

int main(){
    puntero=NULL;

    volver = 's';
    while(volver=='s'){
        crear_menu();
        cin>>opc;

        switch(opc){
            case '1':
            //Insertar nodo en el grafo
                insertar_nodo();
                break;
            case '2':
                insertar_arista();
                break;
            case '3':
                mostrar_grafo();
                break;
            case '4':
                mostrar_aristas();
                break;
            case '5':
                cout<<"Salir"<<endl;
                return 0;
                break;

            default:
                cout<<"Opcion no valida"<<endl;
            }
            cout<<"Para volver al menu principal dijite s/n";
            cin>>volver;
        }
    return 0;
}
