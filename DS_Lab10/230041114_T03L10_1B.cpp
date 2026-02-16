#include <iostream>
#include <vector>
using namespace std;

void printAdjList(vector<vector<int>> adjList, int V) {
    cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i + 1 << ": ";
        for (int neighbour : adjList[i]) {
            cout << neighbour << " ";
        }
        cout << endl;
    }
}

void printAdjMatrix(vector<vector<int>> adjmatrix, int V) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjmatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adjList(V);
    vector<vector<int>> adjMatix(V, vector<int>(V, 0));
    while (E--) {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v);
        adjList[v - 1].push_back(u);
        adjMatix[u - 1][v - 1] = 1;
        adjMatix[v - 1][u - 1] = 1;
    }
    printAdjList(adjList, V);
    printAdjMatrix(adjMatix, V);
}