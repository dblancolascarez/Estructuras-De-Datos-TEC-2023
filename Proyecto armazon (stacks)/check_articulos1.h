#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>

using namespace std;

void read_txt_files(const string& folder_path) {
    DIR* dir = opendir(folder_path.c_str());
    struct dirent* entry;

    if (dir == NULL) {
        cout << "Error opening directory: " << folder_path << endl;
        return;
    }

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

            cout << "Finished reading file: " << file_path << endl;
        } else {
            cout << "Error opening file: " << file_path << endl;
        }
    }

    closedir(dir);
}
