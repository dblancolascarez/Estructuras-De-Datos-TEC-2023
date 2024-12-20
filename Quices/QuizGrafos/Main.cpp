#include <Grafo.h>

int main() {
    Graph g;
    g.addEdge("0", "1");
    g.addEdge("0", "2");
    g.addEdge("0", "3");
    g.addEdge("1", "2");
    g.addEdge("1", "3");
    g.addEdge("2", "3");

    vector<string> paths = g.findPaths("0", "2");

    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}