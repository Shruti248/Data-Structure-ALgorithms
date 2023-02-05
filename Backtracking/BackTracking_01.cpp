// technique to solve recursive problems by trying to build every possible solution incremnetally and removing those solutions that fail to satisfy the constraints pf the probem at any point of time...

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // rat in a Maze
    // Given Matrix :
    // 1 0 1 0 1
    // 1 1 1 1 1
    // 0 1 0 1 0
    // 1 0 0 1 1
    // 1 1 1 0 1

    // Every 1 represents we can move in that direction , but a 0 means that is blocked , hence cannot move further
    // Result : Matrix which represents the ans path by 1 and all other points as 0

    // A function to check if we can go to that direction or not ---- if true --well and go -- if false -- we need to backtract later
    bool isSafe(int** arr /**Memory Allocated Dynamicallty*/, int x, int y /***Current positions*/, int n /**Size of square matrix*/)
    {
        if (x < n && y < n && arr[x][y] == 1)
        {
            return true;
        }
        return false;
    }

    // Main function
    bool ratInMaze(int** arr, int x, int y, int n, int** solArr)
    {

        // Base condition
        if ((x == n - 1) && (y == n - 1))
        {
            // Rat reached at desired position
            solArr[x][y] = 1;
            return true;
        }

        // if a particular place is safe or not to move
        if (isSafe(arr, x, y, n))
        {
            // if yes : Set 1
            solArr[x][y] = 1;
            if (ratInMaze(arr, x + 1, y, n, solArr))
            {
                // this will return true only wehne on moving in RIGHT DIRECTION , We get a solution
                return true;
            }
            if (ratInMaze(arr, x, y + 1, n, solArr))
            {
                // Move in Downward Direction
                return true;
            }
            // If the solution is not found in the right or in the downward direction , we need to backtrackk
            solArr[x][y] = 0; // Backtarcking --- Changing the ans  back to 0
            return false;
        }
        return false;
    }
};
int main()
{
    Solution s;
    int n;
    cin >> n; // SIze of square matrix

    int** arr = new int*[n]; // Dynamic Allocation

    // Allocating Memory
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    // Input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Solutipn Array
    int** solArr = new int*[n]; // Dynamic Allocation

    // Allocating Memory
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        // Inilializing all the values of array as 0 , ele garbage value
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    if (s.ratInMaze(arr, 0, 0, n, solArr))
    {
        // If true then solution array is required
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] <<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}