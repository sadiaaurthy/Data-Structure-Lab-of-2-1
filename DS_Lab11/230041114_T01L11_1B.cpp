#include <iostream>
#include <vector>
using namespace std;
vector<int> par, rnk;
struct dsu {
    vector<int> par, rnk, sz;
    int max_size;
    int num_of_comp;
    dsu(int city) {
        max_size = 1;
        num_of_comp = city;
        par.resize(city);
        rnk.resize(city, 1);
        sz.resize(city, 1);

        for (int i = 0; i < city; i++) {
            par[i] = i;
        }
    }
    int find(int u) {
        if (par[u] == u)
            return par[u];
        else
            return par[u] = find(par[u]);
    }
    void Union(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru != rv) {
            if (rnk[ru] <= rnk[rv]) {
                par[ru] = rv;
                sz[rv] += sz[ru];
                max_size = max(max_size, sz[rv]);
            }
            else {
                par[rv] = ru;
                sz[ru] += sz[rv];
                max_size = max(max_size, sz[ru]);
            }
            if (rnk[ru] == rnk[rv]) {
                rnk[rv]++;
            }
            num_of_comp--;
        }
    }
    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};
int main() {
    int city, q;
    cin >> city >> q;
    dsu d(city);
    while (q--) {
        int u, v;
        cin >> u >> v;
        d.Union(u - 1, v - 1);
        cout << d.num_of_comp << ' ' << d.max_size << endl;
    }
}