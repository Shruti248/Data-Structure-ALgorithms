#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

// void InsertAtBeginning(Node* head_ref , int new_data){
//     Node* new_node = NULL;
//     new_node = new Node();

//     new_node->data = new_data;
//     new_node->next = head_ref;
//     head_ref = new_node;
//     //cout<<new_node->data<<endl;
// }


// void InsertAtMiddle(Node* head_ref , int new_data, Node* n){
//      Node* new_node = NULL;
//     new_node = new Node();
//     new_node->data = new_data;

//     Node* temp = head_ref;
//     while(temp->next!= n){
//         temp= temp->next;
//     }

//     new_node->next = temp->next;
//     temp->next = new_node;
// }

void InsertAtEnd(Node* head_ref , int new_data ){
    Node* new_node = NULL;
    new_node = new Node();
    new_node->data = new_data;

    Node* temp = head_ref;
    //If linked list is empty then make the new node as the head node
     if(head_ref == NULL){
         new_node = head_ref;
     }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = new_node;
    new_node->next =NULL;
}

void traversal(Node* n){
    while(n!= NULL){
        cout<<n->data<<endl;
        n = n->next;
    }
}

int main(){

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = NULL;

    //InsertAtBeginning(head , 1);
    //InsertAtMiddle(head , 7,third);

    InsertAtEnd(head,20);
    traversal(head);
    return 0 ;
}