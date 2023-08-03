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
bool isSubsetII(vector<int> arr1 , vector<int> arr2){
    int i = 0 , j = 0;

    sort(arr1.begin() , arr1.end());
    sort(arr2.begin() , arr2.end());

    while(i < arr1.size() && j<arr2.size()){
        if(arr1[i] == arr2[j]){
            i++;
            j++;
        }else if(arr1[i] > arr2[j]){
            j++;
        }else{
            i++;
        }
    }


    if(j != arr2.size()-1){
        return false;
    }

    return true;
}

//Find Second Smallest and Second Largest Element in an array
// 1)with sorting
// 2) without sorting : 2 traversals
    // Time Complexity: O(N), We do two linear traversals in our array
    // Space Complexity: O(1)
// 3) Using Single Traversal

void secondSmallestAndLargest(vector<int> arr){
    int smallest = INT_MAX;
    int largest = INT_MIN;

    int secondSmallest = INT_MAX;
    int secondLargest = INT_MIN;

    for(int i = 0 ; i<arr.size() ; i++){
        if(arr[i] < smallest){
            smallest = arr[i];
        }

        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    for(int i = 0 ; i<arr.size() ; i++){
        if(arr[i] < largest && arr[i] > secondLargest){
            secondLargest = arr[i];
        }

        if(arr[i] > smallest && arr[i] < secondSmallest){
            secondSmallest = arr[i];
        }
    }

    if(secondLargest == INT_MIN){
        secondLargest = -1;
    }

    if(secondSmallest == INT_MAX){
        secondSmallest = -1;
    }

    cout<<secondSmallest<<secondLargest<<endl;
}


// O(N) : Single traversal
// Similarly seocnd Smallest
void secondLargestEle(vector<int> arr){
    int largest = INT_MIN , secondLargest = INT_MIN;

    for(int i = 0 ; i<arr.size() ; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }

    cout<<secondLargest<<endl;
}

int main()
{
    // freq({2 , 2 , 4 , 2 , 6 , 6 });
    // freqUsingVisitedArray({2 , 2 , 4 , 2 , 6 , 6 , 6});
    // freqHashing({2 , 2 , 4 , 2 , 6 , 6 , 6});

    // cout << issubset({11, 1, 13, 21, 3, 7}, {11, 1, 3});
    // cout << isSubsetII({11, 1, 13, 21, 3, 7}, {11, 16, 3});

    // secondSmallestAndLargest({1});
    secondLargestEle({1 , 4 , 2 , 6, 7});
    return 0;
}
