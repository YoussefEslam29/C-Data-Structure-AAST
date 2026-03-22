#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertkey(Node*& head, int key) {
    Node* newNode = new Node();
    newNode->data = key;
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

void deletekey(Node*& head, int key) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* T = head;
    Node* prev = NULL;
    do {
        if (T->data == key) {
            if (prev == NULL) { 
                Node* temp = head;
                while (temp->next != head) temp = temp->next;
                if (head == head->next) { 
                    delete head;
                    head = NULL;
                } else {
                    temp->next = head->next;
                    delete head;
                    head = temp->next;
                }
            } else {
                prev->next = T->next;
                delete T;
            }
            return;
        }
        prev = T;
        T = T->next;
    } while (T != head);
    cout << "Key not found" << endl;
}

void print(Node* head) {
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
   int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> key;
        insertkey(head, key);
    }
    print(head);

    cout << "Enter the key to delete: ";
    cin >> key;
    deletekey(head, key);
    print(head);
    cout << "Enter the key to insert: ";
    cin >> key;
    insertkey(head, key);
    print(head);
    return 0;
}