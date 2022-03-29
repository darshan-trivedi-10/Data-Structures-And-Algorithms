// https://leetcode.com/problems/two-city-scheduling/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int ans = 0;
        vector<int> refund;
        for (int i = 0; i < n; i++)
        {
            ans += arr[i][0];
            refund.push_back(arr[i][1] - arr[i][0]);
        }
        sort(refund.begin(), refund.end());
        for (int i = 0; i < (n / 2); i++)
        {
            ans += refund[i];
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