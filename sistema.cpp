#include "sistema.hpp"
using namespace std;



// FUNCIONES AUXILIARES //

void mostrar_info_animal(Animal *animal)
{
    if(animal -> esta_eliminado() || animal -> esta_adoptado())
        return;
    std::cout << "----------------------------------------" << endl;
    std::cout << "nombre: " << animal->obtener_nombre() << endl;
    std::cout << "edad: " << animal->obtener_edad() << endl;
    std::cout << "tamaño: " << animal->obtener_tamanio() << endl;
    std::cout << "especie: " << animal->devolver_especie() << endl;
    std::cout << "personalidad: " << animal->mostrar_personalidad() << endl;
    std::cout << "hambre: " << animal->obtener_hambre() << endl;
    std::cout << "higiene: " << animal->obtener_higiene() << endl;
    std::cout << "----------------------------------------" << endl;
}

void alimentar(Animal *animal)
{
    animal -> alimentarse();
}

void baniar(Animal *animal)
{
    animal -> lavarse(); 
}

void actualizar(Animal* animal, Vector<Animal*> *vector)
{
    animal -> pasar_tiempo();
    if(!animal -> esta_adoptado() && !animal -> esta_eliminado())
    {
        if(animal -> obtener_hambre() == 100 || animal -> obtener_higiene() == 0)
        {
            for(int i = 0; i < vector->tamanio();i++)
            {
                if(vector->en(i) == animal)
                    i++;
            }
            vector-> insertar(0, animal);
            cout << "-----------------------------------------" << endl;
            cout << animal -> obtener_nombre() << " escapó de la reserva, se encontraba en mal estado." << endl;
            animal -> eliminar_animal();
            cout << "¡ATENCION! "<< endl;
            if(vector -> tamanio() < 4)
                cout << "Si se escapan " << 4 - vector -> tamanio() << " animales más, se clausurará la reserva." <<endl;
            else   
                cout << "Su reserva será clausurada de forma inminente." << endl;
        }
    }
}

void borrar_animal(Animal *animal)
{
    delete animal;
}


void guardar_animales(Animal *animal, Vector<Animal*>* vector)
{
    if(!animal -> esta_adoptado() && !animal ->esta_eliminado())
        vector->insertar(0, animal);
}

void _mostrar_animales_disponibles(Animal* animal, int espacio_disponible, Vector<Animal*>* lista_disponibles){
    if(!animal -> esta_adoptado() && !animal->esta_eliminado())
    {
        if (espacio_disponible >= GIGANTE){
            lista_disponibles->insertar(0, animal);
        }
        else if(espacio_disponible >= GRANDE){
            if(animal -> obtener_tamanio() != "gigante"){
                lista_disponibles->insertar(0, animal);
            }
        }
        else if(espacio_disponible >= MEDIANO){
            if (animal -> obtener_tamanio() != "gigante" && animal -> obtener_tamanio() != "grande"){
                lista_disponibles->insertar(0, animal);
            }
        }
        else if(espacio_disponible < PEQUENIO && espacio_disponible > DIMINUTO){
            if (animal -> obtener_tamanio() == "pequeño" || animal -> obtener_tamanio() == "diminuto"){
                lista_disponibles->insertar(0, animal);
            }
        }
        else if(espacio_disponible <= DIMINUTO){
            if(animal -> obtener_tamanio() == "diminuto"){
                lista_disponibles->insertar(0, animal);
            }
        }
    }
}

// FIN DE FUNCIONES AUXILIARES //

Sistema::Sistema(){
    this -> arbol = new AB3<string, Animal*>(3);
    leer_archivo();
    this -> animales_perdidos = new Vector<Animal*>(1);
    this -> mapa = new Mapa();
    incializar_mapa();
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
             

    mapa->mostrar_mapa();

    while(reiniciar_solicitud){
        mapa->trasladar(); 
        
        cout << "Desea ingresar nuevamente los datos? S(sí), N(no)." << endl;
        getline(cin>>ws, input_usuario);
        a_minuscula(input_usuario);

        if(input_usuario.find('n') != string::npos){
            reiniciar_solicitud = false;
        }
    }
}
/*

ATENCION: ESTA TAMPOCO VA (ES DE LA RESERVA ANTERIOR)
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
*/



void Sistema::buscar_animal()
{
    string nombre;
    cout << "Ingrese el nombre" << endl;
    getline(cin>>ws, nombre);
    if(arbol -> clave_existe(nombre))
    {
        Animal* animal = arbol -> buscar(nombre);
        if(animal -> esta_adoptado() || animal -> esta_eliminado())
            cout << "No se encontró ningún animal que se llame <" << nombre << ">." << endl;            
        mostrar_info_animal(animal);
    }
    else
        cout << "No se encontró ningún animal que se llame <" << nombre << ">." << endl;
}

void Sistema::adoptar_animal()
{
    int espacio_disponible;
    cout << "Espacio necesario: " << endl;
    cout << "Diminuto: 2 metros o menos." << endl;
    cout << "Pequeño: 10 metros o menos." << endl;
    cout << "Mediano: 10 metros o más." << endl;
    cout << "Grande: 20 metros o más." << endl;
    cout << "Gigante: 60 metros o más." << endl;
    cout << "--------------------------------------" << endl;
    cout<<"Indicar el espacio disponible en metros cuadrados(desde 1 hasta 500 metros cuadrados):"<<endl;
    espacio_disponible = pedir_opcion(ESPACIO_MIN, ESPACIO_MAX) ;
    mostrar_animales_disponibles(espacio_disponible);

    string input_usuario;
    cout << "¿Desea elegir un animal de los listados para adoptar? S(sí), N(no)." << endl;
    getline(cin>>ws, input_usuario);
    a_minuscula(input_usuario);
    if(input_usuario.find('s') != string::npos)
        seleccionar_animal();
}


void Sistema::mostrar_animales_disponibles(int espacio_disponible)
{
    Vector<Animal*> disponibles(1);
    arbol -> aplicar_funcion2(&_mostrar_animales_disponibles, espacio_disponible, &disponibles);
    merge_sort(disponibles, 0,disponibles.tamanio() - 2); //UN -1 SE DEBE A LA IMPLEMENTACIÓN DE VECTOR
    for(int i = 0; i < disponibles.tamanio() - 1; i++)
        mostrar_info_animal(disponibles.en(i));
}

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
        Animal *animal = arbol -> buscar(nombre);
        cout << "=====================================" << endl;
        cout << "Felicidades! Ha adoptado a " << nombre << endl;
        cout << "=====================================" << endl;
        animal -> adoptar_animal();
        return true;
    }
}

void Sistema::elegir_individualmente()
{
    Vector<Animal*> *animales = new Vector<Animal*>(1);
    arbol -> aplicar_funcion3(&guardar_animales, animales);
    int largo_vector = animales -> tamanio() - 1;
    int opcion = 0;
    bool escogido = false;
    int i = 0;

    while(!escogido && i < largo_vector){
        Animal *actual = animales->en(i);
        mostrar_info_animal(actual);
        cout << i << endl;
        cout<<"\t\t=========================="<<endl;
        cout<<"\t Por favor eliga una de las siguientes opciones\n";
        cout<<"1.Alimentar\n";
        cout<<"2.Baniar\n";
        cout<<"3.Saltear al siguiente\n";
        cout<<"\t\t=========================="<<endl;
        cout<<"Ingrese una opcion: ";
        opcion = pedir_opcion(ALIMENTAR, VOLVER);
        if(opcion == ALIMENTAR){
            actual->alimentarse();
            escogido = true;
        }
        else if(opcion == BANIAR){
            actual->lavarse();
            escogido = true;
        }
        else if(opcion == SALTEAR){
            i++;
        }
        else   
            escogido = true;
    }
    if(largo_vector == i){
        cout<<"\t¡No hay más animales!"<<endl;
    }
    delete animales;
}

int Sistema::pedir_opcion(int rango_min, int rango_max){
    string opcion;
    getline(cin>>ws, opcion);
    while(!es_opcion_valida(opcion, rango_min, rango_max)){
        cout<<"El dato ingresado no es válido. Por favor, ingrese una opción correcta: ";
        getline(cin>>ws, opcion);
    }
    return stoi(opcion);
}


void Sistema::alimentar_todos()
{
    arbol -> aplicar_funcion(&alimentar);
}

void Sistema::baniar_todos()
{
    arbol -> aplicar_funcion(&baniar);
}

void Sistema::actualizar_atributos()
{
    arbol -> aplicar_funcion3(&actualizar, this -> animales_perdidos);
}

void Sistema::borrar_animales()
{
    arbol -> aplicar_funcion(&borrar_animal);
}

int Sistema::cantidad_perdidos()
{
    return this -> animales_perdidos -> tamanio() - 1;
}

void Sistema::cerrar_archivo()
{
    ofstream animales_registrados("animales.csv");
    
    Vector<Animal*> *animales = new Vector<Animal*>(1);
    arbol -> aplicar_funcion3(&guardar_animales, animales);
    int largo_vector = animales -> tamanio() - 1;

    for(int i = 0; i < largo_vector; i++)
    {
        Animal *animal = animales->en(i);

        animales_registrados << animal->obtener_nombre() << ','
        << animal->obtener_edad() << ','
        << animal->obtener_tamanio() << ','
        << animal->devolver_especie() << ','
        << animal->mostrar_personalidad();
        if(i != largo_vector -1)
            animales_registrados << "\n";
        else
        {
            animales_registrados.close();
        }
    }
    delete animales;
}

void Sistema::incializar_mapa(){
    mapa->crear_casilleros();
    mapa->unir_casilleros();
}

void Sistema::cargar_combustible()
{
    mapa->cargar_combustible();
}

Sistema::~Sistema(){
    borrar_animales();
    delete arbol;
    delete animales_perdidos;
    delete mapa;
}