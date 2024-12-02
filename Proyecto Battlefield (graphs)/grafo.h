
struct Grafo
{
       ListaSimple * vertices;
       
       Grafo()
       {
              vertices = new ListaSimple();       
       } 
       
       // para insertar un vertice
       void insertarVertice(int d)
       {
            // valida que no exista
            Nodo * tmp = vertices->buscar(d);
            // si es null no existe, lo inserta
            if (tmp == NULL)
            {
                    // solo llama a insertar de lista            
                vertices->insertarAlFinal(d);
            }
            else
            {
                cout << "El nodo "<< d << "ya existe"<<endl;    
            }
       } 
       
       void insertarArista(int origen, int destino, int peso)
       {
            // si existe el vertice inserta
            Nodo * tmp = vertices->buscar(origen);
            Nodo * tmpDest = vertices->buscar(destino);
            if (tmp != NULL)
            {
               if (tmpDest != NULL)
               {
                 // si la arista no existe       
                 Arista * arista = tmp->aristas->buscar(destino);
                 if (arista == NULL)
                 {
                    tmp->aristas->insertarAlFinal(destino, peso);           
                 }
                 else
                 {
                     cout << "Arista ya existe";    
                 }
               }
               else
               {
                   cout << "Destino no existe";    
               } 
            }
            else
            {
                cout << "Nodo origen no existe"<< endl;    
            }
       }
       

// IMPRIMIR IMPRIMIR IMPRIMIR       
       void imprimir ()
       {
            Nodo * tmp = vertices->primerNodo;
            
            while (tmp != NULL)
            {
                 cout << tmp->dato <<": ";
                 tmp->aristas->imprimir();
                 cout << endl; 
                 tmp = tmp -> siguiente;  
            }    
            cout << endl; 
       }
// BORRAR ARISTA  BORRAR ARISTA
void borrarArista(int origen, int destino)
{
     Nodo * tmp = vertices->buscar(origen);     
     
     if (tmp != NULL)
     {
        int posA = tmp->aristas->posicion(destino);
        if (posA > -1)
        {
           tmp->aristas->borrarEnPosicion(posA);
           cout << "Eliminada arista "<<origen<<" - "<< destino<<endl;         
        }
        else
        {  }           
     }     
}       



// BORRAR BORRAR BORRAR

void borrarVertice (int dato)
{
     // se usan las funciones de lista
     int posV = vertices->posicion(dato);
     // si lo encontro, posV es <> -1
     if (posV > -1)
     {
        //recorre toda la lista de vertices
        // eliminando aristas a dato    
        Nodo * tmp = vertices->primerNodo;
        while (tmp != NULL)
        {
              // usa borrar arista
              borrarArista(tmp->dato, dato);
              tmp = tmp->siguiente;      
        }    
        // ya borro las aristas, ahora el vertice
        vertices->borrarEnPosicion(posV);
     }
     else
     {
         cout << "Vertice no existe"<<endl;    
     }

}

// visitar vertice
void visitarVertice(int dato)
{
     Nodo * tmp = vertices->buscar(dato);
     if (tmp != NULL)
        tmp->visitado = true;     
}

// visitar vertice
bool visitadoVertice(int dato)
{
     Nodo * tmp = vertices->buscar(dato);
     if (tmp != NULL)
        return tmp->visitado;
     else
         return false;     
}

// limpiar visitados
void limpiarVisitados()
{
     Nodo * tmp = vertices->primerNodo;
     while (tmp != NULL)
     {
           tmp->visitado = false;
           tmp = tmp->siguiente;      
     }     
}

// visitar Adyacentes

void visitarAdyacentes(int nodo)
{
     // visita el nodo
     visitarVertice(nodo);
     cout << nodo << " - " ;     
     // busca el vertice para recorrer aristas
     Nodo * tmp = vertices->buscar(nodo);
     
     if (tmp != NULL)
     {
             // recorre las lista de adyacencia
        Arista * actual = tmp->aristas->primerNodo;
        while (actual!=NULL)
        {
              // si no esta visitado
            if (visitadoVertice(actual->dato)==false)
            {
                visitarAdyacentes(actual->dato);
            }

            actual = actual->siguiente;      
        }        
     }     
}

// PROFUNDIDAD - Recorrido por profundidad

void profundidad()
{
     Nodo * tmp = vertices->primerNodo;
     // hace un while de n para recorrer todos
     // aun cuando el grafo es disconexo
     while (tmp != NULL)
     {
         if (tmp->visitado == false)
            visitarAdyacentes(tmp->dato);
            
         tmp = tmp->siguiente;
     }
     limpiarVisitados();
}

// ANCHURA - recorrido anchura
//se le da el vertice de inicio
void anchura(Nodo * v)
{
     cout << v->dato << "  " ;
     visitarVertice(v->dato);// marca el primer nodo
     ListaSimple * cola = new ListaSimple();
     // mete a la cola los adyacentes del nodo inicial
     Arista * aristaTmp = v->aristas->primerNodo;
     while(aristaTmp != NULL)
     {
                     // encola
        cola->encolar(aristaTmp->dato);
        // visita el nodo
        visitarVertice(aristaTmp->dato);
        aristaTmp = aristaTmp -> siguiente;                
     }
     
     // mientras no se vacíe la cola
    while(cola->primerNodo !=NULL)
    {
        // trabaja con el primero de la cola
        Nodo * actual = cola->desencolar();
        visitarVertice(actual->dato);
        // imprime el vertice
        cout << actual->dato << "  ";
        // para cada arista del vertice en la cola
        // va a meter a la cola los adyacentes
        Nodo * nodoCola = vertices->buscar(actual->dato);
        Arista * aristaTmp = nodoCola->aristas->primerNodo;
        
        while (aristaTmp != NULL)
        {
              // si no se ha visitado, se mete en cola
              if (visitadoVertice(aristaTmp->dato) == false)
              {
                 visitarVertice(aristaTmp->dato);
                 cola->encolar(aristaTmp->dato);                       
              }     
              aristaTmp = aristaTmp->siguiente;
        }
    }
    limpiarVisitados();     
 

        
     
}



       
// fin struct
};



