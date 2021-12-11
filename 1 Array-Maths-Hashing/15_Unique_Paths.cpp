// https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

/*
--> Time Complexity: The time comp[lexity of this recursive solution is
    exponential.

--> Space Complexity: As we are using stack space for recursion so the space
    complexity will also be exponential.
*/
class Solution
{
public:
    int countPaths(int i, int j, int n, int m)
    {
        if (i == (n - 1) && j == (m - 1))
            return 1;
        if (i >= n || j >= m)
            return 0;
        else
            return countPaths(i + 1, j, n, m) + countPaths(i, j + 1, n, m);
    }
    int uniquePaths(int m, int n)
    {
        return countPaths(0, 0, m, n);
    }
};

// Using Dynamic Programming
// Time Complexity : O(N*M), Space Complexity : O(N x M)
class Solution
{
public:
    int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if (i == (n - 1) && j == (m - 1))
            return 1;
        if (i >= n || j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        else
            return dp[i][j] = countPaths(i + 1, j, n, m, dp) + countPaths(i, j + 1, n, m, dp);
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        // dp[1][1]=1;
        int num = countPaths(0, 0, m, n, dp);
        if (m == 1 && n == 1)
            return num;
        return dp[0][0];
    }
};

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int N = n + m - 2;     // total steps = n-1 + m-1
        int r = min(n, m) - 1; // will iterate on the minimum for efficiency = (total) C (min(right, down))

        double res = 1;

        // compute nCr
        for (int i = 1; i <= r; ++i, N--)
        {

            res = res * (N) / i;
        }

        return (int)res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}