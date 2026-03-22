#include <iostream>
using namespace std;

struct Node
{
      int data;
      Node *left;
      Node *right;
};

bool areIdentical(Node *root1, Node *root2)
{
      if (root1 == NULL && root2 == NULL)
      {
            return true; // Both trees are empty
      }
      if (root1 == NULL || root2 == NULL)
      {
            return false; // One tree is empty, the other is not
      }
      return (root1->data == root2->data) &&
             areIdentical(root1->left, root2->left) &&
             areIdentical(root1->right, root2->right);
}
bool areMirrors(Node *root1, Node *root2)
{
      if (root1 == NULL && root2 == NULL)
      {
            return true; // Both trees are empty
      }
      if (root1 == NULL || root2 == NULL)
      {
            return false; // One tree is empty, the other is not
      }
      return (root1->data == root2->data) &&
             areMirrors(root1->left, root2->right) &&
             areMirrors(root1->right, root2->left);
}
int main()
{
      Node *root1 = new Node{1, nullptr, nullptr};
      root1->left = new Node{2, nullptr, nullptr};
      root1->right = new Node{3, nullptr, nullptr};

      Node *root2 = new Node{1, nullptr, nullptr};
      root2->left = new Node{3, nullptr, nullptr};
      root2->right = new Node{2, nullptr, nullptr};

      if (areIdentical(root1, root2))
      {
            cout << "The trees are identical." << endl;
      }
      else
      {
            cout << "The trees are not identical." << endl;
      }

      if (areMirrors(root1, root2))
      {
            cout << "The trees are mirrors of each other." << endl;
      }
      else
      {
            cout << "The trees are not mirrors of each other." << endl;
      }

      return 0;
}