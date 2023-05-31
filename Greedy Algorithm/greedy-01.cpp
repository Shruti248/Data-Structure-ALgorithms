#include<bits/stdc++.h>
using namespace std;

// IMPORTANT
    // 1) Generally sorting is done first while applyin greedy
    // 2) Sometimes we do not realise that we are applying greedy ecause it comes from inside

// Indian Coin Change Problem
int coinChange(vector<int> denominations , int amount){
    int n = denominations.size();

    sort(denominations.begin() , denominations.end() , greater<int>());

    int ans = 0;

    for(int i = 0 ; i<n ; i++){
        ans += amount/denominations[i];
        amount -= amount/denominations[i]*denominations[i];
    }
    return ans;

}

// Activity Selection Problem
int activitySelectionProblem(vector<vector<int>> v /**Start & end Times*/){
    int n = v.size();

    // Sort Acc to finish Times
    sort(v.begin() , v.end() , [&](vector<int> &a , vector<int> &b){
        return a[1] < b[1];
    });

    // Taking the first Activity
    int take = 1;
    int end = v[0][1];
    for(int i = 1 ; i<n ; i++){
        if(v[i][0] >= end){
            take++;
            end = v[i][1];
        }
    }

    return take;

}

int main(){
    // vector<int> denomiations = {1 , 2 , 5 , 10 , 20 , 50 , 100 , 200 , 500 , 2000};
    // cout<<coinChange(denomiations , 350);

    vector<vector<int>> times = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};

    cout<<activitySelectionProblem(times);
    return 0;
}
