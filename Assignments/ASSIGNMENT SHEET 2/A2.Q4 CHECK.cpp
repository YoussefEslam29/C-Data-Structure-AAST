/*Function isCircular(head):
    If head is NULL:
        Return false

    Initialize slowPointer = head
    Initialize fastPointer = head

    While fastPointer is not NULL and fastPointer.next is not NULL:
        Move slowPointer one step forward (slowPointer = slowPointer.next)
        Move fastPointer two steps forward (fastPointer = fastPointer.next.next)

        If slowPointer is equal to fastPointer:
            Return true

    Return false
*/
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void isCircular(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* slowPointer = head;
    Node* fastPointer = head;

    while (fastPointer != NULL && fastPointer->next != NULL) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;

        if (slowPointer == fastPointer) {
            cout << "List is circular" << endl;
            return;
        }
    }
    cout << "List is not circular" << endl;
}
bool isCircularRec(Node* head, Node* slowPointer = nullptr, Node* fastPointer = nullptr) {
    if (head == NULL) {
        return false;
    }
    if (slowPointer == NULL && fastPointer == NULL) {
        slowPointer = head;
        fastPointer = head;
    }
    if (fastPointer == NULL || fastPointer->next == NULL) {
        return false;
    }
    if (slowPointer == fastPointer) {
        return true;
    }
    return isCircularRec(head, slowPointer->next, fastPointer->next->next);
}
int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = head; // Making it circular
    isCircular(head);
    if (isCircularRec(head)) {
        cout << "List is circular (recursive)" << endl;
    } else {
        cout << "List is not circular (recursive)" << endl;
    }
    delete head;
    delete second;
    return 0;
}
