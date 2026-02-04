#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, string> dictionary;
    string english, foreign;
    string line;

    while (getline(cin, line) && !line.empty()) {
        int spacePos = line.find(" ");
        english = line.substr(0, spacePos);
        foreign = line.substr(spacePos + 1);

        dictionary[foreign] = english;
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
