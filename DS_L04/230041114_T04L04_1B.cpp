#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Wizard {
    string name;
    int age;
    string house;
    Wizard(string n, int a, string h) : name(n), age(a), house(h) {}
};
class MaxHeap {
private:
    vector<Wizard> v;
    void build_max_heap(vector<Wizard> &v) {
        for (int i = v.size() / 2; i >= 0; i--) 
            max_heapify(v, i);

    }
    void max_heapify(vector<Wizard> &v, int par) {
        int left = 2 * par + 1;
        int right = 2 * par + 2;
        int largest = par;

        if (left < v.size() && v[left].age > v[largest].age)
            largest = left;
        if (right < v.size() && v[right].age > v[largest].age)
            largest = right;
        if (largest != par) {
            swap(largest, par);
            max_heapify(v, largest);
        }
    }

public:
    void insert(Wizard w) {
        v.push_back(w);
        build_max_heap(v);
    }

    Wizard extract_max() {
        if (v.empty()) {
            throw runtime_error("Heap is empty.");
        }
        Wizard max_wizard = v[0];
        v[0] = v[v.size() - 1];
        v.pop_back();
        max_heapify(v, 0);
        return max_wizard;
    }
    Wizard maximum() {
        if (v.empty()) {
            throw runtime_error("Heap is empty.");
        }
        return v[0];
    }

    bool empty() {
        return v.empty();
    }
};

int main() {
    MaxHeap pq;
    char command;
    while (true) {
        cin >> command;
        if (command == 'I') { 
            string name, house;
            cin.ignore();
            getline(cin, name);
            int age;
            cin >> age >> house;
            pq.insert(Wizard(name, age, house));
        }
        else if (command == 'S') {  
            if (!pq.empty()) {
                Wizard w = pq.extract_max();
                cout << "Name: " << w.name << ", Age: " << w.age << ", House: " << w.house << endl;
            }
        }
        else if (command == 'X') { 
            break;
        }
    }
    return 0;
}
