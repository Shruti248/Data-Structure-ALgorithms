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

    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1
    void InvertedNumberHalfPyramid(int n)
    {
        for (int i = n; i > 0; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                // if(i>=j){
                cout << " " << j << " ";
                // }
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

    // 1
    // 0 1
    // 1 0 1
    // 0 1 0 1
    void zeroOnePattern(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {

                if ((i + j) % 2 == 0)
                {
                    cout << " " << 1 << " ";
                }
                else
                {
                    cout << " " << 0 << " ";
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
    s.InvertedNumberHalfPyramid(n);
    cout << endl
         << endl;
    s.SameNumberHalfPyramid(n);
    cout << endl
         << endl;
    s.zeroOnePattern(n);

    return 0;
}
