// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    bool findSubset(vector<int> &arr, vector<vector<int>> &dp, int sum, int idx)
    {
        if (sum <= 0)
        {
            return sum == 0;
        }

        if (idx == 0)
        {
            return arr[0] == sum;
        }

        if (dp[idx][sum] != -1)
        {
            return dp[idx][sum];
        }

        bool a = findSubset(arr, dp, sum, idx - 1);
        bool b = findSubset(arr, dp, sum - arr[idx], idx - 1);
        return dp[idx][sum] = a || b;
    }

public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return findSubset(arr, dp, sum, n - 1);
    }
};

// Tabulastion
class Solution
{

public:
    bool isSubsetSum(vector<int> arr, int k)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if (arr[0] <= k)
        {
            dp[0][arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= k; target++)
            {

                bool notTaken = dp[ind - 1][target];

                bool taken = false;
                if (arr[ind] <= target)
                {
                    taken = dp[ind - 1][target - arr[ind]];
                }

                dp[ind][target] = notTaken || taken;
            }
        }

        return dp[n - 1][k];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}