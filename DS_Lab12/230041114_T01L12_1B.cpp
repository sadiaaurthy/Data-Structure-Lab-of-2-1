#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string str;
    cin >> str;
    int Q;
    cin >> Q;
    vector<vector<int>> preFreq;
    preFreq.assign(str.size() + 1, vector<int> (26, 0));
    for (int i = 0; i < str.size(); i++) {
        preFreq[i + 1] = preFreq[i];
        preFreq[i + 1][str[i] - 'a'] ++;
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        vector<int>  f(26, 0);
        for (int i = 0; i < 26; i++) {
            f[i] = preFreq[r + 1][i] - preFreq[l][i];
        }
        int maxFreq = 0;
        char maxChar = 'a'; 
        for (int i = 0; i < f.size(); i++) {
            if (f[i] > maxFreq) {
                maxFreq = f[i];
                maxChar = 'a' + i; 
            }
        }
        cout << maxChar << ':' << maxFreq << endl;
    }
}
