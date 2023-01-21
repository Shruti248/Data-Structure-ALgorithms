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

        for (int i = 0; i < n; i++)
        {
            //  if we found new buy value which is more smaller then previous one
            if (arr[i] < min)
            {
                // update our least so far
                min = arr[i];
            }
            profitIfSoldToday = arr[i] - min;
            if (overallProfit < profitIfSoldToday)
            {
                overallProfit = profitIfSoldToday;
            }
        }
        cout << "Overall Profit : " << overallProfit;
    }

    // InterviewBit RepeatAndMissingNumberArray : given array from 1 to n , find A which is repeated TWICE and B which is MISSING.
    void RepeatAndMissingNumberArray(int arr[], int n)
    {
    }

    // Google Kickstart Question
    int LongestArithemicSubarray(int arr[], int n)
    {
        int previousCommonDifference = arr[1] - arr[0];
        int currentArithmeticSubarrayLength = 2;
        int maxArithmeticSubarrayLength = 2; // ans

        // Minimum length of array is 2 for AP
        if (n < 2)
        {
            cout << "Minimum Length of an AP is 2." << endl;
            return -1;
        }
        cout << "before loop" << endl;
        for (int i = 2; i < n; i++)
        {
            if (arr[i] - arr[i - 1] == previousCommonDifference)
            {
                cout << "True pd" << endl;
                currentArithmeticSubarrayLength++;
                cout << currentArithmeticSubarrayLength << endl;
            }
            else
            {
                cout << "false pd" << endl;
                previousCommonDifference = arr[i] - arr[i - 1];
                currentArithmeticSubarrayLength = 2;
                cout << currentArithmeticSubarrayLength << endl;
            }

            if (currentArithmeticSubarrayLength > maxArithmeticSubarrayLength)
            {
                cout << "Length" << endl;
                maxArithmeticSubarrayLength = currentArithmeticSubarrayLength;
            }
        }

        return maxArithmeticSubarrayLength;
    }

    // Google KIckstart Question
    // Record Breaking Day : Strictly Greater than the previous days & Strictly greater than the following Days
    int recordBreaker(int arr[], int n)
    {
        vector<int> recordBreakingDay;
        int NumberofRecordBreakingDays = 0;
        int mx = -1;

        if (n == 1)
        {
            cout << "1" << endl;
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mx && arr[i] > arr[i + 1])
            {
                NumberofRecordBreakingDays++;
            }
            mx = max(mx, arr[i]);
        }
        return NumberofRecordBreakingDays;
    }

    // Amazon Oracle
    // Element that occurs more than once and whose index of first occurrence is smallest
    int FirstRepeatingElement(int arr[], int n)
    {
        int ans;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    // ans = arr[i]; //element
                    ans = i + 1; // index
                    return ans;
                }
            }
        }
    }

    // Google , Facebook , Amazon, Visa
    // Find continuous subarray which adds to a given number s.
    // Output : Starting and ending index
    int subarrayWithgivenSum(int arr[], int n, int givenSum)
    {
    }

    void chocolateDistributionProblem(int arr[], int n, int numberofStudents)
    {

        if (numberofStudents == 0 || n == 0)
        {
            cout << "No Chocolates or Students." << endl;
        }
        sort(arr, arr + n);
        int minimumDifference = INT_MAX;
        for (int i = 0; i < n - numberofStudents; i++)
        {
            if (arr[i + numberofStudents - 1] - arr[i] < minimumDifference)
            {
                minimumDifference = arr[i + numberofStudents - 1] - arr[i];
            }
        }
        cout << minimumDifference << endl;
    }

    int searchInRotatedSortedArray(int arr[], int n, int pivot, int target)
    {
        vector<int> rotatedArray;

        for (int i = pivot; i < n; i++)
        {
            rotatedArray.push_back(arr[i]);
        }
        for (int i = 0; i < pivot; i++)
        {
            rotatedArray.push_back(arr[i]);
        }
        // cout<<"Rotated Array : "<<endl;
        // for(int i = 0 ; i< rotatedArray.size() ; i++){
        //     cout<<rotatedArray[i]<<" ";
        // }

        for (int i = 0; i < rotatedArray.size(); i++)
        {
            if (rotatedArray[i] == target)
            {
                return i; // index of the target
            }
        }

        return -1;
    }

    // Kth Kargest element of the Array : LeetCode
    // Later Optimized Solution
    void kthLargestElement(int arr[], int n, int k)
    {
        sort(arr, arr + n);

        cout << arr[n - k] << endl;
    }

    // Kth Smallest element of the Array : LeetCode
    // Later Optimized Solution
    void kthSmallestElement(int arr[], int n, int k)
    {
        sort(arr, arr + n);

        cout << arr[k-1] << endl;
    }


    // Leetcode
    // Product of all the element of teh array except itself

    int calculateProduct(int arr[], int start, int end)
    {
        int product = 1;
        for (int i = start; i < end; i++)
        {
            product *= arr[i];
        }
        return product;
    }

    void productofArrayExceptItself(int arr[], int n)
    {
        vector<int> resultantArray;
        int resultantProduct = 1;

        for (int i = 0; i < n; i++)
        {
            resultantProduct = calculateProduct(arr, 0, i) * calculateProduct(arr, i + 1, n);
            resultantArray.push_back(resultantProduct);
        }

        for (int i = 0; i < resultantArray.size(); i++)
        {
            cout << resultantArray[i] << " ";
        }
    }

    // LeetCode
    // return Maximum Product
    void maximumProductSubarray(int arr[], int n)
    {
        vector<int> result;
        int product = 1;
        for (int i = 0; i < n; i++)
        {
            product = 1;
            for (int j = i; j < n; j++)
            {
                product *= arr[j];
                result.push_back(product);
            }
        }
        // cout << "Product of Subarrays : ";
        // for (int i = 0; i < result.size(); i++)
        // {
        //     cout << result[i] << " ";
        // }

        sort(result.begin(), result.end());

        cout << result.back();
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
    // s.BestDayToBuyAndSellStocks(arr, n);
    // s.RepeatAndMissingNumberArray(arr , n);
    // cout << s.LongestArithemicSubarray(arr, n);
    // cout << s.recordBreaker(arr, n) << endl;
    // cout<<s.FirstRepeatingElement(arr , n)<<endl;

    // left
    // int Sum;
    // cin >> Sum;
    // cout << s.subarrayWithgivenSum(arr, n, Sum) << endl;

    // int numberofStudents;
    // cin>>numberofStudents;
    // s.chocolateDistributionProblem(arr , n , numberofStudents);

    // int pivot , target;
    // cin>>pivot;
    // cin>>target;
    // cout<<s.searchInRotatedSortedArray(arr , n , pivot , target)<<endl;

    int k;
    cin>>k;
    // s.kthLargestElement(arr , n , k);
    s.kthSmallestElement(arr , n , k);

    // s.productofArrayExceptItself(arr, n);
    // s.maximumProductSubarray(arr, n);
    return 0;
}