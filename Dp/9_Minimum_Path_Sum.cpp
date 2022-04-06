// https://leetcode.com/problems/minimum-path-sum/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    int findMinPath(vector<vector<int>> &arr, vector<vector<int>> &dp, int i, int j)
    {
        int n = arr.size(), m = arr[0].size();
        if (i == n - 1 && j == m - 1)
        {
            return arr[i][j];
        }
        if (i < 0 || j < 0 || i >= n || j >= m)
        {
            return INT_MAX;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int down = findMinPath(arr, dp, i + 1, j);
        int right = findMinPath(arr, dp, i, j + 1);

        return dp[i][j] = arr[i][j] + min(down, right);
    }

public:
    int minPathSum(vector<vector<int>> &arr)
    {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return findMinPath(arr, dp, 0, 0);
    }
};

// Tablusation

class Solution
{
    int findMinPath(vector<vector<int>> &matrix, int i, int j)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = matrix[i][j];
                }
                else
                {

                    int up = matrix[i][j];
                    if (i > 0)
                    {
                        up += dp[i - 1][j];
                    }
                    else
                    {
                        up += 1e9;
                    }

                    int left = matrix[i][j];
                    if (j > 0)
                    {
                        left += dp[i][j - 1];
                    }
                    else
                    {
                        left += 1e9;
                    }

                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[n - 1][m - 1];
    }

public:
    int minPathSum(vector<vector<int>> &arr)
    {
        return findMinPath(arr, 0, 0);
    }
};

int main()
{

    return 0;
}