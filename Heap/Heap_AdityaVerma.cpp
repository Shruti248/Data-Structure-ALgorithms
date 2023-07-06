// IMP

// Identification
// k (Make Heap of this k size)
// Smallest / Largest

// If this 2 given in question : Definitely Heap Problem

// 2 types
// Min Heap , max Heap

// REMEMBER
// k + smallest = max : We remove larger elements
// k + largest = min : Bcoz we remove smaller elements

// if elements greater than k in heap : POP
// Ans : Top of teh heap

// All question sof heap are of sorting : SOrting (O(nlogn))

// IMP
// With heap this sorting happens in nlogk times(Reducing the extra work done in soring) : Sort only k elements

// WORKING
// Eg : kth smallest element
// input : array : 7 10 4 3 20 15 , k = 3

// Smallest : Max Heap

// push k elements in heap ,
// if element greater than k then pop from heap : Element popped witll be as large as possible and will never be in the answer...
// At end of traversal : top of the heap : ANSSSSS

// Extra work on the elements is removed in this case , hence sorting is only on k elements which is smallest among the array and complexity becomes nlogk;

// STL :
// max heap : priority_queue<int> pq;
// min heap : priority_queue<int , vector<int> , greater<int>> pq;

// If you need to insert pairs : replace int with pair<int , int>

// #type def pair<int , <pair<int , int>> ppi; --> pair of pair of int

#include <bits/stdc++.h>
using namespace std;

// kth smallest element
// 1) Sorting : return arr[k-1]; -->nlogn
// 2) Heap : nlogk

int kthSmallestElement(vector<int> arr, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.top();
}

// Return k largest elements in the array

vector<int> kLargestElement(vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    // Now all the elements in the heap is the k largest elements
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

// IMP :  Sort a k sorted array/Nearly sorted array

// k sorted array : elements are present at k range away from there original position in the sorted array

// Eg : 6 5 3 2 8 9 10
// 2 should be at 0 : at index 3
// 3 should be at 1 : at index 2
// 5 should be at 2 : at index 1

// k is 3 : Within 3 range all elements become sorted

// 1st approach is always sorting : O(nlogn)

// Heap Approach
// Since size is fixed : k

// min heap : bcoz we want min element at the top of heap

vector<int> sortKSortedArray(vector<int> arr, int k)
{
    vector<int> ans;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);

        if (pq.size() > k)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

// k closest elements
// Brute force : SUbtract all teh values from the element whose closest si to be found
// Eg : 5 6 7 8 9
// 3 closest to 7

// 2 1 0 1 2 --> subtratcting abs value
// we sort acc to this values : return thos number by adding it again to this

// Sorting is done in this abs difference array
// then we find the ans with first k elements

// Using sorting
// vector<int> kClosestElements(vector<int> arr , int k , int num){
//     vector<int> ans;

//     vector<pair<int , int>> temp;

//     for(int i = 0 ; i<arr.size() ; i++){
//         temp.push_back({abs(arr[i] - num) , arr[i]});
//     }

//     sort(temp.begin() , temp.end() ,  [](const pair<int, int>& a, const pair<int, int>& b) {
//         return a.first < b.first;
//     });

//     for(int i = 0 ; i<k ; i++){
//         ans.push_back(temp[i].second);
//     }

//     return ans;
// }

// Using Heap : Key is the absolute difference
// Closest : smallest : Max Heap : therefore larger values are popped out

// Heap : pair<int , int> : Automatically sorting on first int

vector<int> kClosestElements(vector<int> arr, int k, int num)
{

    // Max Heap of type pair<int , int>
    priority_queue<pair<int, int>> pq;

    // first value L key , second : Element

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({abs(arr[i] - num), arr[i]});

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

// Top k frequent(largest) numbers
// Key : Frequency

vector<int> topKFrequent(vector<int> arr, int k)
{
    unordered_map<int, int> mp;

    // COnverted array to hash
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    // Using this hash for heap
    // Sort the frequency

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        pq.push({i->second, i->first});

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

// Frequency sort : Sort based on frequency
// Ans : 1 1 1  2 2 3 4

// Compare function approach is also done

// Using heap

vector<int> frequencySort(vector<int> arr)
{
    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    // Max heap
    priority_queue<pair<int, int>> pq;

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        pq.push({i->second, i->first});
    }

    while (!pq.empty())
    {
        int freq = pq.top().first;
        while (freq != 0)
        {
            ans.push_back(pq.top().second);
            freq--;
        }
        pq.pop();
    }

    return ans;
}

// IMPPP
// k closest point to origin
// Input : 2D Array  or pair<int, int> --> x & y corrdinate are given

// Find distance of points from origin

// Sice second point is origin : Hence distance formula becomes : underroot(x2+y2)
// We need to minimize the value of underroot(x2+y2); ---> KEYYYYY
// Sort on the basis of this

// underroot(x2+y2); ---> KEYYYYY

// EVen if we find just the x2+ y2 that is the whole sqaure of underoot(....) ---> No difference just the calculation is less

// x2+y2 == KEY

// Closest --> nearest --> smallest --> max Heap

// priority_queue<pair<int /**Key : x2+y2*/,pair<int , int> /**x y coordinates*/>>>

vector<vector<int>> kClosestPointsToOrigin(vector<vector<int>> &arr, int k)
{

    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1], {arr[i][0], arr[i][1]}});

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<vector<int>> ans;
    while (!pq.empty())
    {
        auto point = pq.top().second;
        ans.push_back({point.first, point.second});
        pq.pop();
    }

    return ans;
}


// connect ropes : to minimize the cost
// at any time , add 2 ropes that is minimum --> Most optimal cost occurs in this only

// take min 2 element : add them to ans : push back to heap

// if(heap.size() < 2) --> STOP --> return ans

int connectRopes(vector<int> arr){

    // Min heap : Boz we want 2 min elements
    priority_queue<int , vector<int> , greater<int>> pq;

    for(int i = 0  ; i<arr.size() ; i++){
        pq.push(arr[i]);
    }

    int cost = 0;
    while(pq.size() >= 2){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        cost += first+second;

        pq.push(first+second);
    }

    return cost;
}



int main()
{
    // cout<<kthSmallestElement({9 , 6 , 3 , 4 ,5} , 3);

    // vector<int> ans = kLargestElement({7 , 10 , 4 , 3 , 20 , 15} , 3);
    // vector<int> ans = sortKSortedArray({6 , 5 , 3 , 2 , 8 , 9 , 10} , 3);
    // vector<int> ans = kClosestElements({5, 6, 7, 10, 9}, 3, 7);
    // vector<int> ans = topKFrequent({5, 6, 5, 6, 9}, 2);
    // vector<int> ans = frequencySort({5, 5, 6, 3, 2, 5, 3, 2});

    cout<<connectRopes({1 , 2 , 3 , 4 , 5});
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    return 0;
}
