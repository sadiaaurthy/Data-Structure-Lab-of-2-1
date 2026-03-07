#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V;
    cin >> V;
    vector<vector<int>> graph(V);

    for (int i = 0; i < V; i++) {
        int n;
        cin >> n;
        graph[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    vector<int> color(V, -1);

    for (int start = 0; start < V; start++) {
        if (color[start] != -1) continue;

        queue<int> q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for (int neighborNode : graph[u]) {
                if (color[neighborNode] == -1) {
                    color[neighborNode] = 1 - color[u];
                    q.push(neighborNode);
                } 
                else if (color[neighborNode] == color[u]) {
                    cout << "NO\n";
                }
            }
        }
    }

    cout << "YES\n";
}