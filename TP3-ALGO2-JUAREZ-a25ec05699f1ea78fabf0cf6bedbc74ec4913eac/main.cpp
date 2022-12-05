#include "menu.h"
#include <time.h>

int main(){
    srand((unsigned) time(NULL));
    Menu menu = Menu();
    menu.seleccionar_opcion();
    return 0;
}