#include <iostream>
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
        } else {
            cout << "Stack Overflow\n";
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            return '\0';
        }
    }

    char peek() {
        if (top >= 0) {
            return arr[top];
        }
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(const string& expr) {
    Stack s;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.isEmpty() || !isMatchingPair(s.pop(), ch)) {
                return false;
            }
        }
    }

    return s.isEmpty();
}

int main() {
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);

    if (isBalanced(expression)) {
        cout << "Expression is balanced.\n";
    } else {
        cout << "Expression is NOT balanced.\n";
    }

    return 0;
}
