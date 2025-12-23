#include <iostream>
#include <vector>
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
    void LeafNodesFinder(Node* node, vector<int>& leaves) {
        if (node == nullptr) return;
        LeafNodesFinder(node->left, leaves);
        if (node->left == nullptr && node->right == nullptr) {
            leaves.push_back(node->data);
        }
        LeafNodesFinder(node->right, leaves);
    }
public:
    BST() {
        root = nullptr;
    }
    void insert(int elm) {
        root = insert(root, elm);
    }
    vector<int> getLeafNodes() {
        vector<int> leaves;
        LeafNodesFinder(root, leaves);
        return leaves;
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
    vector<int> leafNodes = bst.getLeafNodes();
    cout << "Leaf nodes:" << endl;
    for (int i = 0; i < leafNodes.size(); i++) {
        if (i != 0) cout << ", ";
        cout << leafNodes[i];
    }
    cout << endl;

    return 0;
}
