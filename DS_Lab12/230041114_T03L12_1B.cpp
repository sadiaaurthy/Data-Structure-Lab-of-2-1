#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        tree.resize(n + 1, 0);  
    }

    void update(int idx, int value) {
        while (idx <= n) {
            tree[idx] += value;
            idx += (idx & -idx);
        }
    }

    int getSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);  
        }
        return sum;
    }

    int rangeSum(int L, int R) {
        return getSum(R) - getSum(L - 1);
    }

    void printTree() {
        cout << "Status of Fenwick Tree (idx : value):" << endl;
        for (int i = 1; i <= n; i++) {
            cout << i << ":" << tree[i];
            if (i < n) {
                cout << " ";  
            }
        }
        cout << endl;
    }
};

int main() {
    int N;  
    cin >> N;

    vector<int> arr(N + 1);
    FenwickTree fenwickTree(N);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        fenwickTree.update(i, arr[i]); 
    }

    cout << "Ranges to be stored in the Fenwick Table:" << endl;
    for (int i = 1; i <= N; i++) {
        cout << i << ":(" << i << "," << i << ")" << " ";
    }
    cout << endl;

    fenwickTree.printTree();

    int Q;  
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        
        int sum = fenwickTree.rangeSum(L, R);  
        
        
        cout << "Query-" << q + 1 << ": Sum=" << sum;
        cout << " [Tree idx: sum(" << L << "," << R << ") - sum(" << L - 1 << ")]" << endl;
    }

    return 0;
}