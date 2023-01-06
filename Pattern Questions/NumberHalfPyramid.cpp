#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 1
    // 1 2
    // 1 2 3
    void NumberHalfPyramid(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    cout << " " << i << " ";
                }
                else if (i > j)
                {
                    cout << " " << j << " ";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    void SameNumberHalfPyramid(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= j)
                {
                    cout << " " << i << " ";
                }
                else
                {
                    cout << "   ";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    int n;
    Solution s;
    cin >> n;
    s.NumberHalfPyramid(n);
    cout << endl
         << endl;
    s.SameNumberHalfPyramid(n);
    return 0;
}
