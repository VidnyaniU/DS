#include <iostream>

// Node class
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
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

    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAt(int data, int position);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFrom(int position);
};
