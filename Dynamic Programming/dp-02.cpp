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
// int static t[1001][1001];
int LCSMemorized(string x, string y, int xlen, int ylen)
{
    // Bse condition
    if (xlen == 0 || ylen == 0)
    {
        return 0;
    }

    int t[xlen + 1][ylen + 1]; //--> Depends on constraint : If x , y max value is 1000 , take one more .
    // memset(t , -1 , sizeof(t));

    if (t[xlen][ylen] != -1)
        return t[xlen][ylen];

    // Choice Diagram
    if (x[xlen - 1] == y[ylen - 1])
        return t[xlen][ylen] = 1 + LCSMemorized(x, y, xlen - 1, ylen - 1);
    else
        return t[xlen][ylen] = max(LCSMemorized(x, y, xlen - 1, ylen), LCSMemorized(x, y, xlen, ylen - 1));
}

// Tabulation : Top Down
int LCSTabulation(string x, string y, int xlen, int ylen)
{

    int t[xlen + 1][ylen + 1];

    for (int i = 0; i < xlen + 1; i++)
    {
        for (int j = 0; j < ylen + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
                continue;
            }

            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }

    return t[xlen][ylen];
}


// Longest Common Substring
// Substring is contigous

// Once there is discontinuity , start it again from 0 , that is length = 0 , thenn incremenet if common

int LCSubstring(string x, string y, int xlen, int ylen)
{

    int t[xlen + 1][ylen + 1];

    for (int i = 0; i < xlen + 1; i++)
    {
        for (int j = 0; j < ylen + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
                continue;
            }


            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                // Make length 0 - if discontinous
                t[i][j] = 0;
        }
    }

    // Find max length from table
    int mx = INT_MIN;
    for(int i = 0 ; i<xlen+1 ; i++){
        for(int j = 0 ; j<ylen +1 ; j++){
            mx = max(mx , t[i][j]);
        }
    }

    return mx;
}

int main()
{
    string x = "abcde";
    string y = "cbcda";
    // cout<<LCS(x , y , 5 , 3);

    // memset(t , -1 , sizeof(t));
    // cout<<LCSMemorized(x , y , 5 , 3);

    // cout << LCSTabulation(x, y, 5, 3);

    cout << LCSubstring(x, y, 5, 5);
    return 0;
}
