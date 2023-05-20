// Max 2 children : Binary Tree

// Properties
// Maximum nodes at level L : 2^L (l = 0 --> 1 , l = 1 --> 2 , l = 2 --> 4)

// Maximum nodes in a tree at height h = 2^h-1 (h starts from 1)

// For N Nodes , minimum possible hieght or minimum number of levels are log(N+1)(Base 2);

// A binary tree with L Leaves has at least log(n+1)(Base 2) + 1 number of levels

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// TREE TRAVERSALS
void preOrder(struct Node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// void inOrder(struct Node* root){
void inOrder(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(struct Node *root)
{

    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// BUILD TREE FROM PREORDER & INORDER

int search(int inOrder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int preOrder[], int inOrder[], int start, int end /**Start & end or inorder*/)
{
    static int idx = 0;

    if (start > end)
    {
        return NULL;
    }

    int curr = preOrder[idx];
    idx++;
    Node *node = new Node(curr);

    // Leaf Nodes : no left & right child in inorder
    if (start == end)
    {
        return node;
    }

    int pos = search(inOrder, start, end, curr);

    node->left = buildTree(preOrder, inOrder, start, pos - 1);

    node->right = buildTree(preOrder, inOrder, pos + 1, end);

    return node;
}

// BUILD TREE FROM POSTORDER & INORDER

Node *buildTreePostOrderGiven(int postOrder[], int inOrder[], int start, int end)
{
    static int idx = 4;

    if (start > end)
    {
        return NULL;
    }

    int curr = postOrder[idx];
    idx--;
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(inOrder, start, end, curr);

    node->right = buildTreePostOrderGiven(postOrder, inOrder, pos + 1, end);
    node->left = buildTreePostOrderGiven(postOrder, inOrder, start, pos - 1);

    return node;
}

// LEVEL ORDER TRAversal : QUEUE : FIFO
void printLevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

// Find SUm of Nodes at kth Level
void sumAtKthLevel(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    int k = 0;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int sum = 0;
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {

            sum += node->data;


            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else
        {
            cout << k << " level : " << sum << endl;
            sum=0;
            k++;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

// Count all the ndoes in the binary Tree
// LEft subtree + rightsubtree + 1
int countNodes(Node* root){

    if(root == NULL){
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Sum of ALl nodes in Binary Tree
int sumofAllNodes(Node* root){

    if(root== NULL){
        return 0;
    }

    return sumofAllNodes(root->left) + sumofAllNodes(root->right) + root->data;

}

// Hieght of the binary Tree
// max(leftSubtree , rightSubtree) + 1
int calcHeight(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = calcHeight(root->left);
    int rightHeight = calcHeight(root->right);

    return max(leftHeight , rightHeight) + 1;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // preOrder(root);
    // cout<<endl;
    // cout<<endl;
    // inOrder(root);
    // cout<<endl;
    // cout<<endl;
    // postOrder(root);
    // cout<<endl;
    // cout<<endl;

    // int preorder[] = {1 ,2  , 4 , 3 , 5};
    // int postorder[] = {4 , 2 , 5 , 3 , 1};
    // int inorder[] = { 4 , 2 , 1 , 5 , 3};

    // Node* root = buildTree(preorder , inorder , 0  , 4);
    // Node* root = buildTreePostOrderGiven(postorder , inorder , 0  , 4);
    // inOrder(root);

    // printLevelOrder(root);
    // sumAtKthLevel(root);
    // cout<<countNodes(root);
    // cout<<sumofAllNodes(root);
    cout<<calcHeight(root);
    return 0;
}
