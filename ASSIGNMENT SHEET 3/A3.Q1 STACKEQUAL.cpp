#include <iostream>
using namespace std;

struct stack {
    int data;
    stack* next;
};

void push(stack*& s, int data) {
    stack* n = new stack;
    n->data = data;
    n->next = s;
    s = n;
}

void pop(stack*& s) {
    if (s == NULL) {
        return;
    }
    stack* temp = s;
    s = s->next;
    delete temp;
}

void StackEqual(stack*& s1, stack*& s2) {
    if (s1 == NULL && s2 == NULL) {
        cout << "Both stacks are empty" << endl;
        return;
    }
    if (s1 == NULL || s2 == NULL) {
        cout << "Stacks are not equal" << endl;
        return;
    }

    stack* temp1 = s1;
    stack* temp2 = s2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) {
            cout << "Stacks are not equal" << endl;
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 == NULL && temp2 == NULL) {
        cout << "Stacks are equal" << endl;
    } else {
        cout << "Stacks are not equal" << endl;
    }
}

int main() {
    stack* s1 = NULL;
    stack* s2 = NULL;
    int n, x;
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> x;
        push(s1, x);
    }
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> x;
        push(s2, x);
    }
    StackEqual(s1, s2);

    return 0;
}