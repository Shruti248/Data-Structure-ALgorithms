// Identification

// Array or string + FIND subarray or substring + FIND largest or max or least

// ALso k : Window Size will be GIVEN

// Types : 2
// 1) Fixed Sized Window (Like given k , find max sum)
// 2) Varibale Sized Window (No window size will be given)(You need to find the window size , like the largest window or smallest window subjected to a condition) (like given sum , find max k)

// PROBLEMS

#include <bits/stdc++.h>
using namespace std;

// Maximum sum subarray of size k

// Window size is always (k ): j-i+1;

// Initilze : i = 0 , j = 0;

// while(j-i+1) < k --> Increament j --> to find the i and j of size k

// Now maintain the window size

// Remove ith element (i++)
// Add next to jth element (j++)
// Till we reach last

int maxSumSubarray(vector<int> arr, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int mx = INT_MIN;

    while (j < arr.size())
    {
        sum += arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }

        else if (j - i + 1 == k)
        {
            mx = max(sum, mx);
            sum -= arr[i];
            i++;
            j++;
        }
    }

    return mx;
}
int main()
{
    vector<int> arr = {1 , 2 , 3 , 4 , 5};
    cout<<maxSumSubarray(arr , 3);
    return 0;
}
