#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> v(N + 1), pref(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        pref[i] = pref[i - 1] + v[i]; 
    }

    while(Q--) {
        int L, R;
        cin >> L >> R;

        int window = R - L + 1;

        if (window & 1) {
            cout << -1 << endl;
            continue; 
        }

        int total_1 = pref[R] - pref[L-1], total_0 = window - total_1;

        cout << abs(total_1 - total_0) / 2 << endl;
    }
}