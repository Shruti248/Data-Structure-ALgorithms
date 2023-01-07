//Insertion of Node

//Linked list creation 
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

// void insertAtBeginning(Node* head_ref , int new_data){
//     //creating the new node
//     Node* new_node = NULL;
    
//     //Allocating the memory to the new node
//     new_node = new Node();

//     //insering new_node data
//     new_node->data = new_data;

//     //Pointing the next to the head ref
//     new_node->next = head_ref;

//     //Making new node as the head node
//     head_ref = new_node;
//     cout<<"New_Node data = "<<new_node->data<<endl;
// }

//Insert at the end
void insertAtEnd(Node* head_ref , int new_data){
    //creating the Node
    Node* new_node_end = NULL;
    //Allocating memory
    new_node_end = new Node();
    new_node_end->data = new_data;

    Node* temp = head_ref;
    //If linked list is empty then make the new node as the head node
     if(head_ref == NULL){
         new_node_end = head_ref;
     }

    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = new_node_end;
    new_node_end->next = NULL;
}

//After a specified location 
// void insertAtMiddle(Node* head_ref , int new_data , Node* n){
//     //creating the new node
//     Node* new_node_Middle = NULL;

//     //Allocating memory
//     new_node_Middle = new Node();

//     //entering data
//     new_node_Middle->data = new_data;

//     Node* temp = head_ref;
//     //traversing till 
//     while(temp->next == n){
//         temp = temp->next;
//     }

//     new_node_Middle->next = temp->next;
//     temp->next = new_node_Middle;
    
// }

void traversal(Node* n){
    while(n!= NULL){
        cout<<n->data<<endl;
        n=n->next;
    }
}
 
int main(){    
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    //creating the new node
    Node* new_node = NULL;
    
    //allocating memory to the nodes.
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1; //To access this the node created must be public 
    head->next = second;

    second->data = 2 ;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // insertAtBeginning(head , 5);
    // traversal(head);

    insertAtEnd(head , 4);
    // traversal(head);

    //insertAtMiddle(head , 100 , second);
    traversal(head);
    return 0;
}