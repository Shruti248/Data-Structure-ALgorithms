// 24 = 2 2 2 3
// 42 = 2 3 7
// GCD : 2 3 = 6

// Algo
// 42 - 24 = 18 ---> GD of 18 and 24 will also remain same as 42 and 24
// 24-18 = 6
// 18 - 6 = 12
// 12 - 6 = 6
//  6 - 6 = 0
// Before 0 whichever is the ans is the GCD ----> 6

// Better Way : Instead of subtracting ---> Finding Remainder
// 42 % 24 = 18
// 24 % 18 = 6
// 18 % 6 = 0   ---> GCD : 6

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
};
int main()
{
    Solution s;
    int a, b;
    cin >> a >> b;
    cout<< s.gcd(a, b);

    return 0;
}