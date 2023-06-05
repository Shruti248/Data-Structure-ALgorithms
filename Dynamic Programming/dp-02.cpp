// Longest Common Subsequence
// Most no of Questions

// Palindrome is the subset of LCS
// Input : X (String) , Y(String )
// Output  common in both strings(LCS) --> print length of LCS

// Subsequence : non contiguous
// substring  Contignous

#include <bits/stdc++.h>
using namespace std;

// Recursive Approach
int LCS(string x, string y, int xlen, int ylen)
{
    // Bse condition
    if (xlen == 0 || ylen == 0)
    {
        return 0;
    }

    // Choice Diagram
    if (x[xlen - 1] == y[ylen - 1])
        return 1 + LCS(x, y, xlen - 1, ylen - 1);
    else
        return max(LCS(x, y, xlen - 1, ylen), LCS(x, y, xlen, ylen - 1));
}

// Memorized Version (Bottom Up Approach)
int static t[1001][1001];
int LCSMemorized(string x, string y, int xlen, int ylen)
{
    // Bse condition
    if (xlen == 0 || ylen == 0)
    {
        return 0;
    }

    // int t[xlen+1][ylen+1]; --> Depends on constraint : If x , y max value is 1000 , take one more .

    if(t[xlen][ylen] != -1)
        return t[xlen][ylen];

    // Choice Diagram
    if (x[xlen - 1] == y[ylen - 1])
        return t[xlen][ylen] = 1 + LCSMemorized(x, y, xlen - 1, ylen - 1);
    else
        return t[xlen][ylen] = max(LCSMemorized(x, y, xlen - 1, ylen), LCSMemorized(x, y, xlen, ylen - 1));
}


int main()
{
    string x = "abcde";
    string y="cbe";
    // cout<<LCS(x , y , 5 , 3);


    memset(t , -1 , sizeof(t));
    cout<<LCSMemorized(x , y , 5 , 3);
    return 0;
}
