// https://leetcode.com/problems/climbing-stairs/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    int findWay(int n, vector<int> &dp)
    {
        if (n <= 0)
        {
            return (n == 0 ? 1 : 0);
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = findWay(n - 1, dp) + findWay(n - 2, dp);
        return dp[n];
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return findWay(n, dp);
    }
};

int main()
{

    return 0;
}