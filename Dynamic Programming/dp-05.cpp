#include<bits/stdc++.h>
using namespace std;

// recursive approach
// Time Complexity: Exponential, as every function calls two other functions.
// Auxiliary space complexity: O(n), as the maximum depth of the recursion tree is n.

int fib(int n){
    if(n <= 0){
        return n;
    }

    return fib(n-1) + fib(n-2);
}


// Iterative Approach to Find and Print Nth Fibonacci Numbers:
// Time Complexity: O(n)
// Auxiliary Space: O(1)
int fibIterative(int n){
    int a = 0 , b = 1 , c , i;

    if(n == 0){
        return a;
    }

    for(int i = 1 ; i<n ; i++){
        c = a+b;
        a = b;
        b = c;
    }

    return b;
}

// DP Approach
// Time complexity: O(n) for given n
// Auxiliary space: O(n)
int fibDP(int n){

    int f[n+2];

    f[0] = 0;
    f[1] = 1;

    for(int i = 2 ; i<=n ; i++){
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}


int main(){
    cout<<fibIterative(9)<<endl;
    return 0;
}
