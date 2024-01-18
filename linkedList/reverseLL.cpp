#include <iostream>
using namespace std;
// Node struct
struct Node
{
    int data;
    Node *next; // address of next node

    Node(int val)
    {
        this->data = val;
        next = NULL;
    }
};

struct LinkedList
{

    Node *head;

    LinkedList()
    {
        head = NULL;
    }
    // reverse linked list using iterative approach
    void reverseIter()
    {
        // we will use 3 pointers and iterate them until we reach current =NULL
        Node *prevPtr = NULL;
        Node *currPtr = head;
        Node *nextPtr;

        while (currPtr != NULL)
        {
            nextPtr = currPtr->next;
            currPtr->next = prevPtr;

            prevPtr = currPtr;
            currPtr = nextPtr;
        }
        head = prevPtr; // this is our new head
    }

    Node *reverseRecur(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *newhead = reverseRecur(head->next);
        head->next->next = head;
        head->next = NULL;

        return newhead;
    }

    void push(int data) // insert at beginning
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {

            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main(int argc, char const *argv[])
{
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);

    ll.printList();
    // ll.reverseIter();
    ll.head = ll.reverseRecur(ll.head);
    ll.printList();

    return 0;
}
