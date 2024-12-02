#include "Grafo.h"
#include "Display.h"

int main() {
    Graph g;
    g.addEdge("0", "1");
    g.addEdge("0", "2");
    g.addEdge("0", "3");
    g.addEdge("1", "2");
    g.addEdge("1", "3");
    g.addEdge("2", "3");

    while (true) {
        cout << "1. Find paths between nodes" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string start, end;
            cout << "Enter the starting node: ";
            cin >> start;
            cout << "Enter the ending node: ";
            cin >> end;

            vector<string> paths = g.findPaths(start, end);
            displayPaths(paths);
        }
        else if (choice == 2) {
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}