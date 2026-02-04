#include <iostream>
#include <vector>
using namespace std;
class Hash {
    vector<int> v;
    int choice, tableSize, query, cnt = 0;
public:
    Hash(int c, int n, int q) : choice(c), tableSize(n), query(q) {
        v.resize(tableSize, -1);
    }
    int hash1(int x) {
        return x % tableSize;
    }
    int hash2(int x) {
        return 7 - (x % 7);
    }
    int f(int i, int x) {
        if (choice == 1) return i;
        else if (choice == 2) return i*i;
        else if (choice == 3) return i*hash2(x);
        return 0;
    }
    double Load_factor() {
        return static_cast<double>(cnt) /tableSize;
    }
    void insert(int x) {
        for (int i = 0; i < 6; i++) {
            int idx = (x + f(i, x)) % tableSize;
            if (v[idx] == -1) {
                v[idx] = x;
                cnt++;
                cout << "Inserted : Index- " << idx << "(L.F = " << Load_factor() << " )\n";
                return;
            } else {
                cout << "Collision : Index- " << idx << endl;
            }
        }
        cout << "Input Abandoned\n";
    }
};
int main() {
    int c, size, q;
    cin >> c >> size >> q;
    Hash hashTable(c, size, q);
    for (int i = 0; i < q; i++) {
        int key;
        cin >> key;
        hashTable.insert(key);
    }
}