// Linear & Bineary Search
#include <bits/stdc++.h>
#include <algorithm>
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
        if (!is_sorted(arr, arr + n))
        {
            sort(arr, arr + n);
        }
        int low = 0, high = n - 1, mid;
        while (low <= high)
        {
            mid = ceil(low + high) / 2;
            if (k == arr[mid])
            {
                return mid;
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

// Min and max element in array using the minimum number of camparisons (O(n) O(1))

void minMaxEle(vector<int> arr)
{
    int n = arr.size();

    int mn = INT_MAX;
    int mx = INT_MIN;
    // If odd : 0th element is min and max
    // if even : min nd max as per elements

    // Then process the elements in pair

    int i;
    if (n % 2 == 0)
    {
        // Even
        if (arr[0] > arr[1])
        {
            mx = arr[0];
            mn = arr[1];
        }
        else
        {
            mx = arr[1];
            mn = arr[0];
        }
        i = 2;
    }
    else
    {
        // Odd
        mx = arr[0];
        mn = arr[0];
        i = 1;
    }

    // Process 2 elements at once
    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > mx)
            {
                mx = arr[i];
            }

            if (arr[i + 1] < mn)
            {
                mn = arr[i + 1];
            }
        }
        else
        {
            if (arr[i + 1] > mx)
            {
                mx = arr[i + 1];
            }

            if (arr[i] < mn)
            {
                mn = arr[i];
            }
        }

        i += 2;
    }

    cout << mn << " " << mx;
}

int main()
{
    // Solution s;
    // int n; // size of array
    // cin >> n;

    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // int k; // Element to be Searched
    // cin >> k;

    // Call the Function as per required-----
    // s.linearSearch(arr, n, k);

    // int result = s.binarySearch(arr, n, k);
    // if (result == -1)
    // {
    //     cout << "NOT FOUND" << endl;
    // }
    // else
    // {
    //     cout << result << endl;
    // }

    vector<int> arr = {1 , 7 , 3 , 4 , 5};
    minMaxEle(arr);
    return 0;
}
