#include <iostream>
using namespace std;

struct stack
{
      int data;
      stack *next;
};

void push(stack *&s, int data)
{
      stack *n = new stack;
      n->data = data;
      n->next = s;
      s = n;
}
int pop(stack *&s)
{
      if (s == NULL)
      {
            return -1;
      }
      int curr_data;
      curr_data = s->data;
      stack *temp = s;
      s = s->next;
      delete (temp);
      return curr_data;
}
int isEmpty(stack *&s)
{
      if (s == NULL)
      {
            return 1;
      }
      else
            return 0;
}

int count(stack *&s)
{
      int c = 0;
      stack *stemp = NULL;
      while (isEmpty(s) == 0)
      {
            int x = pop(s);
            c++;
            push(stemp, x);
      }
      while (isEmpty(stemp) == 0)
      {
            int x = pop(stemp);
            push(s, x);
      }
      return c;
}
void print_stack(stack *&s)
{
      stack *stemp = NULL;
      while (isEmpty(s) == 0)
      {
            int x = pop(s);
            push(stemp, x);
      }
      while (isEmpty(stemp) == 0)
      {
            int x = pop(stemp);
            cout << x << " ";
            push(s, x);
      }
}
void insert_in_middle(stack *&s, int data)
{
      stack *stemp = NULL;
      int c = count(s);
      int c1 = 0;
      while (isEmpty(s) == 0 && c1 < c / 2)
      {
            int x = pop(s);
            push(stemp, x);
            c1++;
      }
      push(s, data);
      while (isEmpty(stemp) == 0)
      {
            push(s, pop(stemp));
      }
}
int main()
{
      stack *s = NULL;
      cout << "Num of elem";
      int n, x;
      cin >> n;
      for (int i = 0; i < n; i++)
      {
            cin >> x;
            push(s, x);
      }
      print_stack(s);
      cout << endl;
      insert_in_middle(s, 10);
      print_stack(s);
}