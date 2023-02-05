// Combinational Sum
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void isSafe(vector<int> &candidates, int target, vector<int> &combination, int start, vector<vector<int>> &result)
    {
        // Base
        if (target == 0)
        {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size() && target >= candidates[i]; i++)
        {
            // Remove Duplicates
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            combination.push_back(candidates[i]);
            isSafe(candidates, target - candidates[i], combination, i, result);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;

        vector<int> combination;

        isSafe(candidates, target, combination, 0, result);
        return result;
    }
};
int main()
{
    Solution s;
    int n;
    cin >> n;

    vector<int> candidates;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        candidates.push_back(val);
    }

    int target;
    cout << "Target : ";
    cin >> target;

    vector<vector<int>> result = s.combinationSum(candidates, target);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}