#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    vector<string> Products;

    TrieNode() {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& product) {
        TrieNode* node = root;
        for (char c : product) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->Products.push_back(product);
        }
    }

    vector<vector<string>> getSuggestions(const string& searchWord) {
        TrieNode* node = root;
        vector<vector<string>> result;

        for (int i = 0; i < searchWord.length(); ++i) {
            char c = searchWord[i];
            if (node->children.find(c) == node->children.end()) {
                result.push_back({"NULL"}); 
                continue;
            }
            node = node->children[c];
            sort(node->Products.begin(), node->Products.end());
            vector<string> suggestions;
            for (int j = 0; j < min(3, (int)node->Products.size()); ++j) {
                suggestions.push_back(node->Products[j]);
            }
            result.push_back(suggestions);
        }

        return result;
    }
};

vector<vector<string>> suggestedProducts(vector<string>& Products, string searchWord) {
    Trie trie;

    for (const string& product : Products) {
        trie.insert(product);
    }

    return trie.getSuggestions(searchWord);
}

int main() {
    string line;
    vector<string> Products;
    getline(cin, line); 
    string product;
    for (char c : line) {
        if (c == ' ') {
            if (!product.empty()) {
                Products.push_back(product); 
                product.clear(); 
            }
        } else {
            product += c;
        }
    }
  
    if (!product.empty()) {
        Products.push_back(product);
    }

    string searchWord;
    getline(cin, searchWord);

    vector<vector<string>> result = suggestedProducts(Products, searchWord);

    for (const auto& suggestions : result) {
        for (const string& suggestion : suggestions) {
            cout << suggestion << " ";
        }
        cout << endl;
    }

    return 0;
}
