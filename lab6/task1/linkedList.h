#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void insertAtEnd(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPosition(Node* &head, int value, int position) {
    if (position <= 1 || head == nullptr) {
        insertAtBeginning(head, value);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++)
        temp = temp->next;
    
    Node* newNode = new Node{value, nullptr};
    if (temp == nullptr) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning(Node* &head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node* &head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void deleteAtPosition(Node* &head, int position) {
    if (head == nullptr || position <= 1) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp->next != nullptr && i < position - 1; i++)
        temp = temp->next;

    if (temp->next == nullptr) return;

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

void search(Node* head, int value) {
    int position = 1;
    while (head != nullptr) {
        if (head->data == value) {
            cout << "Value found at position " << position << endl;
            return;
        }
        head = head->next;
        position++;
    }
    cout << "Value not found.\n";
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Linked List: ";
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

