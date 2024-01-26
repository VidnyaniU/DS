#include <iostream>
#include "node.hpp"
#include "linkedList.hpp"

using namespace std;

int listSize = 0;
// Node class
Node::Node(int val)
{
    this->data = val;
    this->next = NULL;
}

linkedList::linkedList()
{
    this->head = NULL;
}

void linkedList::insertAtBeginning(int data)
{
    Node *newNode = new Node(data); // creating a new node
    newNode->next = head;           // storing the address of current head in the next node of new node
    head = newNode;                 // updating head to newNode
    listSize++;
    return;
}
void linkedList::insertAtEnd(int data)
{
    Node *newNode = new Node(data);
    // check if the linkedlist is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    // to traverse through whole linked list
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next; // until we get next = NULL we will run this loop
    }                      // after this loop we have reached at our last element

    temp->next = newNode; // inserting at end
    listSize++;
}
void linkedList::insertAt(int data, int position)
{
    Node *newNode = new Node(data);

    // Check for invalid pos
    if (position < 1 || position > listSize + 1)
    {
        cout << "Invalid" << endl;
        return;
    }

    // Insert at first node
    if (position == 1)
    {
        newNode->next = head; // storing the address of current head in the next node of new node
        head = newNode;       // updating head to newNode
        listSize++;
        return;
    }

    else
    {
        Node *temp = head;

        // Traverse to the current (position -1)th node
        while (--position > 1)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        listSize++;
    }
}
void linkedList::deleteFromBeginning()
{
    Node *todelete = head;
    head = head->next; // poiting the head to the second element
    delete todelete;   // deleting first element
}
void linkedList::deletion(int val) // to delete nth node point (n-1)th node to (n+1)th node
{
    if (head == NULL) // if ll is empty
    {
        return;
    }

    // if only one element is there
    if (head->next == NULL)
    {
        deleteFromBeginning();
        return;
    }
    Node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    Node *todelete = temp->next;   // node to delete
    temp->next = temp->next->next; // next of temp becomes next of next of temp
    delete todelete;
}

// to detect cycle we use floyds algorithm
// we hare(fast pointer) which takes 2 steps  and tortoise (slow  pointer) which takes 1 step at a time
// if hare and tortoise comes to the same position after some point then cycle is detected
bool linkedList::detectCycle(Node *&head)
{
    // at start hare and tortoise will point to same head
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // moving one step forward
        fast = fast->next->next; // two steps forward

        if (fast == slow)
        {
            return true; // cycle detected
        }
    }
    return false;
}
void linkedList::makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp; // start  cycle from here
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
void linkedList::removeCycle(Node *&head)

{
    Node *fast = head; // hare
    Node *slow = head; // tortoise
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast); // after the end of this loop cycle is detected
    // after detection of the cycle we will put the hare(or tortoise) at the head and move of them one step
    // and wherever we detect that both (hare and tortoise) of the next pointing to same Node we will make next of tortoise(or hare) point to NULL

    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
void linkedList::reverseIter()
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

Node *linkedList::reverseRecur(Node *head)
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
// reverse k nodes in a linked list
Node *linkedList::reverseK(Node *&head, int k)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    Node *nextptr;

    int count = 0;
    while (currptr != NULL && count < k) // to reverse k nodes
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    // check  if nextptr is NULL
    if (nextptr != NULL)
    {
        // next k nodes
        head->next = reverseK(nextptr, k);
    }

    return prevptr;
}
void linkedList::printList()
{
    Node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
