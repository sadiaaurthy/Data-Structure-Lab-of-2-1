#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    int n;
    int treeSize;
    vector<int> tree;
    vector<int> lazy;
    vector<int> vec;

    int Min(int a, int b) {
        return (a < b ? a : b);
    }

    void buildSegTree(int node, int left, int right) {
        if (left == right) {
            tree[node] = vec[left];
            return;
        }

        int mid = (left + right) / 2;
        int lc = node * 2;
        int rc = lc + 1;

        buildSegTree(lc, left, mid);
        buildSegTree(rc, mid + 1, right);

        tree[node] = Min(tree[lc], tree[rc]);
    }

    void push(int node, int left, int right) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];

            if (left != right) {
                int lc = node * 2;
                int rc = lc + 1;
                lazy[lc] += lazy[node];
                lazy[rc] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    void updateRange(int node, int left, int right, int i, int j, int val) {
        push(node, left, right);

        if (right < i || left > j) return;

        if (i <= left && right <= j) {
            lazy[node] += val;
            push(node, left, right);
            return;
        }

        int mid = (left + right) / 2;
        int lc = node * 2;
        int rc = lc + 1;

        updateRange(lc, left, mid, i, j, val);
        updateRange(rc, mid + 1, right, i, j, val);

        tree[node] = Min(tree[lc], tree[rc]);
    }

    int RangeMinQuery(int node, int left, int right, int i, int j) {
        push(node, left, right);

        if (right < i || left > j) return -1;

        if (i <= left && right <= j) {
            return tree[node];
        }

        int mid = (left + right) / 2;
        int lc = node * 2;
        int rc = lc + 1;

        int minL = RangeMinQuery(lc, left, mid, i, j);
        int minR = RangeMinQuery(rc, mid + 1, right, i, j);

        return Min(minL, minR);
    }

    int TreeSize(int n) {
        int x = 1;
        while (x < n) x *= 2;
        return 2 * x;
    }

public:
    SegmentTree(const vector<int>& input) {
        n = input.size() - 1;
        vec = input;
        treeSize = TreeSize(n);

        tree = vector<int>(treeSize);
        lazy = vector<int>(treeSize);

        buildSegTree(1, 1, n);
    }

    void update(int i, int j, int val) {
        updateRange(1, 1, n, i, j, val);
    }

    int Query(int i, int j) {
        return RangeMinQuery(1, 1, n, i, j);
    }

    void printTree() {
        int last = 2 * n - 1;
        for (int i = 1; i <= last; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    void printLazy() {
        int last = 2 * n - 1;
        for (int i = 1; i <= last; i++) {
            cout << lazy[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> vec(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> vec[i];
    }

    SegmentTree st(vec);

    st.printTree();
    st.printLazy();
    cout << endl;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 2) {
            int i, j, x;
            cin >> i >> j >> x;
            st.update(i, j, x);
            st.printTree();
            st.printLazy();
            cout << endl;
        } else if (type == 1) {
            int i, j;
            cin >> i >> j;
            cout << st.Query(i, j) << '\n';
            st.printTree();
            st.printLazy();
            cout << endl;
        }
    }

}
