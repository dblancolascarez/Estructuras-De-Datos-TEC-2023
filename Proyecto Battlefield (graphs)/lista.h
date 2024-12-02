#include <cstdlib>
#include <iostream>
using namespace std;


// estructura nodo para lista simple

// estructura arista para lista de aristas
struct Arista {
       int dato; // parte de datos
       int peso;
       // int poblacion
       // int distancia
       //int.....
       Arista * siguiente;// puntero para enlazar nodos
       // constructor
       
       Arista(int d, int p) 
       {
                dato = d; // asigna los datos 
                peso = p;
                siguiente = NULL; // sig es null
                
       }
       
       // imprimir
       void imprimir()
       {
            cout <<dato << "("<<peso<<")";
       }
};


struct ListaAristas {
       // solo con pN es suficiente
       Arista *primerNodo, *ultimoNodo;
       
       ListaAristas()
       {
           primerNodo = ultimoNodo = NULL;
       }
       
       // encabezados de funcion
       void insertarAlInicio (int dato, int peso);
       Arista* borrarAlInicio(void);
       void imprimir(void);
       void insertarAlFinal(int dato, int peso);
       Arista* borrarAlFinal(void);
       Arista* buscar (int dato);//
       int largo (void);//
       bool vacia(void); 
       void borrarEnPosicion(int pos);       
       int posicion (int);
         
};


struct Nodo {
       int dato; // parte de datos
       ListaAristas * aristas;
       bool visitado;
       Nodo* siguiente;// puntero para enlazar nodos
       // constructor
       
       Nodo(int d) 
       {
                dato = d; // asigna los datos
                aristas = new ListaAristas(); 
                visitado = false;
                siguiente = NULL; // sig es null
                
       }
       
       void imprimir();
       
};


struct ListaSimple {
       // solo con pN es suficiente
       Nodo *primerNodo, *ultimoNodo;
       
       ListaSimple()
       {
                    primerNodo = ultimoNodo = NULL;
       }
       
       // encabezados de funcion
       void insertarAlInicio (int dato);
       Nodo* borrarAlInicio(void);
       void imprimir(void);
       void insertarAlFinal(int dato);
       Nodo* borrarAlFinal(void);
       Nodo* buscar (int dato);//
       int largo (void);//
       int largoRec (void);
       int largo_aux(Nodo*);
       void insertarAlFinalConRecorrido(int dato);//
       bool vacia(void);
       ListaSimple* retornaNuevaListaInvertida(void);//
       void insertarEnPosicion(int dato, int pos);
       void borrarEnPosicion(int pos);       
       int posicion (int);
        
       void encolar(int);
       Nodo* desencolar();
};

