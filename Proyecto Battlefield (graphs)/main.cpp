#include "lista.h"
#include "grafo.h"
#include "grafoMatriz.h"


int main(int argc, char *argv[])
{
/*    
    Grafo * g = new Grafo();
    
    g->insertarVertice(10);
    g->insertarVertice(20);
    g->insertarVertice(30);
    g->insertarVertice(40);
    g->insertarVertice(50);

        //
    g->insertarArista(30, 20, 0);
    g->insertarArista(10, 30, 0);
    g->insertarArista(10, 40, 0);
    g->insertarArista(10, 50, 0);    
    g->insertarArista(20, 10, 0);    
    g->insertarArista(20, 20, 0);    
    g->insertarArista(20, 30, 0);    
    g->insertarArista(30, 40, 0);    
    g->insertarArista(40, 50, 0);    
    g->insertarArista(50, 10, 0); 
    g->imprimir();   
    
    //g->borrarVertice(10);
    //g->imprimir();   
    
//    g->profundidad();
    g->anchura(g->vertices->primerNodo);
*/

grafoMatriz * g1 = new grafoMatriz();
g1->agregarVertice(10);
g1->agregarVertice(20);
g1->agregarVertice(30);
g1->agregarVertice(40);
g1->agregarVertice(50);
g1->agregarVertice(60);
g1->imprimir();
   
//dijkstra
        g1->agregarArista(g1->vertices[0], g1->vertices[1],7);
        g1->agregarArista(g1->vertices[1], g1->vertices[0],7);
        g1->agregarArista(g1->vertices[0], g1->vertices[2],9);
        g1->agregarArista(g1->vertices[2], g1->vertices[0],9);
        g1->agregarArista(g1->vertices[0], g1->vertices[5],14);
        g1->agregarArista(g1->vertices[5], g1->vertices[0],14);
        g1->agregarArista(g1->vertices[1], g1->vertices[2],10);
        g1->agregarArista(g1->vertices[2], g1->vertices[1],10);
        g1->agregarArista(g1->vertices[1], g1->vertices[3],15);
        g1->agregarArista(g1->vertices[3], g1->vertices[1],15);
        g1->agregarArista(g1->vertices[2], g1->vertices[3],11);
        g1->agregarArista(g1->vertices[3], g1->vertices[2],11);
        g1->agregarArista(g1->vertices[2], g1->vertices[5],2);
        g1->agregarArista(g1->vertices[5], g1->vertices[2],2);
        g1->agregarArista(g1->vertices[3], g1->vertices[4],6);
        g1->agregarArista(g1->vertices[4], g1->vertices[3],6);
        g1->agregarArista(g1->vertices[5], g1->vertices[4],9);
        g1->agregarArista(g1->vertices[4], g1->vertices[5],9);   
        g1->imprimir();
        
cout<< endl;
//g1->dijkstra(10);
g1->warshall_floyd();
cout<< endl;
        
        system("PAUSE");
    return EXIT_SUCCESS; 
}





