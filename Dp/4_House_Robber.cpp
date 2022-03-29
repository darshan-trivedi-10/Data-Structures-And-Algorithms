// https://leetcode.com/problems/house-robber/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

// Time Complexity : O(N), Space Complexity : O(N) + O(N)
// Memorization
class Solution
{
    int findMax(vector<int> &arr, vector<int> &dp, int idx)
    {
        if (idx < 0)
        {
            return 0;
        }
        if (idx == 0)
        {
            return arr[0];
        }

        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        int pick = arr[idx] + findMax(arr, dp, idx - 2);
        int nonPick = 0 + findMax(arr, dp, idx - 1);
        return dp[idx] = max(pick, nonPick);
    }

public:
    int rob(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return findMax(arr, dp, n - 1);
    }
};

// Tabulation
class Solution
{
public:
    int rob(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = arr[0];
        if (n > 1)
        {
            dp[1] = arr[1];
        }
        for (int i = 1; i < n; i++)
        {
            int pick = arr[i] + (i > 1 ? dp[i - 2] : 0);
            int nonPick = 0 + dp[i - 1];
            dp[i] = max(pick, nonPick);
        }
        return dp[n - 1];
    }
};

// Tabulation with space optimization
// TC :- O(N), SC :- O(1)
class Solution
{
public:
    int rob(vector<int> &arr)
    {
        int n = arr.size();
        int prev = arr[0];
        int prev1 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = arr[i] + (i > 1 ? prev1 : 0);
            int nonPick = 0 + prev;
            int curr = max(pick, nonPick);
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution s;
    cout << s.rob(arr) << endl;

    return 0;
}