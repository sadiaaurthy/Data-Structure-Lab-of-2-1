#include <iostream>
#include <string>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node *parent;
    int height;
};
Node *root = nullptr;
int height(Node *n) {
    if (n == nullptr) {
        return 0;
    }
    else {
        return n->height;
    }
}
void updateheight(Node *n) {
    while (n != nullptr) {
        n->height = 1 + max(height(n->left), height(n->right));
        n = n->parent;
    }
}
int balance_factor(Node *n) {
    return height(n->left) - height(n->right);
}
bool balance_check(Node *n) {
    int bf = balance_factor(n);
    if (bf > 1 || bf < -1) {
        return false;
    }
    return true;
}
void right_rotate(Node *z) {
    if (z == nullptr || z->left == nullptr)
        return;
    Node *y = z->left;
    Node *yr = y->right;
    if (z == root) {
        root = y;
        y->parent = nullptr;
    }
    else {
        y->parent = z->parent;
        if (z->parent != nullptr) {
            if (z == z->parent->right) {
                z->parent->right = y;
            }
            else {
                z->parent->left = y;
            }
        }
    }
    y->right = z;
    z->parent = y;
    z->left = yr;
    if (yr != nullptr)
        yr->parent = z;
    updateheight(z);
    updateheight(y);
}

void left_rotate(Node *z) {
    if (z == nullptr || z->right == nullptr)
        return;
    Node *y = z->right;
    Node *yL = y->left;
    if (z == root) {
        root = y;
        y->parent = nullptr;
    }
    else {
        y->parent = z->parent;
        if (z->parent != nullptr) {
            if (z == z->parent->left) {
                z->parent->left = y;
            }
            else {
                z->parent->right = y;
            }
        }
    }
    y->left = z;
    z->parent = y;
    z->right = yL;
    if (yL != nullptr) {
        yL->parent = z;
    }
    updateheight(z);
    updateheight(y);
}

void display(Node *root) {
    if (root == nullptr)
        return;
    display(root->left);
    cout << root->data << "(" << balance_factor(root) << ") ";
    display(root->right);
}

void balance(Node *n, int x) {
    if (!balance_check(n)) {
        if (balance_factor(n) > 1 && x < n->left->data) {
            cout << "Imbalance at node:  " << n->data << endl;
            cout << "LL case" << endl;
            cout << "right_rotate(" << n->data << ")" << endl;
            right_rotate(n);
        }
        else if (balance_factor(n) < -1 && x > n->right->data) {
            cout << "Imbalance at node:  " << n->data << endl;
            cout << "RR case" << endl;
            cout << "left_rotate(" << n->data << ")" << endl;
            left_rotate(n);
        }
        else if (balance_factor(n) > 1 && x > n->left->data) {
            cout << "Imbalance at node:  " << n->data << endl;
            cout << "LR case" << endl;
            cout << "left_rotate(" << n->left->data << "), " << "right_rotate(" << n->data << ")" << endl;
            left_rotate(n->left);
            right_rotate(n);
        }
        else if (balance_factor(n) < -1 && x < n->right->data) {
            cout << "Imbalance at node:  " << n->data << endl;
            cout << "RL case" << endl;
            cout << "right_rotate(" << n->right->data << "), " << "left_rotate(" << n->data << ")" << endl;
            right_rotate(n->right);
            left_rotate(n);
        }
    }
}

void balance_after_deletion(Node *n) {
    if (!balance_check(n)) {
        int bf = balance_factor(n);

        if (bf > 1) {
            if (balance_factor(n->left) >= 0) {
                cout << "Imbalanced at node " << n->data << endl;
                right_rotate(n);
            }
            else {
                cout << "Imbalanced at node " << n->data << endl;
                left_rotate(n->left);
                right_rotate(n);
            }
        }
        else if (bf < -1) {
            if (balance_factor(n->right) <= 0) {
                cout << "Imbalanced at node " << n->data << endl;
                left_rotate(n);
            }
            else {
                cout << "Imbalanced at node " << n->data << endl;
                right_rotate(n->right);
                left_rotate(n);
            }
        }
    }
}

void insert(int x) {
    Node *newNode = new Node();
    newNode->data = x;
    newNode->left = newNode->right = newNode->parent = nullptr;
    newNode->height = 1;
    Node *temp = root;
    if (temp == nullptr)
        root = newNode;
    else {
        Node *tar = nullptr;
        while (temp != nullptr) {
            tar = temp;
            if (newNode->data < temp->data) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        newNode->parent = tar;
        if (newNode->data < tar->data)
            tar->left = newNode;
        else
            tar->right = newNode;
        updateheight(newNode);
    }
    display(root);
    cout << endl;
    if (balance_check(root)) {
        cout << "Balanced" << endl;
        cout << "Root=" << root->data << endl;
    }
    else {
        Node *temp = newNode;
        bool imbalanced = false;
        while (temp != nullptr) {
            if (!balance_check(temp)) {
                imbalanced = true;
                balance(temp, x);
                break;
            }
            temp = temp->parent;
        }
        if (imbalanced) {
            cout << "Status:";
            display(root);
            cout << endl;
            cout << "Root=" << root->data << endl;
        }
    }
}

Node *findMin(Node *n) {
    while (n->left != nullptr) {
        n = n->left;
    }
    return n;
}

void deleteNode(int x) {
    Node *temp = root;
    Node *tar = nullptr;

    while (temp != nullptr && temp->data != x) {
        if (x < temp->data) temp = temp->left;
        else temp = temp->right;
    }

    if (temp == nullptr) {
        cout << "Node not found" << endl;
        return;
    }
    tar = temp;
    Node *checkNode = tar->parent;

    if (tar->left == nullptr && tar->right == nullptr) {
        if (tar == root) {
            root = nullptr;
        }
        else {
            if (tar->parent->left == tar) tar->parent->left = nullptr;
            else tar->parent->right = nullptr;
        }
        delete tar;
    }
    else if (tar->left == nullptr) {
        if (tar == root) {
            root = tar->right;
            root->parent = nullptr;
        }
        else {
            if (tar->parent->left == tar)
            {
                tar->parent->left = tar->right;
            }
            else
            {
                tar->parent->right = tar->right;
            }
            tar->right->parent = tar->parent;
        }
        delete tar;
    }
    else if (tar->right == nullptr) {
        if (tar == root)
        {
            root = tar->left;
            root->parent = nullptr;
        }
        else
        {
            if (tar->parent->left == tar)
            {
                tar->parent->left = tar->left;
            }
            else
            {
                tar->parent->right = tar->left;
            }
            tar->left->parent = tar->parent;
        }
        delete tar;
    }
    else {
        Node *successor = findMin(tar->right);
        int successorData = successor->data;
        checkNode = successor->parent;

        if (successor->parent->left == successor)
            successor->parent->left = successor->right;
        else
            successor->parent->right = successor->right;

        if (successor->right != nullptr)
            successor->right->parent = successor->parent;

        delete successor;
        tar->data = successorData;
    }
    if (checkNode != nullptr) {
        updateheight(checkNode);
        Node *temp = checkNode;
        while (temp != nullptr) {
            if (!balance_check(temp)) {
                balance_after_deletion(temp);
                break;
            }
            temp = temp->parent;
        }
    }

    display(root);
    cout << endl;

    if (balance_check(root)) {
        cout << "Balanced" << endl;
    }

    cout << "Root=" << root->data << endl;
}

int main() {
    string input;

    while (cin >> input) {
        if (input == "Delete") {
            int del;
            cin >> del;
            deleteNode(del);
        }
        else {
            int a = stoi(input);
            if (a == -1) {
                cout << "Status: ";
                display(root);
                cout << endl;
                break;
            }
            else
                insert(a);
        }
    }

    return 0;
}