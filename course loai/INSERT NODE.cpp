#include <iostream>

using namespace std;
struct node{
    int data;
    node *next;
};
node* head = NULL;

void insert(node *list, int value)
{
    node *t= new node;
    t->data = value;
    t->next = NULL;
    if (head == NULL)
    {
        head = t;
        t->next = NULL;
    }
    else
    {
        while(list->next != NULL)
        {
            list = list->next;
        }
        list->next = t;
    }
    
}

int main() {

    return 0;
}