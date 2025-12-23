#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* CreateNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
class BST {
private:
    Node* root;
    Node* insert(Node* node, int elm) {
        if (node == nullptr) {
            return CreateNode(elm);
        }
        if (elm < node->data) {
            node->left = insert(node->left, elm);
        } else if (elm > node->data) {
            node->right = insert(node->right, elm);
        }
        return node;
    }  
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    bool AncsFinder(Node* node, int tar, vector<int>& a) {
        if (node == nullptr) return false;
        
        if (node->data == tar) return true;
        
        if (AncsFinder(node->left, tar, a) ||
            AncsFinder(node->right, tar, a)) {
            a.push_back(node->data);
            return true;
        }
        return false;
    }
    
    Node* NodeFinder(Node* node, int tar) {
        if (node == nullptr || node->data == tar) return node;
        
        if (tar < node->data)
            return NodeFinder(node->left, tar);
        else
            return NodeFinder(node->right, tar);
    }
    
    void getDesc(Node* node, vector<int>& d) {
        if (node == nullptr) return;
        
        getDesc(node->left, d);
        d.push_back(node->data);
        getDesc(node->right, d);
    }
    
public:
    BST() {
        root = nullptr;
    }
    void insert(int elm) {
        root = insert(root, elm);
    }
    void StatusPrinter() {
        cout << "Status: ";
        inorder(root);
        cout << endl;
    }
    vector<int> getAnc(int tar) {
        vector<int> a;
        AncsFinder(root, tar, a);
        sort(a.begin(), a.end());
        return a;
    }
    
    vector<int> getDescOf(int tar) {
        vector<int> d;
        Node* tarNode = NodeFinder(root, tar);
        
        if (tarNode != nullptr) {
            getDesc(tarNode->left, d);
            getDesc(tarNode->right, d);
        }
        return d;
    }
};

int main() {
    BST bst;
    int elm;
    while (true) {
        cin >> elm;
        if (elm == -1) break;
        bst.insert(elm);
    }
    bst.StatusPrinter();
    int n;
    while (true) {
        cin >> n;
        vector<int> a = bst.getAnc(n);
        vector<int> d = bst.getDescOf(n);
        if (a.empty()) cout << "Null" << endl;
        else {
            for (int i = 0; i < a.size(); i++) {
                if (i) cout << " ";
                cout << a[i];
            }
            cout << endl;
        }
        if (d.empty()) cout << "Null" << endl;
        else {
            for (int i = 0; i < d.size(); i++) {
                if (i) cout << " ";
                cout << d[i];
            }
            cout << endl;
        }
    }
    return 0;
}
