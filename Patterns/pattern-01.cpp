#include<bits/stdc++.h>
using namespace std;

// Sqaure Pattern
void square(int n){
    for(int  i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            cout<<" * ";
        }
        cout<<endl;
    }
}

void rightAngledTriangle(int n){
    for(int i = 0 ; i<n ; i++){
        // for(int j = 0 ; j<n ; j++){
        //     if(i >= j){
        //         cout<<" * ";
        //     }else{
        //         cout<<"   ";
        //     }
        // }

        for(int j = 0 ; j<=i ; j++){
            cout<<" * ";
        }
        cout<<endl;
    }
}

void rightAngledNumberedPyramid(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=i ; j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void rightAngledNumberedPyramidII(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=i ; j++){
            cout<<i;
        }
        cout<<endl;
    }
}
void invertedRightPyramid(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j = n ; j>= i ; j--){
            cout<<"*";
        }
        cout<<endl;
    }
}
void invertedNumberedRightPyramid(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j = n ; j>= i ; j--){
            cout<<n-j+1;
        }
        cout<<endl;
    }
}

void starPyramid(int n){
    for(int i = 1 ; i<=n ; i++){

            // Spaces
            for(int j = 1 ; j <= n-i ; j++){
                cout<<" ";
            }

            for(int j = 1 ; j<= 2*i-1 ; j++){
                cout<<"*";
            }

            for(int j = 1 ; j <= n-i ; j++){
                cout<<" ";
            }

            cout<<endl;
    }
}

int main(){
    // square(3);
    // rightAngledTriangle(6);
    // rightAngledNumberedPyramid(5);
    // rightAngledNumberedPyramidII(7);
    // invertedRightPyramid(5);
    // invertedNumberedRightPyramid(6);
    starPyramid(5);
    return 0;
}
