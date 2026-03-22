#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
int max(Node* list) {
    int max = list->data;
    Node* p = list;
    while (p != NULL) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int min(Node* list) {
    int min = list->data;
    Node* p = list;
    while (p != NULL) {
        if (p->data < min) {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

int countNodes(Node* list) {
    int count = 0;
    Node* p = list;
    while ( p != NULL) {
        count++;
     p = p->next;
    }
    return count;
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

    cout << "Max: " << max(first) << endl;
    cout << "Min: " << min(first) << endl;
    cout << "Count: " << countNodes(first) << endl;
    return 0;
}