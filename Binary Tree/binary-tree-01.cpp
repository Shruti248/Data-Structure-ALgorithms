// Max 2 children : Binary Tree

// Properties
// Maximum nodes at level L : 2^L (l = 0 --> 1 , l = 1 --> 2 , l = 2 --> 4)

// Maximum nodes in a tree at height h = 2^h-1 (h starts from 1)

// For N Nodes , minimum possible hieght or minimum number of levels are log(N+1)(Base 2);

// A binary tree with L Leaves has at least log(n+1)(Base 2) + 1 number of levels

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// TREE TRAVERSALS
void preOrder(struct Node* root){

    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// void inOrder(struct Node* root){
void inOrder(Node* root){

    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(struct Node* root){

    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

// BUILD TREE FROM PREORDER & INORDER

int search(int inOrder[] , int start , int end , int curr){
    for(int i = start ; i<=end ; i++){
        if(inOrder[i] == curr){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int preOrder[] , int inOrder[] , int start , int end /**Start & end or inorder*/){
    static int idx = 0;

    if(start > end){
        return NULL;
    }

    int curr = preOrder[idx];
    idx++;
    Node* node = new Node(curr);


    // Leaf Nodes : no left & right child in inorder
    if(start == end){
        return node;
    }

    int pos = search(inOrder , start , end , curr);

    node->left = buildTree(preOrder , inOrder , start , pos-1);

    node->right = buildTree(preOrder , inOrder , pos+1 , end);

    return node;
}


int main(){
    // struct Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);

    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    // preOrder(root);
    // cout<<endl;
    // cout<<endl;
    // inOrder(root);
    // cout<<endl;
    // cout<<endl;
    // postOrder(root);
    // cout<<endl;
    // cout<<endl;

    int preorder[] = {1 ,2  , 4 , 3 , 5};
    int inorder[] = { 4 , 2 , 1 , 5 , 3};

    Node* root = buildTree(preorder , inorder , 0  , 4);
    inOrder(root);
    return 0;
}
