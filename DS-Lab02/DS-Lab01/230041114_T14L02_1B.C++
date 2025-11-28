#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    while (true) {
        int n;
        cin >> n;
        if (!n) break;
        vector<int> left(n);
        vector<int> right(n);
        vector<int> ht(n);
        for (auto& elm : ht) cin >> elm;
        stack<int>s;
        for (int i = n - 1; i >= 0; i--) {
            while (s.size() > 0 && ht[s.top()] >= ht[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = 0; i < n; i++) {
            while (s.size() > 0 && ht[s.top()] >= ht[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = ht[i] * width;
            ans = max(ans, currArea);
        }
        cout << ans << endl;
    }

}