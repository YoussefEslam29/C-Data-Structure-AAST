#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void swapadjacent(Node* list) {
    Node* p = list;
    Node* q = p->next;
    while (p != NULL && q != NULL) {
        int temp = p->data;
        p->data = q->data;
        q->data = temp;
        p = q->next;
        if (p != NULL) {
            q = p->next;
        }
    }
    while (list != NULL) {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
}

void print(Node* list) {
    Node* p = list;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
 
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();  

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    print(first);
    swapadjacent(first);

    return 0;
}