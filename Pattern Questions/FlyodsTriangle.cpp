#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void floydTriangle(int n)
    {
        int num = 0;
        // Option1
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i >= j)
        //         {
        //             num++;
        //             cout << " " << num << " ";
        //         }

        //         cout << " " << num << " ";
        //     }
        //     cout << endl;
        // }
        // Option 2
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                num++;
                cout << " " << num << " ";
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
    s.floydTriangle(n);
    return 0;
}