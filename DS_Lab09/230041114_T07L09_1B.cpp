#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->child[idx] == nullptr) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
    }
    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->child[idx] == nullptr) {
                return false;
            }
            node = node->child[idx];
        }
        return node->isEnd;
    }
};

bool canSegment(Trie& trie, const string& s) {
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true; 
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            string prefix = s.substr(j, i - j);
            if (dp[j] && trie.search(prefix)) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    Trie trie;
    string word;
    while (true) {
        getline(cin, word);
        if (word == "-1") {
            break;
        }
        trie.insert(word);
    }

    string testString;
    getline(cin, testString);
    if (canSegment(trie, testString)) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    return 0;
}


