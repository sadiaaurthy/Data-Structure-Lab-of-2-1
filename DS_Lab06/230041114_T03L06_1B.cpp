#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class BST {
private:
    Node* root;
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        
        return node;
    }
    int findLCA(Node* node, int u, int v) {
        if (node == nullptr) return -1;

        if (u < node->data && v < node->data) {
            return findLCA(node->left, u, v);
        }

        if (u > node->data && v > node->data) {
            return findLCA(node->right, u, v);
        }

        return node->data;
    }
public:
    BST() : root(nullptr) {}
    
    void insert(int val) {
        root = insert(root, val);
    }
    
    int getLCA(int u, int v) {
        return findLCA(root, u, v);
    }
};
int main() {
    int n;
    cin >> n;
    BST tree;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << tree.getLCA(u, v) << endl;
    }
    return 0;
}