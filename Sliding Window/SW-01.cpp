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

// First negative integer in every window of size k
vector<int> firstNegativeNumber(vector<int> arr, int k)
{

    int i = 0, j = 0;
    list<int> negativeNums;
    vector<int> ans;

    while (j < arr.size())
    {
        // Calculations of j
        if (arr[j] < 0)
        {
            negativeNums.push_back(arr[j]);
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (negativeNums.size() == 0)
            {
                // No Negative number
                ans.push_back(0);
            }
            else
            {
                ans.push_back(negativeNums.front());
            }
            // Slide the window and if negative number removaed while sliding , remove from list as well
            if (arr[i] < 0)
            {
                negativeNums.pop_front();
            }

            i++;
            j++;
        }
    }

    return ans;
}

// Count Occurences of Anagram in string

// construct map of pattern
// Make a varaible count : to see the distinct occurence of elements == mp.size()

int countOccurencesOfAnagram(string txt, string pat)
{
    unordered_map<char, int> m;
    for (auto i : pat)
        m[i]++;

    int k = pat.size();
    int count = m.size();
    int ans = 0;
    int i = 0, j = 0;

    while (j < txt.size())
    {

        if (m.find(txt[j]) != m.end())
        {
            m[txt[j]]--;

            if (m[txt[j]] == 0)
                count--;
        }

        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k)
        {
            if (count == 0)
                ans++;

            if (m.find(txt[i]) != m.end())
            {
                m[txt[i]]++;

                if (m[txt[i]] == 1)
                    count++;
            }

            i++;
            j++;
        }
    }

    return ans;
}

// Maximum of all subarrays of size k
vector<int> maxEleinSubarrays(vector<int> arr, int k)
{
    int i = 0, j = 0;
    vector<int> ans;
    list<int> mxArray;

    if (k > arr.size())
    {
        ans.push_back(*max_element(mxArray.begin(), mxArray.end()));
        return ans;
    }

    while (j < arr.size())
    {

        while (mxArray.size() > 0 && mxArray.back() < arr[j])
        {
            mxArray.pop_back();
        }
        mxArray.push_back(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans.push_back(mxArray.front());

            // Slide
            if (arr[i] == mxArray.front())
            {
                mxArray.pop_front();
            }

            i++;
            j++;
        }
    }

    return ans;
}

int main()
{
    // vector<int> arr = {1 , 2 , 3 , 4 , 5};
    // cout<<maxSumSubarray(arr , 3);

    // vector<int> arr = {1, -2, -3, 4, -5};
    // vector<int> ans = firstNegativeNumber(arr, 3);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // string s = "forxxorfxdofr";
    // string p = "for";
    // cout << countOccurencesOfAnagram(s, p);

    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = maxEleinSubarrays(arr, 3);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}