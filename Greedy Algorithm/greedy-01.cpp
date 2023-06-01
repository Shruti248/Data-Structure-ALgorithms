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

// Fractional KnapSack
// Value per unit weight --> select max
// Time Complexity: O(N * logN)
// Auxiliary Space: O(N)
bool compare(pair<int , int> p1 , pair<int , int> p2){
    double v1 = (double) p1.first/p1.second;
    double v2 = (double) p2.first/p2.second;

    return v1 > v2;
}

int fractionalKnapsack(vector<pair<int , int>> a , int W){
    sort(a.begin() , a.end() , compare);

    int ans = 0;
    int n = a.size();
    for(int i = 0 ; i<n ; i++){
        if(W > a[i].second){
            ans += a[i].first;
            W-= a[i].second;
            continue;
        }

        double vw = (double) a[i].first/a[i].second;

        ans += vw*W;
        W = 0;
        break;
    }
    return ans;
}

int main(){
    // vector<int> denomiations = {1 , 2 , 5 , 10 , 20 , 50 , 100 , 200 , 500 , 2000};
    // cout<<coinChange(denomiations , 350);

    // vector<vector<int>> times = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};

    // cout<<activitySelectionProblem(times);

    // vector<pair<int, int>> vw = {{21, 7}, {24, 4}, {12, 6}, {40, 5}, {30, 6}};
    vector<pair<int, int>> vw = {{60, 10}, {100, 20}, {120, 30}};

    // cout<<fractionalKnapsack(vw , 20);
    cout<<fractionalKnapsack(vw , 50);
    return 0;
}
