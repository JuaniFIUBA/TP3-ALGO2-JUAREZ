#include "terreno.hpp"


Terreno::Terreno(){
    for(int i = 0; i < dimension; i ++){
        for(int j = 0; j < dimension; j ++){
            terreno[i][j] = ' ';
        }
    } 
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
    fstream lista_consumo("colores.txt");
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

int Terreno::distancia_manhattan(coor pos1, coor pos2){
    return  (abs((pos1.col - pos2.col)) + abs((pos1.fil - pos2.fil)));
}

void Terreno::colocar_jugador(){
    terreno[auto_jugador.posicion.fil][auto_jugador.posicion.col] = auto_jugador.identificador;
}

void Terreno::cargar_animales(){
    char especies[] = {'P','G','C','L','R','O','E'};
    int i = 0;

    while(i < ANIMALES_A_SER_RESCATADOS){
        bool superpuestos = false;
        coor coor1;
        coor1.fil = rand() % dimension;
        coor1.col = rand() % dimension;
        for(int j = 0; j < ANIMALES_A_SER_RESCATADOS; j++){
            if(distancia_manhattan(coor1,animales[j].pos) == SUPERPUESTOS){
                superpuestos = true;
            }
        }
        if(distancia_manhattan(coor1,auto_jugador.posicion) == SUPERPUESTOS){
            superpuestos = true;
        }
        if(!superpuestos){
            animales[i].pos = coor1;
            animales[i].especie = especies[rand() % ANIMALES_A_SER_RESCATADOS];
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
        terreno[animales[i].pos.fil][animales[i].pos.col] = animales[i].especie;
    };
}

void Terreno::cargar_terreno(){
    cargar_mapa_consumo();
    cargar_colores();
    cargar_animales();
    colocar_jugador();
    colocar_animales();
}

void Terreno::mostrar_terreno(){
    for(int i = 0; i < dimension; i ++){
        for(int j = 0; j < dimension; j ++){
            cout << colores[i][j] << terreno[i][j] << END_COLOR;
        }cout <<' '<<endl;
    } 
}