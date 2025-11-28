#include <iostream>
using namespace std;

#define MAXN 1000  

class Deque {
private:
    int arr[MAXN];
    int front;
    int rear;
    int count;

public:
    Deque() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == MAXN;
    }

    bool isEmpty() {
        return count == 0;
    }

    void push_front(int key) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }
        front = (front - 1 + MAXN) % MAXN;  
        arr[front] = key;
        count++;
    }

    void push_back(int key) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }
        rear = (rear + 1) % MAXN;  
        arr[rear] = key;
        count++;
    }

    void pop_front() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        front = (front + 1) % MAXN;
        count--;
    }

    void pop_back() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        rear = (rear - 1 + MAXN) % MAXN;
        count--;
    }

    int size() {
        return count;
    }

    void print() {
        if (isEmpty()) {
            cout << "\n";
            return;
        }
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << arr[i];
            if (c != count - 1) cout << " ";
            i = (i + 1) % MAXN;
        }
        cout << "\n";
    }
};

int main() {
    Deque dq;
    int option;

    while (true) {
        cin >> option;

        if (option == 6) break;

        if (option == 1) {
            int x;
            cin >> x;
            dq.push_front(x);
            dq.print();
        }
        else if (option == 2) {
            int x;
            cin >> x;
            dq.push_back(x);
            dq.print();
        }
        else if (option == 3) {
            dq.pop_front();
            dq.print();
        }
        else if (option == 4) {
            dq.pop_back();
            dq.print();
        }
        else if (option == 5) {
            cout << dq.size() << "\n";
        }
    }

    return 0;
}