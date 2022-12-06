// // Add 2 numbers 
// #include<iostream>
// using namespace std;

// int main(){

//     int T , A , B;
//     cout<<"Test Cases"<<endl;
//     cin>>T;
//     while(T--){
//         cin>>A>>B;
//     }
//     cout<<"A + B  : "<<A+B<<endl;
//     return 0;
// }

// Remainder
// #include<iostream>
// using namespace std;

// int main(){

//     int T , A , B;
//     cout<<"Test Cases"<<endl;
//     cin>>T;
//     while(T--){
//         cin>>A>>B;
//         cout<<"Remainder  : "<<A%B<<endl;
//     }
    
//     return 0;
// }

//Second max of 3 numbers
// #include<iostream>
// using namespace std;

// int main(){

//     int T , A , B , C ;
//     cout<<"Test Cases"<<endl;
//     cin>>T;
//     while(T--){
//         cin>>A>>B>>C;
//         if(A>B && A>C){
//             if(B>C){
//                 cout<<B<<endl;
//             }
//             else{
//                 cout<<C<<endl;
//             }
//         }
//         if(B> C && B>A){
//             if(A>C){
//                 cout<<A<<endl;
//             }
//             else{
//                 cout<<C<<endl;
//             }
//         }
//         if(C> B && C>A){
//             if(B>A){
//                 cout<<B<<endl;
//             }
//             else{
//                 cout<<A<<endl;
//             }
//         }
//     }
    
//     return 0;
// }

// Mahasena 
// #include<iostream>
// using namespace std;

// int main(){

//     int N , a[N] , i , count1=0 , count2=0;
//     cin>>N;
//     for(i = 0 ; i<N ; i++){
//         cin>>a[i];
//         if(a[i]%2 == 0){
//         count1++;
//     }
//     else{
//         count2++;
//     }
//     }
    
//     if(count1>count2){
//         cout<<"Ready for Battle"<<endl;
//     }
//     else{
//         cout<<"Not Ready"<<endl;
//     }
//     return 0;
// }

// //FIrst & Last Digit
// #include<iostream>
// using namespace std;

// int main(){
//     int T ;
//     cout<<"Test Cases : "<<endl;
//     cin>>T;
//     while(T--){
//         int num, sum=0, firstDigit, lastDigit;
 
//      //Reading a number from user
//     cout<<"Enter any number:";
//     cin>>num;
 
//      lastDigit = num % 10;
 
//     firstDigit = num;
 
//     while(num >= 10)
//     {
//         num = num / 10;
//     }
//     firstDigit = num;
 
//      //Finding sum of first and last digit
//     sum = firstDigit + lastDigit;
 
//     cout<<"Sum of first and last digit: "<<sum;
//     }
    
//     return 0;
// }



// Greedy Puppy 
#include<iostream>
using namespace std;

int main(){
                                   
    int T , N , K;
    cout<<"Test Cases"<<endl;
    cin>>T;
    while(T--){
        cin>>N>>K;
        cout<<"Remainder  : "<<N%K<<endl;
    }
    
    return 0;
}


