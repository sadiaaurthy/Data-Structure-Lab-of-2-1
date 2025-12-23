#include <iostream>
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
    int diameter;
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

    int calculateHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        diameter = max(diameter, leftHeight + rightHeight + 1);

        return max(leftHeight, rightHeight) + 1;
    }
    
public:
    BST() {
        root = nullptr;
        diameter = 0;
    }
    
    void insert(int val) {
        root = insert(root, val);
    }
    
    int getDiameter() {
        diameter = 0;
        calculateHeight(root);
        return diameter;
    }
};

int main() {
    int n;
    cin >> n;
    
    BST bst;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        bst.insert(val);
    }
    cout << bst.getDiameter() << endl;
    return 0;
}