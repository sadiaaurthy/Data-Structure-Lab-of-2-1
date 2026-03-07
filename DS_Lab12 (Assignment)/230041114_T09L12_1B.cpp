#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int getIndex(string tar, vector<string>& name) {
    for (int i = 0; i < name.size(); i++) {
        if (name[i] == tar) {
            return i;
        }
    }
    return -1;
}

bool canReach(int start, int tar, vector<vector<int> >& adj) {
    int n = adj.size();

    vector<bool> visited;
    for (int i = 0; i < n; i++) {
        visited.push_back(false);
    }

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == tar) {
            return true;
        }

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return false;
}

int main() {
    int V, E, Q;
    cin >> V >> E >> Q;

    vector<string> name;
    for (int i = 0; i < V; i++) {
        string s;
        cin >> s;
        name.push_back(s);
    }

    vector<vector<int> > adj;
    for (int i = 0; i < V; i++) {
        vector<int> temp;
        adj.push_back(temp);
    }

    vector<int> indegree;
    for (int i = 0; i < V; i++) {
        indegree.push_back(0);
    }

    for (int i = 0; i < E; i++) {
        string a, b;
        cin >> a >> b;

        adj[getIndex(a, name)].push_back(getIndex(b, name));
        indegree[getIndex(b, name)]++;
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topolog;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topolog.push_back(u);

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (topolog.size() != V) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 0; i < V; i++) {
        cout << name[topolog[i]];
        if (i + 1 < V) cout << " ";
    }
    cout << endl;

    for (int i = 0; i < Q; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        if (canReach(getIndex(s2, name), getIndex(s1, name), adj)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}