// O(n2) brute force --> add some DS to make it optimize

// Identification
// Array is GIVEN

// If array --> DS : Stack or Heap (Heap for Sorting)

// brute firce : O(n2) --> i = 0 to n & j = 0 to n

// inner for loop is dependent --> i = 0 to n & (j = 0 to i j++) (j = i to 0 j--) (j = i to n j++) (j = n to i j--) ---> STACK USED in this type of questions

// Therefire ---> if j loop is dependent on i --> USE STACK for otpimized

#include <bits/stdc++.h>
using namespace std;

// Nearest greater to right OR Next largest Element

// Brute force : i = 0 to n-1 & j = i+1 to n

// Start from last

// if the right part of array is empty : STack empty
// Else right part will be store din the arry

// 1 3 2 4
// arr[i] = 4 So right opart empty : stack empty : -1
// arr[i] = 2 push 4 in stack --> top of the stack greater than arr[i] it is the answer , else pop  --> 4
// arr[i] = 3 , stack contains 2 4 ,  2 less then 3 : POP , ans : 4
// arr[i] = 1 , stack 3 4 , Ans : 3

// Ans is also reverse --> so reverse the final ans

// Algo :
// Stack empty --> -1
// s.top() > arr[i] --> s.top()
// s.top() <= arr[i] --POP ---> till stack is empty
// --> or till s.top() is greater than arr[i]

// Time Complexity: O(N)
// Auxiliary Space: O(N)

vector<int> nextLargestElement(vector<int> arr)
{
    stack<int> st;
    vector<int> ans;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else if (st.size() > 0 && st.top() > arr[i])
        {
            ans.push_back(st.top());
        }
        else if (st.size() > 0 && st.top() <= arr[i])
        {
            while (st.size() > 0 && st.top() <= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
        }

        st.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// Nearest greater to left
// Traverse : Levft to right
// No need to reverse the ans....

// Time Complexity: O(N)
// Auxiliary Space: O(N)
vector<int> nearestGreaterToLeft(vector<int> arr)
{
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < arr.size() ; i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else if (st.size() > 0 && st.top() > arr[i])
        {
            ans.push_back(st.top());
        }
        else if (st.size() > 0 && st.top() <= arr[i])
        {
            while (st.size() > 0 && st.top() <= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
        }

        st.push(arr[i]);
    }

    return ans;
}

// Nearest Smaller to left
vector<int> nearestSmallerToLeft(vector<int> arr)
{
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < arr.size() ; i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else if (st.size() > 0 && st.top() < arr[i])
        {
            ans.push_back(st.top());
        }
        else if (st.size() > 0 && st.top() >= arr[i])
        {
            while (st.size() > 0 && st.top() >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
        }

        st.push(arr[i]);
    }

    return ans;
}


int main()
{
    vector<int> arr = {4 , 5 , 2 , 10 , 8};
    // vector<int> ans = nextLargestElement(arr);
    // vector<int> ans = nearestGreaterToLeft(arr);
    vector<int> ans = nearestSmallerToLeft(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
