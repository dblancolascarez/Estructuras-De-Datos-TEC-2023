#ifndef leerClientes_h
#define leerClientes_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void leerClientes(vector<vector<string>>& clientesLista, const string& filename) {
    ifstream clientesFile(filename);
    if (clientesFile.is_open()) {
        string line;
        while (getline(clientesFile, line)) {
            vector<string> clienteDatos;
            istringstream iss(line);
            string value;
            while (getline(iss, value, '\t')) {
                clienteDatos.push_back(value);
            }
            
            //prueba  validacion 
            if (clienteDatos.size() == 3) {
                try {
                    int valor = stoi(clienteDatos[2]);
                    if (valor >= 1 && valor <= 10) {
                        clientesLista.push_back(clienteDatos);
                    }
                } catch (const invalid_argument& ia) {
                    // Ignore invalid integer values
                }
            }
        
        //fin prueba
            
        }
        clientesFile.close();
    }

    cout << "[";
    for (size_t i = 0; i < clientesLista.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < clientesLista[i].size(); j++) {
            cout << clientesLista[i][j];
            if (j < clientesLista[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < clientesLista.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

#endif
