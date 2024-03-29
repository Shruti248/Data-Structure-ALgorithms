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
int minSum(int a[], int n)
{
    sort(a, a + n);

    int num1 = 0, num2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            num1 = num1 * 10 + a[i];
        else
            num2 = num2 * 10 + a[i];
    }
    cout << "Num 1 : " << num1 << " , Num 2 : " << num2 << endl;
    return num1 + num2;
}

// Minimum sum of absolute difference of pairs of two arrays
// Time Complexity: O(n * logn)
// Auxiliary Space: O(1)
int findMinSum(int a[], int b[], int n)
{
    sort(a, a + n);
    sort(b, b + n);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += abs(a[i] - b[i]);
    }

    return sum;
}

// Find maximum height pyramid from the given array of objects
int maxLevel(int a[], int n)
{
    sort(a, a + n);

    int ans = 1;

    int prevWidth = a[0];
    int prevCount = 1;

    int currCount = 0;
    int currWidth = 0;

    for (int i = 1; i < n; i++)
    {
        currWidth += a[i];
        currCount += 1;

        if (currWidth > prevWidth && currCount > prevCount)
        {
            prevWidth = currWidth;
            prevCount = currCount;

            currCount = 0;
            currWidth = 0;

            ans++;
        }
    }

    return ans;
}

// Find Maximum Equal sum of Three Stacks
// Time Complexity : O(n1 + n2 + n3) where n1, n2 and n3 are sizes of three stacks.

// Auxiliary space: O(1) because using constant space for variables

int maxSum(int stack1[], int stack2[], int stack3[], int n1,
           int n2, int n3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0; i < n1; i++)
        sum1 += stack1[i];

    for (int i = 0; i < n2; i++)
        sum2 += stack2[i];

    for (int i = 0; i < n3; i++)
        sum3 += stack3[i];

    int top1 = 0, top2 = 0, top3 = 0;
    while (1)
    {
        if (top1 == n1 || top2 == n2 || top3 == n3)
            return 0;

        if (sum1 == sum2 && sum2 == sum3)
            return sum1;

        if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= stack1[top1++];
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= stack2[top2++];
        else if (sum3 >= sum2 && sum3 >= sum1)
            sum3 -= stack3[top3++];
    }
}

// Job Sequencing Problem
// Time Complexity: O(N log N)
// Auxiliary Space: O(N)
struct Job
{
    char id;
    int deadline;
    int profit;
};

struct jobProfit {
    bool operator()(Job const& a, Job const& b)
    {
        return (a.profit < b.profit);
    }
};

void printJobScheduling(Job arr[] , int n){
    vector<Job> result;

    sort(arr , arr+n , [](Job a , Job b) {
        return a.deadline < b.deadline;
    });

    priority_queue<Job , vector<Job> , jobProfit>  pq;

    for(int i = n-1 ; i>=0 ; i--){
        int slot_available;

        if(i == 0){
            slot_available = arr[i].deadline;
        }else {
            slot_available = arr[i].deadline - arr[i-1].deadline;
        }

        pq.push(arr[i]);

        while(slot_available > 0 && pq.size() > 0){
            Job job = pq.top();
            pq.pop();

            slot_available--;

            result.push_back(job);
        }
    }

    sort(result.begin() , result.end() , [&](Job a , Job b){return a.deadline < b.deadline;});

    for(int i = 0 ; i<result.size() ; i++){
        cout<<result[i].id<<" ";
    }
    cout<<endl;
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

    // int a[] = {4, 1, 8, 7};
    // int b[] = {2, 3, 6, 5};
    // cout<<findMinSum(a , b , 4);

    // int a[] = {10, 20, 30, 50, 60, 70};

    // cout<<maxLevel(a , 6);

    // int stack1[] = {3, 2, 1, 1, 1};
    // int stack2[] = {4, 3, 2};
    // int stack3[] = {1, 1, 4, 1};

    // int n1 = sizeof(stack1) / sizeof(stack1[0]);
    // int n2 = sizeof(stack2) / sizeof(stack2[0]);
    // int n3 = sizeof(stack3) / sizeof(stack3[0]);

    // cout << maxSum(stack1, stack2, stack3, n1, n2, n3);


    Job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";

    printJobScheduling(arr, n);

    return 0;
}
