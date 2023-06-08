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
int solve(Node* root , int &res){

    // Base condition(Depndednt on problem)
    if(root == NULL){
        return 0;
    }

    // Hypothesis
    int l = solve(root->left , res);
    int r = solve(root->right , res);

    // Induction
    int temp = calculate temp ans (1 + max(l , r)  /** for diameter question*/)
    int ans = max(temp , ans)
    res = max(res , ans);

    return temp;
}
