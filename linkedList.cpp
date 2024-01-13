#include <iostream>
using namespace std;

int listSize = 0;
// Node class
class Node
{
public:
    int data;
    Node *next; // address of next node

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

// linked list class
class linkedList
{
private:
    Node *head;

public:
    linkedList()
    {
        this->head = nullptr;
    }

    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data); // creating a new node
        newNode->next = head;           // storing the address of current head in the next node of new node
        head = newNode;                 // updating head to newNode
        listSize++;
        return;
    }
    void insertAtEnd(int data)
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
    void insertAt(int data, int position)
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
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFrom(int position);
};
