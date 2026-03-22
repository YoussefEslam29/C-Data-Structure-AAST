#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int max(Node* list)
{
    if (list == NULL)
    {
        cout << "List is empty" << endl;
        return -1;
    }
    Node*p = list;
    int max = p->data;
    while (p!=NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int min (Node* list)
{
    if(list == NULL)
    {
        cout<<"list is empty"<<endl;
        return -1;
    }
}

int Count(struct Node* list)
{
    int count = 0;
    Node *p;
    p = list;
    while (p!=NULL)
    {
        count ++;
        p= p->next;
    }
    return count;
}

int CountEven(struct Node* list)
{
    int count = 0;
    Node *p;
    p = list;
    while (p!=NULL)
    {
        if (p->data % 2 == 0)
        {
            count ++;
        }
        p= p->next;
    }
    return count;
}
