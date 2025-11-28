#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int main() {
    int N;
    cin >> N;
    cin.ignore();
    
    while (N--) {
        string str;
        getline(cin, str);
        stack<char> s;
        for (auto& ch : str) {
            s.push(ch);
        }
        while(!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << endl;
    }
    return 0;
}