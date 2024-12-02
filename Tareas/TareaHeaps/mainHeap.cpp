#include "HeapTree.h"
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamaño maximo del heap: ";
    cin >> n;
    
    Heap heap(n);

    int op = 0;
    while (op != 4) {
        cout << endl << "---- MENU ----" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Eliminar elemento maximo" << endl;
        cout << "3. Imprimir heap" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> op;

        switch(op) {
            case 1:
                int element;
                cout << "Ingrese el elemento a insertar: ";
                cin >> element;
                heap.insert(element);
                break;
            case 2:
                cout << "El elemento maximo eliminado es: " << heap.eliminar() << endl;
                break;
            case 3:
                cout << "Heap por niveles:" << endl;
                heap.print();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    }

    return 0;
}

