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
        Node* curr = newNode->par;
        while (curr != nullptr) {
            updateHeight(curr);
            curr = curr->par;
        }
    }
}
void inorder(Node* n) {
    if (n == nullptr) return;
    inorder(n->left);
    cout << n->data << " ";
    inorder(n->right);
}
void print_tree() {
    inorder(root);
    cout << endl;
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
    return nullptr;
}
void search(int key) {
    Node* found = searchNode(key);
    if (found == nullptr) {
        cout << "Not Present" << endl;
    } else {
        cout << "Present" << endl;
        cout << "Parent(";
        if (found->par == nullptr) {
            cout << "null";
        } else {
            cout << found->par->data;
        }
        cout << "), Left(";
        if (found->left == nullptr) {
            cout << "null";
        } else {
            cout << found->left->data;
        }
        cout << "), Right(";
        if (found->right == nullptr) {
            cout << "null";
        } else {
            cout << found->right->data;
        }
        cout << ")" << endl;
    }
}
void NodeHeight(int value) {
    Node* found = searchNode(value);
    if (found != nullptr) {
        cout << found->height << endl;
    } else {
        cout << "Not found" << endl;
    }
}
int findMin(Node* n) {
    if (n == nullptr) return -1;
    while (n->left != nullptr) {
        n = n->left;
    }
    return n->data;
}
int findMax(Node* n) {
    if (n == nullptr) return -1;
    while (n->right != nullptr) {
        n = n->right;
    }
    return n->data;
}
void max_min(int value) {
    Node* found = searchNode(value);
    if (found == nullptr) {
        cout << "Not found" << endl;
        return;
    }
    int minVal = findMin(found);
    int maxVal = findMax(found);
    cout << minVal << " " << maxVal << endl;
}
Node* Before(Node* n) {
    if (n->left != nullptr) {
        Node* temp = n->left;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp;
    }
    Node* parent = n->par;
    while (parent != nullptr && n == parent->left) {
        n = parent;
        parent = parent->par;
    }
    return parent;
}
Node* After(Node* n) {
    if (n->right != nullptr) {
        Node* temp = n->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }
    Node* parent = n->par;
    while (parent != nullptr && n == parent->right) {
        n = parent;
        parent = parent->par;
    }
    return parent;   
}
void before_after(int value) {
    Node* found = searchNode(value);
    if (found == nullptr) {
        cout << "Not found" << endl;
        return;
    }
    Node* before = Before(found);
    Node* after = After(found);
    if (before == nullptr) {
        cout << "null ";
    } else {
        cout << before->data << " ";
    }
    if (after == nullptr) {
        cout << "null" << endl;
    } else {
        cout << after->data << endl;
    }
}
int main() {
    int operation, value;
    while (cin >> operation) {
        switch (operation) {
            case 1:
                cin >> value;
                insert(value);
                print_tree();
                break;             
            case 2:
                print_tree();
                break;     
            case 3: 
                cin >> value;
                search(value);
                break;
            case 4: 
                cin >> value;
                NodeHeight(value);
                break;
            case 5: 
                cin >> value;
                before_after(value);
                break;
            case 6:
                cin >> value;
                max_min(value);
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    }
    return 0;
}
