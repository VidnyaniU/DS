#include <iostream>
using namespace std;
#define n 100;

class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int(n);
        top = -1;
    }

    void Push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void Pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow!" << endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }

        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};
int main()
{
    /* code */
    return 0;
}
