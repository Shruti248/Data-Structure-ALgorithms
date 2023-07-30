#include <bits/stdc++.h>
using namespace std;

// Count Number of Digits

// O(n)
// O(1)
int countDigitsI(int n)
{
    int count = 0;

    while (n > 0)
    {
        n = n / 10;
        count++;
    }

    return count;
}

// O(1)
// O(1)
int countDigitsII(int n)
{
    string num = to_string(n);
    return num.length();
}

// The number of digits in an integer = the upper bound of log10(n).
// O(1)
// O(1)
int countDigitsIII(int n)
{
    return floor(log10(n) + 1);
}

// Reverse the Number
// O(n)
// O(1)
int reverseNumber(int n)
{
    int reversedNum = 0;
    while (n > 0)
    {
        reversedNum = reversedNum * 10 + n % 10;
        n = n / 10;
    }

    return reversedNum;
}

// Check if a number is Palindrome or Not
// O(logn) -- for reversing
// O(1)
bool isPalindrome(int n)
{
    return n == reverseNumber(n);
}

// GCD -- Brute Force
// O(n) O(1)
int GCD(int x, int y)
{
    int mx = INT_MIN;

    int minNum = min(x, y);

    for (int i = 1; i <= minNum; i++)
    {
        if (x % i == 0 && y % i == 0)
        {
            mx = i;
        }
    }

    return mx;
}

// Solution 2: Using Euclidean’s theorem
// Time Complexity: O(logɸmin(a,b)), where ɸ is 1.61.
// Space Complexity: O(1).
int GCDUsingEuclideanTheorem(int x, int y)
{
    if (y == 0)
    {
        return x;
    }

    return GCDUsingEuclideanTheorem(y, x % y);
}

int main()
{
    // cout<<countDigitsI(158);
    // cout<<countDigitsII(123);
    // cout<<countDigitsIII(124);
    // cout<<reverseNumber(123456789);
    // cout<<isPalindrome(12132);
    // cout << GCD(16, 8);
    cout << GCDUsingEuclideanTheorem(16, 32);
    return 0;
}
