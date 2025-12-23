#include <iostream>
#include <vector>
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

    void findLeafNodes(Node* node, vector<int>& leaves) {
        if (node == nullptr) {
            return;
        }

        findLeafNodes(node->left, leaves);

        if (node->left == nullptr && node->right == nullptr) {
            leaves.push_back(node->data);
        }
        
        findLeafNodes(node->right, leaves);
    }
    
public:
    BST() {
        root = nullptr;
    }
    
    void insert(int val) {
        root = insert(root, val);
    }
    
    vector<int> getLeafNodes() {
        vector<int> leaves;
        findLeafNodes(root, leaves);
        return leaves;
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
    vector<int> leafNodes = bst.getLeafNodes();
    cout << "Leaf nodes:" << endl;
    for (int i = 0; i < leafNodes.size(); i++) {
        if (i > 0) cout << ", ";
        cout << leafNodes[i];
    }
    cout << endl;
    return 0;
}