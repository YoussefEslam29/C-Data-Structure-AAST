#include <iostream>
using namespace std;

struct queue {
    int data;
    queue* next;
};

void insert(queue*& h, queue*& t, int k) {
    queue* p = new queue;
    p->data = k;
    p->next = NULL;
    if (t != NULL) {
        t->next = p;
        t = p;
    } else {
        h = p;
        t = p;
    }
}

void deleteK(queue*& h, queue*& t, int k) {
    queue* temp = h;
    queue* prev = NULL;

    while (temp != NULL) {
        if (temp->data == k) {
            if (prev == NULL) {
                h = temp->next;
                delete temp;
                temp = h;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    t = prev; 
}

