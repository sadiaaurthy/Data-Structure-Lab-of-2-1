#include <iostream>
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
    int totalNodes;
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

    void findKthSmallest(Node* node, int k, int& count, int& result) {
        if (node == nullptr || count >= k) {
            return;
        }

        findKthSmallest(node->left, k, count, result);

        count++;
        if (count == k) {
            result = node->data;
            return;
        }

        findKthSmallest(node->right, k, count, result);
    }
    
public:
    BST() {
        root = nullptr;
        totalNodes = 0;
    }
    void insert(int val) {
        root = insert(root, val);
        totalNodes++;
    }
    int getKthSmallest(int k) {
        if (k > totalNodes || k <= 0) {
            return -1;
        }
        int count = 0;
        int result = -1;
        findKthSmallest(root, k, count, result);
        return result;
    }
    int getSize() {
        return totalNodes;
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
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        
        if (k > bst.getSize() || k <= 0) {
            cout << "Invalid" << endl;
        } else {
            int result = bst.getKthSmallest(k);
            cout << result << endl;
        }
    }
    return 0;
}