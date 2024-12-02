#ifndef leerPedidos1_h
#define leerPedidos1_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "leer_clientes.h"
#include <algorithm>

using namespace std;

void leerPedidos1(const string& filename1, const vector<vector<string>>& clientesLista) {
    ifstream fin(filename1);

    int num_requests;
    int num_clients;
    vector<int> products;

    if (!(fin >> num_requests)) {
        cerr << "Error: first line of input file must be an integer" << endl;
        return;
    }else{
        string temp_num_requests = to_string(num_requests);
        cout << "num requests: " << temp_num_requests << endl;
        //string temp_client_code = to_string(num_clients);
        //cout << "num clients: " << temp_client_code << endl;
    }
    
    //string client_code;
    if (!(fin >> num_clients)) {
        cout << "client_code: " << num_clients << endl;
        cerr << "Error: second line of input file must be a string" << endl;
        return;
    }
    
    else{
        string temp_client_code = to_string(num_clients);
        cout << "client code: " << temp_client_code << endl; 
    } 

        
    string temp_client_code = to_string(num_clients);
    bool found_client = false;
    for (size_t i = 0; i < clientesLista.size(); i++) {
        if (to_string(stoi(clientesLista[i][0])) == temp_client_code) {
            found_client = true;
            break;
        }
    }


    if (!found_client) {
        cerr << "Error: client code " << temp_client_code << " not found" << endl;
        return;
    }

    string product_id;
    int quantity;
    bool found_product = false;

    while (fin >> product_id >> quantity) {
        found_product = true;
        int product_num = stoi(product_id.substr(1));
        products.push_back(product_num);
        products.push_back(quantity);
    }

    if (!found_product) {
        cerr << "Error: input file must contain at least one product ID and quantity" << endl;
        return;
    }
    
    
    cout << "[" << num_requests << ", " << num_clients << ", [";

   
    for (int i = 0; i < products.size(); i += 2) {
    string product_id = to_string(products[i] / 10) + to_string(products[i] % 10);
    char product_code = 'A' + products[i] / 100 - 1; // get the first letter of the product code
    product_id = product_code + product_id; // prepend the first letter of the product code to the product_id string
    int quantity = products[i + 1];
    cout << product_id << " " << quantity;
    if (i < products.size() - 2) {
        cout << ", ";
    }
}


    cout << "]]\n";
    
 
}


#endif 