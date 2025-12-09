#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void max_heapify(vector<int> &v, int par) {
    int lc = 2 * par + 1;
    int rc = 2 * par + 2;
    int largest = par;

    if (lc < v.size() && v[lc] > v[largest]) {
        largest = lc;
    }
    if (rc < v.size() && v[rc] > v[largest]) {
        largest = rc;
    }
    if (largest != par) {
        swap(v[largest], v[par]);
        max_heapify(v, largest);
    }
}

void build_max_heap(vector<int> &v) {
    for (int i = (v.size() - 1) / 2; i >= 0; i--) { 
        max_heapify(v, i);
    }
}

int Heap_max(const vector<int> &v) {
    return v[0];
}

int Heap_extract_max(vector<int> &v) {
    if (v.size() < 1) {
        cout << "Underflow" << endl;
        return -1;
    }
    int Max = v[0];
    v[0] = v[v.size() - 1];
    v.pop_back();
    max_heapify(v, 0);
    return Max;
    
}

void max_heap_insert(vector<int> &v, int k) {
    v.push_back(k);
    int child = v.size() - 1;
    int par = (child - 1) / 2;

    while (child > 0 && v[par] < v[child]) {
        swap(v[child], v[par]);
        child = par;
        par = (child - 1) / 2;
    }
}

void Heap_increase_key(vector<int> &v, int k, int idx) {
    v[idx] += k;
    max_heapify(v, idx);
}

void Heap_decrease_key(vector<int> &v, int k, int idx) {
    v[idx] -= k;
    int child = idx;
    int par = (child - 1) / 2;
    while (child > 0 && v[par] < v[child]) {
        swap(v[par], v[child]);
        child = par;
        par = (child - 1) / 2;
    }
}

void Print(const vector<int> &v) {
    for (auto& elm : v) {
        cout << elm << " ";
    }
    cout << endl;
}

int main() {
    int num, func_id, key, idx;
    vector<int> v;

    while (true) {
        cin >> num;
        if (num == -1) break;
        v.push_back(num);
    }

    build_max_heap(v);
    cout << "Max heap: ";
    Print(v);

    while (true) {
        cin >> func_id;

        if (func_id == -1) break;

        switch(func_id) {
            case 1: {  
                cout << Heap_max(v) << endl;
                Print(v);
                break;
            }
            case 2: { 
                int heapSize = v.size();
                cout << "Extracted max: " << Heap_extract_max(v) << endl;
                Print(v);
                break;
            }
            case 3: { 
                cin >> key;
                max_heap_insert(v, key);
                Print(v);
                break;
            }
            case 4: { 
                cin >> key >> idx;
                Heap_decrease_key(v, key, idx - 1);
                Print(v);
                break;
            }
            default: { 
                cin >> key >> idx;
                Heap_increase_key(v, key, idx - 1);
                Print(v);
                break;
            }
        }
    }
    return 0;
}