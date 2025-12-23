#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        height = 0;
        left = nullptr;
        right = nullptr;
    }
};
class BST {
private:
    Node* root;
    int getHeight(Node* node) {
        return (node == nullptr) ? -1 : node->height;
    }
    void updateHeight(Node* node) {
        if (node != nullptr) {
            node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        }
    }
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        updateHeight(node);
        
        return node;
    }
    void inorderWithHeight(Node* node) {
        if (node == nullptr) return;
        
        inorderWithHeight(node->left);
        cout << node->data << "(" << node->height << ") ";
        inorderWithHeight(node->right);
    }
    bool findPath(Node* node, int target, vector<int>& path) {
        if (node == nullptr) {
            return false;
        }

        path.push_back(node->data);
        if (node->data == target) {
            return true;
        }
        if (target < node->data) {
            if (findPath(node->left, target, path)) {
                return true;
            }
        } else {
            if (findPath(node->right, target, path)) {
                return true;
            }
        }

        path.pop_back();
        return false;
    }
    Node* findLCA(Node* node, int x, int y) {
        if (node == nullptr) {
            return nullptr;
        }
        if (x < node->data && y < node->data) {
            return findLCA(node->left, x, y);
        }
        if (x > node->data && y > node->data) {
            return findLCA(node->right, x, y);
        }
        return node;
    }
public:
    BST() {
        root = nullptr;
    }
    void insert(int val) {
        root = insert(root, val);
    }
    void printStatus() {
        cout << "Status: ";
        inorderWithHeight(root);
        cout << endl;
    }
    void printPath(int x, int y) {
        vector<int> pathX, pathY;
        findPath(root, x, pathX);
        findPath(root, y, pathY);
        Node* lca = findLCA(root, x, y);
        vector<int> completePath;
        vector<int> xToLCA;
        findPath(root, x, xToLCA);
        int lcaIndex = -1;
        for (int i = 0; i < xToLCA.size(); i++) {
            if (xToLCA[i] == lca->data) {
                lcaIndex = i;
                break;
            }
        }
        for (int i = xToLCA.size() - 1; i >= lcaIndex; i--) {
            completePath.push_back(xToLCA[i]);
        }
        vector<int> lcaToY;
        findPath(root, y, lcaToY);
        for (int i = 0; i < lcaToY.size(); i++) {
            if (lcaToY[i] == lca->data) {
                for (int j = i + 1; j < lcaToY.size(); j++) {
                    completePath.push_back(lcaToY[j]);
                }
                break;
            }
        }
        for (int i = 0; i < completePath.size(); i++) {
            if (i > 0) cout << " ";
            cout << completePath[i];
        }
        cout << endl;
        cout << completePath.size() << endl;
    }
};
int main() {
    BST bst;
    int val;
    while (cin >> val && val != -1) {
        bst.insert(val);
    }
    bst.printStatus();
    int x, y;
    while (cin >> x >> y) {
        bst.printPath(x, y);
    }
    return 0;
}