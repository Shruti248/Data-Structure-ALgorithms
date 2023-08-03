#include <bits/stdc++.h>
using namespace std;

// Count frequency of each element in the array
// Brute force
void freq(vector<int> arr)
{
    vector<pair<int , int>> ans;

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
            cout<<arr[i-1]<<" "<<count<<endl;
            count = 1;
        }
    }

    if(count > 0){
        cout<<arr.back()<<" "<<count<<endl;
    }
}

// Another brute force : Jyare bhi hashing ave tyare visited array/frequency array no concept lagi jase : Keys act as indexes in array
void freqUsingVisitedArray(vector<int> arr){
    vector<int> visited(arr.size(), 0);

    for(int i = 0 ; i<arr.size() ; i++){
            visited[arr[i]]++;
    }

    // Print
    for(int i = 0 ; i<visited.size() ; i++){
        if(visited[i] != 0){
            cout<<i<<" "<<visited[i]<<endl;
        }
    }

}

// Using Hashing : bcoz key value type data
// O(n)
// O(n)
void freqHashing(vector<int> arr){
    unordered_map<int , int> mp;

    for(int i = 0 ; i<arr.size() ; i++){
            mp[arr[i]]++;
    }

    // print map
    for(auto i : mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
}

int main()
{
    // freq({2 , 2 , 4 , 2 , 6 , 6 });
    freqUsingVisitedArray({2 , 2 , 4 , 2 , 6 , 6 , 6});
    // freqHashing({2 , 2 , 4 , 2 , 6 , 6 , 6});
    return 0;
}
