#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    cin >> n;
    unordered_map<string, int> morse_count;
    while (n--) {
        string s;
        cin >> s;
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        string m = "";
        for (int i = 0; i < s.length(); i++) {
            m += morse[s[i] - 'a'];
        }
        morse_count[m]++;
    }
    cout << morse_count.size() << endl;
    for (auto entry : morse_count) {
        cout << entry.first << endl;
    }
}