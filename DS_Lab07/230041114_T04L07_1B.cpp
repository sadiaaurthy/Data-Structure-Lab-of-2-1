#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* par;
    int height;
    int subtree_size; 
    Node(int val) : data(val), left(nullptr), right(nullptr), 
                    par(nullptr), height(1), subtree_size(1) {}
};
Node* root = nullptr;
int height(Node* n) {
   return (!n) ? 0 : n->height;
}
int getSize(Node* n) {
    return (!n) ? 0 : n->subtree_size;
}
void updateNode(Node* n) {
    if (n) {
        n->height = 1 + max(height(n->left), height(n->right));
        n->subtree_size = 1 + getSize(n->left) + getSize(n->right);
    }
}
void updateHeight(Node* n) {
    while (n != nullptr) {
        n->height = 1 + max(height(n->left), height(n->right));
        n->subtree_size = 1 + getSize(n->left) + getSize(n->right);
        n = n->par;
    }
}
int balance_factor(Node* n) {
    return height(n->left) - height(n->right);
}
bool balance_check(Node* n) {
    int bf = balance_factor(n);
    return !(bf > 1 || bf < -1);
}
void right_rotate(Node* z) {
    if (z == nullptr || z->left == nullptr) return;
    
    Node* y = z->left;
    Node* yr = y->right;
    
    if (z == root) {
        root = y;
        y->par = nullptr;
    } else {
        y->par = z->par;
        if (z->par != nullptr) {
            if (z == z->par->right) {
                z->par->right = y;
            } else {
                z->par->left = y;
            }
        }
    }
    
    y->right = z;
    z->par = y;
    z->left = yr;
    if (yr != nullptr) yr->par = z;
    
    updateNode(z);
    updateNode(y);
}

void left_rotate(Node* z) {
    if (z == nullptr || z->right == nullptr) return;
    Node* y = z->right;
    Node* yL = y->left;
    
    if (z == root) {
        root = y;
        y->par = nullptr;
    } else {
        y->par = z->par;
        if (z->par != nullptr) {
            if (z == z->par->left) {
                z->par->left = y;
            } else {
                z->par->right = y;
            }
        }
    }
    y->left = z;
    z->par = y;
    z->right = yL;
    if (yL != nullptr) {
        yL->par = z;
    }
    updateNode(z);
    updateNode(y);
}

void balance(Node* n, int x) {
    if (!balance_check(n)) {
        if (balance_factor(n) > 1 && x < n->left->data) {
            right_rotate(n);
        } else if (balance_factor(n) < -1 && x > n->right->data) {
            left_rotate(n);
        } else if (balance_factor(n) > 1 && x > n->left->data) {
            left_rotate(n->left);
            right_rotate(n);
        } else if (balance_factor(n) < -1 && x < n->right->data) {
            right_rotate(n->right);
            left_rotate(n);
        }
    }
}

void insert(int x) {
    Node* newNode = new Node(x);
    
    if (root == nullptr) {
        root = newNode;
        return;
    }
    
    Node* temp = root;
    Node* tar = nullptr;
    
    while (temp != nullptr) {
        tar = temp;
        if (newNode->data < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    newNode->par = tar;
    if (newNode->data < tar->data) tar->left = newNode;
    else tar->right = newNode;
    
    updateHeight(newNode);

    temp = newNode;
    while (temp != nullptr) {
        if (!balance_check(temp)) {
            balance(temp, x);
            break;
        }
        temp = temp->par;
    }
}
int lowerCount(int x) {
    Node* curr = root;
    int cnt = 0;
    while (curr != nullptr) {
        if (x <= curr->data) curr = curr->left;
        else {
            cnt += 1 + getSize(curr->left);
            curr = curr->right;
        }
    }
    return cnt;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int num;
    while (cin >> num && num != -1) {
        insert(num);
    }
    int q;
    while (cin >> q) {
        int result = lowerCount(q);
        cout << result << endl;
    }
    return 0;
}

