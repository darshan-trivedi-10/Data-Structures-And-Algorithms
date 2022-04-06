// https://leetcode.com/problems/minimum-falling-path-sum/
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
        if (i < 0 || j < 0 || i >= n || j >= m)
        {
            return INT_MAX;
        }

        if (i == n - 1)
        {
            return arr[i][j];
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        return dp[i][j] = arr[i][j] + min({findMinPath(arr, dp, i + 1, j - 1), findMinPath(arr, dp, i + 1, j), findMinPath(arr, dp, i + 1, j + 1)});
    }

public:
    int minFallingPathSum(vector<vector<int>> &arr)
    {
        int n = arr.size(), m = arr[0].size();
        int minAns = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < m; i++)
        {
            minAns = min(minAns, findMinPath(arr, dp, 0, i));
        }
        return minAns;
    }
};

//  Tabulastion
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Initializing first row - base condition
        for (int j = 0; j < m; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int up = matrix[i][j] + dp[i - 1][j];

                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0)
                    leftDiagonal += dp[i - 1][j - 1];
                else
                    leftDiagonal += 1e9;

                int rightDiagonal = matrix[i][j];
                if (j + 1 < m)
                    rightDiagonal += dp[i - 1][j + 1];
                else
                    rightDiagonal += 1e9;

                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }

        int maxi = INT_MAX;

        for (int j = 0; j < m; j++)
        {
            maxi = min(maxi, dp[n - 1][j]);
        }

        return maxi;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}