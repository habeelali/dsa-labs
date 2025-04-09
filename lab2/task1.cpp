#include <iostream>
using namespace std;

int add(int& op1, int& op2) { return op1 + op2; }
int sub(int& op1, int& op2) { return op1 - op2; }
int mul(int& op1, int& op2) { return op1 * op2; }
int dvd(int& op1, int& op2) { return op1 / op2; }

int main() {
    int op1, op2;
    int choice;
    while(1) {
        cout << "Operand 1: ";
        cin >> op1;
        cout << "Operand 2: ";
        cin >> op2;
        cout << "Select an option:\n";
        cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n";
        cout << "\nChoice: ";
        cin >> choice;
        int result;
        switch(choice) {
            case 1:
                result = add(op1, op2);
                break;
            case 2:
                result = sub(op1, op2);
                break;
            case 3:
                result = mul(op1, op2);
                break;
            case 4:
                result = dvd(op1, op2);
                break;
            default:    
                return 0;
        }
        cout << "Result: " << result << "\n";
    }
}