#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

bool find_rec(Node* head, int key, Node* current = nullptr) {
    if (head == NULL) {
        return false;
    }
    if (current == NULL) {
        current = head;
    }
    if (current->data == key) {

        return true;
    }
    if (current->next == head) {
        return false;
    }
    return find_rec(head, key, current->next);
}

bool find_nonrec(Node* head, int key) {
    if (head == NULL) {
        return false;
    }
    Node* T = head;
    do {
        if (T->data == key) {

            return true;
        }
        T = T->next;
    } while (T != head);
    return false;
}

void printcircular(Node* head) {
    Node* T = head;
    do {
        cout << T->data << " ";
        T = T->next;
    } while (T != head);
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = NULL;
    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node();
        newNode->data = arr[i];
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
    printcircular(head);
    int key = 3;
    if (find_rec(head, key)) {
        cout  << key << " recursively." << endl;
    } else {
        cout << key << " not found recursively." << endl;
    }
    if (find_nonrec(head, key)) {
        cout << key << " non-recursively." << endl;
    } else {
        cout << key << " not found non-recursively." << endl;
    }


    return 0;
}
