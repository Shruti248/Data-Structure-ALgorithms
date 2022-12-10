// Queue Reversal
#include <bits/stdc++.h>
using namespace std;

class queueReversal
{
    // queue<int> q;
    stack<int> st;
    queue<int> q2;

public:
    queue<int> reverse(queue<int> q, int k)
    {
        stack<int> st;
        queue<int> temp;

        // Pushing first k elements in stack
        for(int i = 0; i<k ; i++){
            st.push(q.front());
            q.pop();
        }
        // Remaning elements push in queue
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        // Pushing back to queuw from stack(reverse order)
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        // Queue to origial queue in the same order
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        return q;
    }
};

int main()
{
    queueReversal qr;
    queue<int> q;
    int n, k;
    cout << "n : ";
    cin >> n;
    cout << "k : ";
    cin >> k;
    int arr[n];
    cout << "Enter Elements of queue : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        q.push(arr[i]);
    }

    queue<int> a = qr.reverse(q, k);

    while (!a.empty())
    {
        cout << a.front() << " ";
        a.pop();
    }
    return 0;
}