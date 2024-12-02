#include <string>
#include <iostream>

using namespace std;

//Estructura de hobbie
struct Hobbie{
    string nombrehobbie; //nombre del hobbie
    int frecuencia; //frecuencia del hobbie
    Hobbie* siguiente; // puntero que apunta al siguiente hobbie en la lista

    Hobbie(string nombre,int frecuencia){ //constructor de hobbie
        this->nombrehobbie = nombre; //inicializa el atributo de nombre con el argumento dado
        this->frecuencia = frecuencia; //inicializa el atributo de frecuencia con el argumento dado
        this->siguiente = nullptr; //siguiente hobbie es null
    }
};

//Estructura para representar un hijo
struct Hijo{
    string nombrehijo; //atributo
    int edad; //atributo
    Hobbie* hobbies; //puntero hobbies de la lista Hobbie
    Hijo* siguiente; //cada objeto hijo tiene un atributo siguiente, que es un puntero al siguiente hijo en la lista

    Hijo(string nombre, int edad){ //constructor de hijo
        this->nombrehijo = nombre; //inicializa con el argumento de nombre dado anteriormente
        this->edad = edad; //inicializa con el argumento de edad dado anteriormente
        this->hobbies = nullptr; //inicializa el atributo de hobby nulo(lista vacia inicialmente)
        this->siguiente = nullptr; 
    }
};

//estructura que representa un cliente en la lista de clientes
struct Cliente{
    string nombre; //atributo
    int salario; //atributo
    Hijo* hijos; //puntero a la estructura Hijo
    Cliente* siguiente; //puntero al siguiente cliente en la lista de clientes

    Cliente(string nombre, int salario){
        this->nombre = nombre; //inicializa la variable con el valor del argumento
        this->salario = salario; //inicializa la variable con el valor del argumento
        this->hijos = nullptr; //hijos apunto a null porque no existen hijos por default
        this->siguiente = nullptr; 
    }
};

class ListaClientes{ 
private:
    Cliente* primero; //seguir el primer elemento de la lista de clientes

public:
    ListaClientes(){
        primero = nullptr; //primer cliente se hace nulo cuando un nuevo objeto es creado
    }

    //nuevo cliente en la lista
    void nuevoCliente(string nombre, int salario){ //parametro de nombre del nuevo cliente
        Cliente* nuevoCliente = new Cliente(nombre, salario); 
        if (primero == nullptr){ //si la lista esta vacia
            primero = nuevoCliente; //primero se asigna a la lista nuevoCliente
        }
        else{ //si el puntero primero no es nulo 
            Cliente* tmp = primero; //temporal es el primer nodo de la lista
            while(tmp->siguiente != nullptr){ //itera la lista hasta llegar al final donde siguiente = nullptr
                tmp = tmp->siguiente; 
            }
            tmp->siguiente = nuevoCliente; //asigna el nuevo cliente
        }
    }

    //asignar hijo a cliente
    void agregarHijo(string nombreCliente, string nombreHijo, int edad){
        Cliente* tmp = primero; //comienza al principio de la lista
        while(tmp != nullptr && tmp->nombre != nombreCliente){ //itera para encontrar al cliente dado en el argumento de la funcion
            tmp = tmp->siguiente;
        }
        if (tmp != nullptr){ //si encuentra el cliente
            Hijo* nuevoHijo = new Hijo(nombreHijo,edad); //crea un nuevo hijo con el nombre dado en el argumento
            if (tmp->hijos == nullptr){ //valida si el cliente no tiene hijos aun 
                tmp->hijos = nuevoHijo; //se convierte en el primer hijo del cliente
            }
            else{ //si el cliente ya tiene hijos
                Hijo* tmpHijo = tmp->hijos; //apunta al primer hijo del cliente
                while (tmpHijo->siguiente != nullptr){ //itera hasta llegar al ultimo hijo del cliente
                    tmpHijo->siguiente = nuevoHijo; 
                    cout << "Se agrego el hijo" << endl;
                }
                tmpHijo = tmpHijo->siguiente; //se convierte en el ultimo hijo del cliente
            }
        }
        else{
            cout << "No se encontro el cliente" << endl;
        }
    }

    //metodo que agrega un hobby a un hijo
    void agregarHobbie(string nombreCliente, string nombreHijo, string nombreHobbie, int frecuencia){
        Cliente* tmp = primero; //inicializa el puntero al primer cliente
        while(tmp != nullptr && tmp->nombre != nombreCliente){ //itera la lista hasta encontrar el nombre del cliente
            tmp = tmp->siguiente; 
        }
        if(tmp != nullptr){ //si encuentra el cliente
            Hijo* tmpHijo = tmp->hijos; //crea puntero temporal
            while(tmpHijo != nullptr && tmpHijo->nombrehijo != nombreHijo){ //itera para encontrar al hijo con el nombre dado
                tmpHijo = tmpHijo->siguiente;
            }
            if(tmpHijo != nullptr){ //si encuentra el hijo
                Hobbie* nuevoHobbie = new Hobbie(nombreHobbie, frecuencia);
                if(tmpHijo->hobbies == nullptr){ //si el hijo no tiene hobbies
                    tmpHijo->hobbies = nuevoHobbie; //asigna el hobbie
                }
                else{ //si ya el hijo tiene hobbies
                    Hobbie* tmpHobbie = tmpHijo->hobbies; //crea puntero temporal
                    while(tmpHobbie->siguiente != nullptr){ //itera para encontrar el ultimo hobbie de la lista
                        tmpHobbie = tmpHobbie->siguiente;
                    }
                    tmpHobbie->siguiente = nuevoHobbie; //agrega un nuevo hobbie al final
                }
            }
            else{
                cout << "No se encontro el hijo" << endl;
            }
        }
        else{
            cout << "No se encontro el cliente" << endl;
        }
    }

    //metodo para imprimir la lista de clientes con sus hijos y hobbies
    void imprimirLista(){
        Cliente* tmp = primero;
        while(tmp != nullptr){
            cout << "Cliente: " << tmp->nombre <<endl;
            cout << "Salario: $" << tmp->salario << endl;
            Hijo* tmpHijo = tmp->hijos;
            while(tmpHijo != nullptr){
                cout << "   " << "Hijx: " << tmpHijo->nombrehijo << endl;
                cout << "   " << "Edad: " << tmpHijo->edad << " años" << endl;
                Hobbie* tmpHobbie = tmpHijo->hobbies;
                while(tmpHobbie != nullptr){
                    cout << "       " << "Hobbie: " <<tmpHobbie->nombrehobbie << endl;
                    cout << "       " << "Frecuencia: " << tmpHobbie->frecuencia << " dias a la semana"<<endl;
                    tmpHobbie = tmpHobbie->siguiente;
                }
                tmpHijo = tmpHijo->siguiente;
            }
            tmp = tmp->siguiente;
        }
    }

    public List<String> getDistinctHobbies() {
    List<String> distinctHobbies = new ArrayList<>();

    for (Child child : children) {
        for (String hobby : child.hobbies) {
            if (!distinctHobbies.contains(hobby)) {
                distinctHobbies.add(hobby);
            }
        }
    }

    return distinctHobbies;
}


    

};