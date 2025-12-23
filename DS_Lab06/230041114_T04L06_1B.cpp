#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
};
Node* createNode(int elm) {
    Node* newNode = new Node();
    newNode->data = elm;
    newNode->height = 0;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
class BST {
private:
    Node* root;
    int getHeight(Node* node) {
        if (node == nullptr) return -1 ;
        else return node->height;
    }
    void updateHeight(Node* node) {
        if (node != nullptr) {
            node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        }
    }
    Node* insert(Node* node, int elm) {
        if (node == nullptr) {
            return createNode(elm);
        }
        if (elm < node->data) {
            node->left = insert(node->left, elm);
        } else if (elm > node->data) {
            node->right = insert(node->right, elm);
        }
        updateHeight(node);
        return node;
    }
    void inorder(Node* node) {
        if (node == nullptr) return; 
        inorder(node->left);
        cout << node->data << "(" << node->height << ") ";
        inorder(node->right);
    }
    bool PathFinder(Node* node, int tar, vector<int>& v) {
        if (node == nullptr) {
            return false;
        }
        v.push_back(node->data);
        if (node->data == tar) {
            return true;
        }
        if (tar < node->data) {
            if (PathFinder(node->left, tar, v)) {
                return true;
            }
        } else {
            if (PathFinder(node->right, tar, v)) {
                return true;
            }
        }
        v.pop_back();
        return false;
    }
    Node* LCA_finder(Node* node, int x, int y) {
        if (node == nullptr) {
            return nullptr;
        }
        if (x < node->data && y < node->data) {
            return LCA_finder(node->left, x, y);
        }
        if (x > node->data && y > node->data) {
            return LCA_finder(node->right, x, y);
        }
        return node;
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
    void Print(int x, int y) {
        vector<int> pathX, pathY;
        PathFinder(root, x, pathX);
        PathFinder(root, y, pathY);
        Node* lca = LCA_finder(root, x, y);
        vector<int> ComPath;
        vector<int> XtoLCA;
        PathFinder(root, x, XtoLCA);
        int LCA_idx = -1;
        for (int i = 0; i < XtoLCA.size(); i++) {
            if (XtoLCA[i] == lca->data) {
                LCA_idx = i;
                break;
            }
        }
        for (int i = XtoLCA.size() - 1; i >= LCA_idx; i--) {
            ComPath.push_back(XtoLCA[i]);
        }
        vector<int> LCAtoY;
        PathFinder(root, y, LCAtoY);
        for (int i = 0; i < LCAtoY.size(); i++) {
            if (LCAtoY[i] == lca->data) {
                for (int j = i + 1; j < LCAtoY.size(); j++) {
                    ComPath.push_back(LCAtoY[j]);
                }
                break;
            }
        }
        for (int i = 0; i < ComPath.size(); i++) {
            if (i > 0) cout << " ";
            cout << ComPath[i];
        }
        cout << endl;
        cout << ComPath.size() << endl;
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
    int x, y;
    while (true) {
        cin >> x >> y;
        bst.Print(x, y);
    }
    return 0;
}
