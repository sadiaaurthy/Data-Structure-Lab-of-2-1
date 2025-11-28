#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    stack<char> s;
    vector<char> v;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!s.empty() && (str[i] == s.top())) {
            s.pop();
        }
        else s.push(str[i]);
    }
    if (!s.size()) {
        cout << "NULL";
        return 0;
    }
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
    } 
    return 0;
}