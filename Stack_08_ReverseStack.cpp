// 2 approaches : take 2 stack : pop from one &push into another
// --> 2nd : using only one stack :Recursion

// 1st Approach
// #include <bits/stdc++.h>
// using namespace std;
// stack<int> st;
// stack<int> st2;
// #define n 100
// void reverseStack()
// {

//     cout << "Original stack is : ";
//     while (!st.empty())
//     {
//         cout << st.top() << " ";
//         st2.push(st.top());
//         st.pop();
//     }
//     cout << "Reveresed Stack is : ";
//     while (!st2.empty())
//     {
//         cout << st2.top() << " ";
//         st2.pop();
//     }
// }

// int main()
// {

//     // Stack is 1 2 3 4 5
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     st.push(5);

//     reverseStack();

//     return 0;
// }

// 2nd Approach : Recursion (Not understood)
#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int ele)
{

    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();
    insertAtBottom(st, ele);

    st.push(topele);
}

// &st :call by reference :Changes are made in teh same stack at same address
void reverse(stack<int> &st)
{

    if (st.empty())
    {
        return;
    }

    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, ele);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    reverse(st);
    cout << "Reversed string is : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}