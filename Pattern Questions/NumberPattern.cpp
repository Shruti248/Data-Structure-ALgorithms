#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        // . . 1 . . 
        // . 1 . 2 . 
        // 1 . 2 . 3 
        void NumberPattern(int n){
            for(int i = 1 ; i<=n ; i++){
                for(int j = 1 ; j<=n-i ; j++){
                    cout<<" ";
                }
                for(int j = 1 ; j<=i ; j++){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    s.NumberPattern(n);
    return 0;
}