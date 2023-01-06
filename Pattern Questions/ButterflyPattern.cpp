#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        void ButterflyPattern(int n){
            // Upper Part
            for(int i = 0 ; i< n ; i++){
                for(int j = 1 ; j<=(2*n) ; j++){
                    if(j <= i+1 || j>= ((2*n)-i)){
                        cout<<" * ";
                    }else{
                        cout<<"   ";
                    }
                }
                cout<<endl;
            }
            // Bottom Part
            for(int i = n ; i< 2*n ; i++){
                for(int j = 1 ; j<=(2*n) ; j++){
                    if(j >= i+1 || j<= ((2*n)-i)){
                        cout<<" * ";
                    }else{
                        cout<<"   ";
                    }
                }
                cout<<endl;
            }
        }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    s.ButterflyPattern(n);
    return 0;
}