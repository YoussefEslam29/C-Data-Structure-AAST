#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};


void printDOUBLE(Node* head) {
    Node* T = head;
    while  (T != NULL) {
        cout << T->data << " ";
     T = T->next;
    }
    cout << endl;
}


int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();
    head->data = 1;
    head->next = second;
    head->prev = NULL;
    second->data = 2;
    second->next = third;
    second->prev = head;
    third->data = 3;
    third->next = fourth;
    third->prev = second;
    fourth->data = 4;
    fourth->next = fifth;
    fourth->prev = third;
    fifth->data = 5;
    fifth->next = NULL;
    fifth->prev = fourth;
    printDOUBLE(head);
    return 0;
}