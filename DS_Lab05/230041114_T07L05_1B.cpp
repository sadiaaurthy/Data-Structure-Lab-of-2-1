#include <iostream>
using namespace std;

class Queue {
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

    Node* CreateNode(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

public:
    Queue(int capacity) {
        head = tail = nullptr;
        cap = capacity;
        cnt = 0;
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

    void printQueueOnly() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "EnQueue: Overflow" << endl;
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

        cout << "EnQueue: ";
        printQueueOnly();
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "DeQueue: Underflow" << endl;
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        cnt--;

        cout << "DeQueue: ";
        if (isEmpty()) cout << endl;
        else printQueueOnly();
    }

    void frontValue() {
        if (isEmpty()) {
            cout << "Front: Underflow" << endl;
            return;
        }
        cout << "Front: " << head->data << endl;
    }
};

int main() {
    int N;
    cin >> N;

    Queue q(N);

    int id;
    while (cin >> id) {
        if (id == -1) {
            cout << "Exit" << endl;
            break;
        }

        if (id == 1) {
            int x; cin >> x;
            q.enqueue(x);
        } 
        else if (id == 2) {
            q.dequeue();
        } 
        else if (id == 3) {
            if (q.isEmpty())
                cout << "isEmpty: True" << endl;
            else cout << "isEmpty: False" << endl;
        } 
        else if (id == 4) {
            if (q.isFull())
                cout << "isFull: True" << endl;
            else cout << "isFull: False" << endl;
        } 
        else if (id == 5) {
            cout << "Size: " << q.size() << "\n";
        } 
        else if (id == 6) {
            q.frontValue();
        }
    }

    return 0;
}
