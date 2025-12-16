#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class Deque {
private:
    Node* head;
    Node* tail;
    int cnt;

    Node* CreateNode(int key) {
        Node* newNode = new Node();
        newNode->data = key;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    }

public:
    Deque() {
        head = tail = nullptr;
        cnt = 0;
    }
    void push_front(int key) {
        Node* newNode = CreateNode(key);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cnt++;
    }

    void push_back(int key) {
        Node* newNode = CreateNode(key);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cnt++;
    }

    int pop_front() {
        if (cnt == 0) {
            cout << "Underflow" << endl;
            return -1; 
        }

        int val = head->data;
        Node* temp = head;

        if (head == tail) { 
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        cnt--;
        return val;
    }

    int pop_back() {
        if (cnt == 0) {
            cout << "Underflow" << endl;
            return -1;
        }

        int val = tail->data;
        Node* temp = tail;

        if (head == tail) { 
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        cnt--;
        return val;
    }

    int size() {
        return cnt;
    }

    void printDeque() {
        if (cnt == 0) {
            cout << "Empty" << endl; 
            return;
        }
        Node* t = head;
        while (t != nullptr) {
            cout << t->data;
            if (t->next != nullptr) cout << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    int op;

    while (cin >> op) {
        switch (op) {
            case 1: {
                int x; cin >> x;
                dq.push_front(x);
                dq.printDeque();
                break;
            }
            case 2: { 
                int x; cin >> x;
                dq.push_back(x);
                dq.printDeque();
                break;
            }
            case 3: {
                int val = dq.pop_front();
                if (val != -1) dq.printDeque();
                else dq.printDeque();            
                break;
            }
            case 4: { 
                int val = dq.pop_back();
                if (val != -1) dq.printDeque();
                else dq.printDeque();
                break;
            }
            case 5: { 
                cout << dq.size() << endl;
                break;
            }
            case 6: {
                cout << "Exit" << endl;
                return 0;
            }
            default: {
                cout << "Invalid input" << endl;
                break;
            }
        }
    }
    return 0;
}
