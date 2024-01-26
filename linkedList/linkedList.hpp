#pragma once
#include "node.hpp"
class linkedList
{
private:
    Node *head;

public:
    linkedList();
    void insertAtBeginning(int);
    void insertAtEnd(int);
    void insertAt(int, int);
    void deleteFromBeginning();
    void deletion(int); // to delete nth node point (n-1)th node to (n+1)th node
    void printList();
};