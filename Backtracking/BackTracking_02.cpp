// N Queen Problem
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSafe(int **arr, int x, int y, int n)
    {
        for (int row = 0; row < x; row++)
        {
            if (arr[row][y] == 1)
            {
                // If queen is present
                return false;
            }
        }

        // DIagonals
        int row = x;
        int column = y;

        // Left diagonal : row-- , column --
        // Right diagonal : row-- , column ++

        // Left Diagonal
        while (row >= 0 && column >= 0)
        {
            if (arr[row][column] == 1)
            {
                return false;
            }
            row--;
            column--;
        }

        row = x;
        column = y;
        // Right Diagonal
        while (row >= 0 && column < n)
        {
            if (arr[row][column] == 1)
            {
                return false;
            }
            row--;
            column++;
        }

        return true;
    }

    // Every queen has to be placed in each column --- no 2 queens in same row , hence y is not required
    bool nQueen(int **arr, int x, int n)
    {

        // Base
        if (x >= n)
        {
            // Means n queens are placed
            return true;
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafe(arr, x, col, n))
            {
                arr[x][col] = 1;

                // if it is placed at this position then checking if the queen can be placed in next row
                if (nQueen(arr, x + 1, n))
                {
                    return true;
                }

                // Backtracking
                arr[x][col] = 0;
            }
        }

        return false;
    }
};
int main()
{
    Solution s;

    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (s.nQueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}