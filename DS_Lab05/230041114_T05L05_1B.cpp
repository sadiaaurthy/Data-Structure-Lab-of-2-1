#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class List {
private:
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = nullptr;
    }

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

    Node* getHead() {
        return head;
    }
};

void SetList(List &list) {
    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        list.insert_node(x);
    }
}

int main() {
    List L1, L2, inter;

    SetList(L1);
    SetList(L2);

    Node* fir = L1.getHead();
    Node* sec = L2.getHead();

    while (fir != nullptr && sec != nullptr) {
        if (fir->data == sec->data) {
            inter.insert_node(fir->data);
            int val = fir->data;
            while (fir && fir->data == val) fir = fir->next;
            while (sec && sec->data == val) sec = sec->next;
        }
        else if (fir->data < sec->data) {
            fir = fir->next;
        }
        else {
            sec = sec->next;
        }
    }

    if (inter.isEmpty()) {
        cout << "Empty\n";
    } else {
        inter.Print();
    }

    return 0;
}
