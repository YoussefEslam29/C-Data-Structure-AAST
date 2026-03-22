#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void sortedlist(Node* L1, Node* L2) {
    Node* p = L1;
    Node* q = L2;
    Node* r = NULL;
    Node* s = NULL;
    Node* t = NULL;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            r = p;
            p = p->next;
        }
        else {
            if (r != NULL) {
                r->next = q;
            }
            s = q->next;
            q->next = p;
            r = q;
            q = s;
        }
    }
    if (q != NULL) {
        r->next = q;
    }
    while (L1 != NULL) {
        cout << L1->data << " ";
        L1 = L1->next;
    }
    cout << endl;
}

void

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
    
    
    return 0;
}