#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void rhombusPattern(int n){
            for(int i = 0 ; i<n ; i++){
                for(int j = 0 ; j<2*n ; j++){
                   if(j>=n-i && j<2*n-i){
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
    int n ;
    cin>>n;
    Solution s;
    s.rhombusPattern(n);
    return 0;
}