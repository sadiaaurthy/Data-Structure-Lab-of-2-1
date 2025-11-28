#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class QueueUsingStacks {
    stack<int> s1, s2;
    int maxSize;

public:
    QueueUsingStacks(int n) { 
        maxSize = n; 
    }

    int getSize() {
        return s1.size() + s2.size();
    }

    bool isFull() {
        return getSize() == maxSize;
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Size:" << getSize() << " Elements: Overflow!" << endl;
            return;
        }
        s1.push(x);
        printQueue();
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Size:0 Elements: Null" << endl;
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
        printQueue();
    }

    void printQueue() {
        int size = getSize();
        cout << "Size:" << size << " Elements: ";

        if (size == 0) {
            cout << "Null" << endl;
            return;
        }

        vector<int> temp;

        stack<int> s2copy = s2;
        vector<int> v1;
        while (!s2copy.empty()) {
            v1.push_back(s2copy.top());
            s2copy.pop();
        }
        
        for (int x : v1) temp.push_back(x);

        stack<int> s1copy = s1;
        vector<int> v2;
        while (!s1copy.empty()) {
            v2.push_back(s1copy.top());
            s1copy.pop();
        }
        
        reverse(v2.begin(), v2.end());
        for (int x : v2) temp.push_back(x);

        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int N, q;
    cin >> N >> q;

    QueueUsingStacks qu(N);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            qu.enqueue(x);
        }
        else if (type == 2) {
            qu.dequeue();
        }
    }
    return 0;
}