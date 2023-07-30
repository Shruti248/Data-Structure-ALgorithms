#include<bits/stdc++.h>
using namespace std;

// Count Number of Digits

// O(n)
// O(1)
int countDigitsI(int n){
    int count = 0;

    while(n > 0){
        n = n/10;
        count++;
    }

    return count;
}

// O(1)
// O(1)
int countDigitsII(int n){
    string num = to_string(n);
    return num.length();
}

// The number of digits in an integer = the upper bound of log10(n).
// O(1)
// O(1)
int countDigitsIII(int n){
    return floor(log10(n) + 1);
}

// Reverse the Number
// O(n)
// O(1)
int reverseNumber(int n){
    int reversedNum = 0;
    while(n > 0){
        reversedNum = reversedNum*10 + n%10;
        n = n/10;
    }

    return reversedNum;
}

// Check if a number is Palindrome or Not
// O(logn) -- for reversing
// O(1)
bool isPalindrome(int n){
    return n == reverseNumber(n);
}

int main(){
    // cout<<countDigitsI(158);
    // cout<<countDigitsII(123);
    // cout<<countDigitsIII(124);
    // cout<<reverseNumber(123456789);
    cout<<isPalindrome(12132);
    return 0;
}
