// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

// Time Complexity : O(N), Space Complexity : O(1)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int profit = 0;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, prices[i]);
            profit = max(profit, prices[i] - mini);
        }

        return profit;
    }
};

// Time Complexity : O(N), Space Complexity : O(N)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int ans = 0;
        int max_a[n] = {0};
        max_a[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            max_a[i] = max(max_a[i - 1], prices[i]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                ans = max(ans, prices[j] - prices[j + 1]);
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}