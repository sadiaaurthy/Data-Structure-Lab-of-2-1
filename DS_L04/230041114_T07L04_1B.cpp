#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    priority_queue<int> maxHp;
    for (int i = 0; i < N; i++) {
        maxHp.push(v[i]);
        if (maxHp.size() < 3) cout << -1 << "\n";
        else {
            int fir = maxHp.top();
            maxHp.pop();
            int sec = maxHp.top();
            maxHp.pop();
            int thi = maxHp.top();
            maxHp.pop();
            int product = fir * sec * thi;
            cout << product << endl;
            maxHp.push(fir);
            maxHp.push(sec);
            maxHp.push(thi);
        }
    }
    return 0;
}