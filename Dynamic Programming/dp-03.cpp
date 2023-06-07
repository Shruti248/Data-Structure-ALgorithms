// Matrix chain Multiplication

// Identification
// Given : String or Array
// Take some i & j
// Take k between k
// SO larger problem (i to j) --> divided in various subproblems(i to k & k+1 to j)
// SO smaller problems will be solved by taking k everytime between i to j
// All the partition of different k will result in some temp ans;
// We apply some function in the temp ans to get the final ans

// Main format code : All the questions based on MCM will have this format

// NOTE : Base condition of recursion : (Smallest valid Input or think of first invalid Input )

// Recursive Code
// int solve( int arr[] , int i , int j){

//     // Base condition
//     // i == j : 1 element in array
//     // i > j : Invalid input (No element in array)
//     if(i > j){
//         return 0;
//     }

//     // Breaking into k from i to j
//     for(int k = i ; k<j ; k++){
//         // Calculate temp ans
//         int tempAns = solve(arr , i , k) + solve(arr , k+1 , j);

//         int ans = func(tempAns) // applying some func in tempAns (like max , min etc ) )which depends on question
//     }

//     return ans;

// }

// Change teh format as per the questions

#include <bits/stdc++.h>
using namespace std;

// MCM Recursive
// Input : Arr[](A1 A2 A3 ... --> Matrix (Find dimensionfrom that))
// Output : Multiply the array inputs such that the cost is minimum

// ARRAY SIze : n --->  MATRIX SIZE : n-1

// FORMULA FOR CALCULATING DIMENSION
// Ai = arr[i-1] * arr[i]

// FORMULA FOR CALCUING COST OF MATRIX
// Eg : Matrix are : 20 x 3 & 3 x 10
// COst : 20 x 3(common) x 10 --> 600

// Eg : [40 20 30 10 30]
// arrsize = 5 then matric is 4
// Dimension of matrixs
// A1 --> 40 x 20
// A2 --> 20 x 30
// A3 --> 30 x 10
// A4 --> 10 x 30

// CHOOSING i & j  --> Passed in main Function
// i --> left end --> index 1 --> bcoz at index 0(Ai = arr[i-1] * arr[i]) is violated
// j --> right end --> n-1(Last index)

int solve(int arr[], int i, int j)
{

    // Base Case
    // i == j --> 1 matrix --> No multiplication for 1 matrix
    if (i >= j)
    {
        return 0;
    }

    // 2 Possible cases --> do any one
    // k = i , k = j-1 , i to k , k+1 to j
    // k = i-1 , k = j , i to k-1 , k to j

    // Eg : i to k (AB)
    // Eg : k+1 to j (CD)
    // Total cost : (AB) * (CD) --> Multiplying AB & CD is also a cost
    // That is multiplying the 2 groups cost.

    // Calculating the cost of 2 groups
    // arr[i-1]*arr[k]*arr[j];

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int cost = arr[i - 1] * arr[k] * arr[j];
        int tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + cost;

        ans = min(ans, tempAns);
    }

    return ans;
}

// MCM Memorized (Bottom Up)

int static t[1001][1001];
int solveMemorized(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }

    if (t[i][j] != -1)
    {
        return t[i][j];
    }

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

        ans = min(ans, tempAns);
    }

    return t[i][j] = ans;
}

// Palindrome Partioning
// Divide the string in such a way that all the substrings are plaindrome , return the number of partitions done

// Input : String
// Output : No of partition (Minimize) --> each partition should be a palindrome

// i =  0 , j - s.length()-1;

bool isPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }

    return true;
}

// Recursive
int palindromePartioning(string s, int i, int j)
{

    // i == j , string klength 1 , 0 partition required
    // is s is palindrome , 0 partition
    if (i >= j || isPalindrome(s, i, j))
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int tempAns = palindromePartioning(s, i, k) + palindromePartioning(s, k + 1, j) + 1 /**Partition of groups*/;
        ans = min(ans, tempAns);
    }

    return ans;
}

// Recursive
int palindromePartioningMemorized(string s, int i, int j)
{

    // i == j , string klength 1 , 0 partition required
    // is s is palindrome , 0 partition
    if (i >= j || isPalindrome(s, i, j))
    {
        t[i][j] = 0;
        return 0;
    }

    if(t[i][j] != -1){
        return t[i][j];
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int tempAns = palindromePartioningMemorized(s, i, k) + palindromePartioningMemorized(s, k + 1, j) + 1 /**Partition of groups*/;
        ans = min(ans, tempAns);
    }

    return t[i][j] = ans;
}

// Memorized Optimized
int palindromePartioningMemorizedOptimized(string s, int i, int j)
{

    // i == j , string klength 1 , 0 partition required
    // is s is palindrome , 0 partition
    if (i >= j || isPalindrome(s, i, j))
    {
        t[i][j] = 0;
        return 0;
    }

    if(t[i][j] != -1){
        return t[i][j];
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        // int tempAns = palindromePartioning(s, i, k) + palindromePartioning(s, k + 1, j) + 1;

        // Checking if the recursive calls are already solved in the table
        int left , right;
        if(t[i][k] != -1){
            left =  t[i][k];
        }else{
            left = palindromePartioningMemorizedOptimized(s , i , k);
            t[i][k] = left;
        }

        if(t[k+1][j] != -1){
            right = t[k+1][j];
        }else{
            right = palindromePartioningMemorizedOptimized(s , k+1 , j);
            t[k+1][j] = right;
        }

        int tempAns = left + right + 1;

        ans = min(ans, tempAns);
    }

    return t[i][j] = ans;
}

int main()
{
    // int arr[] = {40, 20, 30, 10, 30};
    // cout << solve(arr, 1 /**i*/, 4 /**j*/);

    // int arr[] = {1, 2, 3, 4, 3};
    // cout << solve(arr, 1, 4);

    // int arr[] = {1 , 2 , 3};
    memset(t , -1 , sizeof(t));
    // cout<<solveMemorized(arr , 1 , 2);

    string s = "YnitinX";
    cout << palindromePartioning(s, 0, s.length() - 1)<<endl;
    cout<<palindromePartioningMemorized(s , 0 , s.length()-1);

    return 0;
}
