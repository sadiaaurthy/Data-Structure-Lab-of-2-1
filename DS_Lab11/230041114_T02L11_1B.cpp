#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> Deg(V);
    while (E--) {
        int u, v;
        cin >> u >> v;
        Deg[u - 1]++;
        Deg[v - 1]++;
    }
    int d = Deg[0];
    bool regular = true;
    for (int i = 1; i < Deg.size(); i++) {
        if (Deg[i] == d) {
            regular = false;
            break;
        }
    }
    if (regular)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}