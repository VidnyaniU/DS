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
    Node *n = new Node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
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

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void deleteFromHead(Node *&head)
{
    Node *toDelete = head;
    head = head->next;
    head->prev = NULL;
    delete toDelete;
}
void deleteFrom(Node *&head, int pos)
{
    if (pos == 1)
    {
        deleteFromHead(head);
    }

    Node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    // to delete
    // suppose we want to delete 2 from 0 1 2 3 4
    temp->prev->next = temp->next; // 1's next will point to 3
    if (temp->next != NULL)        // check if the element we are deleting is the last one because if it is then its next NULL which wont have a prev ptr
    {
        temp->next->prev = temp->prev; // 3's prev will point to 1
    }

    delete temp;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    printList(head);
    insertAtBeginning(head, 0);
    printList(head);
    deleteFromHead(head);
    printList(head);
    deleteFrom(head, 2);
    printList(head);

    return 0;
}
