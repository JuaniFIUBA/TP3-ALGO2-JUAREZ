#include "terreno.hpp"


Terreno::Terreno(){};

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

void Terreno::cargar_terreno(){
    for(int i = 0; i < dimension; i ++){
        for(int j = 0; j < dimension; j ++){
            terreno[i][j] = asignar_color(mapa_de_consumo[i][j]);
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