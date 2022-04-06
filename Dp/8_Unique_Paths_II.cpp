// https://leetcode.com/problems/unique-paths-ii/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    int findPath(vector<vector<int>> &arr, vector<vector<int>> &dp, int i, int j)
    {
        int n = arr.size(), m = arr[0].size();
        if (i == n - 1 && j == m - 1)
        {
            return arr[i][j] == 1 ? 0 : 1;
        }
        if (i >= n || j >= m || i < 0 || j < 0 || arr[i][j] == 1)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = findPath(arr, dp, i, j + 1);
        int bottom = findPath(arr, dp, i + 1, j);
        return dp[i][j] = right + bottom;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &arr)
    {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int totalPath = findPath(arr, dp, 0, 0);
        return totalPath;
    }
};

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!obstacleGrid[i - 1][j - 1])
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    return 0;
}