

#include "lista.h"


// funcion que inserta un nodo nuevo en la lista
// entradas: el dato a guardar
// salidas: no tiene
void ListaAristas::insertarAlInicio (int dato, int peso)
{
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new Arista(dato, peso);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo               
     }
     else
     {
         Arista *nuevo = new Arista(dato, peso);
         // a lo que apunta pN ahora es el segundo
         // por eso, nuevo->siguiente es pN
         nuevo->siguiente = primerNodo;
         // ahora devolvemos pN a que apunte al nuevo
         // y primero de las lista
         primerNodo = nuevo; 
         // el puntero nuevo deja de existir, no se libera
         // memoria porque se pierde la info
     }
}

// funcion que elimina el primer elemento de las lista
// entradas: no tiene
// salidas: el puntero al primer nodo. Este puntero
// en siguiente apuntara a null. No se libera memoria

Arista* ListaAristas::borrarAlInicio(void)
{
      // si no hay elementos, no borra nada, retorna null
      if (primerNodo == NULL)
      {
         return NULL;
      }
      else
      {
          // un puntero que apunta al nodo que se
          // "despegara" de la lista y se retorna
          Arista* borrado = primerNodo;     
          // pN se pasa al segundo de la lista
          // porque el primero se eliminara
          primerNodo = primerNodo->siguiente;
          // el nodo borrado, se debe despegar
          // entonces siguiente apunta a null y no
          // al segundo de la lista que ahora es pN
          borrado->siguiente = NULL;
          // aca se deberia liberar la memoria si no se
          // retornara el borrado
          return borrado;
      }
}


// funcion que recorre toda la lista con pt tmp
// imprimiendo en consola cada dato de nodos
// entradas no tiene
// salidas: no tiene, solo imprime en consola
void ListaAristas::imprimir(void)
{
     // puntero temporal que avanza
     // por toda la lista
     // apunta a los mismo que pN
     Arista *tmp = primerNodo;
     
     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           // imprime el dato del nodo en el que esta tmp
           cout << tmp->dato << "  ";
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
}

// funcion que inserta un nodo nuevo al final de la lista
// entradas: el dato a guardar
// salidas: no tiene
void ListaAristas::insertarAlFinal (int dato, int peso)
{
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new Arista(dato,peso);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo               
     }
     else
     {
         // se crea el nuevo nodo
         Arista *nuevo = new Arista(dato, peso);
         // uN siguiente debe apuntar al nuevo nodo
         // uN debe apuntar al nuevo nodo enlazado
         ultimoNodo->siguiente = nuevo;
         ultimoNodo = nuevo;
         // el puntero nuevo deja de existir, no se libera
         // memoria porque se pierde la info
     }
}



// funcion que retorna true si la lista es vacia
// entradas: ninguna
// salidas: true si es no tiene elmentos, false otro caso
bool ListaAristas::vacia()
{
     // si primerNodo es nulo, no hay elementos
     if (primerNodo == NULL)
        return true;
     else
         return false;     
}



Arista* ListaAristas::borrarAlFinal(void)
{
      if (vacia())
         return NULL;
      // este caso es cuando tiene un solo elemento
      else if (primerNodo->siguiente == NULL)
      {
            Arista* actual = primerNodo;
            primerNodo = ultimoNodo = NULL;
            return actual;
      }
      else 
      {
            // referencia al primero para recorrer la lista
            Arista * actual = primerNodo;
            // recorre la lista hasta llegar al penultimo nodo
            //while (actual->siguiente != NULL)
            while (actual->siguiente->siguiente != NULL)
              actual = actual->siguiente; 
              
            // al salir actual referencia al penultimo nodo
            // refencia nueva al ultimo nodo para despues retornarlo
            Arista* tmp = ultimoNodo;
            // ultimo nodo pasa al penultimo
            ultimoNodo = actual;
            //le quita el enlace al que era ultimo
            actual->siguiente = NULL;
            // retorna el que desenlazo al final
            return tmp;
        }
}

// LARGO LARGO LARGO
int ListaAristas::largo(void)
{
    int contador = 0;
     // apunta a los mismo que pN
     Arista *tmp = primerNodo;
     
     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           contador++;
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
     return contador;
}

// BUSCAR BUSCAR BUSCAR
Arista * ListaAristas::buscar(int valor)
{
       Arista * tmp = primerNodo;
       while (tmp!=NULL)
       {
             if (tmp->dato == valor)
                return tmp;
             
             tmp = tmp->siguiente;      
             
       }       
       
       return NULL;
}

// BORRAR POSICION BORRAR POSICION
// Funcion que elimina el elmento de la lista en una posicion
// esta funcion no retorna el nodo eliminado, por lo que
// si libera memoria
void ListaAristas::borrarEnPosicion(int pos)
{
     // si esta vacia no borra
        if (vacia())
        { }
        // pos 0 borra el inicio
        else
        if (pos == 0)
        {
            // borrar al inicial no libera memoria, se hace
            // luego de llamar a la funcion
            Arista * borrado = borrarAlInicio();
        
            if (borrado != NULL)
               delete borrado;        
                
        }
        else 
        {
            //recorre la lista hasta el nodo previo a eliminar
            Arista *actual = primerNodo;
            // deja el puntero en el nodo antes a eliminar
            for (int i=1; i < pos && actual->siguiente != NULL;i++)
                actual=actual->siguiente;
            
            // si es el ultimo borra el final
            if (actual->siguiente == NULL)
            {
                 // borrar al final no libera memoria, se hace
                 // luego de llamar a la funcion
                 Arista* borrado = borrarAlFinal();
                 if (borrado != NULL)
                        delete borrado;
            }
            else
            {
                //referencia tmp que apunta al que se eliminara
                Arista *tmp = actual->siguiente;
                // anterior a borrar siguiente será el sig.sig
                actual->siguiente = actual->siguiente->siguiente;
                // el que se eliminara.sig sera null
                tmp->siguiente = NULL;
                delete tmp;
            }
        }
    }
    
// POSICION POSICION
int ListaAristas::posicion(int valor)
{
    int pos = 0;
       Arista * tmp = primerNodo;
       while (tmp!=NULL)
       {
             if (tmp->dato == valor)
                return pos;
             
             pos++;
             tmp = tmp->siguiente;      
             
       }       
       
       return -1;
}

    

