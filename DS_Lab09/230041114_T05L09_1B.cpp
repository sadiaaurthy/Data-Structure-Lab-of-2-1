#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    vector<string> Products;

    TrieNode() {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string& prod) {
        TrieNode* node = root;
        for (char c : prod) {
            if (node->child.find(c) == node->child.end()) {
                node->child[c] = new TrieNode();
            }
            node = node->child[c];
            node->Products.push_back(prod);
        }
    }

    vector<vector<string>> getSuggestions(string& searchWord) {
        TrieNode* node = root;
        vector<vector<string>> result;

        for (int i = 0; i < searchWord.length(); ++i) {
            char c = searchWord[i];
            if (node->child.find(c) == node->child.end()) {
                result.push_back({"NULL"}); 
                continue;
            }
            node = node->child[c];
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

    for (string& prod : Products) {
        trie.insert(prod);
    }

    return trie.getSuggestions(searchWord);
}

int main() {
    string line;
    vector<string> Products;
    getline(cin, line); 
    string prod;
    for (char c : line) {
        if (c == ' ') {
            if (!prod.empty()) {
                Products.push_back(prod); 
                prod.clear(); 
            }
        } else {
            prod += c;
        }
    }
  
    if (!prod.empty()) {
        Products.push_back(prod);
    }

    string searchWord;
    getline(cin, searchWord);

    vector<vector<string>> result = suggestedProducts(Products, searchWord);

    for (auto& elm : result) {
        for (string& n : elm) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
