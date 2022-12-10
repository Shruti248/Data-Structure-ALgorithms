// 2 methods

// 1) Making push operation costly

// 2) Making pop operation costly

// Approach 1 :Refer geeks
// #include <bits/stdc++.h>
// using namespace std;

// class StackUsingQueue
// {
//     int N;
//     queue<int> q1;
//     queue<int> q2;

// public:
//     StackUsingQueue()
//     {
//         N = 0;
//     }

//     void push(int x)
//     {
//         q2.push(x);
//         N++;  //increasing the size of queue bcoz of push
//         while (!q1.empty())
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         // Swap using temp queue
//         queue<int> temp = q1;
//         q1 = q2;
//         q2=temp;

//     }

//     void pop(){
//         q1.pop();
//         N--;
//     }

//     int top(){
//         if(q1.empty()){
//             return -1;
//         }
//         return q1.front();
//     }

//     int size(){
//         return N;
//     }
// };

// int main()
// {
//     StackUsingQueue st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);

//     cout<<st.top()<<endl;
//     st.pop();
//     cout<<st.top()<<endl;
//     st.pop();
//     // cout<<st.top()<<endl;
//     // st.pop();
//     // cout<<st.top()<<endl;
//     // st.pop();
//     // cout<<st.top()<<endl;

//     cout<<"Size : "<<st.size()<<endl;

//     return 0;
// }

// Approach 2
#include <bits/stdc++.h>
using namespace std;

class StackUsingQueue
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    StackUsingQueue()
    {
        N = 0;
    }

    void push(int x)
    {
        q1.push(x);
        N++;
    }

    void pop()
    {
        if (q1.empty())
        {
            return;
        }

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        N--;

        // Swap uisng temp queue
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front();
        q2.push(ans);
        

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;

    }

    int size()
    {
        return N;
    }
};

int main()
{
    StackUsingQueue st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    // cout << st.size() << endl;
    return 0;
}