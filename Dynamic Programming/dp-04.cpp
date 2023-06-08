// DP on Trees

// Identification
// When you need to traverse the complete tree on every node then use dp (Bcoz why to repeatatively traverse the complete tree)

// DP ON TREE : Genral Syntax

// Tree Recursive
// int func(inputsss){

     // Base CONDITION

     // HYPOTHESIS (This brings teh ans of left subtree & right Subtree)

    // INDUCTION(Use the result of left & right subtrees to get the value of paren node)

// }

// Basic Format
// int solve(Node* root , int &res){

//     // Base condition(Depndednt on problem)
//     if(root == NULL){
//         return 0;
//     }

//     // Hypothesis
//     int l = solve(root->left , res);
//     int r = solve(root->right , res);

//     // Induction
//     int temp = calculate temp ans (1 + max(l , r)  /** for diameter question*/)
//     int ans = max(temp , ans)
//     res = max(res , ans);

//     return temp;
// }


// Diameter of teh Tree (IMP & BASIC Que of Tree)
// Diameter : lOngest Path between 2 leaf Nodes

// Return teh number of nodes along the longest path between 2 leaf nodes

// Diameter may or may not pass through the root


#include<bits/stdc++.h>
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

int diameterOfTheBinaryTree(Node* root , int &res){

        // Base condition
        if(root == NULL){
            return 0;
        }

        // Hypotheses
        // This remains the same in all questions
        int l = diameterOfTheBinaryTree(root->left , res);
        int r = diameterOfTheBinaryTree(root->right , res);

        // Induction
        // This  is wha changes in each question

        // it is the case when node is involved just in the longest ans
        // Means the ans just passes through thsi node
        // Does not derive the ans
        int tempAns = 1 + max(l , r);

        // When the node actually want to be a part of ans
        // Which means the longest diameter is  : 1 (root node) + l + r
        int ans = max(tempAns , 1 + l + r);

        res = max(res , ans);

        return tempAns;
}


int main(){

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int res = INT_MIN;
    diameterOfTheBinaryTree(root , res);
    cout<<res<<endl;

    return 0;
}
