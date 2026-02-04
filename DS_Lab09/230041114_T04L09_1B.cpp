#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct trie {
    trie* node[26];
    bool endmark;
    int preCnt;
    
    trie() {
        endmark = false;
        preCnt = 0;
        for (int i = 0; i < 26; i++) {
            node[i] = nullptr;
        }
    }
};

void insert(trie* root, string word){
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] + 32;
        }
    }
    trie* curr = root;
    trie* temp = root;
    bool exists = true;
    for(int i = 0; i < word.length(); i++){
        int idx = word[i] - 'a';
        if(temp->node[idx] == nullptr){
            exists = false;
            break;
        }
        temp = temp->node[idx];
    }
    if(exists && temp->endmark){
        return;
    }
    for(int i = 0; i < word.length(); i++){
        int idx = word[i] - 'a';
        if(curr->node[idx] == nullptr){
            curr->node[idx] = new trie();
        }
        curr = curr->node[idx];
        curr->preCnt++;
    }
    curr->endmark = true;
}

int PrefixCount(trie* root, string prefix){
    for (int i = 0; i < prefix.length(); i++) {
        if (prefix[i] >= 'A' && prefix[i] <= 'Z') {
            prefix[i] = prefix[i] + 32;
        }
    }
    
    trie* curr = root;
    for(int i = 0; i < prefix.length(); i++){
        int idx = prefix[i] - 'a';
        if(curr->node[idx] == nullptr){
            return 0;
        }
        curr = curr->node[idx];
    }
    return curr->preCnt;
}

int main() {
    trie* root = new trie();
    int N, Q;
    cin >> N >> Q;
    cin.ignore();
    
    for (int i = 0; i < N; i++) {
        string word;
        getline(cin, word);
        insert(root, word);
    }
    
    for (int i = 0; i < Q; i++) {
        string prefix;
        getline(cin, prefix);
        cout << PrefixCount(root, prefix) << endl;
    }
    
    return 0;
}