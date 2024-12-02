

#include "lista.h"


// funcion que inserta un nodo nuevo en la lista
// entradas: el dato a guardar
// salidas: no tiene
void ListaSimple::insertarAlInicio (int dato)
{
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new Nodo(dato);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo               
     }
     else
     {
         Nodo *nuevo = new Nodo(dato);
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

Nodo* ListaSimple::borrarAlInicio(void)
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
          Nodo* borrado = primerNodo;     
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
void ListaSimple::imprimir(void)
{
     // puntero temporal que avanza
     // por toda la lista
     // apunta a los mismo que pN
     Nodo *tmp = primerNodo;
     
     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           // imprime el dato del nodo en el que esta tmp
           cout << tmp->dato << "  ";
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
     cout << endl;
}

// funcion que inserta un nodo nuevo al final de la lista
// entradas: el dato a guardar
// salidas: no tiene
void ListaSimple::insertarAlFinal (int dato)
{
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new Nodo(dato);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo               
     }
     else
     {
         // se crea el nuevo nodo
         Nodo *nuevo = new Nodo(dato);
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
bool ListaSimple::vacia()
{
     // si primerNodo es nulo, no hay elementos
     if (primerNodo == NULL)
        return true;
     else
         return false;     
}

Nodo* ListaSimple::borrarAlFinal(void)
{
      if (vacia())
         return NULL;
      // este caso es cuando tiene un solo elemento
      else if (primerNodo->siguiente == NULL)
      {
            Nodo* actual = primerNodo;
            primerNodo = ultimoNodo = NULL;
            return actual;
      }
      else 
      {
            // referencia al primero para recorrer la lista
            Nodo* actual = primerNodo;
            // recorre la lista hasta llegar al penultimo nodo
            //while (actual->siguiente != NULL)
            while (actual->siguiente->siguiente != NULL)
              actual = actual->siguiente; 
              
            // al salir actual referencia al penultimo nodo
            // refencia nueva al ultimo nodo para despues retornarlo
            Nodo* tmp = ultimoNodo;
            // ultimo nodo pasa al penultimo
            ultimoNodo = actual;
            //le quita el enlace al que era ultimo
            actual->siguiente = NULL;
            // retorna el que desenlazo al final
            return tmp;
        }
}

Nodo * ListaSimple::buscar(int valor)
{
       Nodo * tmp = primerNodo;
       while (tmp!=NULL)
       {
             if (tmp->dato == valor)
                return tmp;
             
             tmp = tmp->siguiente;      
             
       }       
       
       return NULL;
}

int ListaSimple::posicion(int valor)
{
    int pos = 0;
       Nodo * tmp = primerNodo;
       while (tmp!=NULL)
       {
             if (tmp->dato == valor)
                return pos;
             
             pos++;
             tmp = tmp->siguiente;      
             
       }       
       
       return -1;
}




// Funcion que elimina el elmento de la lista en una posicion
// esta funcion no retorna el nodo eliminado, por lo que
// si libera memoria
void ListaSimple::borrarEnPosicion(int pos)
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
            Nodo* borrado = borrarAlInicio();
        
            if (borrado != NULL)
               delete borrado;        
                
        }
        else 
        {
            //recorre la lista hasta el nodo previo a eliminar
            Nodo *actual = primerNodo;
            // deja el puntero en el nodo antes a eliminar
            for (int i=1; i < pos && actual->siguiente != NULL;i++)
                actual=actual->siguiente;
            
            // si es el ultimo borra el final
            if (actual->siguiente == NULL)
            {
                 // borrar al final no libera memoria, se hace
                 // luego de llamar a la funcion
                 Nodo* borrado = borrarAlFinal();
                 if (borrado != NULL)
                        delete borrado;
            }
            else
            {
                //referencia tmp que apunta al que se eliminara
                Nodo *tmp = actual->siguiente;
                // anterior a borrar siguiente será el sig.sig
                actual->siguiente = actual->siguiente->siguiente;
                // el que se eliminara.sig sera null
                tmp->siguiente = NULL;
                delete tmp;
            }
        }
    }
    
// se hace un borrar al inicio llamado desencolar
// para simular una cola
Nodo* ListaSimple::desencolar(void)
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
          Nodo* borrado = primerNodo;     
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

// se hace un insertar al final, llamado encolar
void ListaSimple::encolar (int dato)
{
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new Nodo(dato);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo               
     }
     else
     {
         // se crea el nuevo nodo
         Nodo *nuevo = new Nodo(dato);
         // uN siguiente debe apuntar al nuevo nodo
         // uN debe apuntar al nuevo nodo enlazado
         ultimoNodo->siguiente = nuevo;
         ultimoNodo = nuevo;
         // el puntero nuevo deja de existir, no se libera
         // memoria porque se pierde la info
     }
}


 
