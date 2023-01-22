#include<bits/stdc++.h>
using namespace std;

int main(){
    // Size of the charcater array is n+1 .
    // The extra 1 space is used by the NULL CHARACTER'/0'
    // which ensures that the word , sentence is completed.

    // Declaration
    int n;
    cin>>n;
    char arr[n+1];

    // Input
    cin>>arr;

    // Output
    // cout<<arr;
    // cout<<arr[2];

    // check Palindrome : the word that remains same even if it is reversed is said to be a palindrome
    // Eg : Nitin , anna

    bool check = 1;

    for(int i = 0 ; i<n ; i++){
        // Checking charcaters from both ends
        if(arr[i] != arr[n-i-1]){
            check = 0;
            break;
        }
    }
    if(check == true){
        cout<<"Word is Palindrome."<<endl;
    }else{
        cout<<"Word is NOT a Palindrome."<<endl;
    }
    return 0;
}