/* Pendiente*** agregar pedidos con error a PedidosError
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

void updatePedidosFile(vector<vector<string>>& clientesLista, const string& filename1) {
    
    ifstream pedidosFile(filename1);
    if (!pedidosFile.is_open()) {
        cout << "Error opening file " << filename1 << endl;
        return;
    }

    // Read the contents of the file into memory
    stringstream buffer;
    buffer << pedidosFile.rdbuf();
    string contents = buffer.str();
    pedidosFile.close();

    // Find the second line and modify it if the client exists
    string::size_type pos1 = contents.find_first_of('\n') + 1;
    string::size_type pos2 = contents.find_first_of('\n', pos1) + 1;
    if (pos1 != string::npos && pos2 != string::npos) {
        string clientCode = contents.substr(pos1, pos2 - pos1 - 1);
        bool clientFound = false;
        for (const auto& cliente : clientesLista) {
            if (cliente[0] == clientCode) {
                clientFound = true;
                contents.replace(pos1, pos2 - pos1, clientCode + '\t' + cliente[2] + '\n');
                break;
            }
        }

        if (clientFound) {
            // Write the modified contents back to the file
            ofstream pedidosOut(filename1);
            if (pedidosOut.is_open()) {
                pedidosOut << contents;
                pedidosOut.close();
                cout << "Pedidos file updated successfully." << endl;

                // Move the updated file to the specified folder
                string foldername = "CarpetaPedidos";
                string newpath = foldername + '/' + filename1;
                if(rename(filename1.c_str(), newpath.c_str()) != 0) {
                    perror("Error moving file");
                } else {
                    cout << "File moved successfully." << endl;
                }

            }else {
                string foldername1 = "CarpetaPedidosError";
                string newpath1 = foldername1 + '/' + filename1;
                cout << "Error opening file " << filename1 << " for writing." << endl;
                // Move the updated file to the specified folder
                if(rename(filename1.c_str(), newpath1.c_str()) != 0) {
                    perror("Error moving file");
                } else {
                    cout << "File moved successfully." << endl;
                }
            }
        } else {
            string foldername1 = "CarpetaPedidosError";
            string newpath1 = foldername1 + '/' + filename1;
            cout << "Client code " << clientCode << " not found in clientesLista." << endl;
            // Move the updated file to the specified folder
                if(rename(filename1.c_str(), newpath1.c_str()) != 0) {
                    perror("Error moving file");
                } else {
                    cout << "File moved successfully." << endl;
                }
        }
    } else {
        string foldername1 = "CarpetaPedidosError";
        string newpath1 = foldername1 + '/' + filename1;
        cout << "Error reading first or second line of file " << filename1 << endl;
        // Move the updated file to the specified folder
                if(rename(filename1.c_str(), newpath1.c_str()) != 0) {
                    perror("Error moving file");
                } else {
                    cout << "File moved successfully." << endl;
                }
    }
}











