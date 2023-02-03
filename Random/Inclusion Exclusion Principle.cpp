// Useful when there are problems where we need to find the number of ways to do something 

// n1 : Way 1 
// n2 : Way 2 
// n3 : Both ways 

// Total : n1+n2-n3 (Adding both the ways and subtracting the commom way ..... THis is the inclusion exclusion Principle)


// EG 1 : How many numbers between 1 and 1000 are divisble by 5 or 7 ? 

// n1 : Numbers divisible by 5
// n2 : Numbers divisible by 7
// n3 : Numbers divisible by both 5 and 7

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void NumbersDivisble(int upperBound , int a , int b){
            int c1 = upperBound/a;
            int c2 = upperBound/b;

            int c3 = upperBound/(a*b);

            cout<<c1+c2-c3<<endl;
        }
};
int main(){
    Solution s;
    int upperBound , a , b;
    cin>>upperBound;
    cin>>a>>b;
    s.NumbersDivisble(upperBound , a , b);
    
    return 0;
}