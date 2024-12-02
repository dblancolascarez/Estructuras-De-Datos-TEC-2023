#include <iostream>
#include <string>
#include <stack>

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

using namespace std;

string infixToPostfix(string infix) {
    string postfix = "";
    stack<char> s;
    for (int i = 0; i < infix.length(); i++) {
        if (isdigit(infix[i])) {
            // Scan for consecutive digits and append them to the output string
            int j = i;
            while (j < infix.length() && isdigit(infix[j])) {
                postfix += infix[j];
                j++;
            }
            postfix += " ";
            i = j - 1;
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && s.top() != '(' && precedence(infix[i]) <= precedence(s.top())) {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        postfix += " ";
        s.pop();
    }
    // Remove trailing whitespace
    postfix.erase(postfix.length() - 1);
    return postfix;
}

string postfixToInfix(string postfix) {
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            // Scan for consecutive digits and append them to a string
            string operand = "";
            int j = i;
            while (j < postfix.length() && isdigit(postfix[j])) {
                operand += postfix[j];
                j++;
            }
            s.push(operand);
            i = j - 1;
        }
        else if (postfix[i] == ' ') {
            // Do nothing
        }
        else {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            string expr = "(" + operand1 + " " + postfix[i] + " " + operand2 + ")";
            s.push(expr);
        }
    }
    return s.top();
}


int main() {
    string input;
    int choice;
    cout << "Menu:" << endl;
    cout << "1. Enter an infix expression" << endl;
    cout << "2. Enter a postfix expression" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    cin.ignore();
    if (choice == 1) {
        cout << "Enter an infix expression: ";
        getline(cin, input);
        string postfix = infixToPostfix(input);
        cout << "The postfix expression is: " << postfix << endl;
    }
    else if (choice == 2) {
        cout << "Enter a postfix expression: ";
        getline(cin, input);
        string infix = postfixToInfix(input);
        cout << "The infix expression is: " << infix << endl;
    }
    else {
        cout << "Invalid choice" << endl;
    }
    return 0;
}
