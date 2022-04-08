// https://leetcode.com/problems/cherry-pickup-ii/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    int findMaxCherry(vector<vector<int>> &arr, vector<vector<vector<int>>> &dp, int i, int j1, int j2)
    {
        int n = arr.size(), m = arr[0].size();
        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
        {
            return (int)(-1e9);
        }

        if (i == n - 1)
        {
            if (j1 == j2)
            {
                return arr[i][j1];
            }

            return arr[i][j1] + arr[i][j2];
        }

        if (dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }

        //  Explore all paths of alice and bob simultaneously
        int maxi = -1e9;
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                int value = 0;
                if (j1 == j2)
                {
                    value = arr[i][j1];
                }
                else
                {
                    value = arr[i][j1] + arr[i][j2];
                }

                value = value + findMaxCherry(arr, dp, i + 1, j1 + dj1, j2 + dj2);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>> &arr)
    {
        int n = arr.size(), m = arr[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return findMaxCherry(arr, dp, 0, 0, m - 1);
    }
};

// Tabulation

class Solution
{

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        // Outer Nested Loops for travering DP Array
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {

                    int maxi = INT_MIN;

                    // Inner nested loops to try out 9 options
                    for (int di = -1; di <= 1; di++)
                    {
                        for (int dj = -1; dj <= 1; dj++)
                        {

                            int ans;

                            if (j1 == j2)
                                ans = grid[i][j1];
                            else
                                ans = grid[i][j1] + grid[i][j2];

                            if ((j1 + di < 0 || j1 + di >= m) ||
                                (j2 + dj < 0 || j2 + dj >= m))

                                ans += -1e9;
                            else
                                ans += dp[i + 1][j1 + di][j2 + dj];

                            maxi = max(ans, maxi);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}