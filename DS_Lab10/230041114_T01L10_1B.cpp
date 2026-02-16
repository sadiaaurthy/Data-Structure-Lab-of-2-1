#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int find(int num) {
    if (v[num] != num) {
        v[num] = find(v[num]); 
    }
    return v[num];
}
void Union(int num1, int num2) {
    int rep1 = find(num1);
    int rep2 = find(num2);
    if (rep1 != rep2) {
        v[rep2] = rep1;
    }
}

int main() {
    int l, tc, op;
    cin >> l >> tc;
    v.resize(l);
    for (int i = 0; i < l; i++) {
        v[i] = i;
    }

    while(tc--) {
        cin >> op;
        switch(op) {
            case 1:
                for (auto& elm : v) {
                    cout << elm << " ";
                }
                cout << endl;
                break;
            
            case 2:
                int num;
                cin >> num;
                cout << find(num) << endl;
                break;

            case 3:
                int num1, num2;
                cin >> num1 >> num2;
                Union(num1, num2);
                for (auto& elm : v) {
                    cout << elm << " ";
                }
                cout << endl;
                break;
        }
    }
}
