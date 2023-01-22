#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Size of the charcater array is n+1 .
    // The extra 1 space is used by the NULL CHARACTER'/0'
    // which ensures that the word , sentence is completed.

    // Declaration
    int n;
    cin >> n;
    cin.ignore();
    char arr[n + 1];

    // Input
    // cin>>arr;

    // Output
    // cout<<arr;
    // cout<<arr[2];

    // check Palindrome : the word that remains same even if it is reversed is said to be a palindrome
    // Eg : Nitin , anna

    // bool check = 1;

    // for(int i = 0 ; i<n ; i++){
    //     // Checking charcaters from both ends
    //     if(arr[i] != arr[n-i-1]){
    //         check = 0;
    //         break;
    //     }
    // }
    // if(check == true){
    //     cout<<"Word is Palindrome."<<endl;
    // }else{
    //     cout<<"Word is NOT a Palindrome."<<endl;
    // }

    // Largest Word in the Sentence
    // input for a sentence in character arrays is different.
    cin.getline(arr, n);
    cin.ignore(); // to remove the buffer
    int i = 0;

    int currentLength = 0;
    int maxLength = 0;

    int st =0 , maxSt =0;

    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currentLength > maxLength)
            {
                maxLength = currentLength;
                maxSt = st;
            }

            currentLength = 0;
            st=i+1;
        }
        else
            currentLength++;
        if (arr[i] == '\0')
        {
            break;
        }

        i++;
    }

    cout << maxLength << endl;

    for(int i = 0 ; i<maxLength ; i++){
        cout<<arr[i+maxSt];
    }

    return 0;
}