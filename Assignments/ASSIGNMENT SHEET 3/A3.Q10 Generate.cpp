#include <iostream>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(NULL) {}
};

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
bool isEmpty(stack*& s) {
    if (s == NULL) {
        return true;
    }
    else return false;
}

stack* generateSortedStack(ListNode* head) {
    stack* s = NULL;
    ListNode* current = head;
    while (current != NULL) {
        push(s, current->data);
        current = current->next;
    }
    return s;
}
void display(stack* s) {
    while (s != NULL) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(4);

    stack* sortedStack = generateSortedStack(head);
    cout << "Sorted Stack: ";
    display(sortedStack);

    return 0;
}
