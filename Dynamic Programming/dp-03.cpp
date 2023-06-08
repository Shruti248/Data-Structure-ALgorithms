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

    if (t[i][j] != -1)
    {
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

    if (t[i][j] != -1)
    {
        return t[i][j];
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        // int tempAns = palindromePartioning(s, i, k) + palindromePartioning(s, k + 1, j) + 1;

        // Checking if the recursive calls are already solved in the table
        int left, right;
        if (t[i][k] != -1)
        {
            left = t[i][k];
        }
        else
        {
            left = palindromePartioningMemorizedOptimized(s, i, k);
            t[i][k] = left;
        }

        if (t[k + 1][j] != -1)
        {
            right = t[k + 1][j];
        }
        else
        {
            right = palindromePartioningMemorizedOptimized(s, k + 1, j);
            t[k + 1][j] = right;
        }

        int tempAns = left + right + 1;

        ans = min(ans, tempAns);
    }

    return t[i][j] = ans;
}

// Boolean Parentheses
// evaluate expression to true
// input : STring (Constitues of this symbols : T F & | ^(XOR))
// Output : int (Number of ways to evaluate the expression to true)

// How to place brackets in the string to evaluate the expression to true

// K will be always on operator(| & ^) bcoz thane only it will be evaluated
// Eg : T | F & T ^ F
// k on 1 , 3 , 5 indexes
// k incremented by 2 --->  k+=k+2

// i = 0 & j= s.length()-1;

// k is on some operator
// 1st expression : i to k-1
// 2md expression : k+1 to j

// Subprobelms when evaluated can be true or false.. Therefore the numbers of ways in which the subporblems can result in true and false is also needed ..... Therefore on eargument in teh function increases

// boolean isTrue --> true --> NUmber of ways in which expression is evaluated true
// boolean isTrue --> false --> NUmber of ways in which expression is evaluated false

int booleanParentheses(string s, int i, int j, bool isTrue)
{
    if (i > j)
    {
        return false;
    }
    if (i == j)
    {
        if (isTrue)
            return s[i] == 'T';
        return s[i] == 'F';
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {

        // Temp Ans
        int leftTrue = booleanParentheses(s, i, k - 1, true);
        int leftFalse = booleanParentheses(s, i, k - 1, false);
        int rightTrue = booleanParentheses(s, k + 1, j, true);
        int rightFalse = booleanParentheses(s, k + 1, j, false);

        // Ans
        if (s[k] == '&')
        {
            if (isTrue)
                ans += leftTrue * rightTrue;
            else
                ans += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ans += leftTrue * rightTrue + leftTrue + rightFalse + leftFalse * rightTrue;
            else
                ans += leftFalse * rightFalse;
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                ans += leftTrue * rightFalse + leftFalse * rightTrue;
            else
                ans += leftTrue * rightTrue + leftFalse * rightFalse;
        }
    }

    return ans;
}

// Evaluate Expression to True
// Boolean Parentheses

// Memorized
int dp[2][1001][1001];
int booleanParenthesesMemorized(string s, int i, int j, bool isTrue)
{
    if (i >= j)
    {
        if (isTrue)
            dp[1][i][j] = s[i] == 'T';
        else
            dp[0][i][j] = s[i] == 'F';
        return dp[isTrue][i][j];
    }

    if (dp[isTrue][i][j] != -1)
    {
        return dp[isTrue][i][j];
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {

        // Temp Ans
        int leftTrue = booleanParenthesesMemorized(s, i, k - 1, true);
        int leftFalse = booleanParenthesesMemorized(s, i, k - 1, false);
        int rightTrue = booleanParenthesesMemorized(s, k + 1, j, true);
        int rightFalse = booleanParenthesesMemorized(s, k + 1, j, false);

        // Ans
        if (s[k] == '&')
        {
            if (isTrue)
                ans += leftTrue * rightTrue;
            else
                ans += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ans += leftTrue * rightTrue + leftTrue + rightFalse + leftFalse * rightTrue;
            else
                ans += leftFalse * rightFalse;
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                ans += leftTrue * rightFalse + leftFalse * rightTrue;
            else
                ans += leftTrue * rightTrue + leftFalse * rightFalse;
        }
    }

    dp[isTrue][i][j] = ans;

    return ans;
}

// Scrambled String
// Input : String a , b
// Output : T/F(is the string a scarmbled string of other string)

// Constraint
// COnstruct a biary tree of string
// No child should be empty

// You can swap 0 or more non leaf nodes --> to get teh second string --> The 2 strings formed are said to be scrambled sring

// Sum up : Generate a binary tree for one string , swap the non leaft nodes & get the other strings...This strings so formed are said to be scrambled string ...

// k = 1 to n-1 --> We break the string


// Eg :
    // great (For k = 2 we are breaking the string )
    // gr    eat
    // We can either swap or not swap :
    // Swap : eat    gr --> Scrambled string
    // No Swap : gr   eat --> Scrambled string

    // We recursively cahcek gr of 1st and gr of last if they are scrambled , similarly we check for eat & eat --> if both scrambled than whole string scrambled

// The 2 strings can be further broen down to either swap or not to get the desired scrambled string

bool isScrambledString(string a, string b) {

    // Base condition
    if (a.compare(b) == 0) {
        // Equal strings
        return true;
    }

    if (a.length() <= 1) {
        // No string can be empty
        return false;
    }

    int n = a.length();

    for (int i = 1; i < n; i++) {

        bool condition1 = isScrambledString(a.substr(0, i), b.substr(n - i, i)) && isScrambledString(a.substr(i, n - i), b.substr(0, n - i));

        bool condition2 = isScrambledString(a.substr(0, i), b.substr(0, i)) && isScrambledString(a.substr(i, n - i), b.substr(i, n - i));

        if (condition1 || condition2) {
            return true;
        }
    }

    return false;
}

// Memorized : Bottom Up Approach
unordered_map<string , bool> mp;
bool isScrambledStringMemorized(string a, string b) {

    // Base condition
    if (a.compare(b) == 0) {
        // Equal strings
        return true;
    }

    if (a.length() <= 1) {
        // No string can be empty
        return false;
    }

    int n = a.length();

    string key = a;
    key.push_back(' '); // a_
    key.append(b);   //a_b

    if(mp.find(key) != mp.end()){
        return mp[key];
    }

    for (int i = 1; i < n; i++) {

        bool condition1 = isScrambledStringMemorized(a.substr(0, i), b.substr(n - i, i)) && isScrambledStringMemorized(a.substr(i, n - i), b.substr(0, n - i));

        bool condition2 = isScrambledStringMemorized(a.substr(0, i), b.substr(0, i)) && isScrambledStringMemorized(a.substr(i, n - i), b.substr(i, n - i));

        if (condition1 || condition2) {
            return mp[key] =  true;
        }
    }

    return mp[key] = false;
}



int main()
{
    // int arr[] = {40, 20, 30, 10, 30};
    // cout << solve(arr, 1 /**i*/, 4 /**j*/);

    // int arr[] = {1, 2, 3, 4, 3};
    // cout << solve(arr, 1, 4);

    // int arr[] = {1 , 2 , 3};
    memset(t, -1, sizeof(t));
    // cout<<solveMemorized(arr , 1 , 2);

    // string s = "abcbdd";
    // cout << palindromePartioning(s, 0, s.length() - 1)<<endl;
    // cout<<palindromePartioningMemorized(s , 0 , s.length()-1)<<endl;
    // cout<<palindromePartioningMemorizedOptimized(s , 0 , s.length()-1);

    // string s = "T^F&T";
    // cout << booleanParentheses(s, 0, s.length() - 1, true) << endl;

    // memset(dp[0], -1, sizeof(dp[0]));
	// memset(dp[1], -1, sizeof(dp[1]));
    // cout << booleanParenthesesMemorized(s, 0, s.length() - 1, true) << endl;

    string a = "great";
    string b = "rgeta";

    cout<<isScrambledString(a , b)<<endl;
    cout<<isScrambledStringMemorized(a , b);

    return 0;
}
