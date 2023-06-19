// Binary Search : Sorted Array
#include<bits/stdc++.h>
using namespace std;

int search(vector<int> nums , int ele){
    int start = 0;
    int end = nums.size()-1;

    while(start <= end){
        int mid = (start+end)/2;

        if(nums[mid] == ele){
            return mid;
        }else if(nums[mid] > ele){
            // Left
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    return -1;
}

int main(){
    vector<int> nums = {1 , 2 , 3 , 4};
    cout<<search(nums , 1);
    return 0;
}
