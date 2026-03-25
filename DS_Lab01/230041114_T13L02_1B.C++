#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
    int cnt = 0;
    string str;
    cin >> str;
    stack<char> s;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (!s.empty() && 
                ((str[i] == ')' && s.top() == '(') ||
                 (str[i] == '}' && s.top() == '{') ||
                 (str[i] == ']' && s.top() == '['))) {
                s.pop();
                cnt += 2;  
            } else {
                break;  
            }
        }
    }
    
    cout << cnt << endl;
    return 0;
}