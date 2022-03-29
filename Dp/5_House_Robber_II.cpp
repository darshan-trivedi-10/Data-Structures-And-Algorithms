// https://leetcode.com/problems/house-robber-ii/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{

public:
    long long int solve(vector<int> &arr)
    {
        int n = arr.size();
        long long int prev = arr[0];
        long long int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            long long int pick = arr[i];
            if (i > 1)
                pick += prev2;
            int long long nonPick = 0 + prev;

            long long int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    }

    int rob(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> arr1;
        vector<int> arr2;
        if (n == 1)
        {
            return arr[0];
        }
        if (n == 0)
        {
            return 0;
        }
        if (n == 2)
        {
            return max(arr[0], arr[1]);
        }

        for (int i = 0; i < n; i++)
        {

            if (i != 0)
                arr1.push_back(arr[i]);
            if (i != n - 1)
                arr2.push_back(arr[i]);
        }

        long long int ans1 = solve(arr1);
        long long int ans2 = solve(arr2);

        return max(ans1, ans2);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}