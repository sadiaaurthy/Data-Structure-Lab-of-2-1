#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    int n;
    vector<int> bit;
    vector<int> vec;
public:
    FenwickTree(const vector<int>& input) : n((int)input.size() - 1), bit(n + 1, 0), vec(input) {
        for (int i = 1; i <= n; i++) {
            bit[i] += vec[i];
            int par = i + (i & -i);
            if (par <= n) {
                bit[par] += bit[i];
            }
        }
    }

    void addUpdate(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }

    int prefixSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    int rangeSum(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }

    void pointUpdate(int idx, int valAdded) {
        vec[idx] += valAdded;
        addUpdate(idx, valAdded);
    }

    void PrintTree(){
        for (int i = 1; i <= n; i++) {
            cout << i << ":" << bit[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    FenwickTree ft(vec);

    cout << "Status of Fenwick Tree (idx: value):\n";
    ft.PrintTree();
    cout << endl;

    int t;
    cin >> t;

    while (t--) {
        int type;
        cin >> type;

        if (type == 1) {
            int left, right;
            cin >> left >> right;
            cout << "Query: Sum = " << ft.rangeSum(left, right) << " \n";
        } else if (type == 2) {
            int index, newValue;
            cin >> index >> newValue;
            ft.pointUpdate(index, newValue);

            cout << "Updated tree:\n";
            ft.PrintTree();
        }
    }

    return 0;
}