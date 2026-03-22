//Q6.A
//infix: 6 * 7 * 2 + 2 * 10 – 2
// postfix: 6 7 * 2 * 2 10 * 2 - +

//Q6.B ITS NOT BALANCED  missing (parenthesis)
//infix: (A+B*(C+(D+E)-F)
// postfix: A B C D E + F - * +
#include <iostream>

using namespace std;

struct stack {
    int data;
    stack* next;
};

double evaluatePostfix(string exp) 
{
    stack* top = nullptr;
    for (char c : exp) {
        if (isdigit(c)) {
            stack* newNode = new stack{c - '0', top};
            top = newNode;
        } else {
            int op2 = top->data;
            stack* temp = top;
            top = top->next;
            delete temp;

            int op1 = top->data;
            temp = top;
            top = top->next;
            delete temp;

            switch (c) {
                case '+':
                    top = new stack{op1 + op2, top};
                    break;
                case '-':
                    top = new stack{op1 - op2, top};
                    break;
                case '*':
                    top = new stack{op1 * op2, top};
                    break;
                case '/':
                    if (op2 != 0) {
                        top = new stack{op1 / op2, top};
                    } else {
                        cout << "Error: Division by zero" << endl;
                        return 0;
                    }
                    break;
                default:
                    cout << "Error: Invalid operator" << endl;
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
    