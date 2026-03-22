#include <iostream>
using namespace std;

struct Node
{
      int data;
      Node *left;
      Node *right;
};
bool searchNode(Node *root, int key)
{
      while (root != NULL)
      {
            if (key == root->data)
            {
                  return true;
            }
            else if (key < root->data)
            {
                  root = root->left; 
            }
            else
            {
                  root = root->right; 
            }
      }
      return false; 
}
int main ()
{
      Node *root = new Node{10, nullptr, nullptr};
      root->left = new Node{5, nullptr, nullptr};
      root->right = new Node{15, nullptr, nullptr};

      int key;
      cout << "Enter key to search: ";
      cin >> key;

      if (searchNode(root, key))
      {
            cout << "Key " << key << " exists in the BST." << endl;
      }
      else
      {
            cout << "Key " << key << " does not exist in the BST." << endl;
      }

      return 0;
}