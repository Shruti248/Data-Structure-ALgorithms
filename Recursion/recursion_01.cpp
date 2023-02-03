// Function calls Itself to make the problem smaller

// Add All The Numbers till n
// Sum till n = n+ n-1 + n-2 ...... +1
// Sum till n =  n+ sum till n-1
// Sum till n-1 =  n-1 + sum till n-2
// And so on.....

// Sum till 0 = 0
// Stop at 0 (Endpoint where it eeds to be stopped).

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int Sum(int n){

            // Ending point 
            if(n == 0){
                return 0;
            }
            int prevSum  = Sum(n-1);
            // cout<<prevSum<<endl;
            return n+prevSum;
        }
};

int main(){
    Solution s;
    int n;
    cin>>n;
    cout<<s.Sum(n);
    return 0;
}


