#include <iostream>
#include <vector>
using namespace std;
class Stack {
private: 
     vector<int> V;
     int maxSize; 
public:
    Stack(int size) {
        maxSize = size;
    }
    void push(int val) {
        V.push_back(val);
    }
    void pop() {
        V.pop_back();
    }
    bool isEmpty() {
        return V.size() == 0;
    }
    bool isFull() {
        return V.size() == maxSize;
    }
    void printStack() {
        if (isEmpty()) return;
        for (int i = 0; i < V.size(); i++) {
            cout << V[i] << " ";
        }
        cout << endl;
    }
    int size() {
        return V.size();
    }
    int top() {
        return V[V.size() - 1];
    }
};
int main() {
    int n;
    cin >> n;
    Stack s(n);
    
    while (true) {
        int id;
        cin >> id;
        if (id == -1) break;
        if (id == 1) {
            int num;
            cin >> num;
            if (!s.isFull()) {
                s.push(num);
                s.printStack();
            } else cout << "Overflow" << endl;
        }
        else if (id == 2) {
            if (s.isEmpty()) cout << "Underflow" << endl;
            else {
                s.pop();
                s.printStack();
            }
        }
        else if (id == 3) {
            if (s.isEmpty()) {
                cout << "true" << endl;
            } else cout << "false" <<endl;
        }
        else if (id == 4) {
             if (s.isFull()) {
                cout << "true" << endl;
            } else cout << "false" <<endl;
        }
        else if (id == 5) {
            cout << s.size() << endl;
        }
        else cout << s.top() << endl;
    }

}