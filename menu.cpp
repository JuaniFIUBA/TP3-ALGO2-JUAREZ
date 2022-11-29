#include "menu.h"


using namespace std;

void Menu::mostrar_menu()
{
    cout << "Bienvenido a la reserva soniada..." << endl;
    cout << "1. Listar animales" << endl;
    cout << "2. Rescatar animal" << endl;
    cout << "3. Buscar animal" << endl;
    cout << "4. Cuidar animales" << endl;
    cout << "5. Adoptar animal" << endl;
    cout << "6. Guardar y salir" << endl;
    cout << "Seleccione una opcion de las indicadas anteriormente para continuar: ";
}

void Menu::seleccionar_opcion()
{
    int opcion_elegida = 0;
    while(opcion_elegida != GUARDAR_Y_SALIR)
    {        
        mostrar_menu();
        opcion_elegida = sistema.pedir_opcion(LISTAR_ANIMALES, GUARDAR_Y_SALIR);
        switch(opcion_elegida)
        {
            case 1:
                sistema.imprimir_lista();
                cout << "Presione enter para continuar..." << endl;
                cin.get();
                cout << "\e[1;1H\e[2J" << endl; // limpia la consola
                break;
            case 2:    
                sistema.rescatar_animal();
                break;
            case 3:
                sistema.buscar_animal();
                cout << "Presione enter para continuar..." << endl;
                cin.get();
                cout << "\e[1;1H\e[2J" << endl; // limpia la consola
                break;
            // case 4:
            //     mostrar_submenu();
            //     break;
            // case 5:
            //     sistema.adoptar_animal();
            //     cout << "Presione enter para continuar..." << endl;
            //     cin.get();                
            //     cout << "\e[1;1H\e[2J" << endl; // limpia la consola
            //     break;
            case 6:
                sistema.cerrar_archivo();
                break;
        }       

        sistema.actualizar_atributos();
    }
    
}

// void Menu::mostrar_submenu(){ 
//     int opcion_elegida = 0;
//     while(opcion_elegida != REGRESAR)
//     {        
//         cout<<endl;
//         cout<<"\t\t=========================="<<endl;
//         cout<<"\t Por favor eliga una de las siguientes opciones\n";
//         cout<<"1. Elegir individualmente"<<endl;
//         cout<<"2. Alimentar a todos"<<endl;
//         cout<<"3. Bañar a todos"<<endl;
//         cout<<"4. Regresar al inicio"<<endl;
//         cout<<"\t\t=========================="<<endl;
//         cout<<"Ingrese una opción: ";
//         opcion_elegida = sistema.pedir_opcion(ELEGIR_INDIVIDUALMENTE, REGRESAR);
//         switch(opcion_elegida)
//         {
//             case 1:
//                 sistema.elegir_individualmente();
//                 break;
//             case 2:    
//                 sistema.alimentar_todos();
//                 cout << "Presione enter para continuar..." << endl;
//                 cin.get();
//                 cout << "\e[1;1H\e[2J" << endl; // limpia la consola
//                 break;

//             case 3:
//                 sistema.baniar_todos();
//                 cout << "Presione enter para continuar..." << endl;
//                 cin.get();
//                 cout << "\e[1;1H\e[2J" << endl; // limpia la consola

//                 break;
//             case 4:
//                 opcion_elegida = REGRESAR;
//                 break;
//         }       
//     }
// }