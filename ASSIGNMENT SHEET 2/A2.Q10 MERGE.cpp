#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insert(Node*& head, int data) {
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

Node *merge(Node*& head1, Node*& head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }

    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }

    temp1->next = head2;
    head2->prev = temp1;
   

    return head1;
}
void print(Node*& head) {
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n, value;

    cout << "Enter the number of elements for the first list: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insert(head1, value);
    }

    cout << "Enter the number of elements for the second list: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insert(head2, value);
    }

    cout << "First list: ";
    print(head1);
    cout << "Second list: ";
    print(head2);

    Node* mergedHead = merge(head1, head2);

    cout << "Merged list: ";
    print(mergedHead);

    return 0;
}
