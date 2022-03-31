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

int const maxi = (int)(1e5 + 10);
vector<triplet> arr(maxi);
int dp[maxi][4];

// Time Complexity : O(n x 4 x 2).
int solve(int s, int n, int flag)
{
    if (s == n)
    {
        return 0;
    }

    if (dp[s][flag] != -1)
    {
        return dp[s][flag];
    }

    int cost = INT_MIN;
    if (flag == 0)
    {
        cost = max(cost, (arr[s].a + (int)solve(s + 1, n, 1)));
        cost = max(cost, (arr[s].b + (int)solve(s + 1, n, 2)));
        cost = max(cost, (arr[s].c + (int)solve(s + 1, n, 3)));
    }
    else if (flag == 1)
    {
        cost = max(cost, (arr[s].b + (int)solve(s + 1, n, 2)));
        cost = max(cost, (arr[s].c + (int)solve(s + 1, n, 3)));
    }
    else if (flag == 2)
    {
        cost = max(cost, (arr[s].a + (int)solve(s + 1, n, 1)));
        cost = max(cost, (arr[s].c + (int)solve(s + 1, n, 3)));
    }
    else
    {
        cost = max(cost, (arr[s].a + (int)solve(s + 1, n, 1)));
        cost = max(cost, (arr[s].b + (int)solve(s + 1, n, 2)));
    }

    dp[s][flag] = cost;

    return dp[s][flag];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }

    cout << solve(0, n, 0) << endl;

    return 0;
}