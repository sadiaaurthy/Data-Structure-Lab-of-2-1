#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void min_heapify(int par, vector<int> &v, int heapSize) {
    int lc = 2*par + 1;
    int rc = 2*par + 2, smallest = par;
    if (lc < heapSize && v[lc] < v[smallest]) {
        smallest = lc;
    } 
    if (rc < heapSize && v[rc] < v[smallest]) {
        smallest = rc;
    }
    if (smallest != par) {
        swap(v[smallest], v[par]);
        min_heapify(smallest, v, heapSize);
    }
}
void build_min_heap(vector<int> &v, int heapSize) {
    for (int i = (heapSize/2) - 1; i >= 0; i--) {
        min_heapify(i, v, heapSize);
    }
}
void heapSort(vector<int> &v, int heapSize) {
    build_min_heap(v, heapSize) ;
    for (int i = heapSize - 1; i >= 1; i--) {
        swap(v[i], v[0]);
        min_heapify(0, v, i);
    }
    reverse(v.begin(), v.end());
}
void Print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> v;
    int num;
    while (true) {
        cin >> num;
        if (num == -1) break;
        v.push_back(num);
    }
    build_min_heap(v, v.size());
    cout << "Min Heap: ";
    Print(v);
    heapSort(v, v.size());
    cout << "Sorted: ";
    Print(v);
}
