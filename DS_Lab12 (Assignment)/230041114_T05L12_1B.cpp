#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int getIdx(string tar, vector<string>& city) {
    for (int idx = 0; idx < city.size(); idx++) {
        if (city[idx] == tar) return idx;
    }
    return -1;
}

void citiesAtDistance_K(int k, int u, int par, int depth, vector<vector<int>>& adj, vector<int>& res) {
    if (depth == k) {
        res.push_back(u);
        return;
    }

    for (int i = 0; i < adj[u].size(); i++) {
        int node = adj[u][i];
        if (node != par) {
            citiesAtDistance_K(k, node, u, depth + 1, adj, res);
        }
    }
}
bool BFS(int src, int des, int k, vector<int>& par, vector<vector<int>>& adj) {
    int nodes = adj.size();
    vector<bool> visited;
    for (int i = 0; i < nodes; i++) {
        visited.push_back(false);
        par.push_back(-1);
    }

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == des) return true;

        vector<int> nextCity;
        citiesAtDistance_K(k, u, -1, 0, adj, nextCity);

        for (int i = 0; i < nextCity.size(); i++) {
            int node = nextCity[i];
            if (!visited[node]) {
                visited[node] = true;
                par[node] = u;
                q.push(node);
            }
        }
    }
    return false;
}

int main() {
    int V, E, Q, k;
    cin >> V >> E;
    string c1, c2, str, src, des;
    vector<vector<int>> adj;
    vector<string> city;

    for (int i = 0; i < V; i++) {
        cin >> str;
        city.push_back(str);
    }

    for (int i = 0; i < V; i++) {
        vector<int> temp;
        adj.push_back(temp);
    }

    for (int i = 0; i < E; i++) {
        cin >> c1 >> c2;

        adj[getIdx(c1, city)].push_back(getIdx(c2, city));
        adj[getIdx(c2, city)].push_back(getIdx(c1, city));
    }

    while (true) {
        cin >> src >> des >> k;
        vector<int> par;
        bool fnd = BFS(getIdx(src, city), getIdx(des, city), k, par, adj);

        if (!fnd) cout << "NO\n";

        else {
            vector<int> path;
            int curr = getIdx(des, city);

            while(curr != -1) {
                path.push_back(curr);
                curr = par[curr];
            }

            for (int i = path.size()-1; i >= 0; i--) {
                cout << city[path[i]] << " ";
            }
            cout << endl;
        }
    }
}
