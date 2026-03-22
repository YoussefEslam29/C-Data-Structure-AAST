#include <iostream>
using namespace std;

struct queue {
    int data;
    queue *next;
};

queue* h = NULL;
queue* t = NULL;


void deleteK(queue*& h, queue*& t, int k) 
{
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