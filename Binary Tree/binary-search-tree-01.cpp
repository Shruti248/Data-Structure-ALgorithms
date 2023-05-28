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

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr != NULL)
    {
        curr = curr->left;
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
    }
    else
    {
        // case 1 & 2 both together
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // CASE 3
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

// CHECK FOR BST
// node > max of left subtree
// node < min of right subtree

// Other Approach : Traverses the tree only once
// minALlowed < node
// maxAllowed > node

bool isBST(Node *root, Node *min = NULL, Node *max = NULL)
{

    if (root == NULL)
    {
        return true;
    }

    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    return leftValid && rightValid;
}

// BUILD balanced BSt from sorted Array
// Make Middle elemnet the root.
// start to mid-1 : Left SUbtree
// mid+1 to end : Right Subtree

Node *sortedArrayToBST(int arr[], int start, int end)
{

    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;

    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

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
int catalan(int n)
{

    // C0 && C1 == 1
    if (n <= 1)
    {
        return 1;
    }

    int res = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
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
vector<Node *> constructTrees(int start, int end)
{
    vector<Node *> trees;

    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubtrees = constructTrees(start, i - 1);
        vector<Node *> rightSubtrees = constructTrees(i + 1, end);

        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            Node *left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                Node *right = rightSubtrees[k];

                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }

    return trees;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
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

bool isBSTIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 != NULL && root2 != NULL)
    {
        if (root1->data == root2->data)
        {
            bool left = isBSTIdentical(root1->left, root2->left);
            bool right = isBSTIdentical(root1->right, root2->right);

            if (left && right)
            {
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
struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node *root)
{
    if (root == NULL)
    {
        return {
            0, INT_MIN, INT_MAX, 0, true};
    }

    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    // Info of current Level
    Info curr;
    curr.size = (1 /**Current Node*/ + leftInfo.size + rightInfo.size);

    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root->data));
        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

// Recover BST
// Strategy : Inorder of a BST is sorted

// Case 1 : swapped elements are not adjacent to each other
// Case 2 : Swapped elements are adjacent to each other

// Miantain 3 pointers : first , last , end
// first : previous node where 1st numeber <previous[8];
// mid : number where 1st element <previous[3];
// last : 2nd node where number <previous[2]

// CASE 1 : swap first & last
// CASE 2 : swap first & MID bcoz last is NULL

void calcPointers(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root == NULL)
    {
        return;
    }

    calcPointers(root->left, first, mid, last, prev);

    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }

    *prev = root;

    calcPointers(root->right, first, mid, last, prev);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void restoreBST(Node *root)
{
    Node *first = NULL, *mid = NULL, *last = NULL, *prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    // case 1
    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}

// FIND MAXIMUM POSSIBLE MINIMUM DISTANCE FOR K ELEMENTS THAT CAN BE GROUPED TOPGETHER
// Sort the array for binary search technique
// pick middle element as result & check for feasibiliy.
// if middle element is feasible , search the right half of the array with larger min distance .
// if middle element is not feasible , search left half

bool isFeasible(int mid, int arr[], int n, int k)
{
    int pos = arr[0], elements = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int result = -1;
    int left = 1;
    int right = arr[n - 1];

    // Binary search on left to right
    while (left < right)
    {
        int mid = (left + right) / 2;

        if (isFeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1; // right half
        }
        else
        {
            right = mid; // left half
        }
    }

    return result;
}

// Allocate Min Pages
// Apply binary search for minimum & maximum possible values of max values
// Check the feasibility

bool isPossible(int arr[], int n, int m, int min)
{
    int studentsRequired = 1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            return false;
        }

        if (sum + arr[i] > min)
        {
            studentsRequired++;
            sum = arr[i];

            if (studentsRequired > m)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }

    return true;
}

int allocateMinimumPages(int arr[], int n, int m)
{
    int sum = 0;

    if (n < m)
    {
        // Books less than students
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        // Sum of all the pages of th books
        sum += arr[i];
    }

    int start = 0, end = sum, ans = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            end = mid - 1; // left half
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

// Search ELement in sorted & pivot element
// Find pivot
// APply biary search on left & right half

int searchInRotatedArray(int arr[], int key, int left, int right)
{
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[left <= arr[mid]])
    {
        if (key >= arr[left] && key <= arr[mid])
        {
            return searchInRotatedArray(arr, key, left, mid - 1);
        }
        return searchInRotatedArray(arr, key, mid + 1, right);
    }

    if (key >= arr[mid] && key <= arr[right])
    {
        return searchInRotatedArray(arr, key, mid + 1, right);
    }

    return searchInRotatedArray(arr, key, left, mid - 1);
}

// Sliding Window Problems
// FInd Peak Element : Elmeent greater than both previous & next element

// Ascending array : last element is peak
// Descending array : first element is peak
// For all the same element : Each element is peak

int peakElements(int arr[], int low, int high, int n)
{
    int mid = low + (high - low) / 2;

    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
    {
        return mid;
    }
    else if (mid > 0 && arr[mid - 1] > arr[mid])
    {
        // Left Half
        return peakElements(arr, low, mid - 1, n);
    }
    return peakElements(arr, mid + 1, high, n);
}

// Sliding WIndow Problems

// MAX SUM SUBARRAY
// Size = K & sum < x
// The goal of the function is to find the maximum subarray sum that is less than x.

int maxSubarraySum(int arr[], int n, int k, int x)
{
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    if (sum < x)
    {
        ans = sum;
    }

    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k] /**start pointer*/;
        sum = sum + arr[i]; /** end pointer*/

        if (sum < x)
        {
            ans = max(ans, sum);
        }
    }

    return ans;
}

// Smallest Subarray with sum > K
// Slidiling window approach
// Use variables ans  , sum , start
// Iterate over array & start adding elements to sum
// If sum > x , remove elements from the start
// O(n)

// ans = INT_max or size greter than n , such way no possible solution is found , sum = 0 , X given

int smallestSubarraywithSum(int arr[], int n, int x)
{
    int sum = 0, minLength = n + 1, start = 0, end = 0;

    while (end < n)
    {
        while (sum < x && end < n)
        {
            sum += arr[end++];
        }

        while (sum >= x && start < n)
        {
            if (end - start < minLength)
            {
                minLength = end - start;
            }

            sum -= arr[start++];
        }
    }

    return minLength;
}

// Number formed from subarray of size k divisible by 3;
// O(n)
void computeNumberFromSubarray(vector<int> arr, int k)
{
    pair<int, int> ans;
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    bool found = false;

    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }

    for (int j = k; j < arr.size(); j++)
    {
        if (found)
        {
            break;
        }

        sum += arr[j] - arr[j - k]; // Sliding Window Technique

        if (sum % 3 == 0)
        {
            ans = make_pair(j - k + 1, j);
            found = true;
        }
    }

    if (!found)
    {
        ans = make_pair(-1, 0);
    }
    if (ans.first == -1)
    {
        cout << "No such Pair Exist." << endl;
    }
    else
    {
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

// Subarray of size k with palindromic concatenation
// O(n2)
// We are returing the starting index where palindrome exists

bool isPalindrome(int n){
    int temp = n , number = 0;

    // Calculates reverse of a number
    while(temp > 0){
        number = number*10 + temp%10;
        temp = temp/10;
    }

    if(number == n){
        return true;
    }

    return false;
}

int findPalindromicSubarray(vector<int> arr, int k)
{
    int num = 0;

    for (int i = 0; i < k; i++)
    {
        // Concatenation
        num = num * 10 + arr[i];
    }

    if (isPalindrome(num))
    {
        return 0;
    }

    for (int j = k; j < arr.size(); j++)
    {
        // Both subtraction & addition in same line
        num = (num % (int)pow(10, k - 1)) * 10 + arr[j];

        if (isPalindrome(num))
        {
            return j-k+1;
        }
    }

    return -1;
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
    root->left = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(2);
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
    // cout<<largestBSTinBT(root).ans<<endl;

    // inorder(root);
    // cout<<endl;
    // restoreBST(root);

    // inorder(root);
    // cout<<endl;

    // int arr[] = {1 , 2 , 8 , 4 , 9};
    // int n = 5;
    // int k = 3;

    // cout<<largestMinDistance(arr , n , k);

    // int arr[] = {12 , 34 , 67 , 90};

    // int n = 4;
    // int m = 2;
    // cout<<allocateMinimumPages(arr , n , m);

    // int arr[] = {6, 7, 8, 9, 10, 1, 2, 3};
    // int n = 8;
    // int key = 8;

    // int idx = searchInRotatedArray(arr , key , 0 , n-1);
    // if(idx == -1){
    //     return false;
    // }else{
    //     return true;
    // }

    // cout<<peakElements(arr, 0, 7 , 7); // return index
    // int arr[] = {1, 4, 45, 6, 10, 19};
    // cout<<maxSubarraySum(arr , 6 , 3 , 20);
    // if (smallestSubarraywithSum(arr, 6, 51) == 7 /**n+1*/)
    // {
    //     cout << "No such Subarray Exist" << endl;
    // }
    // else
    // {
    //     cout << smallestSubarraywithSum(arr, 6, 51) << endl;
    // }

    // vector<int> arr = {84, 23, 45, 12, 56, 82};
    // computeNumberFromSubarray(arr, 3);

    vector<int> arr = {2 , 3, 5, 1, 1, 5};
    cout<<findPalindromicSubarray(arr , 4);

    return 0;
}
