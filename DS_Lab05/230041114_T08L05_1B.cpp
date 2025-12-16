#include <iostream>
#include <string>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

bool isEmpty() {
    return head == nullptr;
}

Node* CreateNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insert_back(int key) {
    Node* newNode = CreateNode(key);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void Print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void Rearrange() {

    if (head == nullptr || head->next == nullptr) return; 

    Node* OddHead = nullptr;
    Node* OddTail = nullptr;
    Node* EvenHead = nullptr;
    Node* EvenTail = nullptr;

    Node* temp = head;
    int idx = 1;

    while (temp != nullptr) {

        Node* nxt = temp->next; 
        temp->prev = nullptr;
        temp->next = nullptr;

        if (idx & 1) {
            if (OddHead == nullptr) {
                OddHead = OddTail = temp;
            } else {
                OddTail->next = temp;
                temp->prev = OddTail;
                OddTail = temp;
            }
        } else {
            if (EvenHead == nullptr) {
                EvenHead = EvenTail = temp;
            } else {
                EvenTail->next = temp;
                temp->prev = EvenTail;
                EvenTail = temp;
            }
        }
        temp = nxt;
        idx++;
    }
    head = OddHead;
    if (EvenHead != nullptr) {
        OddTail->next = EvenHead;
        EvenHead->prev = OddTail;
        tail = EvenTail;
    } else {
        tail = OddTail;
    }
}

int main() {
    string str;
    while (true) {
        cin >> str;
        if (str == "NULL") break;
        insert_back(stoi(str));
    }
    Rearrange();
    Print();
}
