// https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    int findPath(vector<vector<int>> &dp, int m, int n, int i, int j)
    {
        if (i == n - 1 && j == m - 1)
        {
            return 1;
        }
        if (i >= n || j >= m || i < 0 || j < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = findPath(dp, m, n, i, j + 1);
        int bottom = findPath(dp, m, n, i + 1, j);
        return dp[i][j] = right + bottom;
    }

public:
    int uniquePaths(int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int totalPath = findPath(dp, m, n, 0, 0);
        return totalPath;
    }
};

class Solution
{
public:
    int uniquePaths(int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }

                dp[i][j] = up + left;
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Solution a;
    cout << a.uniquePaths(n, m);

    return 0;
}