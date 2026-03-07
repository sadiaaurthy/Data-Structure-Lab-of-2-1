#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int sparse[100][17];

int query(int L, int R) {
    int j = floor(log2(R - L + 1));
    return max(sparse[L][j], sparse[R - (1 << j) + 1][j]);
}

int main() {
    int N, M, magicBall = 0;
    cin >> N >> M;
    vector<int> Height(N + 1);
    for (int i = 1; i <=N; i++) {
        cin >> Height[i];
        sparse[i][0] = Height[i];
    }

    for (int j = 1; (1 << j) <= N; j++) {
        for (int i = 1; i + (1 << j) - 1 <= N; i++) {
            sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        int L = min(A, B);
        int R = max(A, B);

        if (query(L, R - 1) <= Height[A]) {
            magicBall++;
        }
    }

    cout << magicBall << endl;
    
}