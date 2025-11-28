#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Stack {
private: 
    vector<char> V;
    int maxSize;
public:
    Stack(int len){
       maxSize = len;
    }
    bool isEmpty() {
        return V.size() == 0;
    }
    char top() {
        if (!isEmpty()) return V[V.size() - 1];
        else return '\0';
    }
    void push(char val) {
        V.push_back(val);
    }
    void pop() {
        V.pop_back();
    }
    int size() {
        return V.size();
    }
};
int main() {
    int line, flag = 0;
    cin >> line;
    while (line--) {
        string str;
        cin >> str;
        Stack s(str.length());
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                s.push(str[i]);
            } 
            if (s.top() == '\0') {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
            if ((s.top() == '(' && str[i] == ')') || 
                (s.top() == '{' && str[i] == '}') || 
                (s.top() == '[' && str[i] == ']')) {
                if (!s.isEmpty()) {
                    s.pop();
                }
                else break;
            }
             
        }
        if (flag) continue;
        if (s.size()) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

}