#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> vec;
    int n;

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

        tree[node] = tree[lc] + tree[rc];
    }

    void update(int node, int left, int right, int idx, int val) {
        if (left == right) {
            tree[node] = val;
            vec[idx] = val;
            return;
        }

        int mid = (left + right) / 2;
        int lc = node * 2;
        int rc = lc + 1;

        if (idx <= mid) update(lc, left, mid, idx, val);
        else update(rc, mid + 1, right, idx, val);

        tree[node] = tree[lc] + tree[rc];
    }

    int sumQuery(int node, int left, int right, int i, int j) {
        if (j < left || right < i) return 0;
        if (i <= left && right <= j) return tree[node];

        int mid = (left + right) / 2;
        int lc = node * 2;
        int rc = lc + 1;

        return sumQuery(lc, left, mid, i, j) + sumQuery(rc, mid + 1, right, i, j);
    }

public:
    SegmentTree(vector<int>& input) {
        vec = input;
        n = input.size();
        tree = vector<int>(4 * n + 5, 0);
        if (n > 0) buildSegTree(1, 0, n - 1);
    }

    int getValue(int idx) {
        return vec[idx];
    }

    void setValue(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int rangeSum(int i, int j) {
        return sumQuery(1, 0, n - 1, i, j);
    }

    void Print() {
        for (int i = 0; i < n; i++) {
            cout << vec[i] << " ";
        }
    }
};

int main() {

    int N, Q;
    cin >> N >> Q;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    SegmentTree st(v);

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int i;
            cin >> i;
            i--;

            int money = st.getValue(i);
            st.setValue(i, 0);

            cout << money << " (";
            st.Print();
            cout << ")\n";
        }
        else if (type == 2) {
            int i, v;
            cin >> i >> v;
            i--;

            int cur = st.getValue(i);
            st.setValue(i, cur + v);

            st.Print();
            cout << endl;
        }
        else if (type == 3) {
            int i, j;
            cin >> i >> j;
            i--;
            j--;
            cout << st.rangeSum(i, j) << '\n';
        }
    }

    return 0;
}