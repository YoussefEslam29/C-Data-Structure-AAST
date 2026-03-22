#include <iostream>
using namespace std;

struct queue {
    int data;
    queue* next;
};

void reverse(queue*& h, queue*& t) {
    queue* prev = NULL;
    queue* current = h;
    queue* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    t = h;
    h = prev;
}