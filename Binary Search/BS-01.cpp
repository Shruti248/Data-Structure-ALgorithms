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

int main()
{
    // vector<int> nums = {1 , 2 , 3 , 4};
    // cout<<search(nums , 1);

    // vector<int> nums = {4 , 3 , 2 , 1};
    // cout<<searchonReverseSortedArray(nums , 1);

    vector<int> nums = {1 , 2 , 3 , 4};
    cout << searchonOrderNotKnown(nums, 2);
    return 0;
}
