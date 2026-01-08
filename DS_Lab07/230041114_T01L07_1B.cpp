#include <iostream>
#include <algorithm>
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

int height(Node* n) {
    return (n == nullptr) ? -1 : n->height;
}

void updateHeight(Node* n) {
    if (n == nullptr) return;
    int leftHeight = (n->left == nullptr) ? -1 : n->left->height;
    int rightHeight = (n->right == nullptr) ? -1 : n->right->height;
    n->height = max(leftHeight, rightHeight) + 1;
}

int balance_factor(Node* n) {
    if (n == nullptr) return 0; 
    return height(n->left) - height(n->right);
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
        if (x < temp->data) temp = temp->left;
        else temp = temp->right; // duplicates go right
    }

    newNode->par = tar;
    if (x < tar->data) tar->left = newNode;
    else tar->right = newNode;


    while (newNode->par != nullptr) {
        newNode = newNode->par;
        updateHeight(newNode);
    }
}

void inorderBF(Node* n) {
    if (n == nullptr) return;

    inorderBF(n->left);

    // first = false;
    cout << n->data << "(" << balance_factor(n) << ") " ;

    inorderBF(n->right);
}

void print_tree() {
    inorderBF(root);
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while (cin >> x && x != -1) {
        insert(x);
        print_tree(); 
    }
    return 0;
}
