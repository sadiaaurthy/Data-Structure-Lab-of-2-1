#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front_idx;
    int rear_idx;
    int capacity;
    int count;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front_idx = 0;
        rear_idx = -1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "EnQueue: Overflow" << endl;
            return;
        }
        rear_idx = (rear_idx + 1) % capacity;
        arr[rear_idx] = value;
        count++;
        display();
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "DeQueue: Underflow" << endl;
            return;
        }
        front_idx = (front_idx + 1) % capacity;
        count--;
        display();
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    int size() {
        return count;
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front_idx];
    }

    void display() {
        if (isEmpty()) {
            return;
        }
        cout << "EnQueue: ";
        int idx = front_idx;
        for (int i = 0; i < count; i++) {
            cout << arr[idx];
            if (i < count - 1) cout << " ";
            idx = (idx + 1) % capacity;
        }
        cout << endl;
    }

    void displayDequeue() {
        if (isEmpty()) {
            cout << "DeQueue: ";
            return;
        }
        cout << "DeQueue: ";
        int idx = front_idx;
        for (int i = 0; i < count; i++) {
            cout << arr[idx];
            if (i < count - 1) cout << " ";
            idx = (idx + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    CircularQueue cq(n);

    int operation, value;
    while (true) {
        cin >> operation;
        
        if (operation == -1) {
            cout << "Exit" << endl;
            break;
        }

        switch (operation) {
            case 1:
                cin >> value;
                cq.enqueue(value);
                break;
            
            case 2: 
                cq.dequeue();
                break;
            
            case 3: 
                if (cq.isEmpty()) {
                    cout << "isEmpty: True" << endl;
                } else {
                    cout << "isEmpty: False" << endl;
                }
                break;
            
            case 4: 
                if (cq.isFull()) {
                    cout << "isFull: True" << endl;
                } else {
                    cout << "isFull: False" << endl;
                }
                break;
            
            case 5: 
                cout << "Size: " << cq.size() << endl;
                break;
            
            case 6:
                cout << "Front: " << cq.front() << endl;
                break;
        }
    }

    return 0;
}
