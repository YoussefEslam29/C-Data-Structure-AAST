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
int max(stack *&s)
{
      int max = pop(s);
      stack *stemp = NULL;
      while (isEmpty(s) == 0)
      {
            int x = pop(s);
            if (x > max)
            {
                  max = x;
            }
            push(stemp, x);
      }
      while (isEmpty(stemp) == 0)
      {
            int x = pop(stemp);
            push(s, x);
      }
      return max;
}
int min(stack *&s)
{
      int min = pop(s);
      stack *stemp = NULL;
      while (isEmpty(s) == 0)
      {
            int x = pop(s);
            if (x < min)
            {
                  min = x;
            }
            push(stemp, x);
      }
      while (isEmpty(stemp) == 0)
      {
            int x = pop(stemp);
            push(s, x);
      }
      return min;
}
int main()
{
      stack *s = NULL;
      int n, x;
      cout << "number of elem: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            push(s, x);
        }
        cout << "count: " << count(s) << endl;
        cout << "max: " << max(s) << endl;
        cout << "min: " << min(s) << endl;
        
      return 0;
}