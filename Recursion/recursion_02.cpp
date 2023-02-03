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
};
int main()
{
    Solution s;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<s.isArraySorted(arr , n);
    return 0;
}