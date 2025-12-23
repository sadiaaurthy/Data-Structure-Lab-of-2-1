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
    int LCA_finder(Node* node, int u, int v) {
        if (node == nullptr) return -1;

        if (u < node->data && v < node->data)
            return LCA_finder(node->left, u, v);

        if (u > node->data && v > node->data)
            return LCA_finder(node->right, u, v);
        return node->data;  
    }
public:
    BST() {
        root = nullptr;
    }
    void insert(int elm) {
        root = insert(root, elm);
    }
    int LCA(int u, int v) {
        return LCA_finder(root, u, v);
    }
};

int main() {
    int n;
    cin >> n;
    BST tree;
    for (int i = 0; i < n; i++) {
        int elm;
        cin >> elm;
        tree.insert(elm);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << tree.LCA(u, v) << endl;
    }
    return 0;
}
