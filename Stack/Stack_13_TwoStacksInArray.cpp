#include <bits/stdc++.h>
using namespace std;
#define n 20

// this app
class twoStacks
{
    int arr[n];
    int top1;
    int top2;

public:
    // This approach: Wastage of the space occurs bcoz if one stack is full and othe r stack still has space still stack 1 element cannot e pushed and overflow condition coccurs
    twoStacks()
    {
        top1 = -1;
        top2 = n;
    }

    // void push1(int x)
    // {
    //     if (top1 == n / 2 - 1)
    //     {
    //         cout << "Stack1 Overflow" << endl;
    //     }
    //     top1++;
    //     arr[top1] = x;
    // }
    // int pop1()
    // {
    //     if (top1 == -1)
    //     {
    //         // cout << "Stack is Empty" << endl;
    //         return -1;
    //     }
    //     // cout << "Popped element : " << arr[top1] << endl;
    //     int val = arr[top1];
    //     top1--;
    //     return val;
    // }
    // void push2(int x)
    // {
    //     if (top2 == n / 2)
    //     {
    //         cout << "Stack2 Overflow" << endl;
    //     }
    //     top2--;
    //     arr[top2] = x;
    // }
    // int pop2()
    // {
    //     if (top2 == n)
    //     {
    //         // cout << "Stack is Empty" << endl;
    //         return -1;
    //     }
    //     // cout << "Popped element : " << arr[top2] << endl;
    //     int val;
    //     val = arr[top2];
    //     top2++;
    //     return val;
    // }

    // To prevent the wastage of teh resources , we do not divide teh array into 2 halfs , rather we check the pointers if the space si available;

    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack 1 Overflow ";
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int val = arr[top1];
            top1--;
            return val;
        }
        else
        {
            cout << "Stack 1 Underflow";
            return -1;
        }
    }

    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }else{
            cout<<"Stack 2 Overflow";
        }
    }
    int pop2()
    {
        if(top2 < n){
            int val = arr[top2];
            top2++;
            return val;
        }else{
            cout<<"Stack 2 Undeflow";
            return -1;
        }
    }
};

int main()
{
    twoStacks st;
    // st.push1(1);
    // st.push1(2);
    // st.push1(3);
    // cout<<st.pop1()<<" ";

    // st.push2(11);
    // st.push2(12);
    // st.push2(13);
    // cout<<st.pop2()<<" ";

    st.push1(2);
    st.push1(3);
    st.push2(4);
    cout << st.pop1() << " ";
    cout << st.pop2() << " ";
    cout << st.pop2() << " ";

    return 0;
}
