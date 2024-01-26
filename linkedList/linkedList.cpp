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


