#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void indexes(vector<int>& que, vector<int>& cocks, stack<int>& s) {
    for (int i = 0; i < que.size(); i++) {
        int tar = -1;
        for (int j = 0; j < cocks.size(); j++) {
            if (que[i] == cocks[j]) {
                cout << j + 1 << " "; 
                tar = cocks[j];  
                cocks.erase(cocks.begin() + j); 
                break;
            }
        }

        for (int i = cocks.size() - 1; i >= 0; i--) {
            s.push(cocks[i]);
        }

        cocks.clear();  
        while (!s.empty()) {
            cocks.push_back(s.top());
            s.pop();
        }

        cocks.insert(cocks.begin(), tar);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> cocks(n), que(q);
    stack<int> s;

    for (auto& elm : cocks) cin >> elm;

    for (auto& val : que) cin >> val;

    indexes(que, cocks, s);
    return 0;
}
