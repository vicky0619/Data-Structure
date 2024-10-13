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

string postfixToInfix(string postfix){
    stack<string> s;
    for(char c : postfix){
        if(isOperator(c)){
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            string expression = "(" + operand1 + c + operand2 + ")";
            s.push(expression);
        }else{
            s.push(string(1, c));
        }
    }
    return s.top();
}

string infixToPrefix(const string& infix) {
    stack<char> operators;
    stack<string> operands;

    for (char c : infix) {
        if (isOperand(c)) {
            operands.push(string(1, c));
        } else if (isOperator(c)) {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                string expression = operators.top() + operand1 + operand2;
                operands.push(expression);
                operators.pop();
            }
            operators.push(c);
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                string expression = operators.top() + operand1 + operand2;
                operands.push(expression);
                operators.pop();
            }
            operators.pop(); // Pop the '('
        }
    }

    while (!operators.empty()) {
        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();
        string expression = operators.top() + operand1 + operand2;
        operands.push(expression);
        operators.pop();
    }

    return operands.top();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        a = postfixToInfix(a);
        string tmp = a + b;
        string prefix = infixToPrefix(tmp);
        cout << prefix << endl;
    }
}