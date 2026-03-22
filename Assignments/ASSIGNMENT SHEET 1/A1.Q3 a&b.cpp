#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int select(Node* list, int n) {
    Node* p = list;
    for (int i = 0; i < n; i++) {
        p = p->next;
    }
    return p->data;
}

int selectrec(Node* list, int n) {
    if (n == 0) {
        return list->data;
    }
    return selectrec(list->next, n - 1);
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

    int x;
    cin >> x;

    cout << "non-recursive " << select(first, x) << endl;
    cout << "Recursive " << selectrec(first, x) << endl;
    return 0;
}