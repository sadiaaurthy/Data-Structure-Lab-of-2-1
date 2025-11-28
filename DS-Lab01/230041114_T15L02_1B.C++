#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Stack {
private:
    vector<int> v;
    int maxSize;
public: 
    Stack(int size) {
        maxSize = size;
    }
    void push(int num) {
        v.push_back(num);
    }
    void pop() {
        v.pop_back();
    }
    bool isEmpty() {
        return v.size() == 0;
    }
    bool isFull() {
        return v.size() == maxSize;
    }
    void print() {
        for (auto& elm : v) {
            cout << elm << " ";
        }
        cout << endl;
    }
    int size() {
        return v.size();
    }
    int top() {
        if (v.size() > 0) return v[v.size() - 1];
        else return 0;
    }
};
int main() {
    int size;
    cin >> size;
    Stack s(size);
    
    while (true) {
        char ch;
        cin >> ch;
        if (ch == '/') break;
        if (ch == '-') {
            s.pop();
            cout << "Size : " << s.size() << endl;
            cout << "Stack elements : " ;
            s.print() ;
            cout << "Top Element : " << s.top() << endl;
            cout << "isFull : " ;
            if (s.isFull()) cout << "True" << endl;
            else cout << "False" << endl;
            cout << "isEmpty : " ;
            if(s.isEmpty()) cout << "True" << endl;
            else cout << "False" << endl;
            continue;
        }
        int num;
        cin >> num;
        if (ch == '+' && !s.isFull()) {
            s.push(num);
            cout << "Size : " << s.size() << endl;
            cout << "Stack elements : " ;
            s.print() ;
            cout << "Top Element : " << s.top() << endl;
            cout << "isFull : " ;
            if (s.isFull()) cout << "True" << endl;
            else cout << "False" << endl;
            cout << "isEmpty : " ;
            if(s.isEmpty()) cout << "True" << endl;
            else cout << "False" << endl;
        }
        if (ch == '+' && s.isFull()) {
            cout << "Overflow !!!" << endl;
            cout << "Size : " << s.size() << endl;
            cout << "Stack elements : " ;
            s.print() ;
            cout << "Top Element : " << s.top() << endl;
            cout << "isFull : " ;
            if (s.isFull()) cout << "True" << endl;
            else cout << "False" << endl;
            cout << "isEmpty : " ;
            if(s.isEmpty()) cout << "True" << endl;
            else cout << "False" << endl;
        }
        
    }

}