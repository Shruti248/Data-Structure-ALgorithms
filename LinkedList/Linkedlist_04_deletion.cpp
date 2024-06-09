#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void DeleteFirst(Node *head_ref)
{
    if (head_ref != NULL)
    {

        // 1. if head is not null, create a
        //    temp node pointing to head
        Node *temp = head_ref;

        // 2. move head to next of head
        head_ref = head_ref->next;

        // 3. delete temp node
        free(temp);
    }
}

void traversal(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << endl;
        n = n->next;
    }
}

int main()
{

    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = NULL;

    DeleteFirst(head);
    traversal(head);
    return 0;
}
