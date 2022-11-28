#include "terreno.hpp"


Terreno::Terreno(){};

int Terreno::asignar_consumo(string color){
    if(color == BGND_BROWN_94){ //MONTAÑA
        return 5;
    }else if(color == BGND_BROWN_137){ //TIERRA
        return 2;
    }else if(color == BGND_LIGHT_GRAY_246){ //CAMINO
        return 1;
    }else{ //PRECIPICIO
        return 40;
    }
};

void Terreno::cargar_terreno(){
    srand((unsigned) time(NULL));
    string colores[] = {BGND_BROWN_94,BGND_BROWN_137,BGND_LIGHT_GRAY_246,BGND_BLACK_16};
    for(int i = 0; i < dimension; i ++){
        for(int j = 0; j < dimension; j ++){
            terreno[i][j] = colores[(rand() % 4)];
            mapa_de_consumo[i][j] = asignar_consumo(terreno[i][j]);
        }
    }
}

void Terreno::mostrar_terreno(){
    for(int i = 0; i < dimension; i ++){
        for(int j = 0; j < dimension; j ++){
            cout << terreno[i][j] << "  " << END_COLOR;
            if(j == dimension -1){
                cout << terreno[i][j] << "  " << END_COLOR<<endl;
            }
        }
    } 
}