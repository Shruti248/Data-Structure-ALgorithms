#include <bits/stdc++.h>
using namespace std;

// IMPORTANT
// 1) Generally sorting is done first while applyin greedy
// 2) Sometimes we do not realise that we are applying greedy ecause it comes from inside

// Indian Coin Change Problem
int coinChange(vector<int> denominations, int amount)
{
    int n = denominations.size();

    sort(denominations.begin(), denominations.end(), greater<int>());

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += amount / denominations[i];
        amount -= amount / denominations[i] * denominations[i];
    }
    return ans;
}

// Activity Selection Problem
int activitySelectionProblem(vector<vector<int>> v /**Start & end Times*/)
{
    int n = v.size();

    // Sort Acc to finish Times
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    // Taking the first Activity
    int take = 1;
    int end = v[0][1];
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] >= end)
        {
            take++;
            end = v[i][1];
        }
    }

    return take;
}

// Fractional KnapSack
// Value per unit weight --> select max
// Time Complexity: O(N * logN)
// Auxiliary Space: O(N)
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    double v1 = (double)p1.first / p1.second;
    double v2 = (double)p2.first / p2.second;

    return v1 > v2;
}

int fractionalKnapsack(vector<pair<int, int>> a, int W)
{
    sort(a.begin(), a.end(), compare);

    int ans = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (W > a[i].second)
        {
            ans += a[i].first;
            W -= a[i].second;
            continue;
        }

        double vw = (double)a[i].first / a[i].second;

        ans += vw * W;
        W = 0;
        break;
    }
    return ans;
}

// Optimal Merge Pattern
// Time Complexity: O(nlogn)
// Auxiliary Space: O(n)
int optimalMergePattern(vector<int> arr)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

    int ans = 0;
    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        ans += (first + second);
        cout << "ans : " << ans << " ";
        pq.push(first + second);
    }

    return ans;
}

// EXPEDI (Expedition)
int countRefill(int N, vector<pair<int, int>> distAndFuels, int L /**truct currently holds l litres away from town*/, int P /**currrently P units of fuel*/)
{

    for (int i = 0; i < N; i++)
    {
        // initial diatnce from the truck
        distAndFuels[i].first = L - distAndFuels[i].first;
    }

    sort(distAndFuels.begin(), distAndFuels.end());

    int ans = 0;
    int curr = P; // currnet capacity of fuel

    priority_queue<int, vector<int>> pq;
    bool flag = 0;

    for (int i = 0; i < N; i++)
    {
        if (curr >= L)
        {
            break;
        }

        while (curr < distAndFuels[i].first)
        {
            if (pq.empty())
            {
                flag = 1;
                break;
            }

            ans++;
            curr += pq.top();
            pq.pop();
        }

        if (flag)
            break;
        pq.push(distAndFuels[i].second);
    }

    if (flag)
        return -1;

    while (!pq.empty() && curr < L)
    {
        curr += pq.top();
        pq.pop();
        ans++;
    }

    if (curr < L)
    {
        return -1;
    }

    return ans;
}

// MAximum & Min Array DIfference

vector<int> maxAndMinArrayDifference(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;

    sort(arr.begin(), arr.end());

    long long mx = 0, mn = 0;

    for (int i = 0; i < n / 2; i++)
    {
        mx += (arr[i + n / 2] - arr[i]);

        mn += arr[2 * i + 1] - arr[2 * i];
    }

    ans.push_back(mn);
    ans.push_back(mx);

    return ans;
}

// Minimum sum of two numbers formed from digits of an array
// Time Complexity: O(N * log N)
// Auxiliary Space: O(1)
int minSum(int a[] , int n){
    sort(a , a+n);

    int num1 = 0 , num2 = 0;

    for(int i = 0 ; i<n ; i++){
        if(i%2 == 0)
            num1  = num1*10 + a[i];
        else
            num2 = num2*10 + a[i];
    }
    cout<<"Num 1 : "<<num1<<" , Num 2 : "<<num2<<endl;
    return num1 + num2;
}

// Minimum sum of absolute difference of pairs of two arrays
// Time Complexity: O(n * logn)
// Auxiliary Space: O(1)
 int findMinSum(int a[] ,  int b[] , int n){
    sort(a , a+n);
    sort(b , b+n);

    int sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum += abs(a[i] - b[i]);
    }

    return sum;
}

int main()
{
    // vector<int> denomiations = {1 , 2 , 5 , 10 , 20 , 50 , 100 , 200 , 500 , 2000};
    // cout<<coinChange(denomiations , 350);

    // vector<vector<int>> times = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};

    // cout<<activitySelectionProblem(times);

    // vector<pair<int, int>> vw = {{21, 7}, {24, 4}, {12, 6}, {40, 5}, {30, 6}};
    // vector<pair<int, int>> vw = {{60, 10}, {100, 20}, {120, 30}};

    // cout<<fractionalKnapsack(vw , 20);
    // cout<<fractionalKnapsack(vw , 50);

    // vector<int> arr = {5, 4, 2, 7};
    // cout << optimalMergePattern(arr);

    // vector<pair<int , int>> a = {{4 , 4} , {5 , 2 }  , {11 , 5} , {15 , 10} };

    // cout<<countRefill(4 , a , 25 , 10);

    // vector<int> arr{12, -3, 10, 0};
    // vector<int> ans = maxAndMinArrayDifference(arr);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // int arr[]  = { 5 , 3 , 0 , 7 , 4};

    // cout<<minSum(arr , 5);

    int a[] = {4, 1, 8, 7};
    int b[] = {2, 3, 6, 5};
    cout<<findMinSum(a , b , 4);

    return 0;
}
