// Queue Reversal
#include <bits/stdc++.h>
using namespace std;

class queueReversal
{
        // queue<int> q;
        stack<int> st;

public:
        queue<int> reverse(queue<int> q)
        {
                if (q.empty())
                {
                        cout << "Queue is empty";
                }
                while (!q.empty())
                {
                        st.push(q.front());
                        q.pop();
                }
                while (!st.empty())
                {
                        q.push(st.top());
                        st.pop();
                }
                // while(!q.empty()){
                //         cout<<q.front()<<" ";
                //         q.pop();
                // }
                
                
        }
};

int main()
{
        queueReversal qr;
        queue<int> q;
        int n;
        cout << "n : ";
        cin >> n;
        int arr[n];
        cout << "Enter Elements of queue : " << endl;
        for (int i = 0; i < n; i++)
        {
                cin >> arr[i];
                q.push(arr[i]);
        }
        queue<int> a = qr.reverse(q);
        while (!a.empty())
        {
                cout << a.front() << " ";
                a.pop();
        }
        return 0;
}