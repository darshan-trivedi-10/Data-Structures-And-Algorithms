// https://atcoder.jp/contests/dp/tasks/dp_b
// Learn Tabulation
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

// Memorization
// TC :- O(N * k) , SC :- O(N) + O(N)
int minCost(vector<int> &heights, vector<int> &dp, int k, int ind)
{
    if (ind == 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int ans = INT_MAX;
    for (int i = ind - 1; i >= max(0, ind - k); i--)
    {
        int currCost = minCost(heights, dp, k, i) + abs(heights[ind] - heights[i]);
        ans = min(ans, currCost);
    }

    return dp[ind] = ans;
}

 

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    vector<int> dp(n, -1);
    cout << minCost(heights, dp, k, n - 1) << "\n";

    return 0;
}