#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void insertstart(Node** head, int value) {
    Node* newnode = new Node(value);
    newnode->next = *head;
    *head = newnode;
}

void insertmiddle(Node* prev, int value) {
    if (prev == nullptr) {
        cout << "The given previous node cannot be null";
        return;
    }
    Node* newnode = new Node(value);
    newnode->next = prev->next;
    prev->next = newnode;
}

void insertend(Node** head, int value) {
    Node* newnode = new Node(value);
    if (*head == nullptr) {
        *head = newnode;
        return;
    }
    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newnode;
}

void deletestart(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty";
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

void deletemiddle(Node* prev) {
    if (prev == nullptr || prev->next == nullptr) {
        cout << "The given previous node cannot be null";
        return;
    }
    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}

void deleteend(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty";
        return;
    }
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != nullptr) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void print(Node* list) {
    while (list != nullptr) {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertend(&head, 1);
    insertstart(&head, 2);
    insertstart(&head, 3);
    insertend(&head, 4);
    insertmiddle(head->next, 5);
    print(head);
    deletestart(&head);
    deletemiddle(head->next);
    deleteend(&head);
    print(head);
    return 0;
}
