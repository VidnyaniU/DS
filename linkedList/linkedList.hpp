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
    void deletion(int);
    bool detectCycle(Node *&head);
    void makeCycle(Node *&head, int pos);
    void removeCycle(Node *&head);
    void reverseIter();
    Node *reverseRecur(Node *head);
    Node *reverseK(Node *&head, int k);
    int length(Node *&head);
    // Node *appendK(Node *head, int k);
    void printList();
    void printList(Node *head);
};