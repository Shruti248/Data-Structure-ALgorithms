#include <bits/stdc++.h>
using namespace std;

// Sqaure Pattern
void square(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }
}

void rightAngledTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        // for(int j = 0 ; j<n ; j++){
        //     if(i >= j){
        //         cout<<" * ";
        //     }else{
        //         cout<<"   ";
        //     }
        // }

        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void rightAngledNumberedPyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

void rightAngledNumberedPyramidII(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
void invertedRightPyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void invertedNumberedRightPyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << n - j + 1;
        }
        cout << endl;
    }
}

void starPyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {

        // Spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

void invertedstarPyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {

        // Spaces
        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= 2 * n - (2 * i - 1); j++)
        {
            cout << "*";
        }

        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

void diamondStarPattern(int n)
{

    starPyramid(n);
    invertedstarPyramid(n);
}

void halfDiamondStarPattern(int n)
{
    rightAngledTriangle(n - 1);
    invertedRightPyramid(n);
}

void binaryNumberTrianglePattern(int n)
{

    int flag;
    for (int i = 1; i <= n; i++)
    {

        i%2 == 0 ? flag = 0 : flag = 1;
        for (int j = 1; j <= i; j++)
        {
            cout<<flag;
            flag == 1 ? flag = 0 : flag = 1;
        }
        cout<<endl;
    }
}

void increaisngNumberedRightTraingle(int n){
    int num = 1;

    for(int i = 1 ; i<= n ; i++){
        for(int j = 1 ; j<=i ; j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

void numberCrownPattern(int n){
    // Number -- Spaces -- Number
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=i ; j++){
            cout<<j;
        }

        for(int j = 1 ; j<=2*(n-i) ; j++){
            cout<<" ";
        }

        for(int j = i ; j>=1 ; j--){
            cout<<j;
        }

        cout<<endl;
    }
}

void increasingLetterTrianglePattern(int n){
    for(int i = 0 ; i<n ; i++){
        for(char ch = 'A' ; ch<='A'+i ; ch++){
            cout<<ch;
        }
        cout<<endl;
    }
}

int main()
{
    // square(3);
    // rightAngledTriangle(6);
    // rightAngledNumberedPyramid(5);
    // rightAngledNumberedPyramidII(7);
    // invertedRightPyramid(5);
    // invertedNumberedRightPyramid(6);
    // starPyramid(5);
    // invertedstarPyramid(5);
    // diamondStarPattern(3);
    // halfDiamondStarPattern(5);
    // binaryNumberTrianglePattern(3);
    // increaisngNumberedRightTraingle(4);
    // numberCrownPattern(5);
    increasingLetterTrianglePattern(5);
    return 0;
}
