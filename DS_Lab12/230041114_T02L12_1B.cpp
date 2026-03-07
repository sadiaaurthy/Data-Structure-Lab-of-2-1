#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int>> makeSparse(vector<int>& arr) {
    int N = arr.size();
    int maxRange = floor(log2(N)) + 1;
    vector<vector<int>> Sparse(N, vector<int> (maxRange, INT_MAX)) ;
        for (int i = 0; i < N; i++) {
            Sparse[i][0] = arr[i];
        }
        for (int j = 1; j < maxRange; j++) {
            for (int i = 0; i + (1 << j) - 1 < N; i++) {
                Sparse[i][j] = min(Sparse[i][j - 1], Sparse[i + (1 << j) - 1][j - 1]);
            }
        }
        return Sparse;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << "Ranges to be stored in the Sparse Table:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < floor(log2(N)); j++) {
            if ((i + (1 << j)) <= N) 
                cout << '(' << i << ',' << i + (1 << j) - 1 << ") ";
        }
        cout << endl;
    }
    vector<vector<int>> table = makeSparse(arr);
    cout << "\n";
    cout << "Status of Sparse Table:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= floor(log2(N)); j++) {
            if (i + (1 << j) - 1 <= N) {
                cout << table[i][j] << " ";
            }
        }
        cout << endl;
    }
    // int Q, i;
    // cin >> Q;
    // i = Q - 1;
    // while (Q--) {
    //     int l, r;
    //     cin >> l >> r;
    //     int window = r - l + 1;
    //     int j = floor(log2(window));
    //     //cout << "Query-" << Q - i << ':' << "Min=" << min(table[l][j], table[r - 1 << j + 1]) ;
    // }
}