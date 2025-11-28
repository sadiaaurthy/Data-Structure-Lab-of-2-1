#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char ch : exp) {
       
        if (isdigit(ch)) {
            st.push(ch - '0');   
        }
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.top();
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string exp;
        cin >> exp;

        cout << evaluatePostfix(exp) << endl;
    }
    return 0;
}