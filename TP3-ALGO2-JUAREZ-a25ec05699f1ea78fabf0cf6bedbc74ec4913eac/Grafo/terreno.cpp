#include "terreno.hpp"


Terreno::Terreno(){
    for(int i = 0; i < dimension; i ++){
        for(int j = 0; j < dimension; j ++){
            terreno[i][j] = ' ';
        }
    }
    tope_animales = ANIMALES_A_SER_RESCATADOS;
};

string Terreno::asignar_color(int consumo){
    if(consumo == 5){ //MONTAÑA
        return BGND_BROWN_94;
    }else if(consumo == 2){ //TIERRA
        return BGND_BROWN_137;
    }else if(consumo == 1){ //CAMINO
        return BGND_LIGHT_GRAY_246;
    }else{
        return BGND_BLACK_16;
    }
};

void Terreno::cargar_mapa_consumo(){
    fstream lista_consumo("./Grafo/colores.txt");
    if(!lista_consumo.is_open()){
        cout<< "Error, no se encuentra el archivo"<<endl;
    }
    string consumo;
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            getline(lista_consumo, consumo,',');
            mapa_de_consumo[i][j] = stoi(consumo);
        }
    }
}

int Terreno::distancia_manhattan(int fil_1, int col_1, int fil_2, int col_2){
    return  (abs((col_1 - col_2)) + abs((fil_1 - fil_2)));
}

void Terreno::colocar_jugador(){
    terreno[0][0] = auto_jugador.identificador;
}

void Terreno::modificar_jugador(int fil_orig, int col_orig, int fil_dest, int col_dest){
    std::cout<<fil_orig<<"-"<<col_orig<<endl;
    std::cout<<fil_dest<<"-"<<col_dest<<endl;
    terreno[fil_orig][col_orig] = ' ';
    terreno[fil_dest][col_dest] = auto_jugador.identificador;
    
}

void Terreno::cargar_animales(){
    char especies[] = {'P','G','C','L','R','O','E'};
    int i = 0;

    while(i < ANIMALES_A_SER_RESCATADOS){
        bool superpuestos = false;
        int fil = rand() % dimension;
        int col = rand() % dimension;
        for(int j = 0; j < ANIMALES_A_SER_RESCATADOS; j++){
            if(distancia_manhattan(fil,col,animales[j].fil,animales[j].col) == SUPERPUESTOS){
                superpuestos = true;
            }
        }
        if(distancia_manhattan(fil,col,0,0) == SUPERPUESTOS){
            superpuestos = true;
        }
        if(!superpuestos){
            char especie = especies[rand() % ANIMALES_A_SER_RESCATADOS];
            animales[i].fil = fil;
            animales[i].col = col;
            animales[i].especie = especie;
            i++;
        }
    }
}

void Terreno::cargar_colores(){
    for(int i = 0; i < dimension; i ++){
        for(int j = 0; j < dimension; j ++){
            colores[i][j] = asignar_color(mapa_de_consumo[i][j]);
        }
    }
}

void Terreno::colocar_animales(){
    for(int i = 0; i < ANIMALES_A_SER_RESCATADOS; i++){
        terreno[animales[i].fil][animales[i].col] = animales[i].especie;
    };
}

int Terreno::jugador_en_animal(int fil_auto, int col_auto){
    bool hay_animal = false;
    int i = 0;
    while((!hay_animal) && (i < tope_animales)){
        if(distancia_manhattan(animales[i].fil,animales[i].col, fil_auto, col_auto) == SUPERPUESTOS){
            return i;
        }i++;
    }return -1;
}

char Terreno::eliminar_animal(int fil_auto, int col_auto){
    int i = jugador_en_animal(fil_auto,col_auto);
    if(i != -1){
        char aux = animales[i].especie;
        terreno[animales[i].fil][animales[i].col] = auto_jugador.identificador;
        for(int j = i; j < tope_animales - 1; j++){
                animales[j] = animales[j+1];
        }tope_animales --;
        return aux;
    }
    return (char)-1;
}

void Terreno::inicializar_terreno(){
    cargar_mapa_consumo();
    cargar_colores();
    cargar_animales();
    colocar_jugador();
    colocar_animales();
}

void Terreno::actualizar_terreno(int fil_orig, int col_orig, int fil_dest, int col_dest){
    modificar_jugador(fil_orig,col_orig, fil_dest, col_dest);
    colocar_animales();
}

void Terreno::mostrar_terreno(){
    cout<<"  01234567"<<endl;
    int k = 0;
    for(int i = 0; i < dimension; i ++){
        for(int j = 0; j < dimension + 2; j ++){
            if (j == 0){
                cout<<k;
                k++;
            }else if(j == 1){
                cout<<"|";
            }else{
                cout << colores[i][j-2] << terreno[i][j-2] << END_COLOR;
            }
        }cout <<' '<<endl;
    } 
}

Terreno::~Terreno(){}