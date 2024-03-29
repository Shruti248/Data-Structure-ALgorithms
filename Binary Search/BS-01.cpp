// Binary Search : Sorted Array
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> nums, int ele)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == ele)
        {
            return mid;
        }
        else if (nums[mid] > ele)
        {
            // Left
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

// BS on reverse Sorted array
int searchonReverseSortedArray(vector<int> nums, int ele)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == ele)
        {
            return mid;
        }
        else if (nums[mid] < ele)
        {
            // Left
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

// Order not known search
// Order acqnostic binary Search
int searchonOrderNotKnown(vector<int> nums, int ele)
{
    int start = 0;
    int end = nums.size() - 1;

    if (nums[0] < nums[1])
    {
        // Ascending
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (nums[mid] == ele)
            {
                return mid;
            }
            else if (nums[mid] > ele)
            {
                // Left
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        if (nums[0] > nums[1])
        {
            // Descending
            while (start <= end)
            {
                int mid = (start + end) / 2;

                if (nums[mid] == ele)
                {
                    return mid;
                }
                else if (nums[mid] < ele)
                {
                    // Left
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }
    }

    return -1;
}

vector<int> firstAndLastOccurenceELe(vector<int> nums, int ele)
{
    vector<int> res;
    int start = 0;
    int first = -1, last = -1;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (ele == nums[mid])
        {
            first = mid;
            end = mid - 1;
        }
        else if (nums[mid] > ele)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    start = 0;
    end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (ele == nums[mid])
        {
            last = mid;
            start = mid + 1;
        }
        else if (nums[mid] > ele)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    res.push_back(first);
    res.push_back(last);

    return res;
}

// Count of the element in a sorted Array
int countSortedArray(vector<int> nums, int ele)
{
    int start = 0;
    int first = -1, last = -1;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (ele == nums[mid])
        {
            first = mid;
            end = mid - 1;
        }
        else if (nums[mid] > ele)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    start = 0;
    end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (ele == nums[mid])
        {
            last = mid;
            start = mid + 1;
        }
        else if (nums[mid] > ele)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    if (first == -1 && last == -1)
    {
        return 0;
    }

    int res = 0;
    res = last - first + 1;

    return res;
}

// Find floor of the element in sorted array
// Floor : Greatest  element less than or equal to ele

int floor(vector<int> nums, int ele)
{
    int start = 0;
    int end = nums.size() - 1;

    int mx = INT_MIN;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == ele)
        {
            return nums[mid];
        }
        else if (nums[mid] > ele)
        {
            // Left
            end = mid - 1;
        }
        else
        {
            if (nums[mid] > mx)
            {
                mx = nums[mid];
                // Right
                start = mid + 1;
            }
        }
    }

    if (mx == INT_MIN)
    {
        return -1;
    }
    return mx;
}

// Ceil of the element in sorted array
// Min element greater than or equal to the ele
int ceil(vector<int> nums, int ele)
{
    int start = 0;
    int end = nums.size() - 1;

    int mn = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == ele)
        {
            return nums[mid];
        }
        else if (nums[mid] > ele)
        {
            if (nums[mid] < mn)
                mn = nums[mid];
            // Left
            end = mid - 1;
        }
        else
        {

            // Right
            start = mid + 1;
        }
    }

    if (mn == INT_MAX)
    {
        return -1;
    }
    return mn;
}

// Next alphabetical Element

char nextAlphabeticalElemen(vector<char> &alpabets, char target)
{
    int start = 0;
    int end = alpabets.size() - 1;

    char res = alpabets[start];

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (alpabets[mid] == target)
        {
            start = mid + 1;
        }
        else if (alpabets[mid] > target)
        {
            // Left
            res = alpabets[mid];
            end = mid - 1;
        }
        else
        {
            // Right
            start = mid + 1;
        }
    }

    return res;
}

// Find the position of the element in the infinite sorted array
// Mostly for face to face interview

// Modified Binary Search
// end = infinite --> Therefore we need to find the end index to apply the BS

// Startegy
// start = 0
// end = 1

// if ele > end --> means ele does not exist between the selected bound

// increase the end --> end = end*2
// --> start = end;

// Repeeat the process untiul the ele < end --> which means the lee exists in the given finite BOUND....---> APPLY BS LATER

int binarySearch(vector<int> arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int searchInInfiniteSortedArray(vector<int> nums, int ele)
{

    int start = 0;
    int end = 1;
    int val = nums[0];

    while (val < ele)
    {
        start = end;
        end = 2 * end;
        val = nums[end];
    }
    return binarySearch(nums, start, end, ele);
}

// Index of the first 1 in the binary sprted array

int firstIndex(vector<int> nums)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == 1)
        {
            if (nums[mid - 1] == 1)
            {
                end = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            if (nums[mid] == 0)
            {
                start = mid + 1;
            }
        }
    }

    return -1;
}

// Minimum Difference Element in the sorted Array
// Eg : 4 , 6 , 10 --> key = 7 --> if 7 then  diff = 0 , or min of floor or ceil

int minDiff(vector<int> nums, int ele)
{
    int start = 0;
    int end = nums.size() - 1;

    int mn = INT_MAX;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == ele)
        {
            return 0;
        }
        else if (nums[mid] < ele)
        {
            mn = min(abs(nums[mid] - ele), mn);
            start = mid + 1;
        }
        else
        {
            mn = min(abs(nums[mid] - ele), mn);
            end = mid - 1;
        }
    }

    return mn;
}

// CONCEPT
// BInary Search on Answer
// Applies on Unosroted array as well
// You need to develop the criteria on whether you nee dto move on left half or right half

// Peek Answer : BAsed on BSA --> IMPORTANT
// Unsorted array
// Output : Index of peak element

int peakEle(vector<int> nums)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        // Integer overflow : Asked in interview
        int mid = start + (end - start) / 2;

        if (mid > 0 && mid < nums.size() - 1)
        {
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid - 1] > nums[mid])
            {
                // Left
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (mid == 0)
        {
            if (nums[0] > nums[1])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            if (nums[nums.size() - 1] > nums[nums.size() - 2])
            {
                return nums.size() - 1;
            }
            else
            {
                return nums.size() - 2;
            }
        }
    }

    return -1;
}

// Find max element in the bitonic array

// Bitonic : Monotonic (means no same elements )Increasing and then monotonic decreasing

// This is the peak element only

// Search an element in bitonic array
// Beafore peak ele : Sorted increasing
// After peak Ele : Sorted Decreasing

// Function for binary search in ascending part
int ascendingBinarySearch(int arr[], int low,
                          int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// Function for binary search in
// descending part of array
int descendingBinarySearch(int arr[], int low,
                           int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// finding bitonic point
int findBitonicPoint(int arr[], int n,
                     int l, int r)
{
    int mid;
    int bitonicPoint = 0;
    mid = (r + l) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
    {
        return mid;
    }

    else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
    {
        bitonicPoint = findBitonicPoint(arr, n, mid, r);
    }

    else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
    {
        bitonicPoint = findBitonicPoint(arr, n, l, mid);
    }
    return bitonicPoint;
}

// Function to search key in
// bitonic array
int searchBitonic(int arr[], int n,
                  int key, int index)
{
    if (key > arr[index])
        return -1;

    else if (key == arr[index])
        return index;

    else
    {
        int temp = ascendingBinarySearch(arr,
                                         0, index - 1,
                                         key);
        if (temp != -1)
        {
            return temp;
        }

        // Search in right of k
        return descendingBinarySearch(arr,
                                      index + 1,
                                      n - 1,
                                      key);
    }
}

// Check if the array id sorted and rotated
int checkSortedAndRotated(vector<int> arr)
{
    // int count = 0;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] > nums[(i + 1) % nums.size()])
    //     {
    //         count++;
    //     }
    // }

    // if (count > 1)
    // {
    //     return false;
    // }

    // return true;

    int x = 0 , y = 0;

            for(int i = 0 ; i<arr.size()-1 ; i++){
                if(arr[i] <= arr[i+1]){
                    x++;
                }else{
                    y++;
                }
            }

            if(y == 0){
                return true;
            }

            if(y == 1){
                if(arr[arr.size()-1] <= arr[0]){
                    x++;
                }else{
                    y++;
                }

                if(y == 1){
                    return true;
                }
            }

            return false;
}

int main()
{
    // vector<int> nums = {1 , 2 , 3 , 4};
    // cout<<search(nums , 1);

    // vector<int> nums = {4 , 3 , 2 , 1};
    // cout<<searchonReverseSortedArray(nums , 1);

    // vector<int> nums = {1, 2, 3, 4};
    // cout << searchonOrderNotKnown(nums, 2);

    // vector<int> nums = {1, 1, 1, 1};
    // vector<int> ans = firstAndLastOccurenceELe(nums, 1);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i];
    // }

    // vector<int> nums = {1, 1, 1, 10};
    // cout << countSortedArray(nums, 1);

    // vector<int> nums = { 1 , 2 , 3 , 4 , 8 , 10 , 10 , 12 , 19};
    // cout<<floor(nums , 20);

    // vector<int> nums = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    // cout << ceil(nums, 20);

    // vector<char> alphabets = {'a' , 'b' , 'c' , 'g' , 'h'};
    // cout<<nextAlphabeticalElemen(alphabets , 'b');

    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cout << searchInInfiniteSortedArray(nums, 7);

    // vector<int> nums = {0, 0, 0, 0, 1, 1, 1, 1};
    // cout << firstIndex(nums);

    // vector<int> nums = {2, 5, 10, 12, 15};
    // cout << minDiff(nums, 6);

    // vector<int> nums = {1, 3, 5, 4, 10};
    // cout << "Index : " << peakEle(nums) << endl;
    // // max in bitonic array
    // cout << "Ele : " << nums[peakEle(nums)];

    // int arr[] = {-8, 1, 2, 3, 4, 5, -2, -3};
    // int key = 5;
    // int index;
    // index = findBitonicPoint(arr, 8, 0, 7);
    // cout << searchBitonic(arr, 8, key, index);

    vector<int> nums = {5, 1, 2, 3, 4};
    cout << checkSortedAndRotated(nums);

    return 0;
}
