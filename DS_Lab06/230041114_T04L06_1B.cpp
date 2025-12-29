#include <iostream>
#include <vector>
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

void updateHeight(Node* node) {
    int lh, rh;
    if (node == nullptr) return;
    if (node->left == nullptr) lh = -1 ;
    else lh = node->left->height;
    if (node->right == nullptr) rh = -1; 
    else rh = node->right->height;
    node->height = max(lh, rh) + 1;
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
        if (newNode->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    newNode->par = tar;
    if (newNode->data < tar->data)
        tar->left = newNode;
    else
        tar->right = newNode;

    Node* curr = newNode->par;
    while (curr != nullptr) {
        updateHeight(curr);
        curr = curr->par;
    }
}
void inorder(Node *node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << "(" << node->height << ") ";
    inorder(node->right);
}
// Node *SearchNode(int key) {
//     Node *temp = root;
//     while (temp != NULL) {
//         if (key == temp->data) return temp;
//         else if (key < temp->data) temp = temp->left;
//         else  temp = temp->right;
//     }
//     return NULL;
// }
Node *LCA_finder(Node* root, int u, int v) {
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

// void findLCA(int u, int v) {
//     Node* lca = LCA_finder(root, u, v);
//     if (lca != nullptr)
//         cout << lca->data << endl;
// }
bool PathToNode(Node *root /*LCA root*/, int key, vector<int> &vec) {
    Node *temp = root; // This root is LCA root
    while (temp != NULL) {
        vec.push_back(temp->data);
        if (temp->data == key) return true;
        else if (key < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    vec.clear();
    return false;
}
void PrintPath(int l, int r) {
    Node *lca = LCA_finder(root, l, r);
    vector<int> pl, pr;
    PathToNode(lca, l, pl);
    PathToNode(lca, r, pr);
    for (int i = pl.size() - 1; i >= 0; i--) cout << pl[i] << " ";
    for (int i = 1; i < pr.size(); i++) cout << pr[i] << " ";
    cout << endl;
    cout << pl.size() + pr.size() - 1 << endl;
}
int main() {
    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        insert(x);
    }
    cout << "Status: ";
    inorder(root);
    cout << endl;

    int u, v;
    while (true) {
        cin >> u >> v;
        PrintPath(u, v);
    }
    return 0;
}
