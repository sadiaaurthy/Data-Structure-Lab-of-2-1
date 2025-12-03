#include <iostream>
#include <queue>
using namespace std;

int lastStone(vector<int>& stones) {
    priority_queue<int> pq;
    for (int w : stones) {
        pq.push(w);
    }

    while (pq.size() > 1) {
        int y = pq.top(); 
        pq.pop();   
        int x = pq.top(); 
        pq.pop();   

        if (x != y) {
            pq.push(y - x); 
        }
    }
    if (pq.empty()) {
        return 0;
    } else return pq.top();
}
int main() {
    vector<int> stones;
    int x;
    while (true) {
        cin >> x;
        if (x == -1) {
            if (!stones.empty()) {
                cout << lastStone(stones) << "\n";
                stones.clear();
                break;
            } else {
                cout << 0 << "\n";
                break;
            }
        } else {
            stones.push_back(x);
        }
    }
    return 0;
}
