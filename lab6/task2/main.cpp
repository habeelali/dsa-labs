#include <iostream>
#include "studentlist.h"
using namespace std;

int main() {
    Node* head = nullptr;
    int choice;

    do {
        cout << "\n1. Add Student\n2. Display Students\n3. Save to File\n4. Load from File\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Student s;
            cout << "Enter Reg No: ";
            getline(cin, s.reg_no);
            cout << "Enter Name: ";
            getline(cin, s.name);
            cout << "Enter DOB (dd/mm/yyyy): ";
            getline(cin, s.dob);
            cout << "Enter Semester: ";
            cin >> s.semester;
            cout << "Enter 5 Course Marks: ";
            for (int i = 0; i < 5; ++i)
                cin >> s.marks[i];
            cin.ignore();
            insertAtEnd(head, s);
        } else if (choice == 2) {
            display(head);
        } else if (choice == 3) {
            saveToFile(head, "students.txt");
        } else if (choice == 4) {
            loadFromFile(head, "students.txt");
        }

    } while (choice != 0);

    return 0;
}
