#include <iostream>
#include <string>
using namespace std;


struct node // stack push and pop
{
    int data;

class stack
{
    private:
        node *top;
    public:
        stack()
        {
            top = NULL;
        }
        void push(int x);
        void pop();
        void display();
        void delete_elements(int n, int k);

};

void stack::push(int x)
{
    node *t = new node;
    t->data = x;
    t->next = top;
    top = t;
}
void stack::pop()
{
    if(top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    node *t = top;
    top = top->next;
    delete t;
}

void stack::display()
{
    node *t = top;
    while(t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

void stack::delete_elements(int n, int k)
{
    node *t = top;
    node *temp = top;
    int count = 0;
    while(t != NULL)
    {
        count++;
        if(count == n)
        {
            for(int i = 0; i < k; i++)
            {
                node *temp = t;
                t = t->next;
                delete temp;
            }
            temp->next = t;
            break;
        }
        temp = t;
        t = t->next;
    }
}