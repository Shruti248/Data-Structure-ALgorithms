#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// BUILD BST FROM ARRAY
Node *insertBST(Node *root, int val)
{

    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        // val>root->data
        root->right = insertBST(root->right, val);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// SEARCH IN BST  : MAjor Operation
// time in binary Tree : O(N)
// in BST : O(log N)

Node *searchInBST(Node *root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return searchInBST(root->left, key);
    }

    // Right subtree
    return searchInBST(root->right, key);
}

// DELETE in BST
// CASE 1 : Leaf Node --> delete directly : Free from memory
// Case 2 : Node has 1 child --> replace the node with child & delete the node
// CASE 3 : Node has 2 children
// Steps 1 : Find the inorder successor : Replace the node with inorder successor : delet the node

Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr!= NULL){
        curr= curr->left;
    }
    return curr;
}

Node *deleteInBST(Node *root, int key)
{

    // first search the key
    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }else{
        // case 1 & 2 both together
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // CASE 3
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right , temp->data);
    }
    return root;
}

int main()
{
    // Node *root = NULL;
    // root = insertBST(root , 5);
    // insertBST(root , 1);
    // insertBST(root , 3);
    // insertBST(root , 4);
    // insertBST(root , 2);
    // insertBST(root , 7);

    // Inorder traversal of BST is always in increaisng order....
    // Prinnt inorder
    // inorder(root);

    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);

    // if (searchInBST(root, 7))
    // {
    //     cout << "Key Exists";
    // }
    // else
    // {
    //     cout << "Key doesn't Exist.";
    // }

    inorder(root);
    cout<<endl;
    root = deleteInBST(root , 5);
    inorder(root);


    return 0;
}
