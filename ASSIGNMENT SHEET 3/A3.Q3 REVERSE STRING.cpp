#include <iostream>
using namespace std;

struct stack {
    char data;
    stack *next;
};

void push(stack *&s, int data) {
    stack *n = new stack;
    n->data = data;
    n->next = s;
    s = n;
}

void pop(stack *&s) {
    if (s == NULL) {
        return;
    }
    stack *temp = s;
    s = s->next;
    delete (temp);
}

string reverse(stack *&s) {
    string str = "";
    stack *stemp = NULL;
    while (s != NULL) {
        char x = s->data;
        str += x;
        push(stemp, x);
        pop(s);
    }
    while (stemp != NULL) {
        char x = stemp->data;
        push(s, x);
        pop(stemp);
    }
    return str;
}

int main() {
    stack *s = NULL;

    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        push(s, c);
    }

    string reversed = reverse(s);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
