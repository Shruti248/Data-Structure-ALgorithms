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

// CHECK FOR BST
// node > max of left subtree
// node < min of right subtree

// Other Approach : Traverses the tree only once
// minALlowed < node
// maxAllowed > node

bool isBST(Node* root , Node * min = NULL , Node* max = NULL){

    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool leftValid = isBST(root->left , min , root);
    bool rightValid = isBST(root->right , root , max);

    return leftValid && rightValid;
}

// BUILD balanced BSt from sorted Array
// Make Middle elemnet the root.
// start to mid-1 : Left SUbtree
// mid+1 to end : Right Subtree

Node* sortedArrayToBST(int arr[] , int start , int end){

    if(start > end){
        return NULL;
    }

    int mid = (start+end)/2;

    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr , start , mid-1);
    root->right = sortedArrayToBST(arr , mid+1 , end);

    return root;
}

// CATALAN NUMBERS : important important
// Cn = 1/(n+1) 2nCn = summataion(Ci Cn-i) , i = 0 to n-1

// C0 = 1
// c1 = 1
// c2 = c0c1 + c1c0

// 0 to n-1 : 1st COeffienect
// n-1 to 0: 2nd COeffienect

// FInd nth catalan Number
// this will be optimized this with dynamic programming wuth O(n) later;
int catalan(int n){

    // C0 && C1 == 1
    if(n <= 1){
        return 1;
    }

    int res = 0;
    for(int i = 0 ; i<=n-1 ; i++){
        res += catalan(i)*catalan(n-i-1);
    }
    return res;
}

// APplications

// Possible BST
// Paranthesis/bracket combination
// Possible Forests
// Ways of triangulations
// Possible path in the matrix
// Dividing a circle using N chords
// dyck words of given length & much more

// 1) Possible Number of Valid BST's
vector<Node*> constructTrees(int start , int end){
    vector<Node*> trees;

    if(start > end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i = start ; i<=end ; i++){
        vector<Node*> leftSubtrees = constructTrees(start , i-1);
        vector<Node*> rightSubtrees = constructTrees(i+1 , end);

        for(int j = 0 ; j<leftSubtrees.size() ; j++){
            Node* left = leftSubtrees[j];
            for(int k = 0 ; k<rightSubtrees.size() ; k++){
                Node* right = rightSubtrees[k];

                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }

    return trees;
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// Are BST Identical ? : Should be structurally identical & have nodes values same

// If both empty , return true
// if both non empty  ,
    // check that the data at nodes is equal
    // check if left subtrees are same
    // check if right subtrees are same

// /if all 3 conditions are trye , return true else false

bool isBSTIdentical(Node* root1 , Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 != NULL && root2 != NULL){
        if(root1->data == root2->data){
            bool left = isBSTIdentical(root1->left , root2->left);
            bool right = isBSTIdentical(root1->right , root2->right);

            if(left && right){
                return true;
            }
        }
    }

    return false;
}

// Largest Binary Serach Tree in Binary Tree
// for each node store the info :
// min in subtree
// max in subtree
// subtree size
// size of tehe largest BST
// isBST

// Recursively traverse in teh bottom-up manner & find out the size of the largest BST
struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node* root){
    if(root == NULL){
        return {
            0 , INT_MIN , INT_MAX , 0 , true
        };
    }

    if(root->left == NULL && root->right == NULL){
        return {1 , root->data , root->data , 1 , true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    // Info of current Level
    Info curr;
    curr.size = (1 /**Current Node*/+ leftInfo.size + rightInfo.size);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data){
        curr.min = min(leftInfo.min , min(rightInfo.min , root->data));
        curr.max = max(rightInfo.max , max(leftInfo.max , root->data));
        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(leftInfo.ans , rightInfo.ans);
    curr.isBST = false;
    return curr;
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

    // inorder(root);
    // cout<<endl;
    // root = deleteInBST(root , 5);
    // inorder(root);

    // cout<<isBST(root);


    // int arr[] = {10 , 20 , 30 , 40 , 50};
    // Node* newroot = sortedArrayToBST(arr , 0 , 4);
    // inorder(newroot);

    // for(int i = 0 ; i<10 ; i++){
    //     cout<<i<<" "<<catalan(i)<<endl;
    // }

    // vector<Node*> totalTrees = constructTrees(1 , 3);

    // for(int i = 0 ; i<totalTrees.size() ; i++){
    //     cout<<(i+1)<<" : ";
    //     preorder(totalTrees[i]);
    //     cout<<endl;
    // }

    // cout<<isBSTIdentical(root , root);
    cout<<largestBSTinBT(root).ans<<endl;

    return 0;
}
