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

int main()
{
    vector<int> arr = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3};
    cout << maximumRepeatingElement(arr , 10);
    return 0;
}
