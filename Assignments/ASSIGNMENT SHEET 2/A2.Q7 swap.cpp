#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insert (Node*& head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void swap(Node*& head, int x, int y)
{
    if (x == y) return;

    Node* prevX = NULL;
    Node* currX = head;
    while (currX != NULL && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    Node* prevY = NULL;
    Node* currY = head;
    while (currY != NULL && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL) {
        cout << "One or both elements not found" << endl;
        return;
    }

    if (prevX != NULL) {
        prevX->next = currY;
    } else {
        head = currY;
    }
    
    if (prevY != NULL) {
        prevY->next = currX;
    } else {
        head = currX;
    }

    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

}
void print(Node*& head)
{
    Node* temp = head;
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    if (head->next == NULL) {
        cout << head->data << endl;
        return;
    }
    while (temp->next != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main()
{
    Node* head = NULL;
    int n, value;
    cout << "Enter the number of elements to insert: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter value: ";
        cin >> value;
        insert(head, value);
    }
    cout << "Original list: ";
    print(head);
    
    int x, y;
    cout << "Enter two values to swap: ";
    cin >> x >> y;
    
    swap(head, x, y);
    
    cout << "List after swapping: ";
    print(head);
    
    return 0;
}