#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include "balanceador.h"

using namespace std;

void read_txt_files(const string& folder_path) {
    DIR* dir = opendir(folder_path.c_str());
    struct dirent* entry;

    if (dir == NULL) {
        cout << "Error opening directory: " << folder_path << endl;
        return;
    }

    string folder_name1 = "CarpetaPedidosError";
    string folder_name2 = "CarpetaPedidosBodega";
    string folder_name3 = "CarpetaPedidosPendientes";
    string error_folder_path = "./" + folder_name1; // Error folder path in the same directory as code
    string pendiente_folder_path = "./" + folder_name3; //folder path in which non processed txt files go
    string bodega_folder_path = "./" + folder_name2; //folder path in which processed txt files go

    while ((entry = readdir(dir)) != NULL) {
        string filename = entry->d_name;
        if (filename.size() < 5 || filename.substr(filename.size() - 4) != ".txt") {
            continue;  // Not a txt file
        }

        string file_path = folder_path + "/" + filename;
        ifstream file(file_path);

        if (file.is_open()) {
            cout << "Reading file: " << file_path << endl;

            string line;
            while (getline(file, line)) {
                // Do something with the line
                // ...
            }

            

            // Call process_file on the file if there were no errors
            if (validate_product_request(file_path)){
                cout << "Product request validated!" << endl;
                string bodega_file_path = bodega_folder_path + "/" + filename;
                if (rename(file_path.c_str(), bodega_file_path.c_str()) != 0) {
                    perror("Error moving file");
                } else {
                    cout << "Order moved to Bodega: " << bodega_file_path << endl;
                }
                

            }else{
                cout << "Product request validation failed." << endl;
                string pendiente_file_path = pendiente_folder_path + "/" + filename;
                if (rename(file_path.c_str(), pendiente_file_path.c_str()) != 0) {
                    perror("Error moving file");
                } else {
                    cout << "Order moved to Pendientes: " << pendiente_file_path << endl;
                }
            }
        } else {
            cout << "Error opening file: " << file_path << endl;
            string error_file_path = error_folder_path + "/" + filename;
            if (rename(file_path.c_str(), error_file_path.c_str()) != 0) {
                perror("Error moving file");
            } else {
                cout << "File moved to error folder: " << error_file_path << endl;
            }
        }

        cout << "Finished reading file: " << file_path << endl;
        cout << endl;
    }

    closedir(dir);
}






