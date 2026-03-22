#include <iostream>
using namespace std;

struct stack { int data; stack* next; };

double evaluatePostfix(string exp) {
    stack* top = nullptr;
    for (char c : exp) {
        if (isdigit(c)) {
           
            top = new stack{c - '0', top};
        } else {
            int op2 = top->data;
            stack* temp = top;
            top = top->next;
            delete temp;

            int op1 = top->data;
            temp = top;
            top = top->next;
            delete temp;

            if (c == '+') {
                top = new stack{op1 + op2, top};
            } else if (c == '-') {
                top = new stack{op1 - op2, top};
            } else if (c == '*') {
                top = new stack{op1 * op2, top};
            } else if (c == '/') {
                if (op2 != 0) {
                    top = new stack{op1 / op2, top};
                } else {
                    cout << "Error: Division by zero\n";
                    return 0;
                }
            } else {
                cout << "Error: Invalid operator\n";
                return 0;
            }
        }
    }
    double result = top->data;
    delete top;
    return result;
}

int main() {
    string exp;
    cout << "Enter a postfix expression: ";
    cin >> exp;
    double result = evaluatePostfix(exp);
    cout << "Result: " << result << endl;
    return 0;
}
