#include<bits/stdc++.h>
using namespace std;


// Prefix sum[i] == 0 thi lai ne ith sudhi nu sum hase e thai gyu prefix sum
vector<int> findPrefixSum(vector<int> arr){

    // same size as teh array --
    vector<int> prefixSum(arr.size());

    // int sum = 0;

    // for(int i = 0 ; i<arr.size() ; i++){
    //     sum += arr[i];
    //     prefixSum[i] = sum;
    // }

    // return prefixSum;

    prefixSum[0] = arr[0];

    for(int i = 1 ; i <arr.size() ; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    return prefixSum;
}

int main(){
    vector<int> arr = {1 , 2 , 3 , 4 , 5};
    vector<int> prefixSum = findPrefixSum(arr);

    for(int i = 0 ; i<prefixSum.size() ; i++){
        cout<<prefixSum[i]<<" ";
    }
    return 0;
}
