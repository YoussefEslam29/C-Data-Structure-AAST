#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int Print_lots(Node* L, Node* P) {
    Node* p = P;
    int count = 0;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
        count++;
    }
    while (L != NULL)
    {
        cout << L->data << " ";
        L = L->next;
    }

    if (L != NULL)
    {
        cout << L->data << " ";
        L = L->next;
    }

    cout << endl;
    return count;
}
    

int main() {

    Node* L = new Node{10, nullptr};
    L->next = new Node{20, nullptr};
    L->next->next = new Node{30, nullptr};
    L->next->next->next = new Node{40, nullptr};
    L->next->next->next->next = new Node{50, nullptr};

    Node* P = new Node{1, nullptr};
    P->next = new Node{3, nullptr};
    P->next->next = new Node{7, nullptr};

    Print_lots(L, P);

    delete L->next->next->next->next;
    delete L->next->next->next;
    delete L->next->next;
    delete L->next;
    delete L;
    
    delete P->next->next;
    delete P->next;
    delete P;
   
    return 0;
}