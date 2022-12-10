// Approach 1
// Using 2 stacks and dequeue operation is costly

//    Enqueue() : O(1)
// --> push in stack

// dequeue operation : O(n) (Worst case)
// --> if both stacks are empty return error message
// --> if stack 1 has some elements ad stack 2 is empty , pop elements from stack 1 and push in stack 2 , then popfrom stack 2(will follow the FIFO principle)

#include <bits/stdc++.h>
using namespace std;

class queueUsingStack
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }

    int dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            // cout << "Queue is empty" << endl;
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }

    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }
};
int main()
{
    queueUsingStack q1;
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // q.enqueue(4);
    // q.enqueue(5);

    // cout<<q.dequeue()<<endl;
    // cout<<q.dequeue()<<endl;
    // cout<<q.dequeue()<<endl;
    // cout<<q.dequeue()<<endl;
    // cout<<q.dequeue()<<endl;
    // cout<<q.dequeue()<<endl;

    int q; // Number of queriers
    int num;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        cin >> num;
        int enqueue_element;
        if (num == 1)
        {
            // enqueue
            cin >> enqueue_element;
            q1.enqueue(enqueue_element);
        }
        else if (num == 2)
        {
            // dequeue
            q1.dequeue();
        }
        else if (num == 3)
        {
            // print the front element
            cout<<q1.dequeue()<<endl;
        }
    }

    return 0;
}

// Approach 2
// Using Function Call STack : 1 stack and using recusion

// Enqueue : push x into stack

// Dequeue :
// --> if stack 1 is empty : return error
// --> sytack 1 has 1 eelement : return it
// --> recursively popeverything from stcak 1,store the popped item in variable res, push the res back in stack1 and return res;

// #include <bits/stdc++.h>
// using namespace std;

// class queueUsingStack
// {
//     stack<int> s1;

// public:
//     void enqueue(int x)
//     {
//         s1.push(x);
//     }

//     int dequeue()
//     {
//         if (s1.empty())
//         {
//             // cout << "Queue is empty" << endl;
//             return -1;
//         }

//         int x = s1.top();
//         s1.pop();
//         if(s1.empty()){
//             return x;
//         }
//         int item = dequeue();
//         s1.push(x);
//         return item;

//     }

//     bool empty(){
//         if(s1.empty()){
//             return true;
//         }
//         return false;
//     }
// };
// int main()
// {
//     queueUsingStack q;
//     // q.enqueue(1);
//     // q.enqueue(2);
//     // q.enqueue(3);
//     // q.enqueue(4);
//     // q.enqueue(5);

//     // cout<<q.dequeue()<<endl;
//     // cout<<q.dequeue()<<endl;
//     // cout<<q.dequeue()<<endl;
//     // cout<<q.dequeue()<<endl;
//     // cout<<q.dequeue()<<endl;
//     // cout<<q.dequeue()<<endl;

//     return 0;
// }