#include <iostream>
 using namespace std;

 struct queue{
    int data;
    queue * next;
};

    queue * h = NULL;
    queue * t = NULL;
    
 void enqueue(queue* &h, queue*& t, int x){
    queue *p = new queue;
    p->data = x;
    p->next = NULL;
    if (t != NULL){
        t->next = p;
        t=p;
    }
    else{
        h = p;
        t = p;
    }
 }

    void dequeue(queue*& h, queue*& t){
        int x = h ->data;
        queue *p = h;
        h = h->next;
        delete p;
        if (h == NULL){
            t = NULL;
        }
        return x;
    }

 void print(queue*& h, queue*& t){
        queue *temp = h;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int main(){
        int n, x;
        cout << "Enter the number of elements: ";
        cin >> n;
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++){
            cin >> x;
            enqueue(h, t, x);
        }
        cout << "Queue after insertion: ";
        print(h, t);
        
        cout << "Dequeue element: " << dequeue(h, t) << endl;
        cout << "Queue after dequeue: ";
        print(h, t);
        
        return 0;
    }
