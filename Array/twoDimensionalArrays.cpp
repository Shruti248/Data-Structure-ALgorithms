#include<bits/stdc++.h>
using namespace std;

int main(){
    // Declaration
    // int arr[rows][columns]; 

    int rows , columns;
    cin>>rows;
    cin>>columns;

    int arr[rows][columns];

    // Taking input
    for(int i = 0 ; i<rows ; i++){
        for(int j = 0 ; j<columns ; j++){
            cin>>arr[i][j];
        }
    }

    // Printing 2D Array
    // for(int i = 0 ; i<rows ; i++){
    //     for(int j = 0 ; j<columns ; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // Searching a Matrix
    int ElementToBeSearched;
    cin>>ElementToBeSearched;
    for(int i = 0 ; i<rows ; i++){
        for(int j = 0 ; j<columns ; j++){
            if(arr[i][j] == ElementToBeSearched){
                cout<<"Element "<<ElementToBeSearched<<" is present at index : "<<i<<" "<<j<<endl;
            }
        }
    }
    
    return 0;
}