#include <iostream>
#include "linkedList.h"
using namespace std;

int main() {
    Node* head = nullptr;
    int choice, value, pos;

    do {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Delete from Beginning\n5. Delete from End\n6. Delete at Position\n";
        cout << "7. Search\n8. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                insertAtPosition(head, value, pos);
                break;
            case 4:
                deleteFromBeginning(head);
                break;
            case 5:
                deleteFromEnd(head);
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPosition(head, pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                search(head, value);
                break;
            case 8:
                display(head);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}
