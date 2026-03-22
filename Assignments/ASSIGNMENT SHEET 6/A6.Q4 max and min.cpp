#include <iostream>
using namespace std;

struct Node
{
      int data;
      Node *left;
      Node *right;
};
int findMax(Node *root)
{
      if (root == NULL)
      {
            return;
      }
      if (root->right == NULL)
      {
            return root->data;
      }
      else if (root->right != NULL)
      {
            return findMax(root->right);
      }
      else
      {
            return root->data;
      }
}
int findMin(Node *root)
{
      if (root == NULL)
      {
            return;
      }
      if (root->left == NULL)
      {
            return root->data;
      }
      else if (root->left != NULL)
      {
            return findMin(root->left);
      }
      else
      {
            return root->data;
      }
}
int sumOfNodes(Node *root)
{
      if (root == NULL)
      {
            return 0;
      }
      return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main()
{
      Node *root = new Node{10, nullptr, nullptr};
      root->left = new Node{5, nullptr, nullptr};
      root->right = new Node{15, nullptr, nullptr};

      cout << "Maximum value in the BST: " << findMax(root) << endl;
      cout << "Minimum value in the BST: " << findMin(root) << endl;
      cout << "Sum of all nodes in the BST: " << sumOfNodes(root) << endl;

      return 0;
}