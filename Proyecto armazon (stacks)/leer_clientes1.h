#ifndef leerClientes1_h
#define leerClientes1_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool isInteger(const string& s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) {
        return false;
    }

    char* p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

void leerClientes1(vector<vector<string>>& clientesLista, const string& filename) {
    ifstream clientesFile(filename);
    if (clientesFile.is_open()) {
        string line;
        while (getline(clientesFile, line)) {
            vector<string> clienteDatos;
            istringstream iss(line);
            string value;
            int count = 0;
            while (getline(iss, value, '\t')) {
                count++;
                if (count == 1 && (!isInteger(value) || stoi(value) < 1 || stoi(value) > 999)) {
                    cerr << "Error: First element in line '" << line << "' is not an integer between 1 and 999." << endl;
                    break;
                } else if (count == 3 && (!isInteger(value) || stoi(value) < 1 || stoi(value) > 10)) {
                    cerr << "Error: Third element in line '" << line << "' is not an integer between 1 and 10." << endl;
                    break;
                }
                clienteDatos.push_back(value);
            }
            if (count == 3) {
                clientesLista.push_back(clienteDatos);
            }
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




