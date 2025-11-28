#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int main() {
    int N;
    cin >> N;
    cin.ignore();
    stack<char> s;
    vector<char> v;
    while (N--) {
        string str;
        getline(cin, str);
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[' || 
                str[i] == ')' || str[i] == '}' || str[i] == ']') 
                v.push_back(str[i]);
        }

    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == '(' || v[i] == '{' || v[i] == '[') s.push(v[i]);
        else if (s.top() == '(' &&  v[i] == ')' || 
                 s.top() == '{' &&  v[i] == '}' || 
                 s.top() == '[' &&  v[i] == ']') {
                    if (!s.empty()) s.pop();
                    else break;
        }
    }
    if (s.size()) cout << "Error" << endl;
    else cout << "No errors" << endl;
    return 0;
}