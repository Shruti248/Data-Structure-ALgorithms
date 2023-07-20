// Recursion

// Make Input Smaller : But Why ?
// Input becomes automatically smaller on taking some decisions

// Recursion : Decision Space
// IDentification : Whether problem statemenet is recursive or not
// 1) CHOICES + DECISION
// Recursion Tree - SOul of Recursion
// IMP : If done this tree , problem Solved

// 2 steps to solve any recursive problem
// 1) Design a recursive tree
// 2) Write Code

// ------------- Recursion is Everywhere ----------
// array , string
// tree
// Graph
// Heap , stack --> less

// Algo
// DP , backtracking , Divide and conquer

// 4 Methods to solve recursive Problems
//  1) Recursive Tree  : I/p /  O/p Method --> When we understand decsion
//  2) BC - Induction - Hypothesis -> Make the input Smaller
//  3) Choice Diagram (DP)
//  4) Left

// BASE COndition -- Hypothesis -- Induction
// eg : Print 1 to N

#include <bits/stdc++.h>
using namespace std;

void print(int n)
{

    if (n < 1)
    {
        return;
    }

    print(n - 1);

    cout << n << " ";
}

void printReverse(int n)
{

    if (n < 1)
    {
        return;
    }


    cout << n << " ";
    print(n - 1);

}

int main()
{
    print(5);
    cout<<endl;
    printReverse(5);
    return 0;
}
