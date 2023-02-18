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

    // Reverse K Nodes of a Linked List

    node *reverse(node *head)
    {
        node *prev = NULL;
        node *curr = head;

        while (curr != NULL)
        {
            node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    node *reverseKNodes(node *head, int k)
    {
        node *dummy = new node(0);
        dummy->next = head;
        node *prev = dummy;
        node *end = dummy;

        while (end->next != NULL)
        {
            for (int i = 0; i < k && end != NULL; i++)
            {
                end = end->next;
            }
            if (end == NULL)
                break;
            node *next = end->next;
            end->next = NULL;
            node *start = prev->next;
            prev->next = reverse(start);
            start->next = next;
            prev = start;
            end = prev;
        }

        return dummy->next;
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
    // node* newHead = s.reverseALinkedList(head);
    // s.display(newHead);

    node *newHead = s.reverseKNodes(head, 2);
    s.display(newHead);
    return 0;
}