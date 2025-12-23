#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class BST {
private:
    Node* root;
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        
        return node;
    }
    bool findAncestors(Node* node, int target, vector<int>& ancestors) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == target) {
            return true;
        }
        if (findAncestors(node->left, target, ancestors) || 
            findAncestors(node->right, target, ancestors)) {
            ancestors.push_back(node->data);
            return true;
        }
        
        return false;
    }

    Node* findNode(Node* node, int target) {
        if (node == nullptr || node->data == target) {
            return node;
        }
        
        if (target < node->data) {
            return findNode(node->left, target);
        } else {
            return findNode(node->right, target);
        }
    }

    void getDescendants(Node* node, vector<int>& descendants) {
        if (node == nullptr) {
            return;
        }
        getDescendants(node->left, descendants);
        descendants.push_back(node->data);
        getDescendants(node->right, descendants);
    }
public:
    BST() {
        root = nullptr;
    }
    void insert(int val) {
        root = insert(root, val);
    }
    vector<int> getAncestors(int target) {
        vector<int> ancestors;
        findAncestors(root, target, ancestors);
        sort(ancestors.begin(), ancestors.end());
        return ancestors;
    }
    vector<int> getDescendantsOf(int target) {
        Node* targetNode = findNode(root, target);
        vector<int> descendants;
        if (targetNode != nullptr) {
            getDescendants(targetNode->left, descendants);
            getDescendants(targetNode->right, descendants);
        }
        return descendants;
    }
};

int main() {
    BST bst;
    int val;
    while (cin >> val && val != -1) {
        bst.insert(val);
    }

    int query;
    while (cin >> query) {
        vector<int> ancestors = bst.getAncestors(query);
        vector<int> descendants = bst.getDescendantsOf(query);

        if (ancestors.empty()) {
            cout << "Null" << endl;
        } else {
            for (int i = 0; i < ancestors.size(); i++) {
                if (i > 0) cout << " ";
                cout << ancestors[i];
            }
            cout << endl;
        }

        if (descendants.empty()) {
            cout << "Null" << endl;
        } else {
            for (int i = 0; i < descendants.size(); i++) {
                if (i > 0) cout << " ";
                cout << descendants[i];
            }
            cout << endl;
        }
    }
    
    return 0;
}