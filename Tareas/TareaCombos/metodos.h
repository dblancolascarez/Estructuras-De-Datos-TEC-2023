#include <iostream>
#include <string>

using namespace std;

//estructura componentes
struct Componente {
    string nombre;
    int cantidad;
    string unidad;
};

//estructura combo 
struct Combo {
    string nombre;
    int porciones;
    Componente componentes[30]; 
};

//estructura base de datos que contiene todos los combos
struct ComboBaseDatos {
    Combo combos[100]; 
    int numCombos = 0;
};

//metodo para agregar combos(opcion 1)
void agregarCombo(ComboBaseDatos& base) {
    // Revisar si la base de datos esta llena
    if (base.numCombos >= 100) {
        cout << "No se pueden agregar mas combos" << endl;
        return;
    }
    // Pedir al usuario el combo y porciones
    string nombre;
    int porciones;
    cout << "Digite el nombre del combo: ";
    getline(cin, nombre);
    // Revisar si el combo ya existe en la base de datos
    for (int i = 0; i < base.numCombos; i++) {
        if (base.combos[i].nombre == nombre) {
            cout << "El combo ya existe en la base de datos" << endl;
            return;
        }
    }
    cout << "Digite el numero de porciones del combo ";
    cin >> porciones;
    cin.ignore(); 
    // Obtener componentes para el nuevo combo 
    int numComponentes = 0;
    do {
        // Revisar si se alcanzo el numero maximo de componentes
        if (numComponentes >= 30) {
            cout << "Se alcanzo el valor maximo de componentes del combo" << endl;
            return;
        }
        // Pedir el nombre, cantidad y unidad para el nuevo componente
        string nombreComponente;
        int cantidadComponente;
        string unidadComponente;
        cout << "Digite el nombre del componente: ";
        getline(cin, nombreComponente);
        // Revisar si el componente ya existe
        for (int i = 0; i < numComponentes; i++) {
            if (base.combos[base.numCombos].componentes[i].nombre == nombreComponente) {
                cout << "Ya existe un componente con ese nombre para un combo" << endl;
                return;
            }
        }
        cout << "Digite la cantidad del componente: ";
        cin >> cantidadComponente;
        cin.ignore();
        cout << "Digite la unidad del componente: ";
        getline(cin, unidadComponente);
        // Agregar nuevo componente al combo 
        base.combos[base.numCombos].componentes[numComponentes].nombre = nombreComponente;
        base.combos[base.numCombos].componentes[numComponentes].cantidad = cantidadComponente;
        base.combos[base.numCombos].componentes[numComponentes].unidad = unidadComponente;
        numComponentes++;
        // Preguntar al usuario si quiere agregar un componente nuevamente
        cout << "Agregar otro componente(s/n): ";
        char respuesta;
        cin >> respuesta;
        cin.ignore(); 
        if (respuesta != 's' && respuesta != 'S') {
            break;
        }
    } while (true);
    // Agregar el nuevo combo a la base de datos
    base.combos[base.numCombos].nombre = nombre;
    base.combos[base.numCombos].porciones = porciones;
    base.numCombos++;
    cout << "El combo fue agregado" << endl;
}

//metodo para buscar un combo en la base de datos(opcion 2)
void buscarCombo(ComboBaseDatos& base) {
    // Preguntar al usuario por el nimbre del combo a buscar
    string nombreCombo;
    cout << "Digite el nombre del combo a buscar: ";
    getline(cin, nombreCombo);

    // Iterar para buscar el combo en la base de datos
    for (int i = 0; i < base.numCombos; i++) {
        if (base.combos[i].nombre == nombreCombo) {
            // Si el combo es encontrado, se imprimen los detalles del mismo 
            cout << "Nombre del combo: " << base.combos[i].nombre << endl;
            cout << "Porciones: " << base.combos[i].porciones << endl;
            cout << "Componentes: " << endl;
            for (int j = 0; j < 30; j++) { //iterar para imprimir los componentes unidad y cantidad
                if (base.combos[i].componentes[j].nombre != "") {
                    cout << base.combos[i].componentes[j].nombre << " (" << base.combos[i].componentes[j].cantidad << " " << base.combos[i].componentes[j].unidad << ")" << endl;
                }
            }
            return;
        }
    }
    // Mensaje en caso de no encontrar el combo 
    cout << " " << endl;
    cout << "Combo no encontrado" << endl;
    cout << " " << endl;
}
//metodo para borrar un combo (opcion 5)
void borrarCombo(ComboBaseDatos& base) {
    // Pregunta al usuario por el nombre del combo
    string nombreCombo;
    cout << "Digite el nombre del combo que desea borrar: ";
    getline(cin, nombreCombo);

    // Buscar el combo dado por el usuario en la base de datos
    for (int i = 0; i < base.numCombos; i++) {
        if (base.combos[i].nombre == nombreCombo) {
            // Al encontrar un combo se crea un espacio libre en el array por lo que se mueven
            //los elementos un index abajo del que poseian antes de que fuera borrado el combo 
            for (int j = i; j < base.numCombos - 1; j++) {
                base.combos[j] = base.combos[j + 1];
            }
            base.numCombos--;
            cout << "Combo borrado exitosamente" << endl;
            return;
        }
    }

    // Mensaje en caso de no encontrar el combo 
    cout << " " << endl;
    cout << "Combo no encontrado" << endl;
    cout << " " << endl;
}

//metodo para imprimir combos (opcion 4)
void imprimirCombos(ComboBaseDatos& base) {
    // Revisar si existen combos en la base de datos
    if (base.numCombos == 0) {
        cout << "No hay combos en el sistema" << endl;
        return;
    }

    // Imprimir todos los combos en la base de datos 
    for (int i = 0; i < base.numCombos; i++) { //iterar por la base de datos utilizando un indice de numero de combo
        cout << "---------------------" << endl;
        cout << "Combo #" << i + 1 << ":" << endl;
        cout << "Nombre: " << base.combos[i].nombre << endl;
        cout << "Porciones: " << base.combos[i].porciones << endl;
        cout << "Componentes: " << endl;
        for (int j = 0; j < 30; j++) { //
            // Revisa si existe el componente, y si es asi, imprime su informacion 
            if (base.combos[i].componentes[j].nombre != "") {
                cout << "  " << base.combos[i].componentes[j].nombre << ": ";
                cout << base.combos[i].componentes[j].cantidad << " ";
                cout << base.combos[i].componentes[j].unidad << endl;
            }
        }
        cout << endl;
    }
}

//metodo para modificar el nombre de combos(opcion 5)
void modificarNombreCombo(ComboBaseDatos& base) {
    // Revisar si existen combos en la base de datos
    if (base.numCombos == 0) {
        cout << "No hay combos en la base de datos" << endl;
        return;
    }

    // Pedir al usuario el nombre del combo a modificar
    string nombreModificar;
    cout << "Digite el nombre del combo que desea modificar: ";
    getline(cin, nombreModificar);

    // Iterar para encontrar el combo con el nombre dado y modificarlo 
    bool encontrado = false;
    for (int i = 0; i < base.numCombos; i++) {
        if (base.combos[i].nombre == nombreModificar) {
            encontrado = true;
            string nuevoNombre;
            cout << "Digite el nuevo nombre del combo: "; //nuevo nombre del combo
            getline(cin, nuevoNombre);
            // Revisar si el nombre esta en uso mediante iteracion 
            for (int j = 0; j < base.numCombos; j++) {
                if (j != i && base.combos[j].nombre == nuevoNombre) {
                    cout << "Ya existe un combo con ese nombre" << endl;
                    return;
                }
            }
            base.combos[i].nombre = nuevoNombre;
            cout << "El nombre del combo fue modificado" << endl;
            break;
        }
    }

    // Mensaje si el combo no fue encontrado 
    if (!encontrado) {
        cout << "No se encontro un combo con ese nombre" << endl;
    }
}

//metodo para modificar componentes de un combo (punto 6)
void modificarComponentes(ComboBaseDatos& base) {
    // Pregunta al usuario por el nombre del combo y componente del mismo
    string nombreCombo, nombreComponente;
    cout << "Digite el nombre del combo a modificar: ";
    getline(cin, nombreCombo);
    cout << "Digite el nombre del componente a modificar: ";
    getline(cin, nombreComponente);

    // Encontrar el combo en la base de datos
    int i = 0;
    bool encontrado = false;
    while (i < base.numCombos && !encontrado) {
        if (base.combos[i].nombre == nombreCombo) {
            // Encontrar el componente en el combo 
            int j = 0;
            while (j < 30) {
                if (base.combos[i].componentes[j].nombre == nombreComponente) {
                    // Pregunat al usuario la nueva cantidad del componente
                    int nuevaCantidad;
                    cout << "Digite la nueva cantidad del componente: ";
                    cin >> nuevaCantidad;
                    cin.ignore(); 
                    // Modificar la cantidad del componente
                    base.combos[i].componentes[j].cantidad = nuevaCantidad;
                    cout << "La cantidad del componente ha sido modificada" << endl;
                    encontrado = true;
                    break;
                }
                j++;
            }
            if (!encontrado) {
                cout << "El componente que se busca no se encuentra en este combo" << endl;
            }
        }
        i++;
    }
    if (!encontrado) {
        cout << "El combo no se encuentra en la base de datos" << endl;
    }
}

