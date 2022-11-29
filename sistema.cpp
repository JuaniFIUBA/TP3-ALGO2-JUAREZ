#include "sistema.hpp"
using namespace std;

Sistema::Sistema(){
    this -> arbol = new AB3<string, Animal*>(3);
    leer_archivo();
    animales_perdidos = 0;
}

void Sistema::leer_archivo(){
    std::fstream lista_animales("animales.csv");
    if(!lista_animales.is_open()){
        std::cout<< "Error, no se encuentra el archivo"<<std::endl;
    }
    std::string nombre,edad,tamanio,especie,personalidad;
    while(getline(lista_animales, nombre,',')){
        getline(lista_animales, edad,',');
        getline(lista_animales, tamanio,',');
        getline(lista_animales, especie,',');
        getline(lista_animales, personalidad);
        crear_animal(personalidad, nombre, stoi(edad), tamanio, especie[0]);
    }
    lista_animales.close();
}


void mostrar_info_animal(Animal *animal)
{
    if(animal -> esta_eliminado() || animal -> esta_adoptado())
        return;
    std::cout << "nombre: " << animal->obtener_nombre() << endl;
    std::cout << "edad: " << animal->obtener_edad() << endl;
    std::cout << "tamaño: " << animal->obtener_tamanio() << endl;
    std::cout << "especie: " << animal->devolver_especie() << endl;
    std::cout << "personalidad: " << animal->mostrar_personalidad() << endl;
    std::cout << "hambre: " << animal->obtener_hambre() << endl;
    std::cout << "higiene: " << animal->obtener_higiene() << endl;
    std::cout << "----------------------------------------" << endl;
}



void Sistema::imprimir_lista()
{
    arbol->aplicar_funcion(&mostrar_info_animal);
}


Animal* Sistema::crear_animal_base(std::string n_nombre, int n_edad, std::string n_tamanio, char n_especie, Personalidad* personalidad){
    if(n_especie == PERRO){
        Animal* n_animal = new Perro(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
        return n_animal;
    }
    if(n_especie == GATO){
        Animal* n_animal = new Gato(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
        return n_animal;
    }
    if(n_especie == CABALLO){
        Animal* n_animal = new Caballo(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
        return n_animal;
    }
    if(n_especie == ROEDOR){
        Animal* n_animal = new Roedor(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
        return n_animal;
    }
    if(n_especie == CONEJO){
        Animal* n_animal = new Conejo(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
        return n_animal;
    }
    if(n_especie == ERIZO){
        Animal* n_animal = new Erizo(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
        return n_animal;
    }else{
        Animal* n_animal = new Lagartija(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
        return n_animal;
    }
}

void Sistema::crear_animal(std::string n_personalidad, std::string n_nombre, int n_edad, std::string n_tamanio, char n_especie){
    if(n_personalidad == "Dormilon"){
        Personalidad* personalidad = new Dormilon();
        Animal* animal = crear_animal_base(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
        this->arbol->agregar(animal -> obtener_nombre(), animal);
        return;
    }
    else if(n_personalidad == "Jugueton"){
        Personalidad* personalidad = new Jugueton();
        Animal* animal = crear_animal_base(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
        this->arbol->agregar(animal -> obtener_nombre(), animal);
        return;
    }
    else if(n_personalidad == "Sociable"){
        Personalidad* personalidad = new Sociable();
        Animal* animal = crear_animal_base(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
        this->arbol->agregar(animal -> obtener_nombre(), animal);
        return;
    }
    else if(n_personalidad == "Travieso")
    {
        Personalidad* personalidad = new Travieso();
        Animal* animal = crear_animal_base(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
        this->arbol->agregar(animal -> obtener_nombre(), animal);
        return;
    }
}


// ATENCION: ESTA ES LA QUE DEBEN CAMBIAR POR LA IMPLEMENTACION DE GRAFOS
void Sistema::rescatar_animal()
{
    bool reiniciar_solicitud = true;
    string input_usuario;

    while(reiniciar_solicitud)
    {
        arbol->print_in_order(); 
        if(!solicitar_datos_y_agregar())
        {
            cout << "Desea ingresar nuevamente los datos? S(sí), N(no)." << endl;
            getline(cin>>ws, input_usuario);
            a_minuscula(input_usuario);

            if(input_usuario.find('n') != string::npos)
                reiniciar_solicitud = false;
        }
        else
            reiniciar_solicitud = false;
    }
}

// ATENCION: ESTA TAMPOCO VA (ES DE LA RESERVA ANTERIOR)
bool Sistema::solicitar_datos_y_agregar()
{
    string nombre = "", tamanio = "", personalidad = "";
    int edad = 0;
    char especie = ' ';
    cout << "Ingrese el nombre (Atención: El nombre no puede estar registrado previamente)" << endl;
    getline(cin>>ws, nombre);
    if(arbol -> clave_existe(nombre))
    {
        cout << "El nombre se encuentra ya registrado." << endl;
        return false;
    }

    if(!solicitar_personalidad(personalidad))
        return false;
    if(!solicitar_tamanio(tamanio))
        return false;
    if(!solicitar_especie(especie))
        return false;
    cout << "Ingrese la edad(debe estar entre 0 y 100 años):" << endl;
    edad = pedir_opcion(EDAD_MIN, EDAD_MAX);
    crear_animal(personalidad, nombre, edad, tamanio, especie);
    return true;
}



void Sistema::buscar_animal()
{
    string nombre;
    cout << "Ingrese el nombre" << endl;
    getline(cin>>ws, nombre);
    if(arbol -> clave_existe(nombre))
    {
        Animal* animal = arbol -> obtener_dato(nombre);
        mostrar_info_animal(animal);
    }
    else
        cout << "No se encontró ningún animal que se llame <" << nombre << ">." << endl;
}

// void Sistema::adoptar_animal()
// {
//     int espacio_disponible;
//     cout<<"Indicar el espacio disponible en metros cuadrados(desde 1 hasta 500 metros cuadrados):"<<endl;
//     espacio_disponible = pedir_opcion(ESPACIO_MIN, ESPACIO_MAX) ;

//     mostrar_animales_disponibles(espacio_disponible);

//     string input_usuario;
//     cout << "¿Desea elegir un animal de los listados para adoptar? S(sí), N(no)." << endl;
//     getline(cin>>ws, input_usuario);
//     a_minuscula(input_usuario);
//     if(input_usuario.find('s') != string::npos)
//         seleccionar_animal();
// }


// void Sistema::mostrar_animales_disponibles(int espacio_disponible){

//     int largo_lista = lista.mostrar_cantidad();
//     for(int i = 0; i < largo_lista; i++){
//         if (espacio_disponible >= GIGANTE){
//             mostrar_info_animal(i);
//         }
//         else if(espacio_disponible >= GRANDE){
//             if(lista.consulta(i)->obtener_tamanio() != "gigante"){
//                 mostrar_info_animal(i);
//             }
//         }
//         else if(espacio_disponible >= MEDIANO){
//             if (lista.consulta(i)->obtener_tamanio() != "gigante" && lista.consulta(i)->obtener_tamanio() != "grande"){
//                 mostrar_info_animal(i);
//             }
//         }
//         else if(espacio_disponible < PEQUENIO && espacio_disponible > DIMINUTO){
//             if (lista.consulta(i)->obtener_tamanio() == "pequeño" || lista.consulta(i)->obtener_tamanio() == "diminuto"){
//                 mostrar_info_animal(i);
//             }
//         }
//         else if(espacio_disponible <= DIMINUTO){
//             if(lista.consulta(i)->obtener_tamanio() == "diminuto"){
//                 mostrar_info_animal(i);
//             }
//         }
//     }
// }

bool Sistema::seleccionar_animal(){
    string nombre;
    cout << "Ingrese el nombre de un animal disponible: " << endl;
    getline(cin>>ws, nombre);

    if(!(arbol->clave_existe(nombre)))
    {
        cout << "No se encontró ningún animal que se llame <" << nombre << ">." << endl;
        return false;
    }
    else{
        Animal *animal = arbol -> obtener_dato(nombre);
        cout << "=====================================" << endl;
        cout << "Felicidades! Ha adoptado a " << nombre << endl;
        cout << "=====================================" << endl;
        animal -> adoptar_animal();
        return true;
    }
}

// void Sistema::elegir_individualmente(){
//     int opcion = 0;
//     bool escogido = false;
//     int i = 0;
//     while(!escogido && i < lista.mostrar_cantidad()){
//         mostrar_info_animal(i);
//         cout<<"\t\t=========================="<<endl;
//         cout<<"\t Por favor eliga una de las siguientes opciones\n";
//         cout<<"1.Alimentar\n";
//         cout<<"2.Baniar\n";
//         cout<<"3.Saltear al siguiente\n";
//         cout<<"\t\t=========================="<<endl;
//         cout<<"Ingrese una opcion: ";
//         opcion = pedir_opcion(ALIMENTAR, SALTEAR);
//         if(opcion == ALIMENTAR){
//             lista.consulta(i)->alimentarse();
//             escogido = true;
//         }
//         else if(opcion == BANIAR){
//             lista.consulta(i)->lavarse();
//             escogido = true;
//         }
//         else if(opcion == SALTEAR){
//             i++;
//         }
//     }
//     if(lista.mostrar_cantidad() == i){
//         cout<<"\t¡No hay más animales!"<<endl;
//     }
// }

int Sistema::pedir_opcion(int rango_min, int rango_max){
    string opcion;
    getline(cin>>ws, opcion);
    while(!es_opcion_valida(opcion, rango_min, rango_max)){
        cout<<"El dato ingresado no es válido. Por favor, ingrese una opción correcta: ";
        getline(cin>>ws, opcion);
    }
    return stoi(opcion);
}

void alimentar(Animal *animal)
{
    animal -> alimentarse();
}

void Sistema::alimentar_todos()
{
    arbol -> aplicar_funcion(&alimentar);
}

void baniar(Animal *animal)
{
    animal -> lavarse(); 
}

void Sistema::baniar_todos()
{
    arbol -> aplicar_funcion(&baniar);
}

void actualizar(Animal* animal)
{
    animal -> pasar_tiempo();
    if(animal -> obtener_hambre() == 100 || animal -> obtener_higiene() == 0)
        animal -> eliminar_animal();
}

void Sistema::actualizar_atributos()
{
    arbol -> aplicar_funcion(&actualizar);
}

void borrar_animal(Animal *animal){
    delete animal;
}

void Sistema::borrar_animales()
{
    arbol -> aplicar_funcion(&borrar_animal);
}
void Sistema::aumentar_perdidos(){
    this -> animales_perdidos++;
}



void guardar_nombres(Animal *animal, Vector<string>* vector){
    vector->insertar(0, animal -> obtener_nombre());
}

void Sistema::cerrar_archivo()
{
    ofstream lista_animales("animales.csv");
    
    Vector<string> *nombres = new Vector<string>(1);
    arbol -> aplicar_funcion3(&guardar_nombres, nombres);
    int largo_vector = nombres -> tamanio() - 1;

    for(int i = 0; i < largo_vector; i++)
    {
        Animal *animal = arbol -> obtener_dato(nombres->en(i));
        if(i == largo_vector - 1)
        {
            lista_animales << animal->obtener_nombre() << ','
            << animal->obtener_edad() << ','
            << animal->obtener_tamanio() << ','
            << animal->devolver_especie() << ','
            << animal->mostrar_personalidad();
            lista_animales.close();
            delete nombres;
            return;
        }
        else
        {
            lista_animales << animal->obtener_nombre() << ','
            << animal->obtener_edad() << ','
            << animal->obtener_tamanio() << ','
            << animal->devolver_especie() << ','
            << animal->mostrar_personalidad() << "\n";
        }
    }
}

Sistema::~Sistema(){
    borrar_animales();
    delete arbol;
}