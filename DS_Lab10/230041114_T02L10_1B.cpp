#include <iostream>
#include <vector>
using namespace std;
vector<int> par, rnk;
void makeSet(int n) {
    par.resize(n);
    rnk.resize(n);
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}
int find(int u, int ops) {
    if (ops == 2) cout << "f(" << u << ") ";
    if (par[u] == u) return u;
    return par[u] = find(par[u], ops);
}
void Union(int u, int v) {
    int ri = find(u, 3);
    int rj = find(v, 3);
    if (ri != rj) {
        if (rnk[ri] <= rnk[rj]) {
            par[ri] = rj;
        }
        else {
            par[rj] = ri;
        }
        if (rnk[ri] == rnk[rj]) {
            rnk[rj]++;
        }
    }
}
void Print() {
    for (int i = 0; i < par.size() && i < rnk.size(); i++) {
        cout << par[i] << "(" << rnk[i] << ")" << " ";
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;
    while (true) {
        int ops;
        cin >> ops;
        if (ops == 1) {
            makeSet(n);
            Print();
        }
        else if (ops == 2) {
            int u;
            cin >> u;
            cout << find(u, 2) << endl;
        }
        else if (ops == 3) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
            Print();
        }
        else {
            Print();
        }
    }
}
