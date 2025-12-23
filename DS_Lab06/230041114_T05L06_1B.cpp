#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* CreateNode(int elm) {
    Node* temp = new Node;
    temp->data = elm;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}
class BST {
private:
    Node* root;
    int nodes;
    Node* insert(Node* node, int elm) {
        if (node == nullptr) {
            return CreateNode(elm);
        }
        if (elm < node->data) {
            node->left = insert(node->left, elm);
        } else if (elm > node->data) {
            node->right = insert(node->right, elm);
        }
        return node;
    }
    void findKthSmallest(Node* node, int k, int& cnt, int& res) {
        if (node == nullptr || cnt >= k) return;
        findKthSmallest(node->left, k, cnt, res);
        cnt++;
        if (cnt == k) {
            res = node->data;
            return;
        }
        findKthSmallest(node->right, k, cnt, res);
    }
public:
    BST() {
        root = nullptr;
        nodes = 0;
    }
    void insert(int elm) {
        root = insert(root, elm);
        nodes++;
    }
    int getKthSmallest(int k) {
        if (k > nodes || k <= 0) return -1;
        int cnt = 0, res = -1;
        findKthSmallest(root, k, cnt, res);
        return res;
    }
    int getSize() {
        return nodes;
    }
};

int main() {
    int n;
    cin >> n;
    BST bst;
    for (int i = 0; i < n; i++) {
        int elm;
        cin >> elm;
        bst.insert(elm);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        if (k > bst.getSize() || k <= 0)
            cout << "Invalid" << endl;
        else
            cout << bst.getKthSmallest(k) << endl;
    }
    return 0;
}
