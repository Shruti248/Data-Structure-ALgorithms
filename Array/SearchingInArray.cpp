// Linear & Bineary Search
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution
{
public:
    // Supports Multiple Occurences of the elements in the array
    void linearSearch(int arr[], int n, int k)
    {
        int ElementFoundStatus = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == k)
            {
                cout << "Element is Present in array at position = " << i + 1 << endl;
                ElementFoundStatus = 1;
            }
        }

        if (ElementFoundStatus == 0)
        {
            cout << "Element NOT FOUND" << endl;
        }
    }

    // Works only on the SORTED ARRAY
    int binarySearch(int arr[], int n, int k)
    {   
        // if the array is not already sorted , sort it first 
        if( ! is_sorted(arr , arr+n)){
            sort(arr , arr+n);
        }
        int low = 0, high = n - 1, mid;
        while (low <= high)
        {
            mid = ceil(low + high) / 2;
            if (k == arr[mid])
            {
                return arr[mid];
            }
            if (k > arr[mid])
            {
                // ELement Present at right Part
                low = mid + 1;
            }
            if (k < arr[mid])
            {
                // Elememt Present at left Part
                high = mid - 1;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    int n; // size of array
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k; // Element to be Searched
    cin >> k;

    // Call the Function as per required-----
    s.linearSearch(arr, n, k);

    // int result = s.binarySearch(arr, n, k);
    // if (result == -1)
    // {
    //     cout << "NOT FOUND" << endl;
    // }
    // else
    // {
    //     cout << result << endl;
    // }
    return 0;
}