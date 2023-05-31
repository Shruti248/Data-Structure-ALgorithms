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

int main(){
    vector<int> denomiations = {1 , 2 , 5 , 10 , 20 , 50 , 100 , 200 , 500 , 2000};
    cout<<coinChange(denomiations , 350);
    return 0;
}
