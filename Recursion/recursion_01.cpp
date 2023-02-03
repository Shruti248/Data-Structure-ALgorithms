// Function calls Itself to make the problem smaller

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Add All The Numbers till n
    // Sum till n = n+ n-1 + n-2 ...... +1
    // Sum till n =  n+ sum till n-1
    // Sum till n-1 =  n-1 + sum till n-2
    // And so on.....

    // Sum till 0 = 0
    // Stop at 0 (Endpoint where it eeds to be stopped).
    int Sum(int n)
    {

        // Ending point
        if (n == 0)
        {
            return 0;
        }
        int prevSum = Sum(n - 1);
        // cout<<prevSum<<endl;
        return n + prevSum;
    }

    // Calculate n raised to power p
    // n^p = n*n*n*n*.......p times
    // n^p = n*n^p-1
    // n^p-1 = n*n^p-2
    // n^p-2 = n*n^p-3
    // And So on

    //  n^0 = 1
    // Stop
    int powerOfN(int n, int p)
    {
        if (p == 0)
        {
            return 1;
        }

        int prevRes = powerOfN(n, p - 1);
        return n * prevRes;
    }

    // Find the factorial of a number n
    // n! = n*n-1*n-2.....1;
    // n! = n*n-1!
      // n-1! = n*n-2!

    // n = 0 STOP return 1
    int factorial(int n)
    {

        if (n == 0)
        {
            return 1;
        }

        // int prevRes = factorial(n - 1);
        // return n * prevRes;

        // Same as above
        return n*factorial(n-1);
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    // cout<<s.Sum(n);
    // int p;
    // cin >> p;
    // cout << s.powerOfN(n, p);
    cout << s.factorial(n);
    return 0;
}
