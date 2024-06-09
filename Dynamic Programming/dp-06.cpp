// Fibonnaci

#include <bits/stdc++.h>
using namespace std;

// Memorization
int fibonnaci(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = fibonnaci(n - 1, dp) + fibonnaci(n - 2, dp);
}

// Tabulation
int fibTabulation(int n, vector<int> &dp)
{

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// 1D DP

// 1) Climbing Stairs
// Same as fibonnaci --> Just the variation dp[0] = 1 -- Else same

// Frog Jump : Find min energy consumed
int frogJump(int n, vector<int> ht)
{
    vector<int> dp(n, -1);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int jumpTwo = INT_MAX;

        int jumpOne = dp[i - 1] + abs(ht[i] - ht[i - 1]);

        if (i > 1)
        {
            jumpTwo = dp[i - 2] + abs(ht[i] - ht[i - 2]);
        }

        dp[i] = min(jumpOne, jumpTwo);
    }

    return dp[n - 1];
}

// Frog Jump with k distances
int frogJumpKDist(vector<int> ht, int k)
{
    int n = ht.size();
    vector<int> dp(n, -1);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if(i-j >= 0){
                int jump = dp[i-j] + abs(ht[i] - ht[i-j]);
                minSteps = min(minSteps , jump);
            }
        }

        dp[i] = minSteps;
    }

    return dp[n-1];
}


// DP On Stocks (6 problems)


int main()
{
    // int n;
    // cin>>n;
    // vector<int> dp(n+1 , -1);
    // cout<<fibonnaci(n , dp);
    // cout<<fibTabulation(n , dp);

    // cout << frogJump(6, {30, 10, 60, 10, 60, 50});
    cout << frogJumpKDist({30, 10, 60, 10, 60, 50} , 2);
    return 0;
}
