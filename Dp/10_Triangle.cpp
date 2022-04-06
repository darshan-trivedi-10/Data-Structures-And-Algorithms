// https://leetcode.com/problems/triangle/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    int findMinPath(vector<vector<int>> &triangle, vector<vector<int>> &dp, int i, int j)
    {
        int n = triangle.size(), m = triangle[0].size();
        if (i == n - 1)
        {
            return triangle[i][j];
        }

        if (dp[i][j] != INT_MIN)
        {
            return dp[i][j];
        }

        int bottom = findMinPath(triangle, dp, i + 1, j);
        int bottomNext = findMinPath(triangle, dp, i + 1, j + 1);

        return dp[i][j] = triangle[i][j] + min(bottom, bottomNext);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        return findMinPath(triangle, dp, 0, 0);
    }
};

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {

                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }
};

int main()
{

    return 0;
}