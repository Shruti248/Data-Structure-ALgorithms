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
//With heap this sorting happens in nlogk times(Reducing the extra work done in soring) : Sort only k elements


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


#include<bits/stdc++.h>
using namespace std;

// kth smallest element
// 1) Sorting : return arr[k-1]; -->nlogn
// 2) Heap : nlogk

int kthSmallestElement(vector<int> arr , int k){
    priority_queue<int> pq;

    for(int i = 0 ; i<arr.size() ; i++){
        pq.push(arr[i]);

        if(pq.size() > k){
            pq.pop();
        }
    }

    return pq.top();
}

// Return k largest elements in the array

vector<int> kLargestElement(vector<int> arr , int k){
    priority_queue<int , vector<int> , greater<int>> pq;

    for(int i = 0 ; i<arr.size() ; i++){
        pq.push(arr[i]);

        if(pq.size() > k){
            pq.pop();
        }
    }

    // Now all the elements in the heap is the k largest elements
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}


//IMP :  Sort a k sorted array/Nearly sorted array

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

vector<int> sortKSortedArray(vector<int> arr , int k){
    vector<int> ans;

    priority_queue<int , vector<int> , greater<int>> pq;
    for(int i = 0 ; i<arr.size() ; i++){
        pq.push(arr[i]);

        if(pq.size() > k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}



int main(){
    // cout<<kthSmallestElement({9 , 6 , 3 , 4 ,5} , 3);

    // vector<int> ans = kLargestElement({7 , 10 , 4 , 3 , 20 , 15} , 3);
    vector<int> ans = sortKSortedArray({6 , 5 , 3 , 2 , 8 , 9 , 10} , 3);
    for(int i = 0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
