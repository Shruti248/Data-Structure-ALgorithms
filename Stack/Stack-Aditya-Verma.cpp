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

    for (int i = 0; i < arr.size(); i++)
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

    for (int i = 0; i < arr.size(); i++)
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

// Nearest Smaller to Right
vector<int> nearestSmallerToRight(vector<int> arr)
{
    stack<int> st;
    vector<int> ans;

    for (int i = arr.size() - 1; i >= 0; i--)
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

    reverse(ans.begin(), ans.end());
    return ans;
}

// Nearest greater to left : Equivalent Problem : consecutive smaller or equal before it --> Stock Span Problem

// arr : 100 80 60 70 60 75 85
// First : Find nearest Greater elemenet to the left  for each element
// 100 80 80 80 70 80 100

// Now suppose you want to find consecutive smaller or equal before it
// For index : i = 5 (75) --> Nearest greater element ( i = 1) --> 5-1 : 4 --> ANSWER

// Required ans : Substract the indices of the current element with the nearest greater element

// We used to store the element in vector : Now we store the indices
// Indices of nearest greater to left : -1 0 1 1 3 0
// Output : i - indexFound : Eg (0- -1 : 1) (1 - 0 : 1)...So on

// Required : Index and element in stack
// Use : stack<pair<int , int> st;

vector<int> stockSpan(vector<int> arr)
{
    stack<pair<int, int>> st;
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else if (st.size() > 0 && st.top().first > arr[i])
        {
            ans.push_back(st.top().second); // in the vector store indexes only
        }
        else if (st.size() > 0 && st.top().first <= arr[i])
        {
            while (st.size() > 0 && st.top().first <= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }

        st.push({arr[i], i});
    }

    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] = i - ans[i];
        // cout<<i-ans[i]<<" ";
    }

    return ans;
}

// Maximum area of the historgram

// max area : nearest smaller element to the left and right combined...

// find index of : Nearest smaller element to left & nearest smallest element to right

// MAX AREA : (rightIndex - LeftIndex - 1 ) * height

// Right array : NSR indices
// left array : NSL indices
// Width array : rightarray[i] - leftArray[i] - 1
// Area Array : arr[i] * width[i]

// retrun max in area array

// Nearest Smaller to left
vector<int> nearestSmallerToLeftIndices(vector<int> arr)
{
    stack<pair<int, int>> st;
    vector<int> ans;
    int psuedoIndex = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
        {
            ans.push_back(psuedoIndex);
        }
        else if (st.size() > 0 && st.top().first < arr[i])
        {
            ans.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(psuedoIndex);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }

        st.push({arr[i], i});
    }

    return ans;
}

// Nearest Smaller to right
vector<int> nearestSmallerToRightIndices(vector<int> arr)
{
    stack<pair<int, int>> st;
    vector<int> ans;
    int psuedoIndex = arr.size();

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans.push_back(psuedoIndex);
        }
        else if (st.size() > 0 && st.top().first < arr[i])
        {
            ans.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(psuedoIndex);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }

        st.push({arr[i], i});
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int maxAreaHistogram(vector<int> arr)
{
    vector<int> left = nearestSmallerToLeftIndices(arr);
    vector<int> right = nearestSmallerToRightIndices(arr);
    vector<int> width;
    vector<int> area;
    int maxArea = INT_MIN;

    width.resize(arr.size());
    area.resize(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        width[i] = right[i] - left[i] - 1;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        area[i] = arr[i] * width[i];
        maxArea = max(area[i], maxArea);
    }

    return maxArea;
}

// MAx Area of the rectangle in Binary Matrix

// max area with rectangle formed from 1's

// MAH : 1D array
// Here : 2D

// convert 2D to 1D and then do max area histogram

// 4x4 matrix : broken down into 4 H1 , H2 , H3 , H4

// MAx aof all is the ans

// ans = max(MAH(H1) , MAH(H2) , MAH(H3) , MAH(H4))

int maxAreaOfRectangleInBinaryMatrix(int **arr, int n, int m)
{
    vector<int> v;

    // n : rows
    // m : cols
    for (int j = 0; j < m; j++)
    {
        v.push_back(arr[0][j]);
    }

    int mx = maxAreaHistogram(v);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                v[j] = 0;
            }
            else
            {
                v[j] = v[j] + arr[i][j];
            }
        }
        mx = max(mx, maxAreaHistogram(v));
    }

    return mx;
}

// No concept of NGR NGL
// Rain Water Trapping
// arr : 300204

// if we are at arr[] = 0 , then we get the max of left array and max of right array
// actual height of water : min(max(left , right))

// Levl of water in each building
//  height of water i height of building --> Add all

// Algo
// First find max of left and max of right
// left array : campare all element and find max
// Eg : 3 0 0 2 0 4 --> 3 3 3 3 3 4(start from first)

// Right array : 300204(start from last) --> 444444

// Therefore :
// water[i] = min(max L[i] , max R[i]) - arr[i];
// All all water

int rainWaterTrapping(vector<int> arr)
{
    vector<int> mxL;
    vector<int> mxR;

    mxL.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        mxL.push_back(max(mxL[i - 1], arr[i]));
    }

    mxR.push_back(arr[arr.size() - 1]);

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        mxR.push_back(max(mxR[i + 1], arr[i]));
    }

    reverse(mxR.begin(), mxR.end());

    vector<int> water;
    int totalWater = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        water.push_back(min(mxL[i], mxR[i]) - arr[i]);
        totalWater += water[i];
    }

    return totalWater;
}

// IMP
// Implement Minimum stack with extra space

// We will implement push and pop operations

// 2 stacks used : one for pushing and poping elements
// other supporting stack for storing the min element

// if new min element in the stack then only push it in supporting stack

// if element is popped then check it in supporting stack , if present there pop that too

// both stacks will e empty at space time

stack<int> st;
stack<int> supportingst;

void push(int a)
{
    st.push(a);

    if(supportingst.size() == 0 || a <= supportingst.top()){
        supportingst.push(a);
    }

    return;
}

int pop(){

    if(st.size() == 0){
        return -1;
    }
    st.pop();

    int ans = st.top();
    if(ans == supportingst.top()){
        supportingst.pop();
    }

    return ans;
}

int minElement()
{
    if(supportingst.size() == 0){
        return -1;
    }

    return supportingst.top();
}


// Implement Minimum stack with O(1) space

// O(1) : Only variables

int minEle;

void pushOptimized(int x){
    if(st.size() == 0){
        st.push(x);
        minEle = x;
    }else{
        if(x >= minEle){
            st.push(x);
        }else if(x < minEle){
            st.push(2*x - minEle);
            minEle = x;
        }
    }
}

void popOptimized(){
    if(st.size() == 0){
        return;
    }else {
        if(st.top() >= minEle){
            st.pop();
        }else if(st.top() < minEle){
            minEle = 2*minEle - st.top();
            st.pop();
        }
    }
}

int topOptimized(){
    if(st.size() == 0){
        return -1;
    }
    else{
        if(st.top() >= minEle){
            return st.top();
        }else if(st.top() < minEle){
            return minEle;
        }
    }
}

int getminEle(){
    if(st.size() == 0){
        return -1;
    }

    return minEle;
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    // vector<int> ans = nextLargestElement(arr);
    // vector<int> ans = nearestGreaterToLeft(arr);
    // vector<int> ans = nearestSmallerToLeft(arr);
    // vector<int> ans = nearestSmallerToRight(arr);

    vector<int> ans = stockSpan(arr);
    // cout << maxAreaHistogram(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    // int arr[4][4] = {
    //     { 0, 1, 1, 0 },
    //     { 1, 1, 1, 1 },
    //     { 1, 1, 1, 1 },
    //     { 1, 1, 0, 0 },
    // };

    // int** ptr = new int*[4];
    // for (int i = 0; i < 4; i++) {
    //     ptr[i] = arr[i];
    // }

    // cout << maxAreaOfRectangleInBinaryMatrix(ptr , 4, 4);

    // delete[] ptr;

    // vector<int> arr = {4, 2, 0, 3, 2, 5};

    // cout << rainWaterTrapping(arr);
    return 0;
}
