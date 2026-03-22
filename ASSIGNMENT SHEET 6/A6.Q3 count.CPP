#include <iostream>
using namespace std;

struct Node
{
      int data;
      Node *left;
      Node *right;
};

int countNodes(Node *root)
{
      if (root == NULL)
      {
            return 0;
      }
      return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node *root)
{
      if (root == NULL)
      {
            return 0;
      }
      if (root->left == NULL && root->right == NULL)
      {
            return 1;
      }
      return countLeaves(root->left) + countLeaves(root->right);
}
int main()
{
      Node *root = new Node{10, nullptr, nullptr};
      root->left = new Node{5, nullptr, nullptr};
      root->right = new Node{15, nullptr, nullptr};
      root->left->left = new Node{3, nullptr, nullptr};
      root->left->right = new Node{7, nullptr, nullptr};

      cout << "Total number of nodes: " << countNodes(root) << endl;
      cout << "Total number of leaves: " << countLeaves(root) << endl;

      return 0;
}