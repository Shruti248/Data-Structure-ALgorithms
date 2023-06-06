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

// Same question : Maximum Length of Repeated Subarray
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
    for (int i = 0; i < xlen + 1; i++)
    {
        for (int j = 0; j < ylen + 1; j++)
        {
            mx = max(mx, t[i][j]);
        }
    }

    return mx;
}

// Print LCS between 2 strings
// INput  X Y String , Output : The actual subsequences

string printLCS(string x, string y, int xlen, int ylen)
{

    // LCS Table
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

    // Start from last
    int i = xlen, j = ylen;
    string ans = "";

    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans += x[i - 1];
            i--;
            j--;
            // Got the string equal so moved to upper diagronal , bcoz that is where we had came from in th etable
        }
        else
        {
            // Left block element greater than upper block element
            if (t[i][j - 1] > t[i - 1][j])
            {
                j--;
            }
            else
            {
                // upper block element greater than left block element
                i--;
            }
        }
    }

    // Since we started from last  , teh string taht we got is in reverse format..
    // to get the LCS in correct order , reverse the string
    reverse(ans.begin(), ans.end());

    return ans;
}

// Shortest Common Supersequence
// Input : X Y String
// Output : Merge the 2 strings in such a way that both strig X & Y is present in it.(As a subsequence) (Shortest possible String)

// Eg : X : geek , y : eke ---> output : geeke
// Eg : X : aggtab , y : gxtxayb ---> output : aggtgxabtxaxb

// Any string is said to be supersequence when the other 2 subsequences(strings) are present in it.
// Sequence is maintained in subsequence
// Subsequence not necessary contigouts

// Output the length of the shortest supersubsequence(xlen + ylen - lcs)

int shortestCommonSuperSequence(string x, string y, int xlen, int ylen)
{
    // Same letters in both string are written only once...
    int lcs = LCS(x, y, xlen, ylen);

    // int diffLettersinX = xlen-lcs;
    // int diffLettersinY = ylen-lcs;

    // return lcs + diffLettersinX + diffLettersinY;

    // Bcoz lcs in present in both , we substract it 1 time...
    return xlen + ylen - lcs;
}

// Minimum number of insertion & deletion to convert String x -> to string y

// Input : String x , string y
// Output : Min No. of insertion ,Min no of deletion

// Eg : heap , pea ---> insert p in heap in frot --> pheap --> delete h & p --> pea

// We observe the untouched part ea(no insertion & deletion) is LCS

int minInsertionAndDeletiontoOConvertString(string x, string y, int xlen, int ylen)
{

    int lcs = LCS(x, y, xlen, ylen);

    // int insertion = ylen - lcs;
    // int deletion = xlen - lcs;

    // return insertion + deletion;
    return xlen + ylen - 2 * lcs;
}

// Largest Palindromic Subsequence
// input : agbcba
// Output : 5 (length of longest plaindromic subsequence)

// Eg : a -> a g b c b a
// Reverse of a = a b c b g a
// Applying LCS on above two string : a b c b a --> Longest Palindromic subsequence

// LPS (x)= (equivalent to) LCS(x , reverse(x));

int LPS(string x, int xlen)
{

    string revX = x;
    reverse(revX.begin(), revX.end());
    return LCS(x, revX, xlen, xlen);
}

// Minimum no of deletion in a string to make it palindrome
int minNoOfDeletionForPalindrome(string x, int xlen)
{
    return xlen - LPS(x, xlen);
}

// Print Longest common supersequence

string printLongestCommonSupersequence(string x, string y, int xlen, int ylen)
{

    int t[xlen + 1][ylen + 1];

    // LCS Tabulation
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
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    // LCS Tabulation

    // Traversing from last
    string ans = "";
    int i = xlen, j = ylen;

    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans += x[i - 1];
            i--;
            j--;
        }
        else
        {
            if (t[i - 1][j] > t[i][j - 1])
            {
                ans += x[i - 1];
                i--;
            }
            else
            {
                ans += y[j - 1];
                j--;
            }
        }
    }

    while (i > 0)
    {
        // take left characters from string x
        ans += x[i - 1];
        i--;
    }
    while (j > 0)
    {
        // take left characters from string x
        ans += y[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

// Longest Repeating Subsequence
// Order should be same & can be discontinous

// Eg : a a b e b c d d
//  Subsequenvce 1 : a b d --> you cannot use this letters from thes string again : So string is : aebcd
//  SUbsequence 2 : a b d
//  ABD occcurs 2 x times --> Ans : abd (Output : Print the length --> 3)

// Approach :
// String 1 : a a b e b c d d
// String 2 : a a b e b c d d  (Same string)
// LCS (string 1 & 2) : a a b e b c d d

// if i == j for any letter -->do not include
// Therefore , leetters chosen are as follows :
// a(0 1) a(1 0) b(2 4) e(3 3) b(4 2) c(5 5) d(6 7) d(7 6)  --> Pairing done in the string 1 with string 2 , means a of 0th index is matched with a of 1st index of string 2....

// Now e & c will be removed
//  a a b b d d --> ans : 6/2 = 3

// apply i != j in the code of LCS

int LRS(string x, int xlen)
{

    string y = x;
    int ylen = xlen;

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

            /** Added this condition on LCS CASE (i != j)*/
            if (x[i - 1] == y[j - 1] && i != j)
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    return t[xlen][ylen];
}

// Sequence Pattern Matching
//  Input : x  , Y String
//  Output : True/false --> is x string a subsequence of string y

bool sequencePatternMatching(string x, string y, int xlen, int ylen)
{
    if (xlen == 0 && ylen == 0)
    {
        // "" is a subsequence of ""
        return true;
    }
    else if (ylen == 0)
    {
        // abcd is not a subsequence of ""
        return false;
    }

    return LCS(x, y, xlen, ylen) == min(xlen, ylen);
}

int main()
{
    string x = "axy";
    string y = "adxcpy";
    // cout<<LCS(x , y , 5 , 3);

    // memset(t , -1 , sizeof(t));
    // cout<<LCSMemorized(x , y , 5 , 3);

    // cout << LCSTabulation(x, y, 5, 3);

    // cout << LCSubstring(x, y, 5, 5);

    // cout << printLCS(x, y, 5, 4);

    // cout << shortestCommonSuperSequence(x, y, 5, 4);

    // cout<<minInsertionAndDeletiontoOConvertString(x , y , 5 , 4);

    // cout<<LPS(x , 6)<<endl;

    // cout<<minNoOfDeletionForPalindrome(x , 5);

    // cout<<printLongestCommonSupersequence(x , y , 5 , 6);

    // cout << LRS(x, 8);

    cout << sequencePatternMatching(x, y, 3, 6);
    return 0;
}
