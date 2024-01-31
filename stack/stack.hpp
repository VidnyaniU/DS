class Stack
{
    int *arr;
    int top;

public:
    Stack();
    void Push(int);
    void Pop();
    int Top();
    bool Empty();
};