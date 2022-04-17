// https://leetcode.com/problems/partition-equal-subset-sum/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    bool checkSum(vector<int> &arr, vector<vector<int>> &dp, int totalSum, int idx)
    {

        if (totalSum <= 0)
        {
            return totalSum == 0;
        }

        if (idx >= arr.size() - 1)
        {
            return arr[idx] == totalSum;
        }

        if (dp[idx][totalSum] != -1)
        {
            return dp[idx][totalSum];
        }

        bool a = checkSum(arr, dp, totalSum, idx + 1);
        bool b = checkSum(arr, dp, totalSum - arr[idx], idx + 1);

        return dp[idx][totalSum] = a || b;
    }

public:
    bool canPartition(vector<int> &arr)
    {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if (totalSum & 1)
        {
            return false;
        }
        totalSum /= 2;
        vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
        return checkSum(arr, dp, totalSum, 0);
    }
};

// Tabulastion
class Solution
{
    bool checkSum(vector<int> &arr, vector<vector<int>> &dp, int totalSum)
    {
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if (arr[0] <= totalSum)
        {
            dp[0][arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= totalSum; target++)
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

        return dp[n - 1][totalSum];
    }

public:
    bool canPartition(vector<int> &arr)
    {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if (totalSum & 1)
        {
            return false;
        }
        totalSum /= 2;
        vector<vector<int>> dp(n, vector<int>(totalSum + 1, 0));
        return checkSum(arr, dp, totalSum);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}