#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int len, cnt = 0;
        cin >> len;
        string str;
        cin >> str;
        stack<char> s;
        for (int i = 0; str[i] != '\0'; i++) {
            if (!s.empty() && ((s.top() == '(' && str[i] == ')') || 
                (s.top() == '{' && str[i] == '}') || 
                (s.top() == '[' && str[i] == ']'))) {
                s.pop();
                cnt += 2;
            } else s.push(str[i]);
        }
        cout << (len - cnt) / 2 << endl;
    }
}