// DP
//  Enhanced Recursion : Parent problem is recursion --> All the prob solved by recursion is solved by DP
//  How to recognize DP :

// 1) CHOICE : We will be given a choice (like whether ti include a element or not)
// RECURSION L 2 calls (overlapping problems) --> means DP can be applied. if recursion calls only 1 function --> NO DP
// 2)OPTIMAL : Min , max , largest

// CHOice & optimal IMPORTANT
// OPTIMAL

// How to solve :
// RECURSIVE SOLUTION ---> MEMOIZATION OR TOP DOWN

// PARENT PROBLEMS IN DP (ALL THE OTHER ARE VARIATIONS OF THIS PROBLEMS ONLY)
// 1) 0-1 KANPSACK (6) (Subset , equal sum partition , count subset)
// 2) UNBOUNDED KNAPSACK (5)
// 3) FIBONNACI(7)
// 4) LCS(15)
// 5) LIS(10)
// 6) KADANES ALGO(6)
// 7) MATRIX CHAIN MULTIPLICATION(7) --> MOST IMP
// 8) DP ON TREES (4)
// 9) DP ON GRID(14)
// 10) OTHERS(5)

// Knapsack Problem 1) Fractional (Greedy) (We can divide the item into fractional & take the profit to maximimze it 2) 01(take the item completely or not at all ) (Either 0 or 1 ) (DP) 3) Unbounded Knapsack ( we can select the item any number of times as per req , whereas in 01 we can take only 1 item)

// PROBLEM 1 : 0 1 KnapSack (choice & optimal(max))(identification)
// same problem variation :
// Subset Sum ,
//  Equal sum partition ,
// count of subset sum ,
// min subset sum diff ,
// target sum ,
// no of subset with given diff

// DP = recursion + Storage(Memoization or Top Down)

// Input : Weight[]
// value[]
// W (Total Weight)

// Output : Max Profit

// Choice Diagram
//          W1
// /       \
// W1 <= W       W1>W
// /  \        \
//   Yes    No      No    --> 3 Possibilities

#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{

    int t[n + 1][W + 1];
    memset(t, -1, sizeof(t));

    // Base Condition (Thik of the smallest valid Input)
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (t[n][W] != -1)
        return t[n][W];

    // choice Diagram
    if (wt[n - 1] <= W)
    {
        return t[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }

    if (wt[n - 1] > W)
    {
        return t[n][W] = knapsack(wt, val, W, n - 1);
    }

    // MEMOIZATION
    // int t[n+1][W+1];  // Use the variales that change in the recursive Call(n+1 == Col && W+1 == row)

    // Initialize the complete matrix with -1;
    // memset(t , -1 , sizeof(t));
    // Chacek the value : If -1 Then make the recursive call & store the result , else do not repeat the recursive call , take the reult stored in it directly & use it....
}

// Top Down Approach
// Recursive Call is removed
// Only table for O/P
// Better beacuse in recursive call the stack is occupied (Stack overflow error)
// This is best

// COnvert RECURSIVE CALL --> Top Down Table(Make matrix of the changeable values

// Step1) Intilization
// Step2) Recursive call is cahnged to iterative version

// BAse case (Recursive)---> Intialization(Iterative)

// Base case : if(n==0 || w == 0) return 0;

// Intialization
// t[n+1][W+1] table

// for(int i = 0 ; i< n+1 ; i++){
//     for(int j = 0 ; j<W+1 ; j++){
//         if(i == 0 || j == 0){
//             t[i][j] = 0;
//         }
//     }
// }

// choice Diagram
// Recursive
// See above

// iterative Top Down
// Cahnge n with i & W with j because we need to fill the matrix
// if(wt[n-1] <= W){
//     t[n][w] = max(val[n+1] + t[n-1][w-wt[n-1]] , t[n-1][w]);
// }else{
//     t[n][w] = t[n-1][w]
// }

int knapsackTopDownApproach(int wt[], int val[], int W, int n)
{

    int t[n + 1][W + 1];
    // base
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
                continue;
            }

            // Choice Diagram
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][W];
}

int main()
{
    int wt[] = {5, 20, 10};
    int val[] = {50, 140, 60};

    cout << knapsack(wt, val, 30, 3)<<endl;
    cout<<knapsackTopDownApproach(wt , val , 30 , 3)<<endl;
    return 0;
}
