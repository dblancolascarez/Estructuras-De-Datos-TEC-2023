#include <iostream>

using namespace std; 

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string infixToPostfix(string infix) {
    string postfix = "";
    stack<char> s;
    for (int i = 0; i < infix.length(); i++) {
        if (isalpha(infix[i])) {
            postfix += infix[i];
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && s.top() != '(' && infix[i] <= s.top()) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
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
        // Do something with the postfix expression
    }
    else {
        cout << "Invalid choice" << endl;
    }
    return 0;
}

