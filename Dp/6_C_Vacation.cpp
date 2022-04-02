// https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'
struct triplet
{
    int a, b, c;
};

// Time Complexity : O(n x 4 x 2).
int solve(vector<vector<int>> &points, vector<vector<int>> &dp, int day, int flag)
{
    if (dp[day][flag] != -1)
    {
        return dp[day][flag];
    }

    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (i != flag)
            {
                maxi = max(maxi, points[day][i]);
            }
        }
        return dp[day][flag] = maxi;
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (i != flag)
        {
            maxi = max(maxi, points[day][i] + solve(points, dp, day - 1, i));
        }
    }
    return dp[day][flag] = maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    vector<vector<int>> dp(n, vector<int>(4, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }

    cout << solve(points, dp, n - 1, 3) << endl;

    return 0;
}