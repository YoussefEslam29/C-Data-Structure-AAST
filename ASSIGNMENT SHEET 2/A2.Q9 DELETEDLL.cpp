#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

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

int deletekey(Node*& head, int key) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return -1;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            if (temp->prev == NULL) { 
                head = temp->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
            }
            delete temp;
            return 0;
        }
        temp = temp->next;
    }
    cout << "Key not found" << endl;
    return -1; 
}

void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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
    
    int key;
    cout << "Enter the key to delete: ";
    cin >> key;
    if (deletekey(head, key) == 0) {
        cout << "List after deletion: ";
        print(head);
    }
    
    return 0;
}