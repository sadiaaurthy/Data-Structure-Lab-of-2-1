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
    int abindex = 0, wordindex = 0;
    trie *curr = root;
    while (wordindex < word.length() && abindex < abb.length()) {
        char abbch = abb[abindex];
        if (isupper(abbch)) {
            while (wordindex < word.length() && islower(word[wordindex])) {
                wordindex++;
            }
            if (wordindex == word.length() || word[wordindex] != abbch) {
                return false;
            }
        }
        else {
            if (word[wordindex] != abbch) {
                return false;
            }
        }
        abindex++;
        wordindex++;
    }
    if (abindex != abb.length())
        return false;
    while (wordindex < word.length()) {
        if (isupper(word[wordindex]))
            return false;
        wordindex++;
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