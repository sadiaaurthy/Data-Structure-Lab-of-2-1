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
    Node* newNode = new Node();
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
        return;
    }
    Node* temp = root;
    Node* tar = nullptr;
    while (temp != nullptr) {
        tar = temp;
        if (x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    newNode->par = tar;
    if (x < tar->data)
        tar->left = newNode;
    else
        tar->right = newNode;

    Node* curr = newNode->par;
    while (curr != nullptr) {
        updateHeight(curr);
        curr = curr->par;
    }
}

Node* LCA_finder(Node* root, int u, int v) {
    Node* temp = root;
    while (temp != nullptr) {
        if (u < temp->data && v < temp->data)
            temp = temp->left;
        else if (u > temp->data && v > temp->data)
            temp = temp->right;
        else
            return temp; 
    }
    return nullptr;
}

void findLCA(int u, int v) {
    Node* lca = LCA_finder(root, u, v);
    if (lca != nullptr)
        cout << lca->data << endl;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        insert(x);
    }

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;
        findLCA(u, v);
    }
    return 0;
}

