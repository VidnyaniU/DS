#include <iostream>

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
    }
    void insertAt(int data, int position);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFrom(int position);
};
