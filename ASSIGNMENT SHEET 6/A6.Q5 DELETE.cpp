#include <iostream>
using namespace std;

struct Node
{
      int data;
      Node *left;
      Node *right;
};
void deleteNode(Node *&root, int value)
{
      if (root == NULL)
      {
            return;
      }
      if (value < root->data)
      {
            deleteNode(root->left, value);
      }
      else if (value > root->data)
      {
            deleteNode(root->right, value);
      }
      else
      {
            if (root->left == NULL)
            {
                  Node *temp = root;
                  root = root->right;
                  delete temp;
            }
            else if (root->right == NULL)
            {
                  Node *temp = root;
                  root = root->left;
                  delete temp;
            }
            else
            {
                  Node *minNode = root->right;
                  while (minNode->left != NULL)
                  {
                        minNode = minNode->left;
                  }
                  root->data = minNode->data;
                  deleteNode(root->right, minNode->data);
            }
      }
}
int main()
{
      Node *root = new Node{10, nullptr, nullptr};
      root->left = new Node{5, nullptr, nullptr};
      root->right = new Node{15, nullptr, nullptr};

      int valueToDelete;
      cout << "Enter value to delete: ";
      cin >> valueToDelete;

      deleteNode(root, valueToDelete);


      return 0;
}