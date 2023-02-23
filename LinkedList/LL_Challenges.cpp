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
    void makeCycle(node *&head, int pos)
    {
        node *temp = head;
        node *startNode;

        int count = 1;

        while (temp->next != NULL)
        {
            if (count == pos)
            {
                startNode = temp;
            }
            temp = temp->next;
            count++;
        }
        // After the loop completes ..It will have temp at the last node & startNode will be the position where the cycle needs to start..
        // Therefore this line
        temp->next = startNode;
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
    bool detectCycle(node *&head)
    {

        // Both pointers start from head as ofc
        node *slow = head;
        node *fast = head;

        while (fast != NULL /**If Already reached to last node**/ && fast->next != NULL /**fast->next->next this cannot be accessed */)
        {
            slow = slow->next;
            fast = fast->next->next;

            // If both coincide
            if (fast == slow)
            {
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
    void removeCycle(node *&head)
    {
        node *slow = head;
        node *fast = head;

        do
        {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        fast = head;
        while (slow->next != fast->next)
        {
            // increment by 1
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = NULL;
    }

    // Both Together
    // Detection and removal of Cycle
    void detectAndRemoveCycle(node *head)
    {
        if (!head || !head->next)
        {
            return;
        }

        // Step 1: Detect the cycle
        node *slow = head;
        node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                break;
            }
        }

        if (slow != fast)
        {
            // No cycle
            return;
        }

        // Step 2: Remove the cycle
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }

    // Leetcode : Reverse A Linked List
    // Reverse the arrows---
    // 1st elemet : NULL

    // Dummy Node : NULL Initialized
    // next pointer : next of head
    // head->next : NULL(dummy)

    // Increase both
    node *reverseList(node *head)
    {
        node *dummy = NULL;
        while (head != NULL)
        {
            node *next = head->next;
            head->next = dummy;
            dummy = head;
            head = next;
        }

        return dummy;
    }

    // Remove nth Node from end of the linked list
    // Brute Force : O(N) : To compute the length , O(n) : to reach the node : O(2n)
    // Optimised
    // 2 Pointers : Slow & fast
    // Move fast till n...
    // Initialize slow to head at that point after fast reahing n
    // Move both by 1 steps
    // if fast reaches NULL (Last node)...
    // Means slow->next is the node to be deleted...
    // Hence modify the slow->next...

    // If the node to be deleted is the head node , modify accordingly..

    // Time complexity : O(n)
    // Space : O(1)

    node *removeNthNodeFromEnd(node *head, int n)
    {
        node *start = new node(0);

        start->next = head;
        node *fast = start;
        node *slow = start;

        for (int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return start->next;
    }

    // Middle Of teh Linked List
    // O(N)+O(n/2) : Brute Force

    // hare Tortoise Optimized
    // Hare : 2 Step
    // Tortoise : 1 Step
    // THEREFORE , when hare completes the entire traversal , tortoise will be in the middle...(For Odd)
    // For Even : We have to return the 2nd of the 2 middle nodes (if 1st is to be retuned stop at second last pointer)

    // Time Complexity : O(n/2)
    // SPace : O(1)

    node *middleNode(node *head)
    {
        node *slow = head;
        node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted Linked List
    // 1) Making entire new list (External Space)
    // Time complexity & Space COmplexity: O(n1+n2)
    // -Dummy node  : intialize to 0
    // H1 & h2 ---Smaller one -- Add to dummy and then increment the head pointer
    // Traverse till end ofc
    // 2) In place Algo  -- Optimized
    // Time : O(n1 , n2)
    // Space : O(1)
    // No External Nodes --Using existing one
    // Eg : 3->4->5->6 (1st LL : 3 5 , 2 LL : 4 6 )

    node *mergeTwoLists(node *l1, node *l2)
    {
        // Iterative
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->data > l2->data)
            std::swap(l1, l2);
        node *res = l1;
        while (l1 != NULL && l2 != NULL)
        {
            node *tmp = NULL;
            while (l1 != NULL && l1->data <= l2->data)
            {
                tmp = l1;
                l1 = l1->next;
            }
            tmp->next = l2;
            std::swap(l1, l2);
        }
        return res;
    }

    // Delete Node In a Linked List
    // No head Given
    // Only th node to be deleted is given
    // Therefore you cannot acess teh previous node and connect the linn and break one ....
    // You can only access the enxt node
    // Therefore Copy the next nodes value into the node to be deleted and continue afterwards....

    // Therefore value is deleted..
    void deleteNode(node *pos)
    {
        if (pos == NULL)
        {
            return;
        }
        else
        {
            if (pos->next == NULL)
            {
                return;
            }
        }

        node *temp = pos->next;

        // Copy data of teh next node to the current node
        pos->data = pos->next->data;

        // Perform coventional deletion
        pos->next = pos->next->next;

        free(temp);
    }

    //  Add Two Numbers
    // Optimal Solution
    // Time : O(max(n1,n2))
    // O(n) : Space

    node *addTwoNumbers(node *l1, node *l2)
    {
        node *dummy = new node(0);
        node *temp = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->data;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                sum += l2->data;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;
            node *Listnode = new node(sum % 10);
            temp->next = Listnode;
            temp = temp->next;
        }

        return dummy->next;
    }

    // Intersection of two Linked List : Return value if intersected else return null
    node *getIntersectionNode(node *headA, node *headB)
    {

        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }

        node *a = headA;
        node *b = headB;

        // Otherwise, the function initializes two pointers a and b to the heads of the respective lists. It then enters a loop that continues until a and b are equal. During each iteration of the loop, a is set to the next node in the list it points to, or to headB if a reaches the end of the list. Similarly, b is set to the next node in the list it points to, or to headA if b reaches the end of the list. This effectively causes the pointers to traverse the combined lists of headA and headB.

        // If there is an intersection between the lists, the pointers will eventually meet at that node during the traversal.

        // a time complexity of O(m+n) where m and n are the lengths of the two lists.

        // Spoace : O(1) : because the only extra space used is for two pointers a and b.

        while (a != b)
        {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }

        return a;
    }

    // Check for Palindromic Linked List

    // The approach used in the code is to find the middle of the linked list using two pointers, slow and fast. Then, the second half of the linked list is reversed using the reverseList function. Finally, the reversed second half is compared with the first half of the linked list to check if the linked list is a palindrome or not.

    // O(n) time complexity and O(1) space complexity.

    bool isPalindrome(node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            // 0 or 1 node
            return true;
        }

        node *slow = head;
        node *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseALinkedList(slow->next);
        slow = slow->next;

        while (slow != NULL)
        {
            if (head->data != slow->data)
            {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

    // Flatenning of the Linked List
    // Merging From teh last 2 linked list : and continue till start

    // time : O(Summation of total Nodes)
    // Space : O(1)

    // Above Merge Function is used here ......
    // GFG Question ------ Try in that 
    // Node *mergeTwoLists(Node *a, Node *b)
    // {

    //     Node *temp = new Node(0);
    //     Node *res = temp;

    //     while (a != NULL && b != NULL)
    //     {
    //         if (a->data < b->data)
    //         {
    //             temp->bottom = a;
    //             temp = temp->bottom;
    //             a = a->bottom;
    //         }
    //         else
    //         {
    //             temp->bottom = b;
    //             temp = temp->bottom;
    //             b = b->bottom;
    //         }
    //     }

    //     if (a)
    //         temp->bottom = a;
    //     else
    //         temp->bottom = b;

    //     return res->bottom;
    // }
    // Node *flatten(Node *root)
    // {

    //     if (root == NULL || root->next == NULL)
    //         return root;

    //     // recur for list on right
    //     root->next = flatten(root->next);

    //     // now merge
    //     root = mergeTwoLists(root, root->next);

    //     // return the root
    //     // it will be in turn merged with its left
    //     return root;
    // }

    // Rotate a Linnked LIst -- k times 
    // K can be greater then length of the list as well

    // Naive approach : Pick up last node , and put in front --- k times --resultant LL
    // Time : O(k*N)
    // Space : O(1)

    // Optimised 
    // case 1 : k<length    
    

    // Case 2 : k>=length
    // ANy multiple of length : Returns teh original LL 
    // That is : k == multiple of length , return original LL
    // Else minus the multiple & the ans is the number of rotations 

    // DO THis : k = k%length ---Nearest multiple of k 

    // SIMPLE : last node to 1st node connect karvanu : etle apnne curcular LL madi jase , pachi jetla rotations hoi ene last thi count kari ne tya api devanu head ne (k = length - k : Last Node , head = k+1)

    // Time : O(N)+O(n-N%k) = O(N)
    // Space : O(1)

    node* rotateRight(node* head , int k){
        if(!head || !head->next || k ==0 ) return head;

        // COmpute teh length 
        node* curr = head;
        int len = 1;
        while(curr->next && ++len){
            curr = curr->next;
        }

        // Go till That Node
        curr->next = head;
        k=k%len;
        k=len-k;

        while(k--)
            curr = curr->next;
        
        // Make the node Head & break teh connection
        head = curr->next;
        curr->next = NULL;

        return head;
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

    // s.makeCycle(head, 3);
    // s.display(head);

    // cout << s.detectCycle(head) << endl;
    // s.removeCycle(head);
    // cout << endl;
    // cout << s.detectCycle(head) << endl;
    // cout << endl;
    // s.display(head);
    // s.detectAndRemoveCycle(head);
    // s.display(head);

    // node *newHead = s.reverseList(head);
    // s.display(newHead);

    // node *newHead = s.removeNthNodeFromEnd(head, 4);
    // s.display(newHead);

    // node* newHead = s.middleNode(head);
    // cout<<newHead->data;

    // node *head2 = NULL;
    // s.insertAtTail(head2, 5);
    // s.insertAtTail(head2, 6);
    // s.insertAtTail(head2, 1);
    // s.insertAtTail(head2, 8);
    // s.insertAtTail(head2, 4);
    // s.insertAtTail(head2, 5);
    // s.display(head2);

    // node* sorted = s.mergeTwoLists(head , head2);
    // s.display(sorted);

    // 1 2 3 4 5 6
    // node* del = head->next;

    // s.deleteNode(del);
    // s.display(head);

    // node* addTwoNumbers = s.addTwoNumbers(head , head2);
    // s.display(addTwoNumbers);

    // node *getIntersectionNode = s.getIntersectionNode(head, head2);
    // s.display(getIntersectionNode);

    // cout << s.isPalindrome(head);

    node* newHead = s.rotateRight(head , 2);
    s.display(newHead);

    return 0;
}