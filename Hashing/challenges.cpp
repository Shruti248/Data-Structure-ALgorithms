#include <bits/stdc++.h>
using namespace std;

// Maximum Repeating ELement

// Brute FOrce APproach : O(n2)
// int maximumRepeatingElement(vector<int> arr){
//     int ans = 0;
//     for(int i = 0 ; i<arr.size() ; i++){
//         int count = 0;
//         for(int j = i ; j<arr.size() ; j++){
//             if(arr[i] == arr[j]){
//                 count += 1;
//             }
//         }
//         if(count > ans){
//             ans = count;
//         }
//     }

//     return ans;
// }

// Better Approach : O(n) time , O(k) space
// int maximumRepeatingElement(vector<int> arr)
// {
//     vector<int> count(arr.size(), 0);

//     for(int i = 0 ; i<arr.size() ; i++){
//         count[arr[i]]++;
//     }

//     int maxRepeating = 0;
//     int maxEle ;
//     for(int i = 0 ; i<count.size() ; i++){
//         maxRepeating = max(count[i] , maxRepeating);
//         maxEle = arr[i-1];
//     }

//     return maxRepeating; //Frequency
//     // return maxEle; //ELement
// }

// Optimized
// O(n) Time & O(1) Space
// Following is the O(n) time and O(1) extra space approach.
// Let us understand the approach with a simple example where arr[] = {2, 3, 3, 5, 3, 4, 1, 7}, k = 8, n = 8 (number of elements in arr[]).

// Iterate though input array arr[], for every element arr[i], increment arr[arr[i]%k] by k (arr[] becomes {2, 11, 11, 29, 11, 12, 1, 15 })
// Find the maximum value in the modified array (maximum value is 29). Index of the maximum value is the maximum repeating element (index of 29 is 3).
// If we want to get the original array back, we can iterate through the array one more time and do arr[i] = arr[i] % k where i varies from 0 to n-1.

int maximumRepeatingElement(vector<int> arr, int k)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % k] += k;
    }

    int max = arr[0], result = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            result = i;
        }
    }

    /* Uncomment this code to get the original array back
       for (int i = 0; i< n; i++)
          arr[i] = arr[i]%k; */

    return result;
}

// Kth smallest integer after removing natural Numbers
// Time Complexity: O(MAX)
// Auxiliary Space: O(MAX)
int kthSmallestInteger(vector<int> arr, int k)
{
    int MAX = 100;
    int b[MAX];
    memset(b, 0, sizeof b); // Intializing the b variable with 0

    for (int i = 0; i < arr.size(); i++)
    {
        b[arr[i]] = 1;
    }

    for (int i = 1; i < MAX; i++)
    {
        if (b[i] != 1)
        {
            k--;
        }
        if (k == 0)
        {
            return i;
        }
    }

    return -1;
}

// Efficent Approach
// Time Complexity: O(nlog(n))
// Auxiliary Space: O(1)
int kthSmallestIntegerOptimized(vector<int> arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    // Checking if k lies before 1st element
    if (k < arr[0])
        return k;

    // If k is more than last element
    if (k > arr[n - 1])
        return k + n;

    // If first element of array is 1.
    if (arr[0] == 1)
        k--;

    // Reducing k by numbers before arr[0].
    else
        k -= (arr[0] - 1);

    for (int i = 0; i < arr.size() - 1; i++)
    {
        int c = arr[i + 1] - arr[i] - 1;

        if ((k - c) <= 0)
        {
            return arr[i] + k;
        }
        else
        {
            k = k - c;
        }
    }

    return arr[n - 1] + k;
}

// EASIEST SOLUTION
// O(n)
// O(1)
int kthSmallestIntegerMostOptimized(vector<int> arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }

    return k;
}

// k CLosest ELement for X
// Time complexity: O(Logn + k).
// Logn for binary Search & k for finding k closest different
// Auxiliary Space: O(1), since no extra space has been used.

int findCrossOver(vector<int> arr, int low, int high, int X)
{
    if (arr[high] <= X)
    {
        // x is greater than all
        return high;
    }
    if (arr[low] > X)
    {
        // x is smaller than all;
        return low;
    }

    int mid = (low + high) / 2;

    if (arr[mid] <= X && arr[mid + 1] > X)
    {
        return mid;
    }

    if (arr[mid] < X)
    {
        return findCrossOver(arr, mid + 1, high, X);
    }

    return findCrossOver(arr, low, mid - 1, X);
}

vector<int> kClosestElement(vector<int> arr, int X, int k)
{
    vector<int> ans;

    int l = findCrossOver(arr, 0, arr.size() - 1, X);
    int r = l + 1;
    int count = 0;

    cout << l << endl;
    if (arr[l] == X)
    {
        l--;
    }

    while (l >= 0 && r < arr.size() && count < k)
    {
        if (X - arr[l] < arr[r] - X)
        {
            ans.push_back(arr[l--]);
        }
        else
        {
            ans.push_back(arr[r++]);
        }

        count++;
    }

    while (count < k && l >= 0)
    {
        ans.push_back(arr[l--]);
        count++;
    }

    while (count < k && r >= 0)
    {
        ans.push_back(arr[r++]);
        count++;
    }

    return ans;
}

//Time complexity: O(log(n-k))
// Space complexity: O(k)
vector<int> kClosestElementsOptimized(vector<int> &arr, int k, int x)
{
    int left = 0, right = arr.size() - k;

    while (left < right)
    {
        int mid = (left + right) / 2;

        if (x - arr[mid] > arr[mid + k] - x)
            left = mid + 1;
        else
            right = mid;
    }

    return vector<int>(arr.begin() + left, arr.begin() + left + k);
}
int main()
{
    // vector<int> arr = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3};
    // cout << maximumRepeatingElement(arr, 10);

    // vector<int> arr = {2, 3};
    // cout << kthSmallestInteger(arr, 2) << endl;
    // cout << kthSmallestIntegerOptimized(arr, 2) << endl;
    // cout << kthSmallestIntegerMostOptimized(arr, 2) << endl;

    vector<int> arr = {1, 2, 3, 4, 5};
    // vector<int> res = kClosestElement(arr, 3, 4);
    vector<int> res = kClosestElementsOptimized(arr, 3, 4);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
