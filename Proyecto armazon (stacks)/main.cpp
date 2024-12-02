#include "leer_clientes.h"
#include "leer_pedidos1.h"
#include "leer_pedidos.h"
#include <cstdio>
#include "articulos.h"
#include "encolador.h"
#include "check_articulos.h"
#include "ordenador.h"
int main() {

    string pregunta;
    cout << "Desea introducir un nuevo archivo de clientes? s/n: ";
    cin >> pregunta;

    string filename;
    vector<vector<string>> clientesLista;
    vector<vector<string>> errorClientes;
    if (pregunta == "S" || pregunta == "s"){
        cout << "Digite el nombre del archivo de clientes a leer: ";
        cin >> filename;
        leerClientes(clientesLista,  filename);
        //leerClientes1(clientesLista, filename);
    }else{
        filename = "clientes.txt";
        leerClientes(clientesLista, filename);
        //leerClientes1(clientesLista, filename);
    }

    cout << endl;
   
    while (true){
        string pregunta_pedidos;
        cout << "Desea introducir un nuevo archivo de pedidos? s/n: ";
        cin >> pregunta_pedidos;

        string filename1;
        vector<vector<string>> pedidosLista;
    
        if (pregunta_pedidos == "S" || pregunta_pedidos == "s"){
        cout << "Digite el nombre del archivo de pedidos a leer: ";
        cin >> filename1;
        //leerPedidos1(filename1, clientesLista);
        updatePedidosFile(clientesLista, filename1);
        encolador(filename1.c_str());
        continue;
        
        }else{
            break;
        }
    }
    cout << endl;
    //ARTICULOS
    ArticleList list;
    if (validate("articulos.txt", list)) {
        // print out the list
        Article* current = list.head;
        cout << "Articulos: " << "[";
        while (current != nullptr) {
            cout << "[" << current->id << "\t" << current->value << "\t" << current->quantity << "\t"
                 << current->category << "\t" << current->code << "]";
            if (current->next != nullptr) {
                cout << ",";
            }
            current = current->next;
        }
        cout << "]" << endl;
        cout << endl;
    }

    //check_articulos.h
    string folder_name = "CarpetaPedidos"; // Modify folder name here
    string folder_path = "./" + folder_name;  // Replace with actual folder path
    read_txt_files(folder_path);

    //ordenador.h
    string folder_path_ordenador = "CarpetaPedidos/";
    order_files_by_number(folder_path_ordenador);
   
    return 0;
}