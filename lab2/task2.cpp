#include <iostream>
#include <string>
using namespace std;

struct Student {
    int reg_number;
    string name;
    int age;
    float cgpa;
};

int main() {
    Student stds[4];
    for(int i = 0; i < 4; i++) {
        cout << "Enter data of student " << i+1 << ": ";
        cout << "Reg. No: ";
        cin >> stds[i].reg_number;
        cin.ignore();
        cout << "Name: ";
        getline(cin, stds[i].name);
        cout << "Age: ";
        cin >> stds[i].age;
        cout << "CGPA: ";
        cin >> stds[i].cgpa;
    }
    cout << "The entered data is:\n";
    for(int i = 0; i < 4; i++) {
        cout << "\nStudent " << i+1 << ": ";
        cout << "\nReg. No: " << stds[i].reg_number;
        cout << "\nName: " << stds[i].name;
        cout << "\nAge: " << stds[i].age;
        cout << "\nCGPA: " << stds[i].cgpa;
    }
}