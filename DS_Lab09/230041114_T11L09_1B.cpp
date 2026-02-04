#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string getUniqueCharacterSet(const string& word) {
    bool seen[26] = {false};
    string uniqueSet = "";

    for (char c : word) {
        if (c >= 'a' && c <= 'z') {
            int idx = c - 'a';
            if (!seen[idx]) {
                seen[idx] = true; 
                uniqueSet += c; 
            }
        }
    }
    sort(uniqueSet.begin(), uniqueSet.end());
    return uniqueSet;
}

int main() {
    string sentence, word;
    getline(cin, sentence);
    getline(cin, word);

    unordered_map<string, vector<string>> wordGrp;

    int start = 0;
    for (int i = 0; i <= sentence.size(); ++i) {
        if (i == sentence.size() || sentence[i] == ' ') {
            string currWord = sentence.substr(start, i - start);
            start = i + 1;

            string uniqueSet = getUniqueCharacterSet(currWord);

            wordGrp[uniqueSet].push_back(currWord);
        }
    }

    string inputWordSet = getUniqueCharacterSet(word);

    if (wordGrp.find(inputWordSet) != wordGrp.end()) {
        for (const string& matchedWord : wordGrp[inputWordSet]) {
            cout << matchedWord << " ";
        }
        cout << endl;
    } else {
        cout << "No words found" << endl;
    }

    return 0;
}

