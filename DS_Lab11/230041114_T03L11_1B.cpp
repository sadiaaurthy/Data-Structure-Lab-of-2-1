#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct graph {
    vector<vector<int>> adjList;
    int V;
    vector<int> distance;
    vector<int> pred;
    vector<string> color;
    vector<pair<int, int>> bfs_edge;
    graph(int vert) {
        V = vert;
        adjList.resize(V + 1);
        distance.resize(V + 1, -1);
        pred.resize(V + 1, -1);
        color.resize(V + 1, "white");
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void BFS(int s) {
        queue<int> q;
        q.push(s);
        distance[s] = 0;
        color[s] = "grey";
        vector<int> bfs_order;
        while (!q.empty()) {
            int node = q.front();
            bfs_order.push_back(node);
            q.pop();
            for (int V : adjList[node]) {
                if (color[V] == "white") {
                    color[V] = "grey";
                    distance[V] = distance[node] + 1;
                    pred[V] = node;
                    q.push(V);
                    bfs_edge.push_back({node, V});
                }
            }
            color[node] = "black";
        }
        cout << "Adjacency list:\n";
        for (int i = 1; i <= V; i++) {
            cout << i << ": ";
            for (int neighbour : adjList[i]) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
        cout << "\nBFS order: ";
        for (int node : bfs_order) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Distance from source: \n";
        for (int i = 1; i <= V; i++) {
            cout << i << "(" << distance[i] << ") ";
        }
        cout << "\n";
        cout << "Paths from source:\n";
        for (int i = 1; i <= V; i++) {
            if (distance[i] != -1) {
                vector<int> path;
                int curr = i;
                while (curr != -1) {
                    path.push_back(curr);
                    curr = pred[curr];
                }
                reverse(path.begin(), path.end());
                cout << i << ": ";
                for (int j = 0; j < path.size(); j++) {
                    if (j > 0)
                        cout << "->";
                    cout << path[j];
                }
                cout << "\n";
            }
        }
        cout << "Edges of BFS tree:\n";
        for (auto it : bfs_edge) {
            cout << it.first << " " << it.second << endl;
        }
    }
};
int main() {
    int V, E, s;
    cin >> V >> E >> s;
    graph g(V);
    while (E--)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.BFS(s);
}