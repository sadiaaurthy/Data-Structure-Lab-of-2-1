#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    Node* head;  
    Node* tail;   
    int cap;
    int cnt;

public:
    Stack(int capacity) {
        head = tail = nullptr;
        cap = capacity;
        cnt = 0;
    }
    Node* CreateNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    }
    bool isEmpty() {
        return cnt == 0; 
    }
    bool isFull() {
        return cnt == cap;
    }  
    int size() {  
        return cnt; 
    }

    void printStack() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Overflow" << endl;
            return;
        }
        Node* newNode = CreateNode(x);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cnt++;
        printStack();
    }

    void pop() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        cnt--;

        printStack();
    }

    void topValue() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }
        cout << tail->data << endl;
    }
};

int main() {
    int N;
    cin >> N;

    Stack s(N);

    int id;
    while (cin >> id) {
        if (id == -1) break;

        if (id == 1) {
            int x;
            cin >> x;
            s.push(x);
        } 
        else if (id == 2) {
            s.pop();
        } 
        else if (id == 3) {
            if (s.isEmpty()) cout << "True" << endl;
            else cout << "False" << endl; 
        } 
        else if (id == 4) {
            if (s.isFull()) cout << "True" << endl;
            else cout << "False" << endl; 
        } 
        else if (id == 5) {
            cout << s.size() << endl;
        } 
        else if (id == 6) {
            s.topValue();
        }
    }

    return 0;
}
