#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int getPrecedence(char op) {
    if (op == '*' || op == '/'|| op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix (string s) {
    stack<char> st; 
    string postFix;
    for(int i = 0; i < s.length(); i++) {
        if (isOperand(s[i])) {
            postFix += s[i];
        }
        else if (s[i] == '(') {
            st.push('(');
        }
        else if (s[i] == ')') {
            while(st.top() != '(') {
                postFix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && getPrecedence(s[i]) <= getPrecedence(st.top())) {
                postFix += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        postFix += st.top();
        st.pop();
    }
    return postFix;
}
