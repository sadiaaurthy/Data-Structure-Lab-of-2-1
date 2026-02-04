#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int a;
    unordered_map<int, int> f;
    vector<int> v;
    while (true) {
        cin >> a;
        if (a == -1) break;
        v.push_back(a);
        f[a]++;
    }
    // for (auto& elm : f) {
    //     cout << elm.first << ": " << elm.second << endl;
    // }
    int target;
    cin >> target;
    bool fnd = false;
    for (auto& elm : f) {
        int curr = elm.first;
        int comp = target - curr;
        if (f.find(comp) != f.end()) {
            if (curr == comp ) {
                cout << "(" << curr << ',' << curr << ") ";
                fnd = true;
            }
            else if (comp > curr) {
                cout << '(' << comp << ',' << curr << ") ";
                fnd = true;
            }
        }
    }
    cout << endl;
    if (!fnd) cout << "No Pairs found\n";

}