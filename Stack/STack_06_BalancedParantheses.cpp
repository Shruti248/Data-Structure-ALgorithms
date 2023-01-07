#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    // ANs which decides if the string is valid or invalid;
    bool ans = true;
    

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (!st.empty() && s[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (!st.empty() && s[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (!st.empty() && s[i] == ']')
        {
            if (st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }else{
            ans=false;
        }
    }

    if (!st.empty())
    {
        return false;
    }
    else
    {
        if(s[0] =='}' || s[0] ==']' || s[0] ==')'){
            return false;
        }else{
            return ans;
        }
        
    }
}

int main()
{
    
    // cout<<"Enter String : ";
    // cin>>s;

    // Number of inputs
    long int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        // cout << s[i];
        if (isValid(s[i]))
        {
            // cout << "Valid String" << endl;
            cout << "YES" << endl;

        }
        else
        {
            // cout << "Invalid String" << endl;
            cout << "NO" << endl;
        }
    }

    return 0;
}