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

        i % 2 == 0 ? flag = 0 : flag = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << flag;
            flag == 1 ? flag = 0 : flag = 1;
        }
        cout << endl;
    }
}

void increaisngNumberedRightTraingle(int n)
{
    int num = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

void numberCrownPattern(int n)
{
    // Number -- Spaces -- Number
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }

        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }

        cout << endl;
    }
}

void increasingLetterTrianglePattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
void reverseIncreasingLetterTrianglePattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
}

void alphaRampPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;

        for (int j = 0; j <= i; j++)
        {
            cout << ch;
        }
        cout << endl;
    }
}

void alphaHill(int n)
{
    for (int i = 0; i < n; i++)
    {

        // Spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;

            j <= breakpoint ? ch++ : ch--;
        }

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

void alphatriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = ('A' + n - 1) - i; ch <= ('A' + n - 1); ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
}

void invertedleftAngledpyramid(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void leftAngledpyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void symmetricVoid(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int star1 = 1; star1 <= n - i + 1; star1++)
        {
            cout << "*";
        }

        for (int space = 1; space <= 2 * (i - 1); space++)
        {
            cout << " ";
        }

        for (int star2 = 1; star2 <= n - i + 1; star2++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = n + 1; i <= 2 * n; i++)
    {
        for (int star1 = 1; star1 <= i - n; star1++)
        {
            cout << "*";
        }

        for (int space = 1; space <= 4 * n - 2 * i; space++)
        {
            cout << " ";
        }

        for (int star2 = 1; star2 <= i - n; star2++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void symmetricButterflyPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int star1 = 1; star1 <= i; star1++)
        {
            cout << "*";
        }
        for (int space = 1; space <= 2 * (n - i); space++)
        {
            cout << " ";
        }
        for (int star2 = 1; star2 <= i; star2++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = n + 1; i <= 2 * n - 1; i++)
    {
        for (int star1 = 1; star1 <= (2 * n - i); star1++)
        {
            cout << "*";
        }
        for (int space = 1; space <= 2 * (i - n); space++)
        {
            cout << " ";
        }
        for (int star2 = 1; star2 <= (2 * n - i); star2++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void hollowRectangle(int n)
{
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || j == 1 || i == n || j == n)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void numberedRectangle(int n)
{
    // Outer loop for no. of rows
    for (int i = 0; i < 2 * n - 1; i++)
    {

        // inner loop for no. of columns.
        for (int j = 0; j < 2 * n - 1; j++)
        {

            // Initialising the top, down, left and right indices of a cell.
            int top = i;
            int bottom = j;
            int right = (2 * n - 2) - j;
            int left = (2 * n - 2) - i;

            // Min of 4 directions and then we subtract from n
            // because previously we would get a pattern whose border
            // has 0's, but we want with border N's and then decreasing inside.
            cout << (n - min(min(top, bottom), min(left, right))) << " ";
        }

        // As soon as the numbers for each iteration are printed, we move to the
        // next row and give a line break otherwise all numbers
        // would get printed in 1 line.
        cout << endl;
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
    // increasingLetterTrianglePattern(5);
    // reverseIncreasingLetterTrianglePattern(5);
    // alphaRampPattern(5);
    // alphaHill(5);
    // alphatriangle(5);
    // leftAngledpyramid(5);
    // invertedleftAngledpyramid(5);
    // symmetricVoid(5);
    // symmetricButterflyPattern(3);
    // hollowRectangle(10);
    numberedRectangle(3);
    return 0;
}
