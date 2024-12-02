#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Heap {
    int *array; // el arreglo que representa el heap
    int size; // tamaño actual del heap
    int capacity; // tamaño máximo del heap

    Heap(int capacity) {
        array = new int[capacity];
        size = 0;
        this->capacity = capacity;
    }

    ~Heap() {
        delete[] array;
    }

    // Devuelve el índice del padre del nodo en el índice i
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Devuelve el índice del hijo izquierdo del nodo en el índice i
    int left(int i) {
        return 2 * i + 1;
    }

    // Devuelve el índice del hijo derecho del nodo en el índice i
    int right(int i) {
        return 2 * i + 2;
    }

    // Inserta un elemento en el heap
    void insert(int element) {
        if (size == capacity) {
            cout << "Heap lleno" << endl;
            return;
        }

        // Inserta el nuevo elemento al final del arreglo
        array[size] = element;

        // Incrementa el tamaño del heap
        size++;

        // Sobe el nuevo elemento hasta su posición correcta en el heap
        int i = size - 1;
        while (i != 0 && array[parent(i)] < array[i]) {
            swap(array[i], array[parent(i)]);
            i = parent(i);
        }
    }

    // Elimina el elemento con el valor máximo del heap
    int eliminar() {
        if (size <= 0) {
            cout << "Heap vacio" << endl;
            return -1;
        }
        if (size == 1) {
            size--;
            return array[0];
        }

        // Almacena el elemento raíz, que será eliminado
        int root = array[0];

        // Reemplaza la raíz por el último elemento del arreglo
        array[0] = array[size - 1];
        size--;

        // Reordena el heap hacia abajo para mantener la propiedad de heap
        int i = 0;
        while (true) {
            int left_child = left(i);
            int right_child = right(i);
            int largest = i;

            if (left_child < size && array[left_child] > array[largest]) {
                largest = left_child;
            } if (right_child < size && array[right_child] > array[largest]) {
                largest = right_child;
            } if (largest != i) {
                swap(array[i], array[largest]);
                i = largest;
            } else {
                break;
            }
        }
        return root;
    }

    // Imprime el heap por niveles
    void print() {
        if (size == 0) {
            cout << "Heap vacio" << endl;
            return;
        }
        int nivel_actual = 0;
        int elementos_nivel_actual = 1;
        while (nivel_actual <= log2(size)) {
            for (int i = 0; i < elementos_nivel_actual && i + pow(2, nivel_actual) - 1 < size; i++) {
                cout << array[static_cast<int>(i + pow(2, nivel_actual) - 1)] << " ";
        }
            cout << endl;
            nivel_actual++;
            elementos_nivel_actual *= 2;
        }
    }
};
