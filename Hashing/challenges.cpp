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

// Iterate though input array arr[], for every element arr[i], increment arr[arr[i]%k] by k (arr[] becomes {2, 11, 11, 29, 11, 12, 1, 15 })

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

    for (int i = 0; i < n; i++)
        arr[i] = arr[i] % k;

    return result;
}

// Kth smallest integer after removing natural Numbers
// Time Complexity: O(MAX)
// Auxiliary Space: O(MAX)
int kthSmallestInteger(vector<int> arr, int k)
{
    int MAX = 100;
    int b[MAX];

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

// Time complexity: O(log(n-k))
//  Space complexity: O(k)
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

// Time Complexity: O(N * log K)
// Auxiliary Space: O(K)
vector<int> kthLargestinaStream(int k, vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);

    // Creating a min-heap using priority queue
    priority_queue<int, vector<int>, greater<int>> pq;

    // Iterating through each element
    for (int i = 0; i < n; i++)
    {
        // If size of priority
        // queue is less than k
        if (pq.size() < k)
            pq.push(arr[i]);
        else
        {
            if (arr[i] > pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        // If size is less than k
        if (pq.size() < k)
            ans[i] = -1;
        else
            ans[i] = pq.top();
    }

    return ans;
}

// Connect N Ropes with Minimum Cost
// Time Complexity: O(N*log(N))
// Auxiliary Space: O(N)

int minCostToConnectNRopes(int arr[], int n)
{
    int res = 0;
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);

    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        res += first + second;
        pq.push(first + second);
    }

    return res;
}

// Find Itinerary from a given list of tickets
// Time Complexity: O(n).
// Auxiliary Space: O(n), The extra space is used in map.

void printItinerary(map<string, string> dataset)
{
    map<string, string> reversemap;
    map<string, string>::iterator it;

    for (it = dataset.begin(); it != dataset.end(); it++)
    {
        reversemap[it->second] = it->first;
    }

    string start;

    for (it = dataset.begin(); it != dataset.end(); it++)
    {
        if (reversemap.find(it->first) == reversemap.end())
        {
            start = it->first;
            break;
        }
    }

    if (start.empty())
    {
        cout << "Invalid Input ";
        return;
    }

    while (it != dataset.end())
    {
        cout << it->first << " -> " << it->second << " , ";
        it = dataset.find(it->second);
    }
}

// Count distinct elements for every window of size K

void countDistinct(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int distCount = 0;

    for (int i = 0; i < k; i++)
    {
        if (mp[arr[i]] == 0)
        {
            distCount++;
        }

        mp[arr[i]] += 1;
    }

    cout << distCount << endl;

    for (int i = k; i < n; i++)
    {
        if (mp[arr[i - k]] == 1)
        {
            distCount--;
        }
        mp[arr[i - k]] -= 1;

        if (mp[arr[i]] == 0)
        {
            distCount++;
        }
        mp[arr[i]] += 1;

        cout << distCount << endl;
    }
}

// Group SHifted Strings
// Time Complexity: O(N*K), where N=length of string array and K is maximum length of string in string array
// Auxiliary Space: O(N)
string getDiffString(string str)
{
    string shift = "";

    for (int i = 1; i < str.length(); i++)
    {
        int diff = str[i] - str[i - 1];
        if (diff < 0)
            diff += 26;

        shift += diff + 'a';
    }
    return shift;
}

void groupShiftedString(string str[], int n)
{
    map<string, vector<int>> groupMap;

    for (int i = 0; i < n; i++)
    {
        string diffStr = getDiffString(str[i]);
        cout << diffStr << endl;
        groupMap[diffStr].push_back(i);
    }

    for (auto it = groupMap.begin(); it != groupMap.end(); it++)
    {
        vector<int> v = it->second;
        for (int i = 0; i < v.size(); i++)
        {
            cout << str[v[i]] << " ";
        }
        cout << endl;
    }
}

// Sliding Window Maximum (Maximum of all subarrays of size K)

vector<int> slidingWindowMaximum(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i], i});
    }

    ans.push_back(pq.top().first);
    pq.pop();

    for (int i = k; i < n; i++)
    {
        pq.push({arr[i], i});

        while (pq.top().second <= i - k)
            pq.pop();

        ans.push_back(pq.top().first);
    }

    return ans;
}

// Smallest Positive Number
// O(nlogn)
// O(1)
// SOrting approach

int smallestMissingPositiveNumber(int arr[], int n)
{
    sort(arr, arr + n);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ans)
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    // vector<int> arr = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3};
    // cout << maximumRepeatingElement(arr, 10);

    // vector<int> arr = {2, 3};
    // cout << kthSmallestInteger(arr, 2) << endl;
    // cout << kthSmallestIntegerOptimized(arr, 2) << endl;
    // cout << kthSmallestIntegerMostOptimized(arr, 2) << endl;

    // vector<int> arr = {1, 2, 3, 4, 5};
    // vector<int> res = kClosestElement(arr, 3, 4);
    // vector<int> res = kClosestElementsOptimized(arr, 3, 4);

    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }

    // vector<int> arr =  { 1, 2, 3, 4, 5, 6 };
    // vector<int> res = kthLargestinaStream( 4 , arr);

    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }

    // int arr[] = {4, 3, 2, 6};
    // cout << minCostToConnectNRopes(arr, 4);

    // map<string, string> dataSet;
    // dataSet["Chennai"] = "Banglore";
    // dataSet["Bombay"] = "Delhi";
    // dataSet["Goa"] = "Chennai";
    // dataSet["Delhi"] = "Goa";

    // printItinerary(dataSet);

    // int arr[] = {1, 2, 1, 3, 4, 2, 3};

    // countDistinct(arr, 7, 4);

    // string str[] = {"acd", "dfg", "wyz", "yab", "mop",
    //                 "bdfh", "a", "x", "moqs"};
    // int n = sizeof(str) / sizeof(str[0]);
    // groupShiftedString(str, n);

    // vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    // int k = 3;

    // vector<int> result = slidingWindowMaximum(arr, k);

    // for (auto i : result)
    //     cout << i << " ";

    int arr[] = { 0, 1, 2, -10, -20 };
    cout << smallestMissingPositiveNumber(arr , 5);
    return 0;
}
