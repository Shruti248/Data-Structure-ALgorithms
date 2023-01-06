#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void invertedHalfPyramid(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                cout << " * ";
            }
            cout << endl;
        }

        // for(int i=n ; i>=1 ; i--){
        //     for(int j = 1 ; j<=i ; j++){
        //         cout<<" * ";
        //     }
        //     cout<<endl;
        // }
    }

    // Half Pyramid after 180 degree rotation
        //  *
    //   *  *
    // * *  *
    void straightHalfPyramid(int n){
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = 0 ; j<n  ; j++){
                if( j>=i){
                    cout<<" * ";
                }else{
                    cout<<"   ";
                }
            }
            cout<<endl;
        }
    }                                                 
};

int main()
{
    int n;
    Solution s;
    cin >> n;
    s.invertedHalfPyramid(n);
    s.straightHalfPyramid(n);
    return 0;
}