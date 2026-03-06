#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct graph {
    vector<vector<int>> adjList;
    int V, time;
    vector<string> colour;
    vector<int> discovery, finishing;
    vector<int> pred;
    vector<tuple<int, int, string>> edge_class;
    vector<pair<int, int>> dfs_order;
    graph(int vert) {
        V = vert;
        time = 0;
        adjList.resize(V + 1);
        colour.resize(V + 1, "white");
        pred.resize(V + 1, 0);
        discovery.resize(V + 1, 0);
        finishing.resize(V + 1, 0);
        colour.resize(V + 1, "white");
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }
    void dfs_visit(int u)
    {
        colour[u] = "gray";
        discovery[u] = ++time;
        dfs_order.push_back({u, discovery[u]});
        for (int V : adjList[u]) {
            if (colour[V] == "white") {
                pred[V] = u;

                edge_class.push_back({u, V, "Tree Edge"});
                dfs_visit(V);
            }

            else if (colour[V] == "gray") {
                edge_class.push_back({u, V, "Back Edge"});
            }
            else if (colour[V] == "black") {
                if (discovery[u] < discovery[V]) {
                    edge_class.push_back({u, V, "Forward Edge"});
                }
                else {
                    edge_class.push_back({u, V, "Cross Edge"});
                }
            }
        }
        colour[u] = "black";
        finishing[u] = ++time;
    }
    void dfs_visit() {
        for (int i = 1; i <= V; i++) {
            if (colour[i] == "white")
            {
                dfs_visit(i);
            }
        }
        cout << "Adjacency list:\n";
        for (int i = 1; i <= V; i++) {
            cout << i << ": ";
            for (int neighbour : adjList[i])
            {
                cout << neighbour << " ";
            }
            cout << endl;
        }
        cout << "DFS order: ";
        for (auto it : dfs_order) {
            cout << it.first << " ";
        }
        cout << endl;
        cout << "Timestamps of Vertex(discovery/finishing):\n";
        for (int i = 1; i <= V; i++) {
            cout << i << "(" << discovery[i] << "/" << finishing[i] << ")" << endl;
        }
        cout << "Edge classification:\n";
        for (auto [u, v, edge] : edge_class) {
            cout << u << " " << v << ": " << edge << endl;
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    graph g(V);
    while (E--) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.dfs_visit();
}