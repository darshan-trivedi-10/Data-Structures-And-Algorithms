// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    int n = arr.size();
    if (target == 0)
    {
        return 1;
    }

    if (ind == n - 1)
    {
        return target == arr[ind] ? 1 : 0;
    }

    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }
    int nonPick = findWaysUtil(ind + 1, target, arr, dp);

    int pick = 0;
    if (arr[ind] <= target)
    {
        pick = findWaysUtil(ind + 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = pick + nonPick;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return findWaysUtil(0, tar, num, dp);
}

int findWays(vector<int> &num, int k)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (num[0] <= k)
    {
        dp[0][num[0]] = 1;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {

            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (num[ind] <= target)
            {
                taken = dp[ind - 1][target - num[ind]];
            }
            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][k];
}

int main()
{

    return 0;
}
