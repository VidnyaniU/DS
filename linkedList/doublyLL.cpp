#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertAtBeginning(Node *&head, int val)
{
}
void insertAtEnd(Node *&head, int val)
{
    if (head == NULL)
    {
        insertAtBeginning(head, val);
        return;
    }

    Node *n = new Node(val);
    Node *temp = head;

    while (temp->next = NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
int main()
{
    /* code */
    return 0;
}
