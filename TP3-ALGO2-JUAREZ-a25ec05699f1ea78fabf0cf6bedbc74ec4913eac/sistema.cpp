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
        agregar_animal(crear_animal(personalidad, nombre, stoi(edad), tamanio, especie[0]));
    }
    lista_animales.close();
}




void Sistema::imprimir_lista()
{
    arbol->aplicar_funcion(&mostrar_info_animal);
}


Animal* Sistema::crear_animal_base(std::string n_nombre, int n_edad, std::string n_tamanio, char n_especie, Personalidad* personalidad){
    Animal* n_animal;
    if(n_especie == PERRO){
        n_animal = new Perro(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
    }
    if(n_especie == GATO){
        n_animal = new Gato(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
    }
    if(n_especie == CABALLO){
        n_animal = new Caballo(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
    }
    if(n_especie == ROEDOR){
        n_animal = new Roedor(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
    }
    if(n_especie == CONEJO){
        n_animal = new Conejo(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
    }
    if(n_especie == ERIZO){
        n_animal = new Erizo(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
    }else if(n_especie == LAGARTIJA){
        n_animal = new Lagartija(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
    }
    return n_animal;
}

Animal *Sistema::crear_animal(std::string n_personalidad, std::string n_nombre, int n_edad, std::string n_tamanio, char n_especie){
    Personalidad* personalidad; 
    
    if(n_personalidad == "Dormilon")
        personalidad = new Dormilon();

    else if(n_personalidad == "Jugueton")
        personalidad = new Jugueton();

    else if(n_personalidad == "Sociable")
        personalidad = new Sociable();

    else if(n_personalidad == "Travieso")
        personalidad = new Travieso();
    
    Animal* animal = crear_animal_base(n_nombre, n_edad, n_tamanio, n_especie, personalidad);
    return animal;
}

void Sistema::agregar_animal(Animal *animal)
{
    this -> arbol -> agregar(animal -> obtener_nombre(), animal);
}


void Sistema::rescatar_animal()
{
    bool reiniciar_solicitud = true;
    string input_usuario;
    string nombre_animal;

    while(reiniciar_solicitud){    
        mapa->mostrar_mapa();
        char especie_rescatada = mapa->trasladar(); 

        if(especie_rescatada != (char)-1)
        {
            cout << "Ingrese como desea llamar al animal encontrado: " << endl;
            getline(cin >> ws, nombre_animal);
            while(arbol -> clave_existe(nombre_animal))
            {
                cout << "El nombre ingresado se encuentra registrado, por favor, ingrese otro nombre." << endl;
                getline(cin >> ws, nombre_animal);
            }    
            Animal* animal_rescatado = crear_animal_random((char)especie_rescatada);
            animal_rescatado -> cambiar_nombre(nombre_animal);
            arbol -> agregar(animal_rescatado -> obtener_nombre(), animal_rescatado);
        }
        
        cout << "Desea ingresar nuevamente los datos? S(sí), N(no)." << endl;
        getline(cin>>ws, input_usuario);
        a_minuscula(input_usuario);

        if(input_usuario.find('n') != string::npos){
            reiniciar_solicitud = false;
        }
    }
}



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

Animal* Sistema::crear_animal_random(char especie)
{
    int edad = (int)(rand() % 100);
    string tamanio = TAMANIOS[(int)(rand() % 5)];
    int personalidad_numero = (int)(rand() % 4);
    string personalidad = PERSONALIDADES[personalidad_numero];
    Animal* animal_random = crear_animal(personalidad, "", edad, tamanio, especie);
    return animal_random;   
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
    mapa -> iniciar_terreno();
}

void Sistema::recarga_automatica()
{
    mapa->recarga_automatica();
}

void Sistema::cargar_combustible(){
    mapa->cargar_combustible();
}

Sistema::~Sistema(){
    borrar_animales();
    delete arbol;
    delete animales_perdidos;
    delete mapa;
}