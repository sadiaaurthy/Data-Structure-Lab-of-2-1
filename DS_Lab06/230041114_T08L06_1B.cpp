#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* par;
    int height;
};
Node* root = nullptr;
Node* CreateNode(int x) {
    Node* newNode = new Node ();
    newNode->data = x;
    newNode->left = newNode->right = newNode->par = nullptr;
    newNode->height = 0;
    return newNode;
}
void updateHeight(Node* n) {
    if (n == nullptr) return;
    int leftHeight = (n->left == nullptr) ? -1 : n->left->height;
    int rightHeight = (n->right == nullptr) ? -1 : n->right->height;
    n->height = max(leftHeight, rightHeight) + 1;
}
void insert(int x) {
    Node* newNode = CreateNode(x);
    if (root == nullptr) {
        root = newNode;
    } else {
        Node* temp = root;
        Node* tar = nullptr;
        while (temp != nullptr) {
            tar = temp;
            if (x < temp->data) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        newNode->par = tar;
        if (x < tar->data) {
            tar->left = newNode;
        } else {
            tar->right = newNode;
        }
        while (newNode->par != nullptr) {
            newNode = newNode->par;
            updateHeight(newNode);
        }
    }
}
void printLeavesInorder(Node* n, bool &first) {
    if (n == nullptr) return;

    printLeavesInorder(n->left, first);

    if (n->left == nullptr && n->right == nullptr) {
        if (!first) cout << ", ";
        cout << n->data;
        first = false;
    }

    printLeavesInorder(n->right, first);
}
void print_leaf_nodes() {
    cout << "Leaf nodes:\n";
    bool first = true;
    printLeavesInorder(root, first);
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    root = nullptr;              
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        insert(x);
    }

    print_leaf_nodes();
    return 0;
}
