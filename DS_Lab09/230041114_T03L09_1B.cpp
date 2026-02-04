#include<iostream>
#include<string>
using namespace std;

struct trie{
    trie* node[26];
    bool endmark;
    trie(){
        endmark = false;
        for(int i = 0; i < 26; i++){
            node[i] = nullptr;
        }
    }
};

void insert(trie* root, const string& word) {
    trie* curr = root;
    for (char ch : word) {
        int idx = ch - 'a';
        if (curr->node[idx] == nullptr) {
            curr->node[idx] = new trie();
        }
        curr = curr->node[idx];
    }
    curr->endmark = true;
}

bool search(trie* root, const string& word) {
    trie* curr = root;
    for (int i = 0; i < word.length(); i++) {
        int idx = word[i] - 'a';
        if (curr->node[idx] == nullptr) {
            return false;
        }
        curr = curr->node[idx];
    }
    return curr->endmark;
}

void display(trie* root, string prefix, int level) {
    if (root->endmark) {
        cout << prefix.substr(0, level) << " ";
    }
    for (int i = 0; i < 26; i++) {
        if (root->node[i] != nullptr) {
            char ch = i + 'a';
            prefix[level] = ch;
            display(root->node[i], prefix, level + 1);
        }
    }
}

int main() {
    trie* root = new trie();
    string line;

    getline(cin, line);
    string word;
    int word_begin = 0;

    for (int i = 0; i <= line.length(); i++) {
        if (i == line.length() || line[i] == ' ') {
            word = line.substr(word_begin, i - word_begin);
            if (!word.empty()) {
                insert(root, word);
            }
            word_begin = i + 1;
        }
    }

    string prefix(1000, '\0');
    display(root, prefix, 0);
    cout << endl;

    string l;
    getline(cin, l);
    word_begin = 0;

    for (int i = 0; i <= l.length(); i++) {
        if (i == l.length() || l[i] == ' ') {
            word = l.substr(word_begin, i - word_begin);
            if (!word.empty()) {
                if (search(root, word)) {
                    cout << "T ";
                } else {
                    cout << "F ";
                }
            }
            word_begin = i + 1;
        }
    }

    cout << endl;
}
