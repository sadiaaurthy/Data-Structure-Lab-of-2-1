#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isAlphanum(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int main() {
    string sentence;
    getline(cin, sentence);
    
    unordered_map<string, int> wordCnt; 
    string word = "";

    for (char c : sentence) {
        if (isAlphanum(c)) {
            word += tolower(c);
        } else if (!word.empty()) {
            wordCnt[word]++;
            word = ""; 
        }
    }

    if (!word.empty()) {
        wordCnt[word]++;
    }

    for (auto& elm : wordCnt) {
        if (elm.second > 1) {
            cout << elm.first << " " << elm.second << endl;
        }
    }

    return 0;
}
