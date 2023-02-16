#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Solution
{
public:
    void insertAtTail(node *&head, int val)
    {

        node *n = new node(val);

        // When Head is NULL (LL is empty)
        if (head == NULL)
        {
            head = n;
            return;
        }

        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = n;
    }

    // Print
    void display(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    node *reverseALinkedList(node *&head)
    {
        // 3 Pointers : Previous  = NULL, current = head , next = current->next

        // Current->next = previous then increment all teh three pointers

        // Break the loop when previous-> next = NULL

        // Head = previous

        node *prevptr = NULL;
        node *currptr = head;
        node *nextptr;

        while (currptr != NULL)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;

            // increment
            prevptr = currptr;
            currptr = nextptr;
        }

        // New Head
        return prevptr;
    }
};

int main()
{
    Solution s;
    node *head = NULL;
    s.insertAtTail(head, 1);
    s.insertAtTail(head, 2);
    s.insertAtTail(head, 3);
    s.insertAtTail(head, 4);
    s.insertAtTail(head, 5);
    s.display(head);
    node* newHead = s.reverseALinkedList(head);
    s.display(newHead);
    return 0;
}