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

    for (const auto& entry : wordCnt) {
        if (entry.second > 1) {
            cout << entry.first << " " << entry.second << endl;
        }
    }

    return 0;
}
