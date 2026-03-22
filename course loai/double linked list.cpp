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

int Rev(node*l1, node*l2)
{
    node*p1 = l1;
    node*p2 = l2;
    if(p2!=NULL)
    {
        while (p2->next!= NULL)
        p2=p2->next;
    }
    while(p1!=NULL && p2!=NULL)
    {
        if (p1 -> data!=p2->data)
            return(0);
        p1=p1->next;
        p2=p2->prev;
    }
    if(p1 == NULL && p2 ==NULL)
        return(1);
return(0);
}

int main() {

    return 0;
}