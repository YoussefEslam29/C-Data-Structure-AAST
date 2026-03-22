#include <iostream>

using namespace std;

struct stack {
    int data;
    stack* next;
};

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void deletenonprime(stack*& top) {
    if (top == nullptr) {
        cout << "Stack is empty, nothing to delete." << endl;
        return;
    }
    stack* temp = top;
    top = top->next;
    delete temp;
}

void display(stack* top) {
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main() {
    stack* top = nullptr;
    int n, num;
    cout << "Enter the number of elements in the stack: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (isPrime(num)) {
            stack* newNode = new stack{num, top};
            top = newNode;
        } else {
            deletenonprime(top);
        }
    }
    cout << "Stack after deleting non-prime numbers: ";
    display(top);
    return 0;
}