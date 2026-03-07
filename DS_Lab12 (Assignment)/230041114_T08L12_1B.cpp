#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;

    for (int neighborNode : graph[node]) {
        if (!visited[neighborNode]) {
            DFS(neighborNode, graph, visited);
        }
    }
}

int main() {
    int N, M, src, des;
    cin >> N >> M;

    vector<vector<int>> graph(N +1);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    cin >> src >> des;
    vector<bool> visited(N + 1, false) ;
    DFS(src, graph, visited);

    if (visited[des]) cout << "Yes\n";
    else cout << "No\n";
}