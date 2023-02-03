#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // check if the array is sorted or not

    // 1 2 3 4 5 6 7 8 --> Stricly increasing
    // array[0] < array[1] AND array[1 ... n] SORTED --> Checl this 2

    // array at n = array at n-1 is smaller
    // array at n-1 = array at n-2 is smaller
    // array at n-2 = array at n-3 is smaller

    // array at 2nd position = array at 1st position is smaller

    bool isArraySorted(int arr[], int n)
    {

        // Base Condition
        if (n == 1)
        {
            return true;
        }

        bool restArray = isArraySorted(arr + 1 /**From 1st index rather than 0*/, n - 1);

        // if(arr[0] < arr[1] && restArray){
        //     // If both conditions are satisfied
        //     return true;
        // }

        // return false;

        // Same as above commented portion
        return (arr[0] < arr[1] && restArray);
    }

    // Print numbers till n
    // 1) Decreasing Order
    // n , n-1 .... 0
    // 2) Increasing order

    void printNumbers(int n)
    {
        // Decreasing Order
        // if(n==0){
        //     return;
        // }

        // cout<<n<<endl;
        // printNumbers(n-1);

        // Increasing Order
        if (n == 0)
        {
            return;
        }

        printNumbers(n - 1);
        cout << n << endl;
    }

    // Find First And Last Occurence of the Number in a Array
    // 1) First occurence
    // -- Traverse using recursion from first
    // 2) Last Occurence
    // -- Traverse from start only -- opposite of first

    int firstOccurence(int arr[], int n, int i /**search from position*/, int key)
    {

        if (i == n)
        {
            return -1;
        }

        if (arr[i] == key)
        {
            return i;
        }
        return firstOccurence(arr, n, i + 1, key);
    }

    // First it will traverse all the way to last and then it will check from there
    int lastOccurence(int arr[], int n, int i, int key)
    {

        if (i == n)
        {
            return -1;
        }
        int restArray = lastOccurence(arr, n, i + 1, key);

        if (restArray != -1)
        {
            return restArray;
        }

        if (arr[i] == key)
        {
            return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << s.isArraySorted(arr, n);

    // s.printNumbers(n);

    int i, key;
    cin >> i;
    cin >> key;
    cout << s.firstOccurence(arr, n, i, key)<<endl;
    cout << s.lastOccurence(arr, n, i, key)<<endl;

    return 0;
}