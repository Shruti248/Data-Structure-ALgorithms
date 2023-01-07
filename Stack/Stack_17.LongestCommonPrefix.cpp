// Left
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    stack<string> st;
    string prefix = "";
    // int min = 1000000;

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // find the minimum length string in the array
        int len = numeric_limits<int>::max();
        for (int i = 0; i < strs.size(); i++)
            len = min(len, (int)strs[i].length());
        for (int i = 0; i < len; i++)
        {
            // compare the ith character of all the strings
            char current = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                // if any of the characters are not the same, return the LCP
                if (strs[j][i] != current)
                    return prefix;
            }

            // if all the characters are the same, add it to the LCP
            prefix += current;
        }
        return prefix;
    }
};

int main()
{
    Solution s;
    int n;
    vector<string> arr;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr.push_back(arr[i]);
    }

    cout << s.longestCommonPrefix(arr);
    // s.longestCommonPrefix(arr);

    return 0;
}