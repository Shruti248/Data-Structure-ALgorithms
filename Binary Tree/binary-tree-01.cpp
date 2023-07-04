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
            sum = 0;
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
int countNodes(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Sum of ALl nodes in Binary Tree
int sumofAllNodes(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    return sumofAllNodes(root->left) + sumofAllNodes(root->right) + root->data;
}

// Hieght of the binary Tree
// max(leftSubtree , rightSubtree) + 1
int calcHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = calcHeight(root->left);
    int rightHeight = calcHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Diameter of the Binary Tree
// Numberof nodes in the longest path etween 2 leaves
// 1) diameter through root
// left height + right height +1
// 2) diameter NOT through root
// MAX  of :
// left diameter
// right diameter

// ANS : max(lheight+rheight+1 , max( left diamater , right diamater))

int calcDiameter(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}

// SUm Replacement : Replace teh value of each node with the sum of all subtree nodes & itself

void sumReplace(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    sumReplace(root->left);
    sumReplace(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

// Balnaced Height Tree : For Each Node , the difference between the heights of the left subtree & right subtree <= 1;

//  mod(leftHeight -  rightHeight) <=1;

int height(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

bool isbalanced(Node *root)
{

    if (root == NULL)
    {
        return true;
    }

    if (isbalanced(root->left) == false)
    {
        return false;
    }
    if (isbalanced(root->right) == false)
    {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// RIGHT VIEW of the binary Tree
// Traverse level wise : Get the RightMost Node
// Level ORder Traversal : QUEUE
void rightView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // Nodes at current level
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << curr->data << " ";
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

void leftView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == 0)
                cout << curr->data << " ";
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

// MINIMUM DISTANCE BETWEEN 2 NODES IN BINARY TREE
// 1) FInd Lowest Common ancestor
// 2) Distance of both nodes from common ancestor.
// 3)Sum of both distance is the total path

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
    {
        return root;
    }

    if (left == NULL && right == NULL)
    {
        return NULL;
    }

    if (left != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int findDistance(Node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        return dist;
    }

    int left = findDistance(root->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }
    return findDistance(root->right, k, dist + 1);
}

int distanceBtwNodes(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);

    int d1 = findDistance(lca, n1, 0);
    int d2 = findDistance(lca, n2, 0);

    return d1 + d2;
}

// Print ALL Nodes At Distance K
// CASE 1 : Nodes Subtree
// CASE 2 : Nodes Ancestor

// CAse 1
void printSubtreeNodes(Node *root, int k)
{
    if (root == NULL & k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}

// Case 2
int printNodesAtK(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root == target)
    {
        printSubtreeNodes(root, k);
        return 0;
    }

    int dl = printNodesAtK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreeNodes(root->right, k - dl - 2);
        }
        return 1 + dl;
    }

    int dr = printNodesAtK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreeNodes(root->left, k - dr - 2);
        }
        return 1 + dr;
    }

    return -1;
}

int maxPathSumUtil(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);
    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);
    // . It is calculated to handle cases where the maximum path sum does not include the current node and instead lies entirely in either the left subtree or the right subtree.
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));

    return singlePathSum;
}

// Maximum Path Sum
int maxPathSum(Node *root)
{
    int ans = INT_MIN;

    int singlePathSum = maxPathSumUtil(root, ans);
    // cout<<"Single Path Sum :"<<singlePathSum<<endl;

    // Max path between any 2 nodes , may or may not pass through the root node
    return ans;
}

// Path Sum with the Traget Sum Given : Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

bool pathSumWithGiventargetSum(Node *root, int target)
{

    if (root == NULL)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }

    int left = pathSumWithGiventargetSum(root->left, target - root->data);
    int right = pathSumWithGiventargetSum(root->right, target - root->data);

    return left || right;
}

// Boundary Traversal Of the Binary Tree

// Time Complexity: O(N).
// Reason: The time complexity will be O(H) + O(H) + O(N) which is ≈ O(N)
// Space Complexity: O(N)
// Reason: Space is needed for the recursion stack while adding leaves. In the worst case (skewed tree), space complexity can be O(N).

bool isLeaf(Node *root)
{
    return root->left == NULL && root->right == NULL;
}
void addLeftBoundary(Node *root, vector<int> &ans)
{
    Node *curr = root->left;

    while (curr)
    {
        if (!isLeaf(curr))
        {
            ans.push_back(curr->data);
        }
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void addLeaves(Node *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }

    if (root->left)
        addLeaves(root->left, ans);
    if (root->right)
        addLeaves(root->right, ans);
}
void addRightBoundary(Node *root, vector<int> &ans)
{
    Node *curr = root->right;
    vector<int> temp;

    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    if (!isLeaf(root))
    {
        ans.push_back(root->data);
    }

    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);

    return ans;
}

int main()
{
    // struct Node *root = new Node(1);
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
    // cout<<calcHeight(root);
    // cout<<calcDiameter(root);

    // preOrder(root);
    // cout<<"\n";
    // sumReplace(root);
    // preOrder(root);
    // cout<<"\n";

    // cout<<isbalanced(root);

    // rightView(root);
    // leftView(root);

    // cout << distanceBtwNodes(root, 4, 7);
    // printNodesAtK(root , root->left , 1);

    // cout << maxPathSum(root);

    // cout << pathSumWithGiventargetSum(root, 3);

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);

    vector<int> printboundaryTraversal = boundaryTraversal(root);

    cout << "The Boundary Traversal is : ";
    for (int i = 0; i < printboundaryTraversal.size(); i++)
    {
        cout << printboundaryTraversal[i] << " ";
    }

    return 0;
}
