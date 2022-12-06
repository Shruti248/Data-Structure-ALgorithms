//Linked list creation 
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void traversal(Node* n ){
    while(n!=NULL){
        cout<<"--> "<<n->data<<endl;
        n = n->next;
    }
}

int main(){    
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    
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

    traversal(head);
    return 0;
}