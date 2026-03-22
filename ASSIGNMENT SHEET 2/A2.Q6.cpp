#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};

void reverse(Node*& head) {
    Node* curr = head;
    Node* next = curr->next;
    curr->next = NULL;
    curr->prev = next;
    while (next != NULL) {
        next->prev = next->next;
        next->next = curr;
        curr = next;
        next = next->prev;
    }
    head = curr;
}

void insert(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void print(Node*& head) {
    Node* temp = head;
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    if (head->next == NULL) {
        cout << head->data << endl;
        return;
    }
    while (temp->next != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main() {
    Node* head = NULL;
    int n, value;
    cout << "Enter the number of elements to insert: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insert(head, value);
    }
    cout << "Original List: ";
    print(head);
    reverse(head);
    cout << "Reversed List: ";
    print(head);
    return 0;
}