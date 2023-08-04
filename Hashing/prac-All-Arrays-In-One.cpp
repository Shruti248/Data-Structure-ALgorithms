#include <bits/stdc++.h>
using namespace std;

// Count frequency of each element in the array
// Brute force
void freq(vector<int> arr)
{
    vector<pair<int, int>> ans;

    sort(arr.begin(), arr.end());

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
        }

        else if (arr[i] == arr[i - 1])
        {
            count++;
        }
        else
        {
            // ans.push_back({arr[i-1] , count});
            cout << arr[i - 1] << " " << count << endl;
            count = 1;
        }
    }

    if (count > 0)
    {
        cout << arr.back() << " " << count << endl;
    }
}

// Another brute force : Jyare bhi hashing ave tyare visited array/frequency array no concept lagi jase : Keys act as indexes in array
void freqUsingVisitedArray(vector<int> arr)
{
    vector<int> visited(arr.size(), 0);

    for (int i = 0; i < arr.size(); i++)
    {
        visited[arr[i]]++;
    }

    // Print
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] != 0)
        {
            cout << i << " " << visited[i] << endl;
        }
    }
}

// Using Hashing : bcoz key value type data
// O(n)
// O(n)
void freqHashing(vector<int> arr)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    // print map
    for (auto i : mp)
    {
        cout << i.first << " " << i.second << endl;
    }
}

// Find whether an array is subset of another array
bool issubset(vector<int> arr1, vector<int> arr2)
{

    for (int i = 0; i < arr2.size(); i++)
    {
        bool isPresent = false;
        for (int j = 0; j < arr1.size(); j++)
        {
            if (arr2[i] == arr1[j])
            {
                isPresent = true;
                break;
                ;
            }
        }

        if (isPresent == false)
        {
            return false;
        }
    }

    return true;
}

// Using SOrting and pointers
bool isSubsetII(vector<int> arr1, vector<int> arr2)
{
    int i = 0, j = 0;

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] == arr2[j])
        {
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    if (j != arr2.size() - 1)
    {
        return false;
    }

    return true;
}

// Find Second Smallest and Second Largest Element in an array
//  1)with sorting
//  2) without sorting : 2 traversals
//  Time Complexity: O(N), We do two linear traversals in our array
//  Space Complexity: O(1)
// 3) Using Single Traversal

void secondSmallestAndLargest(vector<int> arr)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    int secondSmallest = INT_MAX;
    int secondLargest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }

        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }

        if (arr[i] > smallest && arr[i] < secondSmallest)
        {
            secondSmallest = arr[i];
        }
    }

    if (secondLargest == INT_MIN)
    {
        secondLargest = -1;
    }

    if (secondSmallest == INT_MAX)
    {
        secondSmallest = -1;
    }

    cout << secondSmallest << secondLargest << endl;
}

// O(N) : Single traversal
// Similarly seocnd Smallest
void secondLargestEle(vector<int> arr)
{
    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    cout << secondLargest << endl;
}

// Remove Duplicates in-place from Sorted Array
// 1) Brute Force : Data structure : Set -- bcoz does not store duplicate elements
// 2) Using 2 Pointers : Optimal

// Time complexity: O(n*log(n))+O(n)
// Space Complexity: O(n)
vector<int> removeDuplicatesInPlace(vector<int> arr)
{
    set<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }

    int k = s.size();
    int j = 0;
    for (auto i : s)
    {
        arr[j++] = i;
    }

    return vector<int>(arr.begin(), arr.begin() + k);
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Ofc used in sorted array
vector<int> removeDupicatesInPlaceUsing2Pointers(vector<int> arr)
{
    int i = 0;

    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }

    return vector<int>(arr.begin(), arr.begin() + (i + 1));
}

// Left Rotate the Array by One
// Time Complexity: O(n), as we iterate through the array only once.
// Space Complexity: O(1) as no extra space is used

vector<int> leftRotate(vector<int> arr)
{

    if (arr.size() <= 1)
    {
        return arr;
    }
    int firstEle = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[arr.size() - 1] = firstEle;

    return arr;
}

// Rotate array in Right by K elements

// 1) use temp array
// Time Complexity: O(n)
// Space Complexity: O(k) since k array element needs to be stored in temp array
vector<int> rotateRightByK(vector<int> arr, int k)
{

    if (arr.size() == 0)
    {
        return arr;
    }

    k = k % arr.size();

    if (arr.size() == k)
    {
        return arr;
    }

    vector<int> temp(arr.begin() + k + 1, arr.end());

    // REMEMBER THIS : COpy from last , else the repeated elements will be copied
    for (int i = arr.size() - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }

    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }

    return arr;
}

vector<int> rotateLeftByK(vector<int> arr, int k)
{

    if (arr.size() == 0)
    {
        return arr;
    }

    k = k % arr.size();

    if (arr.size() == k)
    {
        return arr;
    }

    vector<int> temp(arr.begin(), arr.begin() + k);

    for (int i = k; i < arr.size(); i++)
    {
        arr[i - k] = arr[i];
    }

    for (int i = arr.size() - k; i < arr.size(); i++)
    {
        arr[i] = temp[i - arr.size() + k];
    }

    return arr;
}

// Using Reversal Algorithm
// Rotate From Right
// rreverse last k elements
// rreverse first  n- k elements
// Reverse whole

// O(N) O(1)
void reverseArr(vector<int> &arr, int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

vector<int> rotateFromrightByKUsingReversalAlgo(vector<int> arr, int k)
{
    // first n-k elements
    reverseArr(arr, 0, arr.size() - k - 1);

    // last k elements
    reverseArr(arr, arr.size() - k, arr.size() - 1);

    reverseArr(arr, 0, arr.size() - 1);

    return arr;
}

vector<int> rotateFromLeftByKUsingReversalAlgo(vector<int> arr, int k)
{
    // first k elements
    reverseArr(arr, 0, k - 1);

    // last n-k elements
    reverseArr(arr, k, arr.size() - 1);

    reverseArr(arr, 0, arr.size() - 1);

    return arr;
}

// MOSt AskEd
// move all teh zeroes to the end

// Brute Force : Using extra array
// O(n)
// O(n)
vector<int> moveAllZeroesToEnd(vector<int> arr)
{
    vector<int> ans;
    int zeroCount = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            ans.push_back(arr[i]);
        }
        else
        {
            zeroCount++;
        }
    }

    while (zeroCount > 0)
    {
        ans.push_back(0);
        zeroCount--;
    }

    return ans;
}

// Optimal : Using 2 pointers
// O(N) O(1)

vector<int> moveAllZeroesToEndUsing2pointers(vector<int> arr)
{
    int j = 0;
    int i;

    while (j < arr.size())
    {
        if (arr[j] != 0)
        {
            j++;
        }
        else
        {
            i = j + 1;

            while (i < arr.size() && arr[i] == 0)
            {
                i++;
            }

            if (i < arr.size())
            {
                // Swap
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;

                j++;
            }
            else
            {
                break;
            }
        }
    }

    return arr;
}

// Union Of the 2 Sorted array : Common of both + Distint elements in both arrays
// Using Set(Same method for map) : Works for both sorted and unsorted array
// Time Compleixty : O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time,
// Space Complexity : O(m+n)
// Using 2 pointers : Only Sorted
vector<int> unionOf2SortedArray(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;

    set<int> s;

    for (int i = 0; i < arr1.size(); i++)
    {
        s.insert(arr1[i]);
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        s.insert(arr2[i]);
    }

    for (auto i : s)
    {
        ans.push_back(i);
    }

    return ans;
}

// Time : O(m+n)
// Space : O(m+n)
vector<int> unionOf2SortedArrayUsing2Pointers(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;

    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            if (ans.size() == 0 || arr1[i] != ans.back())
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || arr2[j] != ans.back())
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < arr1.size())
    {
        if (arr1[i] != ans.back())
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while (j < arr2.size())
    {
        if (arr2[j] != ans.back())
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }

    return ans;
}

// Find the missing number in an array
// 1) using bool array :
// Time Complexity: O(N)
// Auxiliary Space: O(N)
int missingNumber(vector<int> arr)
{

    vector<bool> isPresent(arr.size() + 1, false);

    for (int i = 0; i < arr.size(); i++)
    {
        isPresent[arr[i] - 1] = true;
    }

    for (int i = 0; i < isPresent.size(); i++)
    {
        if (isPresent[i] == false)
        {
            return i + 1;
        }
    }

    return -1;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)
int missingNumberUsingSummation(vector<int> arr)
{

    int n = arr.size() + 1;

    long sum = (n * (n + 1)) / 2;

    long sumOfPresentNumbers = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sumOfPresentNumbers += arr[i];
    }

    return sum - sumOfPresentNumbers;
}

// Count Maximum Consecutive One’s in the array
// Using linear search
// O(N)
// O(1)
int maxConsecutiveOnes(vector<int> arr)
{
    int mx = INT_MIN;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        mx = max(mx, count);
    }

    return mx;
}

// Find the number that appears once, and the other numbers twice
// Most intuitive : Hashing
//  O(N*logM) + O(M) : We are inserting N elements in the map data structure and insertion takes logM time
// O(M)
int numberAppearingOnce(vector<int> arr)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    for (auto i : mp)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }

    return -1;
}

// Longest Subarray with given Sum K(Positives)

// Brute force : All possible subarrays
// O(N2)
// O(1)
int longestSubarrayBruteForce(vector<int> arr, int sum)
{

    int mx = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        long long s = 0;
        for (int j = i; j < arr.size(); j++)
        {
            s += arr[j];

            if (s == sum)
            {
                mx = max(mx, j - i + 1);
            }
        }
    }

    return mx;
}

// Time Complexity: O(2*N)
// Space Complexity: O(1)
int longestSubarrayUsingSlidingWindow(vector<int> arr, int sum)
{
    int i = 0, j = 0;
    int s = 0;
    int mx = INT_MIN;

    while (j < arr.size())
    {
        s += arr[j];

        if (s < sum)
        {
            j++;
        }
        else if (s == sum)
        {
            mx = max(mx, j - i + 1);

            j++;
        }
        else if (s > sum)
        {
            while (s > sum)
            {
                s -= arr[i];
                i++;
            }
            j++;
        }
    }

    return mx;
}

// Longest Subarray with sum K | [Postives and Negatives]
// 1) brute force : Above brute force works for all : Since it genreates all possible and then computes answer

// 2) USing hashing : Prefix Sum Method : for both positive and negative

// Prefix : From the front till that portion
// Learn thsi method in the morning ----

//  2 Sum  : 2 variants : 1) Return true/false 2) return indicies
// Modifyig variant 2 in the same below codes

// Brute Force
// O(n2)
// O(1)
bool twoSum(vector<int> arr, int sum)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                cout << arr[i] << arr[j] << endl;
                return true;
            }
        }
    }

    return false;
}

// 2 pointers but on sorted array
// Time Complexity: O(N) + O(N*logN),
// Space Complexity: O(1)
bool twoSumUsing2Pointers(vector<int> arr, int sum)
{
    sort(arr.begin(), arr.end());

    int i = 0, j = arr.size() - 1;

    while (i <= j)
    {
        if (arr[i] + arr[j] == sum)
        {
            cout << arr[i] << " " << arr[j] << endl;
            return true;
        }
        else if (arr[i] + arr[j] < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return false;
}

// Using Hashing
// if x exists , and sum -x  exists -- return true
// Searching in hashing in constant time

// O(N)
// O(N)
bool twoSumUsingHashing(vector<int> arr, int sum)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (mp.find(sum - arr[i]) != mp.end())
        {
            cout << arr[i] << " " << sum - arr[i] << endl;
            return true;
        }
    }

    return false;
}

// Sort an array of 0s, 1s and 2s : in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

// 1) Simplest brute force : Sorting O(Nlogn)

// 2) Maintaing Count
// O(N) + O(N)
// O(1)
vector<int> sortArrayOfZeroesOnesTwos(vector<int> arr)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        if (arr[i] == 1)
        {
            count1++;
        }

        if (arr[i] == 2)
        {
            count2++;
        }
    }

    int i = 0;

    while (count0 != 0)
    {
        arr[i] = 0;
        i++;
        count0--;
    }

    while (count1 != 0)
    {
        arr[i] = 1;
        i++;
        count1--;
    }

    while (count2 != 0)
    {
        arr[i] = 2;
        i++;
        count2--;
    }

    return arr;
}

// 3) Dutch National flag algorithm.
// 3 pointers : Low , mid , high

// O(N)
// O(1)
vector<int> sortArrayOfZeroesOnesTwosUsingDutchAlgo(vector<int> arr)
{

    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high)
    {
        if(arr[mid] == 0){
            swap(arr[low] , arr[mid]);
            low++;
            mid++;
        }else if(arr[mid] == 1){
            mid++;
        }else{
            // 2
            swap(arr[mid] , arr[high]);
            high--;
        }
    }

    return arr;
}

int main()
{
    // freq({2 , 2 , 4 , 2 , 6 , 6 });
    // freqUsingVisitedArray({2 , 2 , 4 , 2 , 6 , 6 , 6});
    // freqHashing({2 , 2 , 4 , 2 , 6 , 6 , 6});

    // cout << issubset({11, 1, 13, 21, 3, 7}, {11, 1, 3});
    // cout << isSubsetII({11, 1, 13, 21, 3, 7}, {11, 16, 3});

    // secondSmallestAndLargest({1});
    // secondLargestEle({1 , 4 , 2 , 6, 7});

    // vector<int> ans = removeDuplicatesInPlace({1, 4, 2, 1, 6, 8});
    // vector<int> ans = removeDupicatesInPlaceUsing2Pointers({1,1,2,2,2,3,3});
    // vector<int> ans = leftRotate({1 , 2 , 3 , 4 , 5});
    // vector<int> ans = rotateRightByK({1 , 2 , 3 , 4 , 5} , 2);
    // vector<int> ans = rotateLeftByK({1, 2, 3, 4, 5}, 2);
    // vector<int> ans = rotateFromrightByKUsingReversalAlgo({1, 2, 3, 4, 5}, 2);
    // vector<int> ans = rotateFromLeftByKUsingReversalAlgo({1, 2, 3, 4, 5}, 2);
    // vector<int> ans = moveAllZeroesToEnd({1 , 0 , 2 , 3 , 0 , 4 , 0 , 1});
    // vector<int> ans = moveAllZeroesToEndUsing2pointers({1 , 0 , 2 , 3 , 0 , 4 , 0 , 1});
    // vector<int> ans = unionOf2SortedArray({1, 2, 3, 4, 5}, {2, 3, 4, 4, 5});
    // vector<int> ans = unionOf2SortedArrayUsing2Pointers({1, 2, 3, 4, 5}, {2, 3, 4, 4, 5});

    // cout<<missingNumber({ 1 , 2 , 3 });
    // cout<<missingNumberUsingSummation({ 1 , 2 , 4 });
    // cout<<maxConsecutiveOnes({1, 1, 0, 1, 1 , 1 , 1});
    // cout << numberAppearingOnce({2, 1, 2, 1, 3});

    // cout<<longestSubarrayBruteForce({2 , 3 , 5 , 1 , 9 } , 10);
    // cout<<longestSubarrayBruteForce({-1, 1, 1} , 1);
    // cout << longestSubarrayUsingSlidingWindow({2, 3, 5, 1, 9}, 10);

    // cout << twoSum({2, 6, 5, 8, 11}, 14);
    // cout << twoSumUsing2Pointers({2, 6, 5, 8, 11}, 14);
    // cout << twoSumUsingHashing({2, 6, 5, 8, 11}, 14);

    // vector<int> ans = sortArrayOfZeroesOnesTwos({2, 0, 2, 1, 1, 0});
    vector<int> ans = sortArrayOfZeroesOnesTwosUsingDutchAlgo({2, 0, 2, 1, 1, 0});

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
