// Fibonnaci

#include<bits/stdc++.h>
using namespace std;

// Memorization
int fibonnaci(int n , vector<int> &dp){
    if(n <= 1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = fibonnaci(n-1 , dp) + fibonnaci(n-2 , dp);
}

// Tabulation
int fibTabulation(int n , vector<int> &dp){

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2 ; i<=n ; i++){
        dp[i]  = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// 1D DP

// 1) Climbing Stairs
// Same as fibonnaci --> Just the variation dp[0] = 1 -- Else same

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1 , -1);
    // cout<<fibonnaci(n , dp);
    cout<<fibTabulation(n , dp);

    return 0;
}
