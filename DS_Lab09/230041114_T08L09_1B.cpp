#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct trie {
    trie *node[52];
    bool endmark;
    int wordcount;
    trie() {
        endmark = false;
        wordcount = 0;
        for (int i = 0; i < 52; i++) {
            node[i] = nullptr;
        }
    }
};
int getindex(char c) {
    if (c >= 'a' and c <= 'z') {
        return c - 'a';
    }
    else
        return c - 'A' + 26;
}
void insert(trie *root, const string &word) {
    trie *curr = root;
    for (char ch : word) {
        int idx = getindex(ch);

        if (curr->node[idx] == nullptr) {
            curr->node[idx] = new trie();
        }
        curr = curr->node[idx];
    }
    curr->endmark = true;
}
bool search(trie *root, const string &word, const string &abb) {
    int abIdx = 0, wordIdx = 0;
    trie *curr = root;
    while (wordIdx < word.length() && abIdx < abb.length()) {
        char abbchar = abb[abIdx];
        if (isupper(abbchar)) {
            while (wordIdx < word.length() && islower(word[wordIdx])) {
                wordIdx++;
            }
            if (wordIdx == word.length() || word[wordIdx] != abbchar) {
                return false;
            }
        }
        else {
            if (word[wordIdx] != abbchar) {
                return false;
            }
        }
        abIdx++;
        wordIdx++;
    }
    if (abIdx != abb.length())
        return false;
    while (wordIdx < word.length()) {
        if (isupper(word[wordIdx]))
            return false;
        wordIdx++;
    }
    return true;
}
int main() {
    string word;
    int count = 0;
    vector<string> w;
    while (cin >> word && word != "-1") {
        w.push_back(word);
    }
    // cin.ignore();
    string abbreviation;
    cin >> abbreviation;
    for (const string &words : w) {
        trie *root = new trie();
        insert(root, words);
        if (search(root, words, abbreviation))
            cout << "T" << " ";
        else
            cout << "F" << " ";
        delete root;
    }
    cout << endl;
}