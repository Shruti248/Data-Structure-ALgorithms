#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotateArraytoRightByKTimes(int arr[], int n, int k)
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

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    // There are duplicates in the solution , also the time limit exceeded
    // void threeSum(int arr[], int n)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i; j < n; j++)
    //         {
    //             for (int k = j; k < n; k++)
    //             {
    //                 if (arr[i] + arr[j] + arr[k] == 0 && i != j && j != k && k != i)
    //                 {
    //                     cout << "pairs : " << arr[i] << " " << arr[j] << " " << arr[k] << " " << endl;
    //                 }
    //             }
    //         }
    //     }
    // }

    void plusOne(int arr[], int n)
    {
        string s;
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            // convert int to string
            s = to_string(arr[i]);
            ans += s;
            // cout << ans << endl;
        }

        // Convert the concatenated string
        // to integer
        int intAns = stoi(ans);

        int number = intAns+1;
        cout<<"Number is : "<<number<<endl;
        vector<int> resultantArray;
        int remainder;

        while(number!=0){

            // Extract last digit 
            remainder = number%10;
            
            resultantArray.push_back(remainder);

            // To extract next last digit
            number = number/10;

        }

        for(int i = n-1 ; i>=0 ; i-- ){
            cout<<resultantArray[i];
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

    // int k;
    // cin >> k;
    // s.rotateArraytoRightByKTimes(arr, n, k);

    // s.threeSum(arr, n);
    s.plusOne(arr, n);

    return 0;
}