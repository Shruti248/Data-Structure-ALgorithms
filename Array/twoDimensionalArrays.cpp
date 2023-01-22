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
    // int ElementToBeSearched;
    // cin>>ElementToBeSearched;
    // for(int i = 0 ; i<rows ; i++){
    //     for(int j = 0 ; j<columns ; j++){
    //         if(arr[i][j] == ElementToBeSearched){
    //             cout<<"Element "<<ElementToBeSearched<<" is present at index : "<<i<<" "<<j<<endl;
    //         }
    //     }
    // }

    // Spiral Order Traversal 
    int row_start = 0 ;
    int row_end = rows-1;
    int column_start =0;
    int column_end = columns-1;

    while(row_start <=row_end && column_start <=column_end){
        // for Row Start
        for(int col = column_start ; col <=column_end ; col++){
            cout<<arr[row_start][col]<<" ";
        }
        row_start++;

        // for column end
        for(int row = row_start ; row<=row_end ; row++){
            cout<<arr[row][column_end]<<" ";
        }
        column_end--;

        // For Row End
        for(int col = column_end ; col>=column_start ; col--){
            cout<<arr[row_end][col]<<" ";
        }
        row_end--;

        // For Column Start
        for(int row = row_end ; row >=row_start ; row--){
            cout<<arr[row][column_start]<<" ";
        }
        column_start++;
    }
    
    return 0;
}