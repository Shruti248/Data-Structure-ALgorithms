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

// INSERT AT TAIL
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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        // LL is empty
        head = n;
        return;
    }

    n->next = head;
    head = n;
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
    cout << endl;
}
int main()
{
    node *head = NULL;
    // insertAtTail(head , 1);
    // insertAtTail(head , 2);
    // insertAtTail(head , 3);
    // display(head);

    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    display(head);
    return 0;
}