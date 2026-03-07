#include <iostream>
#include <vector>
using namespace std;

void SegmentTree(int node, int start, int end, vector<int>& vec, vector<int>& tree) {
    if (start == end) {
        tree[node] = vec[start];
        return;
    }

    int mid = (start + end) / 2;
    int lc = node * 2;
    int rc = node * 2 + 1;

    SegmentTree(lc, start, mid, vec, tree);
    SegmentTree(rc, mid + 1, end, vec, tree);

    if (tree[lc] < tree[rc]) {
        tree[node] = tree[lc];
    } else {
        tree[node] = tree[rc];
    }
}

int MinQuery(int node, int start, int end, int l, int r, vector<int>& tree) {
    if (r < start || end < l) {
        return -1;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    int MinL = MinQuery(node * 2, start, mid, l, r, tree);
    int MinR = MinQuery(node * 2 + 1, mid + 1, end, l, r, tree);

    if (MinL < MinR) {
        return MinL;
    } else {
        return MinR;
    }
}

int main() {
    int N, Q;
    while (true) {
        cin >> N >> Q;
        vector<int> vec;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            vec.push_back(x);
        }

        vector<int> tree;
        for (int i = 0; i < 4 * N; i++) {
            tree.push_back(0);
        }

        SegmentTree(1, 0, N - 1, vec, tree);

        for (int i = 0; i < Q; i++) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << MinQuery(1, 0, N - 1, l, r, tree) << endl;
        }
    }
}