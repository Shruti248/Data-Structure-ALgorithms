#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void rectangle_pattern(int rows, int columns)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int i = 0; i < columns; i++)
            {
                cout << " * ";
            }
            // New line after the number of column ficnishes -- for the new row
            cout << endl;
        }
    }

    void hollowRectangle(int rows, int columns)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                // All the Stars are in the 1st row/column and last row/column
                if (i == 0 || i == rows - 1)
                {
                    cout << " * ";
                }
                else if (j == 0 || j == columns - 1)
                {
                    cout << " * ";
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
    int rows, columns;
    Solution s;
    cin >> rows;
    cin >> columns;
    // s.rectangle_pattern(rows , columns);
    s.hollowRectangle(rows, columns);
    return 0;
}