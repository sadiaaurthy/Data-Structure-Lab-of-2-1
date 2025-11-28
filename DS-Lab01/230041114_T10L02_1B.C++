#include <iostream>
#include <stack>
using namespace std;
int main() {
    int truck;
    cin >> truck;
    stack<int> s;
    int nxt = 1;
    for (int i = 0; i < truck; i++) {
        int lm;
        cin >> lm;
        s.push(lm);
        while (!s.empty() && s.top() == nxt) {
            s.pop();
            nxt++;
        }
    }
    if (s.empty()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}