#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // PROBLEM : Given an array of size n. For every i from 0 to n-1 , output max(from 0 to ith element)

    // EG : 1(i = 0) 0(i = 1) 5(i = 2) 4(i = 3) 6(i = 4) 8(i = 5)
    //-->MAX: 1(i = 0) 1 (i = 1) 5(i = 2) 5(i = 3) 6(i = 4) 8(i = 5)

    // NOTE : MAX is either CONSTANT OR NON DECREASING
    void maxTillI(int arr[], int n)
    {
        vector<int> maxArray;
        int max = -19999999;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (arr[j] > max)
                {
                    max = arr[j];
                }
            }
            maxArray.push_back(max);
        }

        // Print MAXARRAY
        for (int i = 0; i < maxArray.size(); i++)
        {
            cout << maxArray[i] << " ";
        }
    }

    // SUBARRAY VS SUBSEQUENCES
    // -Subarray : continuos part of teh array
    // Eg : 1 2 3 4 : 123 is a subarray
    //  Number of subarray with n elements: nC2 + 2 = n*(n+1)/2

    // Subsequences
    // a sequences which can be dervied from the array by selecting zero or more elements without chaging the order of remaining elements
    // NOT contiguous but order needs to be maintained
    // Eg : 1 2 3 4 5 : 1 3 5 is subsequence (1 5 3 is not)
    // Number of subsequneces with n elements : 2raised to n

    // NOTE : EVery subarray is an subsequnece but every subsequnece is not a subarray

    // PROBLEM : Given an array of size n , output sum of each subarray of the given array
    void sumOfAllSubArrays(int arr[], int n)
    {
        vector<int> result;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                result.push_back(sum);
            }
        }
        cout << "Sum of Subarrays : ";
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    // LEETCODE Question : Maximum Subarray
    // Brute Force Approach Takes O(N2). --> Implemented Approach
    // DP Using Memoization , Tabulation  : O(N) --> Accepted Solution in Leetcode
    // Refer : https://leetcode.com/problems/maximum-subarray/solutions/1595195/c-python-7-simple-solutions-w-explanation-brute-force-dp-kadane-divide-conquer/
    void subArrayWiththeLargestSum(int arr[], int n)
    {
        int sum = 0;
        int maxSum = -2147483648;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum > maxSum)
                {
                    maxSum = sum;
                }
            }
        }

        cout << "Largest Sum of All the Subarrays : " << maxSum << endl;
    }

    // GFG : Max Min Problem
    void maximumAndMinimumElementInArray(int arr[], int n)
    {
        int min = 19999;
        int max = -19999;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        cout << "Minimum Element in the Array : " << min << endl;
        cout << "Maximum Element in the Array : " << max << endl;
        cout << "Sum of Minimum & Maximum ELement : " << min + max << endl;
    }

    // GFG : Reverse the array
    void RevereseTheArray(int arr[], int n)
    {
        vector<int> reversedArray;
        for (int i = n - 1; i >= 0; i--)
        {
            reversedArray.push_back(arr[i]);
        }
        // Print Array
        for (int i = 0; i < n; i++)
        {
            cout << reversedArray[i] << " ";
        }
    }

    // Reverse Single String
    void reverseArrayContainingCharacters(char arr[], int n)
    {
        vector<int> reversedArray;
        for (int i = n - 1; i >= 0; i--)
        {
            reversedArray.push_back(arr[i]);
        }
        // Print Array
        // Convert ASCII values to char using char().
        for (int i = 0; i < n; i++)
        {
            cout << char(reversedArray[i]) << " ";
        }
    }

    // Reverse a Sentence
    void ReverseArrayContainingString(string arr[], int n)
    {
        vector<string> reversedArray;
        for (int i = n - 1; i >= 0; i--)
        {
            reversedArray.push_back(arr[i]);
        }
        // Print Array
        for (int i = 0; i < n; i++)
        {
            cout << reversedArray[i] << " ";
        }
    }

    // LEETCODE : Contains Duplicate
    void ArrayContainsDuplicate(int arr[], int n)
    {
        // 1) Brute Force Approach
        // bool ContainsDuplicateElement = 0;
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i+1 ; j<n ; j++){
        //         if(arr[i] == arr[j]){
        //             cout<<"Duplicate Element is : "<<arr[i]<<endl;
        //             ContainsDuplicateElement = 1;
        //         }
        //     }
        // }
        // if(ContainsDuplicateElement == 0){
        //     cout<<"No Duplicate Elemets"<<endl;
        // }

        // 2) Sorting Approach --> Accepted Solution
        sort(arr, arr + n);
        bool ContainsDuplicateElement = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                cout << "Contains Duplicate Elements : " << arr[i] << endl;
                ContainsDuplicateElement = 1;
            }
        }
        if (ContainsDuplicateElement == 0)
        {
            cout << "No Duplicate Elements." << endl;
        }
    }

    // LEETCODE : Best day to Buy & Sell Stocks
    // each element of the array represents the price of the stock at ith day. FInd Maximum Profit or else return 0.
    void BestDayToBuyAndSellStocks(int arr[], int n)
    {
        int min = INT_MAX;
        int overallProfit = 0;
        int profitIfSoldToday = 0;

        for(int i = 0 ; i<n ; i++){
            //  if we found new buy value which is more smaller then previous one
            if(arr[i] < min){
                // update our least so far
                min = arr[i];
            }
            profitIfSoldToday = arr[i] - min;
            if(overallProfit < profitIfSoldToday){
                overallProfit = profitIfSoldToday;
            }
        }
        cout<<"Overall Profit : "<<overallProfit;
            
    }
};

int main()
{
    int n; // Size of array
    cin >> n;
    int arr[n];
    // char arr[n]; //use it when required
    // string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution s;
    // s.maxTillI(arr, n);
    // s.sumOfAllSubArrays(arr , n);
    // s.subArrayWiththeLargestSum(arr , n);
    // s.maximumAndMinimumElementInArray(arr , n);
    // s.RevereseTheArray(arr, n);
    // s.reverseArrayContainingCharacters(arr , n);
    // s.ReverseArrayContainingString(arr, n);
    // s.ArrayContainsDuplicate(arr, n);
    s.BestDayToBuyAndSellStocks(arr, n);
    return 0;
}