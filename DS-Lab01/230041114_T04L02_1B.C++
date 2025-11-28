#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int num;
    vector<int> v;
    stack<int> s;
    while (cin >> num) {
        if (num == -1) break;
        v.push_back(num);
    }
    vector<int> ans(v.size());
    for (int i = v.size() - 1; i >= 0; i--) {
        while (s.size() != 0 && s.top() <= v[i]) {
            s.pop();
        }
        if (s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(v[i]);
    }
    for (auto& elm : ans) {
        cout << elm << " ";
    }
}