#include <iostream>
#include "stack.hpp"
using namespace std;
#define n 100

Stack::Stack()
{
    arr = new int(n);
    top = -1;
}

void Stack::Push(int x)
{
    if (top == n - 1)
    {
        cout << "Stack overflow!" << endl;
        return;
    }
    top++;
    arr[top] = x;
}
void Stack::Pop()
{
    if (top == -1)
    {
        cout << "Stack underflow!" << endl;
        return;
    }
    top--;
}

int Stack::Top()
{
    if (top == -1)
    {
        cout << "Stack underflow!" << endl;
        return -1;
    }

    return arr[top];
}

bool Stack::Empty()
{
    return top == -1;
}
