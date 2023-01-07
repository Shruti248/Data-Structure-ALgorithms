#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
             // 1
        //    212
        //   32123
        //  4321234
        // 543212345
    void palindromicPattern(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            // Columns -- 3 Parts
            // 1) Space in the start
            for (int j = 1; j <= n - i; j++)
            {
                cout << " ";
            }
            // 2) Numbers in decreasing Order
            int k = i; // Value to be printed same as row No.
            for (int j = n-i+1; j <= n; j++)
            {
                cout<<k--;
            }

            // 3) Numbers in increasing Order
            k=2;
            for(int j = n+1 ; j<=n+i-1 ; j++){
                cout<<k++;
            }

            cout << endl;
            
        }
    }
};
int main()
{
    int n;
    cin >> n;
    Solution s;
    s.palindromicPattern(n);

    return 0;
}