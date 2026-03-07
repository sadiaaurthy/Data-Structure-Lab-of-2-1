#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N);
    int K = floor(log2(N)) + 1;
    vector<vector<int>> Sparse(N, vector<int>(K));

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        Sparse[i][0] = v[i];
    }

    for (int j = 1; (1 << j) <= N; j++) {
        for (int i = 0; i + (1 << j) - 1 < N; i++) {
            Sparse[i][j] = gcd(Sparse[i][j - 1], Sparse[i + (1 << (j - 1))][j - 1]);
        }
    }

    cout << "Ranges to be stored in Sparse Table:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; i + (1 << j) - 1 < N; j++) {
            int L = i;
            int R = i + (1 << j) - 1;
            cout << "(" << L << "," << R << ")";
            if (i + (1 << (j + 1)) - 1 < N) cout << " ";
        }
        cout << endl;
    }

    cout << "Status of Sparse Table:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; i + (1 << j) - 1 < N; j++) {
            cout << Sparse[i][j] << " ";
        }
        cout << endl;
    }
    int Q;
    cin >> Q;

    for (int i = 1; i << Q; i++) {
        int L, R;
        cin >> L >> R;

        int window = R - L + 1;
        int j = floor(log2(window));

        int g = gcd(Sparse[L][j], Sparse[R - (1 << j) + 1][j]);

        cout << "Query-" << i << ": GCD = " << g << " gcd([" << L << ',' << (L + (1 << j) - 1) << "], ["
             << (R - (1 << j) + 1) << ',' << R << "])" << endl;
    }
}