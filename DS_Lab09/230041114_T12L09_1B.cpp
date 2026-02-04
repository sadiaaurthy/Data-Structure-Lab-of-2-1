#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, string> dictionary;
    string englishWord, foreignWord;
    string line;

    while (getline(cin, line) && !line.empty()) {
        int spacePos = line.find(" ");
        englishWord = line.substr(0, spacePos);
        foreignWord = line.substr(spacePos + 1);

        dictionary[foreignWord] = englishWord;
    }

    while (getline(cin, line)) {
        if (dictionary.find(line) != dictionary.end()) {
            cout << dictionary[line] << endl;
        } else {
            cout << "eh" << endl;
        }
    }

    return 0;
}
