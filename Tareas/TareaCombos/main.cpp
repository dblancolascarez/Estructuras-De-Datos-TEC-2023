#include <iostream>
#include <string>
#include "metodos.h"

using namespace std;

int main() {
    ComboBaseDatos base;

    while (true) {
        // Ensenar menu
        cout << "******MENU******" << endl;
        cout << "1. Agregar combo" << endl;
        cout << "2. Buscar combo" << endl;
        cout << "3. Borrar combo" << endl;
        cout << "4. Imprimir todos los combos" << endl;
        cout << "5. Modificar nombre de un combo" << endl;
        cout << "6. Modificar cantidad de componentes de un combo" << endl;
        cout << "7. Agregar componente a un combo" << endl;
        cout << "8. Calcular para porciones" << endl;
        cout << "9. Salir" << endl;
        cout << "Ingrese una opcion: ";

        int opcion;
        cin >> opcion;
        cin.ignore(); 

        //opciones del menu, llamar al metodo dado 
        if (opcion == 1) {
            agregarCombo(base);
        } else if (opcion == 2) {
            buscarCombo(base);
        } else if (opcion == 3) {
            borrarCombo(base);
        } else if (opcion == 4) {
            imprimirCombos(base);
        } else if (opcion == 5) {
            modificarNombreCombo(base);
        } else if (opcion == 6) {
            modificarComponentes(base);
        } else if (opcion == 9) {
            cout << endl;
            cout << "Gracias por usar el programa :)" << endl;
            cout << endl;
            break;
        } else {
            cout << endl;
            cout << "Opcion invalida, si la opcion que busca no se encuentra, digite 9" << endl;
            cout << endl;
        }
    }

    return 0;
}