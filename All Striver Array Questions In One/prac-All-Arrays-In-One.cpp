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
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            // 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    return arr;
}

// Find the Majority Element that occurs more than N/2 times

// Sorting

// Frequecy : Therefore Hahsing toh avse j
// O(nlogn) + o(N)
// O(N)
int majorityEle(vector<int> arr)
{
    int n = arr.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    for (auto i : mp)
    {
        if (i.second > n / 2)
        {
            return i.first;
        }
    }

    return -1;
}

// Optimal Approach: Moore’s Voting Algorithm -- If teh question quarentees that the array contains the majority element
// If not -- traverse one moere time to check

// Refer striver : GOOD One
// O(N)
// O(1)
int majorityEleUsingMooreVotingAlgo(vector<int> arr)
{
    int count = 0;
    int ele;

    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            ele = arr[i];
            count++;
        }
        else if (ele == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return ele;
}

// FOr longest subarray : Siding window & prefix sum
// But for :

// Maximum Subarray Sum in an Array :  Kadane’s Algorithm

// Brute Force : 3 loops
// O(n3)
// O(1)
int maxSubarraySumI(vector<int> arr)
{
    int mx = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            mx = max(mx, sum);
        }
    }

    return mx;
}

// Brute Force : 2 loops
// O(n2)
// O(1)
int maxSubarraySumII(vector<int> arr)
{
    int mx = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {

            sum += arr[j];

            mx = max(mx, sum);
        }
    }

    return mx;
}

// Kadanes ALgo : EASZZZ PEAAZZZZZ
// SIngle loop : O(N) O(1)
// If sum < 0 --- do not consider such subaarray -- reset sum = 0
// else find max sum

int maxSubarraySumUsingKadanesAlgo(vector<int> arr)
{
    int sum = 0;
    int mx = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        mx = max(sum, mx);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return mx;
}

// Print the array
// Maximum Subarray Sum in an Array :  Kadane’s Algorithm

// Store starting and ending index
int printmaxSubarraySumUsingKadanesAlgo(vector<int> arr)
{
    int sum = 0;
    int mx = INT_MIN;
    int startIndex = 0;
    int endIndex = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        if (sum == 0)
        {
            startIndex = i;
        }

        sum += arr[i];

        if (sum > mx)
        {
            mx = sum;
            endIndex = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    // Printing array
    for (int i = startIndex; i <= endIndex; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return mx;
}

// Stock Buy And Sell

// brute force
// O(n2)
// O(1)
int stockBuySell(vector<int> arr)
{
    int profit = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] - arr[i] > profit)
            {
                profit = arr[j] - arr[i];
            }
        }
    }

    return profit;
}

// O(n)
// O(1)
int stockBuySellOptimised(vector<int> arr)
{
    int maxProfit = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxProfit = max(maxProfit, arr[i] - minPrice);
    }

    return maxProfit;
}

// Rearrange Array Elements by Sign : There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

// Note: Start the array with positive elements.

// Variety 1 : Equal Number of Positive and Negative Elements
// O(N)
// O(N) for ans
vector<int> rearrangeArrayWithALternateSigns(vector<int> arr)
{
    vector<int> ans(arr.size(), 0);

    int posIndex = 0, negIndex = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }

    return ans;
}

// Variety 2 : Different Number of Positive and Negative Elements
// There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

// In this variety, the number of positive and negative numbers shall not necessarily be equal to each other in the given array. So, there can be two cases possible: either the positive elements exceed the negatives or the negatives exceed the positives. So, instead of using the optimal solution discussed for the variety-1 above, we’ll fall back to the brute force solution where we create separate arrays for storing positives and negatives and then put them back into the array alternatively. The remaining negative or positive elements are added to the array at last.

// Leaders in the array : Such elements where all the elements to the right of it are smaller

// Brute Force
// o(n2)
// O(n) -- ans vector
vector<int> leaders(vector<int> arr)
{
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        bool leader = true;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] < arr[j])
            {
                leader = false;
            }
        }
        if (leader)
        {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

// Using Reverse Traversal
// O(n)
// O(n) -- for ans
vector<int> leadersByTraversingReverse(vector<int> arr)
{

    vector<int> ans;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (ans.empty() || arr[i] > ans.back())
        {
            ans.push_back(arr[i]);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// Longest Consecutive Sequence in an Array
// Time Complexity: O(NlogN) + O(N)
// Space Complexity: O(1)

int longestConsecutiveSeq(vector<int> arr)
{
    if (arr.size() == 0)
    {
        return 0;
    }

    sort(arr.begin(), arr.end());

    int lastMin = INT_MIN;
    int count = 0;
    int mx = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] - 1 == lastMin)
        {
            count++;
            lastMin = arr[i];
        }
        else if (arr[i] != lastMin)
        {
            count = 1;
            lastMin = arr[i];
        }

        mx = max(mx, count);
    }

    return mx;
}

// Set Matrix Zero

// Bruet Force : Mark rows and cols with -1 where 0 is encountered -- later replace with 0
// Time Complexity: O((N*M)*(N + M)) + O(N*M)
// Space Complexity: O(1)
void setRow(vector<vector<int>> &arr, int row, int col, int i)
{
    for (int j = 0; j < col; j++)
    {
        arr[i][j] = -1;
    }
}

void setColumn(vector<vector<int>> &arr, int row, int col, int j)
{
    for (int i = 0; i < row; i++)
    {
        arr[i][j] = -1;
    }
}

vector<vector<int>> setMatrixZero(vector<vector<int>> arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                setRow(arr, row, col, i);
                setColumn(arr, row, col, j);
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }

    return arr;
}

// Approach (Using two extra arrays)
// Time Complexity: O(2*(N*M))
// Space Complexity: O(N) + O(M)
vector<vector<int>> setMatrixZeroUsing2Arrays(vector<vector<int>> arr, int row, int col)
{
    int rowArr[row] = {0};
    int colArr[col] = {0};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                rowArr[i] = 1;
                colArr[j] = 1;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (rowArr[i] || colArr[j])
            {
                arr[i][j] = 0;
            }
        }
    }

    return arr;
}

// Rotate Image by 90 degree
// O(N2)
// O(N2)
vector<vector<int>> rotateImageBy90Degree(vector<vector<int>> arr, int row, int col)
{
    vector<vector<int>> rotated(arr.size(), vector<int>(arr.size(), 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            rotated[j][arr.size() - i - 1] = arr[i][j];
        }
    }

    return rotated;
}

// first do TRanspose of the matrix : rows become col , col become row
// Then reverse each row
// O(N*N) + O(N*N)
// Since we are changing in same matrix -- no extra space
// O(1)
vector<vector<int>> rotateImageBy90DegreeOptimized(vector<vector<int>> arr, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < row; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }

    return arr;
}

// Spiral Traversal of Matrix
// Time Complexity: O(m x n) {
// Space Complexity: O(n)
vector<int> spiralTraversalOfTheMatrix(vector<vector<int>> mat)
{
    // Define ans array to store the result.
    vector<int> ans;

    int n = mat.size();    // no. of nows
    int m = mat[0].size(); // no. of columns

    // Initialize the pointers reqd for traversal.
    int top = 0, left = 0, bottom = n - 1, right = m - 1;

    // Loop until all elements are not traversed.
    while (top <= bottom && left <= right)
    {

        // For moving left to right
        for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);

        top++;

        // For moving top to bottom.
        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);

        right--;

        // For moving right to left.
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);

            bottom--;
        }

        // For moving bottom to top.
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);

            left++;
        }
    }
    return ans;
}

// Count Subarray whose sum Equals K

// brute Force : O(n2)
// Prefix sum Method Left
int countSubarraysWithGivenSum(vector<int> arr, int k)
{
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;

        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];

            if (sum == k)
            {
                count++;
            }
        }
    }

    return count;
}

// Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
// O(Nlogn)
// O(n)
vector<int> majorityEleNBy3Times(vector<int> arr)
{
    unordered_map<int, int> mp;
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    for (auto i : mp)
    {
        if (i.second > arr.size() / 3)
        {
            ans.push_back(i.first);
        }
    }

    return ans;
}

// Sliding Window

int maxSubarraySumofSizeK(vector<int> arr, int k)
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
            mx = max(mx, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }

    return mx;
}

// First negative number in every window of size k
vector<int> firstNegative(vector<int> arr, int k)
{
    int i = 0, j = 0;
    list<int> negativeNums;
    vector<int> ans;

    while (j < arr.size())
    {

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
                ans.push_back(0);
            }
            else
            {
                ans.push_back(negativeNums.front());
            }

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

int countOccurencesOfAnagram(string txt, string pat)
{
    unordered_map<char, int> mp;

    for (int i = 0; i < pat.length(); i++)
    {
        mp[pat[i]]++;
    }

    int i = 0, j = 0;
    int count = mp.size();
    int ans = 0;
    int k = pat.size();

    while (j < txt.size())
    {

        if (mp.find(txt[j]) != mp.end())
        {
            mp[txt[j]]--;

            if (mp[txt[j]] == 0)
            {
                count--;
            }
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (count == 0)
            {
                ans++;
            }

            if (mp.find(txt[i]) != mp.end())
            {
                mp[txt[i]]++;

                if (mp[txt[i]] == 1)
                {
                    count++;
                }
            }

            i++;
            j++;
        }
    }

    return ans;
}

// Maximum of all subarrays of size k
vector<int> maxEleInSubarray(vector<int> arr, int k)
{
    // int i = 0, j = 0;
    // vector<int> ans;
    // list<int> kSizedArr;
    // while(j < arr.size()){
    //     kSizedArr.push_back(arr[j]);

    //     if(j - i+1 < k){
    //         j++;
    //     }else if(j - i + 1  == k){
    //         int mx = *max_element(kSizedArr.begin() , kSizedArr.end());
    //         ans.push_back(mx);

    //         kSizedArr.pop_front();
    //         i++;
    //         j++;
    //     }
    // }

    // return ans;

    // Optimzed
    int i = 0, j = 0;
    vector<int> ans;
    list<int> mxArray;

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

int floor(vector<int> arr, int ele)
{
    int start = 0, end = arr.size() - 1;
    int f = INT_MIN;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele)
        {
            return arr[mid];
        }
        else if (arr[mid] < ele)
        {

            if (arr[mid] > f)
            {
                f = arr[mid];
            }

            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    if (f == INT_MIN)
    {
        return -1;
    }

    return f;
}

int ceil(vector<int> arr, int ele)
{
    int start = 0, end = arr.size() - 1;

    int c = INT_MAX;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele)
        {
            return arr[mid];
        }
        else if (arr[mid] < ele)
        {
            start = mid + 1;
        }
        else
        {
            c = min(c, arr[mid]);
            end = mid - 1;
        }
    }

    if (c == INT_MAX)
    {
        return -1;
    }

    return c;
}

// Lower Bound =  arr[ind] >= x.
// Upper Bound =  arr[ind] > x.

int lowerBound(vector<int> arr, int ele)
{
    int ans = -1;
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= ele)
        {
            ans = mid;

            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int upperBound(vector<int> arr, int ele)
{
    int ans = -1;
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] > ele)
        {
            ans = mid;

            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

// Search Element in a Rotated Sorted Array
int searchInRotatedSOrtedArray(vector<int> arr, int target)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = (end + start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[start] <= arr[mid])
        {
            // Left half SOrted
            if (arr[start] <= target && target <= arr[mid])
            {
                // Target present in left half
                end = mid - 1;
            }
            else
            {
                // Target in right half
                start = mid + 1;
            }
        }
        else
        {
            // Right half sorted
            if (arr[mid] <= target && target <= arr[end])
            {
                // Target in right half
                start = mid + 1;
            }
            else
            {
                // Target in left half
                end = mid - 1;
            }
        }
    }
    return -1;
}

// Search Element in Rotated Sorted Array II
// May contain duplicates : retrun true or false

// above apprach will not work when : arr[start] == arr[mid] == arr[end] Eg : 1 0 1 1 1

// How to handle the edge case arr[low] = arr[mid] = arr[high]:

bool searchInRotatedSOrtedArrayII(vector<int> arr, int target)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = (end + start) / 2;

        if (arr[mid] == target)
        {
            return true;
        }

        // One edge case added
        if (arr[start] == arr[mid] && arr[mid] == arr[end])
        {
            start = start + 1;
            end = end - 1;
            continue;
        }

        else if (arr[start] <= arr[mid])
        {
            // Left half SOrted
            if (arr[start] <= target && target <= arr[mid])
            {
                // Target present in left half
                end = mid - 1;
            }
            else
            {
                // Target in right half
                start = mid + 1;
            }
        }
        else
        {
            // Right half sorted
            if (arr[mid] <= target && target <= arr[end])
            {
                // Target in right half
                start = mid + 1;
            }
            else
            {
                // Target in left half
                end = mid - 1;
            }
        }
    }
    return false;
}

// Minimum in Rotated Sorted Array
int minInRotatedSortedArray(vector<int> arr)
{
    int start = 0, end = arr.size() - 1;
    int mn = INT_MAX;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[start] <= arr[end])
        {
            // No rotation form start to end
            mn = min(arr[start], mn);
            break;
        }

        mn = min(arr[mid], mn);

        if (arr[mid] <= arr[end])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return mn;
}

// Find out how many times the array has been rotated -- Index of the min elemnet is the times the array is rotated
int numberOfRotations(vector<int> arr)
{
    int start = 0, end = arr.size() - 1;
    int mn = INT_MAX;
    int ind = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[start] <= arr[end])
        {
            // No rotation form start to end
            if (arr[start] < mn)
            {
                mn = arr[start];
                ind = start;
            }
            break;
        }

        if (arr[mid] < mn)
        {
            mn = arr[mid];
            ind = mid;
        }

        if (arr[mid] <= arr[end])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ind;
}

// Search Single Element in a sorted array
// O(N)
int searchSingleELe(vector<int> arr)
{
    if (arr.size() <= 1)
    {
        return arr[arr.size() - 1];
    }

    for (int i = 1; i < arr.size(); i += 2)
    {
        if (arr[i] != arr[i - 1])
        {
            return arr[i - 1];
        }
    }

    if (arr[arr.size() - 1] != arr[arr.size() - 2])
    {
        return arr[arr.size() - 1];
    }

    return -1;
}

// GOOOD QUE
// O(logn)
int searchSingleEleUsingBinarySearch(vector<int> arr)
{
    // Edge cases
    if (arr.size() == 1)
    {
        return arr[0];
    }

    if (arr[0] != arr[1])
    {
        return arr[0];
    }

    if (arr[arr.size() - 1] != arr[arr.size() - 2])
    {
        return arr[arr.size() - 1];
    }

    int start = 1, end = arr.size() - 2;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        // Mid is the single ele
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }
        else if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid - 1] == arr[mid]))
        {
            // We are in left half of the single ele
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

// Peak element in Array
// arr[i] > arr[i-1] and arr[i] > arr[i+1]
int peakEle(vector<int> arr)
{

    if (arr.size() == 1)
    {
        return 0;
    }

    if (arr[0] > arr[1])
    {
        return 0;
    }

    if (arr[arr.size() - 1] > arr[arr.size() - 2])
    {
        return arr.size() - 1;
    }

    int start = 1, end = arr.size() - 2;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid - 1] < arr[mid])
        {
            // Left half increasing
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

// Sort Characters by frequency
// Bruet Force
// Time Complexity: O(n2)
// Auxiliary Space: O(n)
int countFreq(string str, char s)
{
    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == s)
        {
            count++;
        }
    }

    return count;
}

string sortCharactersByFreq(string str)
{
    vector<pair<int, char>> p;

    for (int i = 0; i < str.length(); i++)
    {
        p.push_back({countFreq(str, str[i]), str[i]});
    }

    sort(p.begin(), p.end());

    string ans = "";

    for (int i = 0; i < p.size(); i++)
    {
        ans += p[i].second;
    }

    return ans;
}

int coinChange(vector<int> denominations, int amount)
{
    int minCoin = 0;

    sort(denominations.begin(), denominations.end(), greater<int>());

    for (int i = 0; i < denominations.size(); i++)
    {
        if (amount == 0)
        {
            break;
        }
        while (denominations[i] <= amount)
        {
            minCoin++;
            amount -= denominations[i];
        }
    }

    return minCoin;
}

// Fractional Knapsack Problem
// Item : {val , wt}

struct Item
{
    int value;
    int weight;
};

bool comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;

    return r1 > r2;
}

int fractionalKnapsack(Item item[], int W, int n)
{

    // SOrt decresing val/wt
    sort(item, item + n, comp);

    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (W == 0)
        {
            break;
        }

        if (item[i].weight <= W)
        {
            profit += item[i].value;
            W -= item[i].weight;
        }
        else if (item[i].weight > W)
        {
            profit += (int)((item[i].value * (double)W) / item[i].weight);
            W = 0;
        }
    }

    return profit;
}

// Finding Sqrt of a number using Binary Search

// Brute force ; Linear Search -- O(N)
// inbuilt FUnction sqrt - O(Logn)
// BS : O(Logn)
int sqrtNum(int num)
{
    int ans = INT_MIN;

    for (int i = 0; i < num; i++)
    {
        if (i * i == num)
        {
            ans = i;
            return ans;
        }
        if (i * i > num)
        {
            break;
        }
        ans = max(ans, i);
    }

    return ans;
}

int sqrtUsingBS(int num)
{
    int ans = INT_MIN;

    int start = 0;
    int end = num;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid * mid == num)
        {
            return mid;
        }
        else if (mid * mid > num)
        {
            end = mid - 1;
        }
        else
        {
            ans = max(ans, mid);
            start = mid + 1;
        }
    }

    return ans;
}

// Nth Root of a Number using Binary Search
// Exact answer not comming due to integer differences -- see the stdout
int nthRoot(int n, int num)
{
    if (num == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return num;
    }

    int start = 0;
    int end = num;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        cout << start << " " << mid << " " << end << " " << pow(mid, n) << endl;
        if (pow(mid, n) == num)
        {
            return mid;
        }
        else if (pow(mid, n) < num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

// Koko Eating Bananas

// Linear Serach
int kokoEatingBananas(vector<int> piles, int h)
{
    int mx = *max_element(piles.begin(), piles.end());

    for (int i = 1; i < mx; i++)
    {
        int hoursTaken = 0;
        for (int j = 0; j < piles.size(); j++)
        {
            hoursTaken += ceil((double)piles[j] / (double)i);
        }

        if (hoursTaken <= h)
        {
            return i;
        }
    }

    return mx;
}

int kokoEatingBananasUsingBS(vector<int> piles, int h)
{
    int mx = *max_element(piles.begin(), piles.end());

    int start = 1;
    int end = mx;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int hoursTaken = 0;
        for (int j = 0; j < piles.size(); j++)
        {
            hoursTaken += ceil((double)piles[j] / (double)mid);
        }

        if (hoursTaken <= h)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}

// Minimum days to make M bouquets

bool isPossible(vector<int> arr, int day, int m, int k)
{
    int count = 0;
    int noOfBloomingDays = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= day)
        {
            count++;
        }
        else
        {
            noOfBloomingDays += count / k;
            count = 0;
        }
    }

    noOfBloomingDays += count / k;
    return noOfBloomingDays >= m;
}

int minDays(vector<int> arr, int m, int k)
{
    if (m * k > arr.size())
    {
        return -1;
    }

    int mn = *min_element(arr.begin(), arr.end());
    int mx = *max_element(arr.begin(), arr.end());

    for (int i = mn; i <= mx; i++)
    {
        if (isPossible(arr, i, m, k))
        {
            return i;
        }
    }

    return -1;
}

int minDaysBS(vector<int> arr, int m, int k)
{
    if (m * k > arr.size())
    {
        return -1;
    }

    int mn = *min_element(arr.begin(), arr.end());
    int mx = *max_element(arr.begin(), arr.end());

    int start = mn;
    int end = mx;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, mid, m, k))
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}

// Find the Smallest Divisor Given a Threshold

int smallestDivisor(vector<int> arr, int limit)
{
    int mx = *max_element(arr.begin(), arr.end());

    for (int i = 1; i <= mx; i++)
    {

        int sum = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            sum += ceil((double)(arr[j]) / (double)(i));
        }

        if (sum <= limit)
        {
            return i;
        }
    }

    return -1;
}

int smallestDivisorBS(vector<int> arr, int limit)
{
    int mx = *max_element(arr.begin(), arr.end());

    int start = 1;
    int end = mx;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int sum = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            sum += ceil((double)(arr[j]) / (double)(mid));
        }

        if (sum <= limit)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}

// Least Capacity to Ship Packages within D Days

int findDays(vector<int> arr, int capacity)
{
    int days = 1;
    int curr = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        if (curr + arr[i] <= capacity)
        {
            curr += arr[i];
        }
        else
        {
            days += 1;
            curr = arr[i];
        }
    }

    return days;
}

int leastCapacity(vector<int> arr, int d)
{
    int start = *max_element(arr.begin(), arr.end());

    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    int end = sum;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (findDays(arr, mid) <= d)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}

// kth Missing Positive Number
int kthMissingPositiveNumber(vector<int> arr, int k)
{
    int positiveNums = 1;
    int count = 0;

    int i = 0;

    while (i < arr.size())
    {
        if (positiveNums != arr[i])
        {
            count++;

            if (count == k)
            {
                return positiveNums;
            }
        }
        else
        {
            i++; // Move to the next element in the array
        }

        positiveNums++;
    }

    // If we haven't found k missing positive numbers, we can calculate the kth missing positive number
    return positiveNums + k - count - 1;
}

// Aggressive Cows : Detailed Solution

bool canPlaceCows(vector<int> arr, int d, int k)
{
    int count = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - arr[i - 1] <= d)
        {
            count++;

            if (count == k)
            {
                return true;
            }
        }
    }

    return false;
}

int aggressiveCows(vector<int> arr, int k)
{
    sort(arr.begin(), arr.end());

    int mx = arr[arr.size() - 1];
    int mn = arr[0];

    int start = 1;
    int end = mx - mn;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (canPlaceCows(arr, mid, k))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return end;
}

// Allocate Minimum Number of Pages
int isPossible(vector<int> arr, int books)
{
    int count = 1;
    int curr = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (curr + arr[i] <= books)
        {
            curr += arr[i];
        }
        else
        {
            count++;
            curr = arr[i];
        }
    }

    return count;
}

int allocateBooks(vector<int> arr, int k)
{

    if (k > arr.size())
    {
        return -1;
    }

    int mx = *max_element(arr.begin(), arr.end());
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    int start = mx;
    int end = sum;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, mid) <= k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}

// Split Array – Largest Sum
// Same as alllocate Books
int splitArray(vector<int> arr, int k)
{
    return allocateBooks(arr, k);
}

// Painters Partition Problem
// Same

// BOOK ALLOCATIOn -- SPLIT ARRY -- PAINTERS PARTITION -- ALL SAME
// MIN(MAX)

// Median of Two Sorted Arrays of different sizes

// Brute FOrce : Merge 2 arrays -- find median

// We want the middle elements - if even
// else only 1 middle element - if odd
// Therefore maintain the counter when selecting the elements from the array & do not push in any dat astructure

double medianOf2SortedArrays(vector<int> arr1, vector<int> arr2)
{
    int totalSize = arr1.size() + arr2.size();
    int middle = totalSize / 2;

    int i = 0, j = 0;

    int prev, curr;

    int count = 0;

    while (count <= middle)
    {
        prev = curr;

        if (i < arr1.size() && (j >= arr2.size() || arr1[i] < arr2[j]))
        {
            curr = arr1[i];
            i++;
        }
        else
        {
            curr = arr2[j];
            j++;
        }
        count++;
    }

    if (totalSize % 2 == 1)
    {
        return curr;
    }

    return (prev + curr) / 2.0;
}

// Kth element of 2 sorted arrays
int kthEle(vector<int> arr1, vector<int> arr2, int k)
{
    int totalSize = arr1.size() + arr2.size();

    if (k <= 0 || k > totalSize)
    {
        return -1; // Invalid k value
    }

    int i = 0, j = 0;
    int count = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            count++;
            if (count == k)
            {
                return arr1[i];
            }
            i++;
        }
        else
        {
            count++;
            if (count == k)
            {
                return arr2[j];
            }
            j++;
        }
    }

    // If we reach here, it means one of the arrays has been exhausted.
    // We can continue from the remaining elements of the other array.

    while (i < arr1.size())
    {
        count++;
        if (count == k)
        {
            return arr1[i];
        }
        i++;
    }

    while (j < arr2.size())
    {
        count++;
        if (count == k)
        {
            return arr2[j];
        }
        j++;
    }

    return -1;
}


// Heap Sort
void heapify(vector<int> &arr , int n , int i){
    int largest = i;

    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr , n , largest);
    }
}

void heapSort(vector<int> &arr){
    int n = arr.size();

    for(int i = n/2-1 ; i>=0 ; i--){
        heapify(arr , n ,i);
    }

    for(int i = n-1 ; i>=0 ; i--){
        swap(arr[0] , arr[i]);
        heapify(arr , i , 0);
    }
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
    // vector<int> ans = sortArrayOfZeroesOnesTwosUsingDutchAlgo({2, 0, 2, 1, 1, 0});

    // cout << majorityEle({2, 2, 1, 1, 1, 2, 2});
    // cout << majorityEleUsingMooreVotingAlgo({2, 2, 1, 1, 1, 2, 2});

    // cout << maxSubarraySumI({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    // cout << maxSubarraySumII({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    // cout << maxSubarraySumUsingKadanesAlgo({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    // cout << printmaxSubarraySumUsingKadanesAlgo({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    // cout<<stockBuySell({7,6,4,3,1});
    // cout<<stockBuySellOptimised({7,1,5,3,6,4});
    // vector<int> ans = rearrangeArrayWithALternateSigns({1,2,-4,-5});
    // vector<int> ans = leaders({10, 22, 12, 3, 0, 6});
    // vector<int> ans = leadersByTraversingReverse({10, 22, 12, 3, 0, 6});
    // cout << longestConsecutiveSeq({100, 200, 1, 3, 2, 4});

    // vector<vector<int>> ans = setMatrixZero({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, 3, 3);
    // vector<vector<int>> ans = setMatrixZeroUsing2Arrays({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, 3, 3);
    // vector<vector<int>> ans = rotateImageBy90Degree({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 3, 3);
    // vector<vector<int>> ans = rotateImageBy90DegreeOptimized({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 3, 3);
    // vector<int> ans = spiralTraversalOfTheMatrix({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}});

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans.size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout<<countSubarraysWithGivenSum({3, 1, 2, 4} , 6);
    // vector<int> ans = majorityEleNBy3Times({11,33,33,11,33,11});

    // cout << maxSubarraySumofSizeK({1, 2, 3, 4, 5}, 2);
    // vector<int> ans = firstNegative({-2 , 2 , 3 , 3 , -5} , 2);
    // cout << countOccurencesOfAnagram("forxxorfxdofr", "for");
    // vector<int> ans = maxEleInSubarray({8, 5, 10, 7, 9, 4, 15, 12, 90, 13} , 4);

    // cout << floor({3, 5, 8, 15, 19}, 9);
    // cout<<ceil({3, 4, 4, 7, 8, 10} , 9);
    // cout<<lowerBound({3, 5, 8, 15, 19} , 9);
    // cout << upperBound({3, 5, 8, 15, 19}, 9);
    // cout << searchInRotatedSOrtedArray({7, 8, 9, 1, 2, 3, 4, 5, 6}, 1);
    // cout<<searchInRotatedSOrtedArrayII({1 , 0 , 1 , 1, 1} , 0);
    // cout<<minInRotatedSortedArray({3,4,5,1,2});
    // cout << numberOfRotations({66, 67, 7, 10, 14, 19, 27, 33, 36, 40, 44, 54, 60});
    // cout<<searchSingleEleUsingBinarySearch({1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6});
    // cout << peakEle({1, 2, 1, 3, 5, 6, 4});
    // cout<<sortCharactersByFreq("geeksforgeeks");
    // cout<<coinChange({ 1, 2, 5, 10, 20, 50, 100, 500, 1000} , 121);
    // Item arr[3] = { {100,20},{60,10},{120,30} };
    // cout << fractionalKnapsack(arr, 50, 3);
    // cout << sqrtNum(28);
    // cout << sqrtUsingBS(37);
    // cout << nthRoot(3, 27);
    // cout << kokoEatingBananasUsingBS({7, 15, 6, 3}, 8);
    // cout<<minDays({7, 7, 7, 7, 13, 11, 12, 7} , 2 , 3);
    // cout << minDaysBS({7, 7, 7, 7, 13, 11, 12, 7}, 2, 3);
    // cout << smallestDivisor({1, 2, 3, 4, 5}, 8);
    // cout << smallestDivisorBS({1, 2, 3, 4, 5}, 8);
    // cout << leastCapacity({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1);
    // cout<<kthMissingPositiveNumber({4 , 7 , 9 , 10} , 4);
    // cout<<aggressiveCows({4,2,1,3,6} , 2);
    // cout<<allocateBooks({12, 34, 67, 90} , 2);
    // cout<<splitArray({1,2,3,4,5} , 3);
    // cout << medianOf2SortedArrays({2, 4, 6}, {1, 3, 5});
    // cout<<kthEle({2,3,6,7,9} , {1,4,8,10} , 5);
    vector<int> ans = {3 , 5 , 2 , 6 , 8};

    heapSort(ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
