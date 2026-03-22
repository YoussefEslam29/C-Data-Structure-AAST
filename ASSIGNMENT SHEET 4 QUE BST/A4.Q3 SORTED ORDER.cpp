#include <iostream>
using namespace std;

struct queue {
    int data;
    queue* next;
};

int mergesorted(queue*& h1, queue*& t1, queue*& h2, queue*& t2) {
    queue* mergedHead = NULL;
    queue* mergedTail = NULL;

    while (h1 != NULL && h2 != NULL) {
        if (h1->data < h2->data) {
            if (mergedHead == NULL) {
                mergedHead = h1;
                mergedTail = h1;
            } else {
                mergedTail->next = h1;
                mergedTail = mergedTail->next;
            }
            h1 = h1->next;
        } else {
            if (mergedHead == NULL) {
                mergedHead = h2;
                mergedTail = h2;
            } else {
                mergedTail->next = h2;
                mergedTail = mergedTail->next;
            }
            h2 = h2->next;
        }
    }

    if (h1 != NULL) {
        if (mergedHead == NULL) {
            mergedHead = h1;
        } else {
            mergedTail->next = h1;
        }
    } else if (h2 != NULL) {
        if (mergedHead == NULL) {
            mergedHead = h2;
        } else {
            mergedTail->next = h2;
        }
    }

    t1 = mergedTail; 
    return 0; 
}

void print(queue*& h, queue*& t) {
    queue* temp = h;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
