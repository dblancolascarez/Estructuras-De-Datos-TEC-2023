#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
private:
    unordered_map<string, vector<string>> graph;

public:
    void addEdge(string source, string destination) {
        graph[source].push_back(destination);
        graph[destination].push_back(source); // To make the graph complete
    }

    void dfs(string current, string destination, unordered_map<string, bool>& visited, vector<string>& currentPath, vector<string>& paths) {
        visited[current] = true;
        currentPath.push_back(current);

        if (current == destination) {
            string path = "";
            for (const string& node : currentPath) {
                path += node + " -> ";
            }
            path = path.substr(0, path.length() - 4); // Remove the last " -> "
            paths.push_back(path);
        }

        for (const string& neighbor : graph[current]) {
            if (!visited[neighbor]) {
                dfs(neighbor, destination, visited, currentPath, paths);
            }
        }

        currentPath.pop_back();
        visited[current] = false;
    }

    vector<string> findPaths(string start, string end) {
        unordered_map<string, bool> visited;
        vector<string> currentPath;
        vector<string> paths;

        for (const auto& pair : graph) {
            visited[pair.first] = false;
        }

        dfs(start, end, visited, currentPath, paths);

        return paths;
    }
};