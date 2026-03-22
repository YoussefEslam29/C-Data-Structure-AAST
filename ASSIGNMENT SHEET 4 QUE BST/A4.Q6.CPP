#include <iostream>
using namespace std;

struct queue {
    int data;
    queue* next;
};

void swapFL(queue*& h, queue*& t) {
    if (h == NULL || h->next == NULL) {
        return;
    }

    queue* first = h;
    queue* second = h->next;

    first->next = second->next;
    second->next = first;
    h = second;

    if (first->next == NULL) {
        t = first;
    } else {
        t = first->next;
    }
}

int main() {
    queue* h = NULL;
    queue* t = NULL;

    int n, x;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        queue* p = new queue;
        p->data = x;
        p->next = NULL;
        if (t != NULL) {
            t->next = p;
            t = p;
        } else {
            h = p;
            t = p;
        }
    }
    return 0;
}

