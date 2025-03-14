#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool isBalanced(const string &s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } 
        else {
            if (st.empty()) {
                return false;
            }
            char topChar = st.top();
            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (true) {
        if (!getline(cin, line)) {
            break;  
        }
        
        if (isBalanced(line)) {
            cout << "Valid\n";
        } else {
            cout << "Invalid\n";
        }
    }

    return 0;
}
