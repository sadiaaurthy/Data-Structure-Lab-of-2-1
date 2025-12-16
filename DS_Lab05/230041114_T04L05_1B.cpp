#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;

bool isEmpty() {
    return head == nullptr;
}

Node* CreateNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insert_node(int val) {
    Node* newNode = CreateNode(val);

    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void remove_end() {
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
}

void Print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int num;
    while (true) {
        cin >> num;
        if (num == -1) break;

        insert_node(num);

        if (tail->prev != nullptr && tail->data == tail->prev->data) {
            remove_end();
        }
    }

    Print();
    return 0;
}
