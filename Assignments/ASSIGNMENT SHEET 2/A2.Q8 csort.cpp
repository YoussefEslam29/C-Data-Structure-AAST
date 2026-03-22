#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertcircular(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* T = head;
        while (T->next != head) T = T->next;
        T->next = newNode;
        newNode->next = head;
    }
}

void sortedcircular(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* T = head;
        Node* prev = NULL;
        do {
            if (T->data > data) {
                break;
            }
            prev = T;
            T = T->next;
        } while (T != head);

        if (prev == NULL) { 
            newNode->next = head;
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            head = newNode;
        } else {
            prev->next = newNode;
            newNode->next = T;
        }
    }
}

void printcircular(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* T = head;
    do {
        cout << T->data << " ";
        T = T->next;
    } while (T != head);
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, value;
    cout << "Enter the number of elements to insert: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertcircular(head, value);
    }
    cout << "Original List: ";
    printcircular(head);

    int newValue;
    cout << "Enter a new value to insert in sorted order: ";
    cin >> newValue;
    sortedcircular(head, newValue);
    
    cout << "List after inserting " << newValue << ": ";
    printcircular(head);

    return 0;
}
