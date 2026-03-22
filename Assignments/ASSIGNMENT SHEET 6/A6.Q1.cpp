#include <iostream>
using namespace std;

struct Node
{
      int data;
      Node *left;
      Node *right;
};

Node *createNode(int value)
{
      Node *newNode = new Node();
      newNode->data = value;
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode;
}

Node *insertNode(Node *root, int value)
{
      if (root == NULL)
      {
            return createNode(value);
      }
      if (value < root->data)
      {
            root->left = insertNode(root->left, value);
      }
      else
      {
            root->right = insertNode(root->right, value);
      }
      return root;
}
void insertNodeInLinkedList(Node *&head, int data)
{
      Node *newNode = new Node();
      newNode->data = data;
      newNode->right = NULL;
      newNode->left = NULL;

      if (head == NULL)
      {
            head = newNode;
            return;
      }

      Node *temp = head;
      while (temp->right != NULL)
      {
            temp = temp->right;
      }
      temp->right = newNode;
      newNode->left = temp;
}
void InOrderTraversal(Node *root)
{
      if (root == NULL)
      {
            return;
      }
      InOrderTraversal(root->left);
      cout << root->data << " ";
      InOrderTraversal(root->right);
}
int main()
{
      Node *Head = NULL;
      int x, n;
      cin >> n;
      for (int i = 0; i < n; i++)
      {
            cin >> x;
            insertNodeInLinkedList(Head, x);
      }

      Node *root = NULL;
      Node *current = Head;
      while (current != NULL)
      {
            root = insertNode(root, current->data);
            current = current->right;
      }

      cout << "In-order traversal of the BST: ";
      InOrderTraversal(root);
      cout << endl;

      return 0;
}