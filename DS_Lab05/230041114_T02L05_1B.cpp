#include <iostream>
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

void insert_front(int key) {
    Node* newNode = CreateNode(key);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
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

void insert_after_node(int key, int v) {
    Node* temp = head;
    while (temp != nullptr && temp->data != v) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value not found\n";
        return;
    }

    Node* newNode = CreateNode(key);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    } else {
        tail = newNode;
    }

    temp->next = newNode;
}

void update_node(int key, int v) {
    Node* temp = head;
    while (temp != nullptr && temp->data != v) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        temp->data = key;
    } else {
        cout << "Value not found\n";
    }
}

void remove_head() {
    if (isEmpty()) {
        cout << "Underflow\n";
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
}

void remove_end() {
    if (isEmpty()) {
        cout << "Underflow\n";
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

void remove_element(int key) {
    if (isEmpty()) {
        cout << "Value Not Found\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value Not Found\n";
        return;
    }

    if (temp == head) {
        remove_head();
        return;
    }

    if (temp == tail) {
        remove_end();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void printlist() {
    if (isEmpty()) {
        cout << "Head=Null, Tail=Null, " << endl;
        cout << "Head2Tail: Empty" << endl;
        cout << "Tail2Head: Empty" << endl;
        return;
    }

    cout << "Head=" << head->data << ", Tail=" << tail->data << ", " << endl;

    cout << "Head2Tail: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Tail2Head: ";
    temp = tail;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->prev != nullptr) cout << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    int a;
    while (true) {
        cin >> a;
        switch (a) {
            case 1: {
                int b;
                cin >> b;
                insert_front(b);
                printlist();
                break;
            }
            case 2: {
                int b;
                cin >> b;
                insert_back(b);
                printlist();
                break;
            }
            case 3: {
                int b, val;
                cin >> b >> val;
                insert_after_node(b, val);
                printlist();
                break;
            }
            case 4: {
                int b, val;
                cin >> b >> val;
                update_node(b, val);
                printlist();
                break;
            }
            case 5: {
                remove_head();
                printlist();
                break;
            }
            case 6: {
                int b;
                cin >> b;
                remove_element(b);
                printlist();
                break;
            }
            case 7: {
                remove_end();
                printlist();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                
                cout << "Invalid input\n";
                break;
            }
        }
    }
}
