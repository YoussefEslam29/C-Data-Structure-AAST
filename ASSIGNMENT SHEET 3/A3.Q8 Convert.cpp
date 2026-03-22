#include <iostream>
using namespace std;
 struct stack { 
    int data; 
    stack* next;
};

void decimalToBinary(int n) {
    stack* top = nullptr;
    while (n > 0) {
        top = new stack{n % 2, top};
        n /= 2;
    }
    while (top != nullptr) {
        cout << top->data;
        stack* temp = top;
        top = top->next;
        delete temp;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
    cout << "Binary representation: ";
    decimalToBinary(n);
    return 0;
}