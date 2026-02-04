#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    TrieNode* left; 
    TrieNode* right; 
    
    TrieNode() {
        left = nullptr;
        right = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    int MAX_BITS;  
    
    Trie() {
        root = new TrieNode();
        MAX_BITS = 32; 
    }
    void insert(int num) {
        TrieNode* node = root;
        for (int i = MAX_BITS - 1; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (node->left == nullptr) {
                    node->left = new TrieNode();
                }
                node = node->left;
            } else {
                if (node->right == nullptr) {
                    node->right = new TrieNode();
                }
                node = node->right;
            }
        }
    }

    int maxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = MAX_BITS - 1; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (node->right != nullptr) {
                    maxXOR |= (1 << i);
                    node = node->right;
                } else {
                    node = node->left;
                }
            } else {
                if (node->left != nullptr) {
                    maxXOR |= (1 << i);
                    node = node->left;
                } else {
                    node = node->right;
                }
            }
        }
        return maxXOR;
    }
};

int MaximumXOR(vector<int>& v) {
    Trie trie;
    int maxXOR = 0;
    
    for (int num : v) {
        trie.insert(num);
    }
    
    for (int num : v) {
        maxXOR = max(maxXOR, trie.maxXOR(num));
    }
    
    return maxXOR;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int result = MaximumXOR(v);
    cout << result << endl;
    
    return 0;
}
