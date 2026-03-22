#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void odd(Node* list) {
    Node* p = list;
    while (p != NULL) {
        cout << p->data << " ";
        if (p->next != NULL) {
            p = p->next->next;
        }
        else {
            break;
        }
    }
    cout << endl;
}

void even(Node* list) {
    Node* p = list->next;
    while (p != NULL) {
        cout << p->data << " ";
        if (p->next != NULL) {
            p = p->next->next;
        }
        else {
            break;
        }
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
    cout <<"odd:";
    odd(first);
    cout<<"even:";
    even(first);

    return 0;
}