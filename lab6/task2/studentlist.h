// studentlist.h

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string reg_no;
    string name;
    string dob;
    int semester;
    int marks[5];
};

struct Node {
    Student data;
    Node* next;
};

void insertAtEnd(Node* &head, Student s) {
    Node* newNode = new Node{s, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
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

void display(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    while (head) {
        cout << "\n--- Student Info ---\n";
        cout << "Reg No: " << head->data.reg_no << "\n";
        cout << "Name: " << head->data.name << "\n";
        cout << "DOB: " << head->data.dob << "\n";
        cout << "Semester: " << head->data.semester << "\n";
        cout << "Marks: ";
        int sum = 0;
        for (int i = 0; i < 5; ++i) {
            cout << head->data.marks[i] << " ";
            sum += head->data.marks[i];
        }
        cout << "\nAverage: " << (sum / 5.0) << "\n";
        head = head->next;
    }
}

void saveToFile(Node* head, const string& filename) {
    ofstream file(filename);
    while (head) {
        file << head->data.reg_no << "\n"
             << head->data.name << "\n"
             << head->data.dob << "\n"
             << head->data.semester << "\n";
        for (int i = 0; i < 5; ++i)
            file << head->data.marks[i] << " ";
        file << "\n";
        head = head->next;
    }
    file.close();
    cout << "List saved to file successfully.\n";
}

void loadFromFile(Node* &head, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Unable to open file.\n";
        return;
    }

    Student s;
    while (file >> ws && getline(file, s.reg_no)) {
        getline(file, s.name);
        getline(file, s.dob);
        file >> s.semester;
        for (int i = 0; i < 5; ++i)
            file >> s.marks[i];
        file.ignore();
        insertAtEnd(head, s);
    }
    file.close();
    cout << "Data loaded from file.\n";
}

#endif
