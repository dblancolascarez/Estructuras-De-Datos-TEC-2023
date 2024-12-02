#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <regex>
#include <dirent.h>

using namespace std;

void order_files_by_number(string folder_path_ordenador) {
    regex filename_regex(R"((\d+)_pedido_\d+_\d+\.txt)");

    priority_queue<int, vector<int>, greater<>> files_queue;

    DIR* dir;
    struct dirent* entry;
    if ((dir = opendir(folder_path_ordenador.c_str())) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            string filename = entry->d_name;
            if (regex_match(filename, filename_regex)) {
                string file_number_str = filename.substr(0, filename.find_first_of("_"));
                int file_number = stoi(file_number_str);

                // Add the file number to the queue
                files_queue.push(file_number);
            }
        }
        closedir(dir);
    } else {
        perror("opendir");
        return;
    }

   // Print the file names in order of priority
    while (!files_queue.empty()) {
        int file_number = files_queue.top();
        files_queue.pop();
        string filename = folder_path_ordenador + to_string(file_number) + "_pedido";
        string suffix = filename.substr(filename.find_last_of("."));
        size_t pos = filename.find_last_of("_");
        cout << "filename: " << filename << ", pos: " << pos << ", size: " << filename.size() << endl;
        filename.replace(folder_path_ordenador.size(), pos - folder_path_ordenador.size(), to_string(file_number));
        filename.append(suffix);
        cout << filename << endl;
    }

}

