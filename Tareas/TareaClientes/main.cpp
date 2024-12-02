#include "Metodos.h"

int main() {
    ListaClientes* clientes = new ListaClientes();
    clientes->nuevoCliente("Juan", 1000);
    clientes->agregarHijo("Juan", "Juanito", 10);
    clientes->agregarHobbie("Juan", "Juanito", "Futbol", 3);
    clientes->agregarHobbie("Juan", "Juanito", "Videojuegos", 3);
    clientes->nuevoCliente("Pedro", 2000);
    clientes->agregarHijo("Pedro", "Pedrito", 5);
    clientes->agregarHobbie("Pedro", "Pedrito", "Videojuegos", 3);
    clientes->nuevoCliente("Maria", 3000);
    clientes->agregarHijo("Maria", "Marito", 15);
    clientes->agregarHobbie("Maria", "Marito", "Futbol", 3);

    ListaSimpleHobbies distintos = clientes->getDistinctHobbies();
	distintos->imprimir();
    
    clientes->imprimirLista();
    return 0;
}