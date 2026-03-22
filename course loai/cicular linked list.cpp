#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};

int printprev(node*Dlist)
{
    if (Dlist!=NULL)
    {
        node*p=Dlist;
        while( p->next!=NULL)
        p=p->next;

        while(p!=NULL)
        {
            cout<<p -> data;
            p=p -> prev;
        }
    }
}