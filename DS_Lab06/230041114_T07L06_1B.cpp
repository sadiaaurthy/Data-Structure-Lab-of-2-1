#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* CreateNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}
class BST {
private:
    Node* root;
    int dm;
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
    int CalcHeight(Node* node) {
        if (node == nullptr) return 0;
        int LH = CalcHeight(node->left);
        int RH = CalcHeight(node->right);
        dm = max(dm, LH + RH + 1);
        return max(LH, RH) + 1;
    }
public:
    BST() {
        root = nullptr;
        dm = 0;
    }
    void insert(int elm) {
        root = insert(root, elm);
    }
    int getDia() {
        dm = 0;
        CalcHeight(root);
        return dm;
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
    cout << bst.getDia() << endl;
    return 0;
}
