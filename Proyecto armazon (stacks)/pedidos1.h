#ifndef PEDIDOS1_H
#define PEDIDOS1_H

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <ctsdl.hpp>

using namespace std;

const string INPUT_DIR = "input/";
const string ERROR_DIR = "error/";

void processFile(const string& filename) {
    ifstream file(INPUT_DIR + filename);
    string line;

    if (getline(file, line)) {
        try {
            int numPedidos = stoi(line);

            // Process pedido items
            while (getline(file, line)) {
                string codigo = line.substr(0, 3);
                int cantidad = stoi(line.substr(4));
                cout << "Pedido: " << codigo << " - Cantidad: " << cantidad << endl;
            }
        } catch (invalid_argument& e) {
            // Move file to error directory
            ctsdl::copy_file(INPUT_DIR + filename, ERROR_DIR + filename);
            ctsdl::remove(INPUT_DIR + filename);
        }
    }
}

void readFiles() {
    while (true) {
        ctsdl::dir_t dir(INPUT_DIR);
        if (dir.exists()) {
            for (auto& entry : dir) {
                string filename = entry.get_filename();
                if (entry.is_regular_file() && filename != "." && filename != "..") {
                    thread fileProcessor(processFile, filename);
                    fileProcessor.detach();
                }
            }
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
}

#endif