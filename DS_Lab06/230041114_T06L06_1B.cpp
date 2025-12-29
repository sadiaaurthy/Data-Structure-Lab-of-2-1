#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node *par;
    int height;
};
Node *root = NULL;
Node *CreateNode(int x) {
    Node *newNode = new Node();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->par = NULL;
    newNode->height = 0;
    return newNode;
}
void UpdateHeight(Node *node) {
    if (node == NULL) return;
    int lh = (node->left != NULL) ? node->left->height : -1;
    int rh = (node->right != NULL) ? node->right->height : -1;
    node->height = max(lh, rh) + 1;
}
void insert(int x) {
    Node* newNode = CreateNode(x);
    if (root == NULL) {
        root = newNode;
        return;
    } else {
        Node *temp = root, *tar = NULL;
        while (temp != NULL) {
            tar = temp;
            if (x < temp->data) temp = temp->left;
            else temp = temp->right;
        }
        newNode->par = tar;
        if (x < tar->data) tar->left = newNode;
        else tar->right = newNode;
        Node *curr = newNode->par;
        while (curr != NULL) {
            UpdateHeight(curr);
            curr = curr->par;
        }
    }
}
void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << "(" << root->height << ") ";
    inorder(root->right);
}
Node *SearchNode(int key) {
    Node *temp = root;
    while (temp != NULL) {
        if (key == temp->data) return temp;
        else if (key < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return NULL;
}
void Ancestor_finder(int x, vector<int>& acs) {
    Node *fnd = SearchNode(x);
    if (fnd == NULL) return;
    Node *curr = fnd->par;
    while (curr != NULL) {
        acs.push_back(curr->data);
        curr = curr->par;
    }
}
void Descendant_finder(Node *node, vector<int>& desc) {
    if (node == NULL) return;
    Descendant_finder(node->left, desc);
    desc.push_back(node->data);
    Descendant_finder(node->right, desc);
}
void PrintAcsDesc(int x) {
    Node *fnd = SearchNode(x);
    if (!fnd) {
        cout << "Not Present" << endl;
        return;
    }
    vector<int> ancs;
    Ancestor_finder(x, ancs);
    if (ancs.empty()) {
        cout << "NULL (NO Ancestors)" << endl;
    } else {
        cout << "Ancestors : ";
        for (auto& elm : ancs) cout << elm << " ";
        cout << endl;
    }
    vector<int> desc;
    Descendant_finder(fnd->left, desc);
    Descendant_finder(fnd->right, desc);
    if (desc.empty()) {
        cout << "NULL (NO Descendants)" << endl;
    } else {
        cout << "Descendants : ";
        for (auto& elm : desc) cout << elm << " ";
        cout << endl;
    }
}
int main() {
    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        insert(x);
    }
    cout << "Status : ";
    inorder(root);
    cout << endl;
    while (true) {
        int n;
        cin >> n;
        PrintAcsDesc(n);
    }
}
