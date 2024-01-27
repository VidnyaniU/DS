#include <iostream>
#include "node.hpp"
#include "linkedList.hpp"

using namespace std;
int main()
{
    // create linked list
    linkedList list;
    Node *head = NULL;

    list.insertAtBeginning(1);
    list.insertAtBeginning(4);
    list.insertAtBeginning(5);
    list.insertAtBeginning(8);
    list.insertAtEnd(3);
    list.insertAt(2, 2);

    // print list
    cout << "List: ";
    list.printList();

    // list.deletion(2);
    // cout << "After deletion List: ";
    // list.printList();

    // list.deleteFromBeginning();
    // cout << "After deletion from head List: ";
    // list.printList();
    list.appendK(head, 2);
    list.printList();
    // cout << list.detectCycle(head) << endl;
    return 0;
}