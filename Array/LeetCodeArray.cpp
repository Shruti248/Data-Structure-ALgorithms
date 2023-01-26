#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rotateArraytoRightByKTimes(int arr[], int n, int k)
    {
        k %= n;

        vector<int> ans;
        for (int i = n - k; i < n; i++)
        {
            ans.push_back(arr[i]);
        }
        for (int i = 0; i < n - k; i++)
        {
            ans.push_back(arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = ans[i];
        }

        for(int i = 0 ; i<n ; i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    Solution s;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;
    s.rotateArraytoRightByKTimes(arr, n, k);
    return 0;
}