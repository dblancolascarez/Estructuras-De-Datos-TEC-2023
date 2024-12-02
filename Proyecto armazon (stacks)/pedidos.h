#ifndef Pedidos_h
#define Pedidos_h

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

// Function to process a text file
void processFile(const string& filePath) {
    // Open the file for reading
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: could not open file: " << filePath << endl;
        return;
    }

    // Read the first line as an integer
    int lineNumber;
    if (!(file >> lineNumber)) {
        cerr << "Error: first line of file is not an integer: " << filePath << endl;
        // Move the file to the error folder
        string errorPath = "error/" + filePath.substr(filePath.find_last_of('/') + 1);
        if (rename(filePath.c_str(), errorPath.c_str()) != 0) {
            cerr << "Error: could not move file to error folder: " << filePath << endl;
        }
        return;
    }

    // Process the file content here...
    cout << "Processing file: " << filePath << endl;

    // Close the file
    file.close();
}

#endif 