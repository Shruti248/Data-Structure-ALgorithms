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


    // At a particular position propvided , cycle will be formed..
    void makeCycle(node* &head , int pos){
        node* temp = head ;
        node* startNode;

        int count = 1;

        while(temp->next !=NULL){
            if(count == pos){
                startNode=temp;
            }
            temp=temp->next;
            count++;
        }
        // After the loop completes ..It will have temp at the last node & startNode will be the position where the cycle needs to start..
        // Therefore this line
        temp->next=startNode;
    }



    // IMP IMP IMP 
    // Detection and removal of  Cycle
    // Floyd's Algo
    // Hare and tortoise algo


    // 2 nodes have same next...

    // Hare and tortoise algo  : Tortoise moves by 1 step ... Hare moves by 2 step 
    // If after any number of times , hare and tortoise come to same point tehn it is said that cycle exist in LL..Else not 

    // hare : Fast Pointer
    // Tortoise : Slow Pointer
    bool detectCycle(node* &head){

        // Both pointers start from head as ofc
        node* slow = head ;
        node* fast = head ;

        while(fast != NULL /**If Already reached to last node**/ && fast->next !=NULL /**fast->next->next this cannot be accessed */){
            slow = slow->next;
            fast  = fast->next->next;

            // If both coincide
            if(fast == slow){
                // Cycle Present
                return true;
            }
        }

        return false;

    }

    // PROOF 
    // Distance moved by fast ptr : m (head to cycle start)+ n(cycle start to whole loop and back to same point) + l*j(Number of loops)
    // Distance moved by slow ptr : m + n + l*i

    // Distance by fast ptr = 2*distance by slow ptr
    // m+n+lj = 2*(m+n+li)
    // m+n= l(j-2i)
    // m = l(j-2i) - n

    // if l is any integer value , then it will always return to the same point.
    // See the video for more clarification


    // Remove the cycle
    // the work will begin at the position where the hare and tortoise have came to the same position 
    // Then we will bring hare(or any one) to the start node(Head);
    // Then move each one of them by one step
    // When both point to the same node...
    // We come to know that it is the starting point  of the cycle

    // Then the next of the tortoise(slow pointer) is Set to NULL....
    // Hence the cycle is removed..

    // Assumed that the cycle is detected beforehand
    void removeCycle(node* &head){
        node* slow = head;
        node* fast = head;

        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);

        fast=head;
        while(slow->next!=fast->next){
            // increment by 1
            slow=slow->next;
            fast=fast->next;
        }

        slow->next = NULL;
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
    s.insertAtTail(head, 6);
    s.display(head);
    // node* newHead = s.reverseALinkedList(head);
    // s.display(newHead);

    // node *newHead = s.reverseKNodes(head, 2);
    // s.display(newHead);

    s.makeCycle(head , 3);
    // s.display(head);

    cout<<s.detectCycle(head)<<endl;
    s.removeCycle(head);
    cout<<endl;
    cout<<s.detectCycle(head)<<endl;
    cout<<endl;
    s.display(head);
    return 0;
}