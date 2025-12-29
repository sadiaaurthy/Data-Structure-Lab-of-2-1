#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node *par;
    int height = 0;
};
Node *root = NULL;
Node *CreateNode(int x) {
    Node *newNode = new Node();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
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
    Node *newNode = CreateNode(x);
    if (root == NULL) {
        root = newNode;
        return;
    } else {
        Node *temp = root;
        Node *tar = NULL;
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
void inorderForKth(Node* root, vector<int>& V) {
    if (root == nullptr) return;
    inorderForKth(root->left, V);
    V.push_back(root->data);
    inorderForKth(root->right, V);
}
int findKthSmallest(int k, int totalNodes) {
    if (k > totalNodes || k <= 0) {
        return -1; 
    }
    vector<int> V;
    inorderForKth(root, V);
    return V[k - 1];
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insert(value);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        if (k > n || k <= 0) {
            cout << "Invalid" << endl;
        } else {
            int result = findKthSmallest(k, n);
            cout << result << endl;
        }
    }
    return 0;
}
