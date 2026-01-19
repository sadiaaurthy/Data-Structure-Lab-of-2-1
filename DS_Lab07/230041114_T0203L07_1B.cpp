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
    return  (n == nullptr) ? -1 : n->height;
}
void updateheight(Node *n) {
    while (n != nullptr) {
        n->height = 1 + max(height(n->left), height(n->right));
        n = n->parent;
    }
}
Node* searchNode(int key) {
    Node* temp = root;
    while (temp != nullptr) {
        if (key == temp->data) {
            return temp;
        } else if (key < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return temp;
}
int balance_factor(Node *n) {
    return height(n->left) - height(n->right);
}
bool balance_check(Node *n) {
    int bf = balance_factor(n);
    return (bf > 1 || bf < -1) ? false : true;
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

void inorder(Node *root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << "(" << balance_factor(root) << ") ";
    inorder(root->right);
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
    inorder(root);
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
            inorder(root);
            cout << endl;
            cout << "Root=" << root->data << endl;
        }
    }
}

Node *findMax(Node *n) {
    while (n->right != nullptr) {
        n = n->right;
    }
    return n;
}

void deleteNode(int x) {
    // --------- Step 1: find the target node (BST search) ----------
    Node* fnd = searchNode(x);
    if (fnd == nullptr) {
        cout << "Node not found" << endl;
        return;
    }

    Node* checkNode = fnd->parent;

    // --------- Case A: tar is a LEAF (no children) ----------
    if (fnd->left == nullptr && fnd->right == nullptr) {
        if (fnd == root) {
            root = nullptr;            
        } else {
            if (fnd->parent->left == fnd) fnd->parent->left = nullptr;
            else fnd->parent->right = nullptr;
        }
        delete fnd;
    }

    // --------- Case B1: tar has ONLY RIGHT CHILD ----------
    else if (fnd->left == nullptr && fnd->right != nullptr) {
        Node* child = fnd->right;

        if (fnd == root) {
            root = child;
            root->parent = nullptr;
            checkNode = root;            
        } else {
            if (fnd->parent->left == fnd) fnd->parent->left = child;
            else fnd->parent->right = child;

            child->parent = fnd->parent;  
        }
        delete fnd;
    }

    // --------- Case B2: tar has ONLY LEFT CHILD ----------
    else if (fnd->right == nullptr && fnd->left != nullptr) {
        Node* child = fnd->left;

        if (fnd == root) {
            root = child;
            root->parent = nullptr;
            checkNode = root;          
        } else {
            if (fnd->parent->left == fnd) fnd->parent->left = child;
            else fnd->parent->right = child;

            child->parent = fnd->parent; 
        }
        delete fnd;
    }

    // --------- Case C: tar has TWO CHILDREN ----------
else {
    Node* pred = findMax(fnd->left);
    int predData = pred->data;
    checkNode = pred->parent;
    Node* predChild = pred->left;
    if (pred->parent->right == pred)
        pred->parent->right = predChild;
    else
        pred->parent->left = predChild;

    if (predChild != nullptr)
        predChild->parent = pred->parent;

    delete pred;
    fnd->data = predData;
}


    // --------- Rebalancing ----------
    if (checkNode != nullptr) {
        updateheight(checkNode);

        Node* temp = checkNode;
        while (temp != nullptr) {
            if (!balance_check(temp)) {
                balance_after_deletion(temp);
                break;
            }
            temp = temp->parent;
        }
    }

    inorder(root);
    cout << endl;

    if (root != nullptr && balance_check(root)) {
        cout << "Balanced" << endl;
        cout << "Root=" << root->data << endl;
    }
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
                inorder(root);
                cout << endl;
                break;
            }
            else
                insert(a);
        }
    }
    return 0;
}
