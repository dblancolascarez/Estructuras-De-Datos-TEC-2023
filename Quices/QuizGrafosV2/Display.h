#pragma once
#include "Includes.h"

void displayPaths(const vector<string>& paths) {
    cout << "Paths found:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }
    cout << endl;
}