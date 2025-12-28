#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node* left, *right, *parent;
    int height;
    Node (int val) {
        data = val;
        left = right = parent = nullptr;
        height = 0;
    }
};
class BST {
    private: 
    Node* root;
    int height(Node* node) {
        if (node == nullptr) return -1;
        return node->height;
    }
    int balance_factor(Node* node) {
        return height(node->left) - height(node->right);
    }
    void update_height(Node* node) {
        while (node != nullptr) {
            node->height = 1 + max(height(node->left), height(node->right));
            node = node->parent;
        }
    }
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << "(" << balance_factor(node) << ")";
        inorder(node->right);
    }
    public: 
        BST() {
            root = nullptr;
        }
        void insertion(int key) {
            if (root == nullptr) {
                root = new Node(key);
                return;
            }
            Node* curr = root;
            Node* parent = nullptr;
            while (curr != nullptr) {
                parent = curr;
                if (key < curr->data) curr = curr->left;
                else curr = curr->right;
            }
            Node* newNode = new Node(key);
            newNode->parent = parent;
            if (key < parent->data) parent->left = newNode;
            else parent->right = newNode;
            update_height(parent);
        }
        void Print() {
            inorder(root);
            cout << endl;
        }
};

int main() {
    BST bst;
    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        bst.insertion(x);
        bst.Print();
    }
    return 0;
}