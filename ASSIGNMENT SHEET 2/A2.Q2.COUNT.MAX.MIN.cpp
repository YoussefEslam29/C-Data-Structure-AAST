#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void max(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* T = head;
    int max = T->data;
    do {
        if (T->data > max) {
            max = T->data;
        }
        T = T->next;
    } while (T != head);
    cout << "Max: " << max << endl;
}

void min(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* T = head;
    int min = T->data;
    do {
        if (T->data < min) {
            min = T->data;
        }
        T = T->next;
    } while (T != head);
    cout << "Min: " << min << endl;
}

void count(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* T = head;
    int count = 0;
    do {
        count++;
        T = T->next;
    } while (T != head);
    cout << "Count: " << count << endl;
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
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = head; 

    print(head);
    max(head);
    min(head);
    count(head);

    return 0;
}
   