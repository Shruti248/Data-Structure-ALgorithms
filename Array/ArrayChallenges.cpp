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

        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
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
    // s.maximumAndMinimumElementInArray(arr , n);
    s.RevereseTheArray(arr, n);
    // s.reverseArrayContainingCharacters(arr , n);
    // s.ReverseArrayContainingString(arr, n);
    return 0;
}