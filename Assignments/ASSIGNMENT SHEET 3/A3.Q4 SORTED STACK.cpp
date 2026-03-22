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
int pop(stack*& s) {
    if (s == NULL) {
        return -1; 
    }
    stack* temp = s;
    int data = temp->data;
    s = s->next;
    delete temp;
    return data;
}
int isEmpty(stack*& s) {
    if (s == NULL) {
        return 1;
    }
    else return 0;
}
bool checksorted(stack*& s) {
    stack* stemp = NULL;
    int prev = pop(s);
    push(stemp, prev);
    while (isEmpty(s) == 0) {
        int curr = pop(s);
        if (curr < prev) {
            while (isEmpty(stemp) == 0) {
                push(s, pop(stemp));
            }
            return false;
        }
        push(stemp, curr);
        prev = curr;
    }
    while (isEmpty(stemp) == 0) {
        push(s, pop(stemp));
    }
    return true;
}
int main() {
    stack* s = NULL;
    int n, x;
    cout << "Enter the number of elements: ";
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(s, x);
    }
    if (checksorted(s)) {
        cout << "Stack is sorted" << endl;
    }
    else {
        cout << "Stack is not sorted" << endl;
    }
    return 0;
}

