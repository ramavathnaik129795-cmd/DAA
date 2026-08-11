#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS
    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int x : adj[v]) {
            if (!visited[x])
                DFS(x, visited);
        }
    }

    // BFS
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            cout << v << " ";

            for (int x : adj[v]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }
};

int main() {
    int V, E;

    cout << "Enter vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // DFS
    vector<bool> visited(V, false);

    cout << "DFS: ";
    g.DFS(start, visited);

    // BFS
    cout << "\nBFS: ";
    g.BFS(start);

    return 0;
}