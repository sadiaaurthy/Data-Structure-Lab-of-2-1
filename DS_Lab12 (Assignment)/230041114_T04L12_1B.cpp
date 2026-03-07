#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    int K = floor(log2(N)) + 1;
    vector<vector<int>> Sparse(K, vector<int>(N));

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        Sparse[0][i] = v[i];
    }

    for (int j = 1; j < K; j++) {
        for (int i = 0; i + (1 << j) <= N; i++) {
            Sparse[j][i] = Sparse[j - 1][i] | Sparse[j - 1][i + (1 << (j - 1))];
        }
    }
    
    int Q;
    cin >> Q;

    while(Q--) {
        int L, R, x;
        cin >> L >> R >> x;

        int window = R - L + 1;
        int j = floor(log2(window));

        int RangeOR = Sparse[j][L] | Sparse[j][R - (1 << j) + 1];

        if (RangeOR == v[x]) cout << "Yes\n";
        else cout << "No\n";
    }
}