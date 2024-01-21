// to detect cycle we use floyds algorithm
// we hare(fast pointer) which takes 2 steps  and tortoise (slow  pointer) which takes 1 step at a time
// if hare and tortoise comes to the same position after some point then cycle is detected

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
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

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    bool detectCycle(Node *&head)
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

    void makeCycle(Node *&head, int pos)
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

    ll.makeCycle(ll.head, 2);
    // ll.printList();
    bool detectCyc = ll.detectCycle(ll.head);
    cout << detectCyc << endl;

    return 0;
}
