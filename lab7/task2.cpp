#include <iostream>
#include <cstring>
using namespace std;

class Stack {
private:
    char arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char ch) {
        if (top < 99) {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (top >= 0)
            return arr[top--];
        return '\0';
    }

    char peek() {
        if (top >= 0)
            return arr[top];
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(const string& infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isOperand(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(') {
                s.pop();
            }
        }
        else { // Operator
            while (!s.isEmpty() &&
                  ((precedence(ch) < precedence(s.peek())) ||
                   (precedence(ch) == precedence(s.peek()) && !isRightAssociative(ch))) &&
                   s.peek() != '(') {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
